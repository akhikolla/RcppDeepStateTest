#include <Rcpp.h>
using namespace Rcpp;

#include "fftable.h"
#include "score.h"

inline int pow(int i, int j)
{
    int k=1; while(j>0){k=k*i;j--;} return(k);
}

bool next_permutation(uint64_t* perm, int n)
{
    uint64_t& v = *perm;
    int p;
    for (p = 0; p < n; ++p) {
        if ((v & (static_cast<uint64_t>(1) << (n - p - 1))) == 0) {
            break;
        }
    }
    int q = p;
    for ( ; p < n; ++p) {
        if ((v & (static_cast<uint64_t>(1) << (n - p - 1))) != 0) {
            break;
        }
    }
    if (p == n) { // perm is 1...10...0
        return false;
    }
    v &= ~(((static_cast<uint64_t>(1) << (p + 1)) - 1) << (n - p - 1));
    v |= (((static_cast<uint64_t>(1) << (q + 1)) - 1) << (n - p));
    return true;
}

DataFrame parent_i(IntegerMatrix matrix, int h, int tw, int proc,
                   /*double s=0,*/ int n, int ss,
                   IntegerVector kind_vec,
                   IntegerVector bit_pos_vec)
{
    //int row = matrix.nrow();
    int col = matrix.ncol();
    int L = static_cast<uint64_t>(1) << (col - 1); // 2^{col-1}
    if (tw == 0) {
        tw = col - 1;
    }

    IntegerVector x(L), y(L);
    NumericVector z(L);

    uint64_t mask = (static_cast<uint64_t>(1) << h) - 1;

    for (int i = 0; i <= tw; ++i) {
        uint64_t perm = (static_cast<uint64_t>(1) << i) - 1;
        do {
            uint64_t ex_perm = (perm & mask) | (perm & ~mask);
            x[ex_perm] = false;
            z[ex_perm] = -100000000.0;
            for (int j = 0; j < col - 1; ++j) {
                if ((ex_perm & (static_cast<uint64_t>(1) << j)) != 0) {
                    uint64_t child = (ex_perm & ~(static_cast<uint64_t>(1) << j));
                    if (x[child]) {
                        x[ex_perm] = true;
                    }
                    if (z[child] > z[ex_perm]) {
                        y[ex_perm] = y[child];
                        z[ex_perm] = z[child];
                    }
                }
            }
            if (!x[ex_perm]) {
                int m = kind_vec[h];
                uint64_t children = (perm & mask) | ((perm & ~mask) << 1);
                int ss2 = 1;
                for (int j = 0; j < col; ++j) {
                    if ((children & static_cast<uint64_t>(1)) != 0) {
                        ss2 *= kind_vec[j];
                    }
                }
                IntegerMatrix T = fftable_i(matrix, m, h, children, bit_pos_vec);
                double bb = bound(T, m, proc, n, ss2);
                if (z[ex_perm] > bound(T, m, proc, n, ss2)) {
                    x[ex_perm] = true;
                } else {
                    double s = Bayes_score(T, m, proc, bb, n, ss2);
                    if (s > z[ex_perm]) {
                        y[ex_perm] = ex_perm;
                        z[ex_perm] = s;
                    }
                }
            }
        } while (next_permutation(&perm, col - 1));
    }
    DataFrame results = DataFrame::create(Named("y")=y,Named("z")=z);
    return(results);
}

// [[Rcpp::export]]
DataFrame parent(NumericMatrix df0, int h, int tw=0, int proc=0){
    IntegerVector kind_vec;
    IntegerVector bit_pos_vec;

    IntegerMatrix table = normalize_table(df0, kind_vec, bit_pos_vec);

    // -1 is a dummy value.
    return parent_i(table, h, tw, proc, df0.nrow(), -1, kind_vec, bit_pos_vec);
}
