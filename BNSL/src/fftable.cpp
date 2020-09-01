#include <Rcpp.h>
using namespace Rcpp;

inline int zerocount(uint64_t x)
{
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);
    x = x | (x >> 32);
    return 64 - __builtin_popcountll( ~x );
}

IntegerMatrix normalize_table(NumericMatrix& matrix,
                              IntegerVector& kind_vec,
                              IntegerVector& bit_pos_vec)
{
    int nrow = matrix.nrow();
    int ncol = matrix.ncol();
    IntegerMatrix ret(nrow, ncol);

    kind_vec = IntegerVector(ncol);
    bit_pos_vec = IntegerVector(ncol + 1);
    bit_pos_vec[0] = 0;

    for (int j = 0; j < ncol; ++j) {
        std::map<int, int> val_map;
        int c = 0;
        for (int i = 0; i < nrow; ++i) {
            if (val_map.find(matrix(i, j)) == val_map.end()) { // not found
                val_map[matrix(i, j)] = c;
                ++c;
            }
            ret(i, j) = val_map[matrix(i, j)];
        }
        kind_vec[j] = c;
        bit_pos_vec[j + 1] = bit_pos_vec[j] + zerocount(c - 1);
        if (bit_pos_vec[j + 1] > 64) {
            stop("bit_pos width cannot exceed 64!");
        }
    }
    return ret;
}

IntegerMatrix fftable_i(IntegerMatrix matrix, int w, int h,
                        uint64_t children, IntegerVector bit_pos_vec)
{
    int nrow = matrix.nrow();
    int ncol = matrix.ncol();
    IntegerMatrix T(nrow, w);
    std::map<uint64_t, std::map<int, int> > counter;

    for (int i = 0; i < nrow; ++i) {
        uint64_t b = 0;
        for (int j = 0; j < ncol; ++j) {
            if ((children & (static_cast<uint64_t>(1) << j)) != 0) {
                b |= (static_cast<uint64_t>(matrix(i, j)) << bit_pos_vec[j]);
            }
        }
        int val = matrix(i, h);
        counter[b][val] += 1;
    }
    int row = 0;
    std::map<uint64_t, std::map<int, int> >::iterator itor1 = counter.begin();
    while (itor1 != counter.end()) {
        int col = 0;
        std::map<int, int>::iterator itor2 = itor1->second.begin();
        while (itor2 != itor1->second.end()) {
            T(row, col) = itor2->second;
            ++col;
            ++itor2;
        }
        ++row;
        ++itor1;
    }
    return T(Range(0, row - 1), _);
}

// [[Rcpp::export]]
IntegerMatrix fftable(NumericMatrix df, int w){
    IntegerVector kind_vec;
    IntegerVector bit_pos_vec;

    IntegerMatrix table = normalize_table(df, kind_vec, bit_pos_vec);
    uint64_t children = (static_cast<uint64_t>(1) << (df.ncol() - 1)) - 1;
    return fftable_i(table, w, df.ncol() - 1, children, bit_pos_vec);
}
