#include <R.h>
#include <Rdefines.h>
#include <Rinternals.h>
#include <algorithm>
#include <vector>

//#define DEBUG

// These functions use the STL function lower_bound to find the index of the
// smallest break exceeding x[i].  Data exceeding the top break get index equal
// to nbreak.


/*

   library(oce)
   system("R CMD SHLIB bin.cpp")
   dyn.load("bin.so")
   set.seed(123)
   x <- rnorm(10, sd=1)
   f <- 2*x
   source('../R/misc.R')
   m <- binMean1D(x, f, seq(-1.5, 1.5, 0.5))
   old <- binAverage(x, f, -1.5, 1.5, 0.5)
   data.frame(mids=m$xmids, mean=m$mean, oldMethod=old$y)

*/

extern "C" {
    void bin_count_1d(int *nx, double *x, int *nxbreaks, double *xbreaks,
            int *number, double *mean)
    {

        if (*nxbreaks < 2)
            error("cannot have fewer than 1 break"); // already checked in R but be safe
        std::vector<double> b(xbreaks, xbreaks + *nxbreaks);
        std::sort(b.begin(), b.end()); // STL wants breaks ordered
        for (int i = 0; i < (*nxbreaks-1); i++) {
            number[i] = 0;
        }
        for (int i = 0; i < (*nx); i++) {
            std::vector<double>::iterator lower_bound;
            lower_bound = std::lower_bound(b.begin(), b.end(), x[i]);
            int bi = lower_bound - b.begin();
            if (bi > 0 && bi < (*nxbreaks)) {
#ifdef DEBUG
                Rprintf("x: %6.3f   bi: %d    (%f to %f)\n", x[i], bi, xbreaks[bi-1], xbreaks[bi]);
#endif
                number[bi-1]++;
            }
        }
    }
}

extern "C" {
    void bin_mean_1d(int *nx, double *x, double *f, int *nxbreaks, double *xbreaks,
            int *number, double *mean)
    {

        if (*nxbreaks < 2)
            error("cannot have fewer than 1 break"); // already checked in R but be safe
        std::vector<double> b(xbreaks, xbreaks + *nxbreaks);
        std::sort(b.begin(), b.end()); // STL wants breaks ordered
        for (int i = 0; i < (*nxbreaks-1); i++) {
            number[i] = 0;
            mean[i] = 0.0;
        }
        for (int i = 0; i < (*nx); i++) {
            if (!ISNA(f[i])) {
                std::vector<double>::iterator lower_bound;
                lower_bound = std::lower_bound(b.begin(), b.end(), x[i]);
                int bi = lower_bound - b.begin();
                if (bi > 0 && bi < (*nxbreaks)) {
#ifdef DEBUG
                    Rprintf("x: %6.3f   bi: %d    (%f to %f)\n", x[i], bi, xbreaks[bi-1], xbreaks[bi]);
#endif
                    number[bi-1]++;
                    mean[bi-1] += f[i];
                }
            }
        }
        for (int i = 0; i < (*nxbreaks-1); i++) {
            if (number[i] > 0) {
                mean[i] = mean[i] / number[i];
            } else {
                mean[i] = NA_REAL;
            }
        }
    }
}


#define ij(i, j) ((i) + (*nxbreaks-1) * (j))
extern "C" {
    void bin_count_2d(int *nx, double *x, double *y,
            int *nxbreaks, double *xbreaks,
            int *nybreaks, double *ybreaks,
            int *number, double *mean)
    {
#ifdef DEBUG
        Rprintf("nxbreaks: %d, nybreaks: %d\n", *nxbreaks, *nybreaks);
#endif
        if (*nxbreaks < 2) error("cannot have fewer than 1 xbreak"); // already checked in R but be safe
        if (*nybreaks < 2) error("cannot have fewer than 1 ybreak"); // already checked in R but be safe
        std::vector<double> bx(xbreaks, xbreaks + *nxbreaks);
        std::sort(bx.begin(), bx.end()); // STL wants breaks ordered
        std::vector<double> by(ybreaks, ybreaks + *nybreaks);
        std::sort(by.begin(), by.end()); // STL wants breaks ordered
        for (int bij = 0; bij < (*nxbreaks-1) * (*nybreaks-1); bij++) {
            number[bij] = 0;
        }
        for (int i = 0; i < (*nx); i++) {
            int bi = std::lower_bound(bx.begin(), bx.end(), x[i]) - bx.begin();
            int bj = std::lower_bound(by.begin(), by.end(), y[i]) - by.begin();
            if (bi > 0 && bj > 0 && bi < (*nxbreaks) && bj < (*nybreaks)) {
#ifdef DEBUG
                Rprintf("x: %6.3f, y: %6.3f, bi: %d, bj: %d\n", x[i], y[i], bi, bj);
#endif
                number[ij(bi-1, bj-1)]++;
            }
        }
    }
}
#undef ij


#define ij(i, j) ((i) + (*nxbreaks-1) * (j))
extern "C" {
    void bin_mean_2d(int *nx, double *x, double *y, double *f,
            int *nxbreaks, double *xbreaks,
            int *nybreaks, double *ybreaks,
            int *fill, int *fillgap, int *number, double *mean)
    {
#ifdef DEBUG
        Rprintf("nxbreaks: %d, nybreaks: %d\n", *nxbreaks, *nybreaks);
#endif
        if (*nxbreaks < 2) error("cannot have fewer than 1 xbreak"); // already checked in R but be safe
        if (*nybreaks < 2) error("cannot have fewer than 1 ybreak"); // already checked in R but be safe
        std::vector<double> bx(xbreaks, xbreaks + *nxbreaks);
        std::sort(bx.begin(), bx.end()); // STL wants breaks ordered
        std::vector<double> by(ybreaks, ybreaks + *nybreaks);
        std::sort(by.begin(), by.end()); // STL wants breaks ordered
        for (int bij = 0; bij < (*nxbreaks-1) * (*nybreaks-1); bij++) {
            number[bij] = 0;
            mean[bij] = 0.0;
        }
        for (int i = 0; i < (*nx); i++) {
            if (!ISNA(f[i])) {
                int bi = std::lower_bound(bx.begin(), bx.end(), x[i]) - bx.begin();
                int bj = std::lower_bound(by.begin(), by.end(), y[i]) - by.begin();
                if (bi > 0 && bj > 0 && bi < (*nxbreaks) && bj < (*nybreaks)) {
#ifdef DEBUG
                    Rprintf("x: %6.3f, y: %6.3f, bi: %d, bj: %d\n", x[i], y[i], bi, bj);
#endif
                    number[ij(bi-1, bj-1)]++;
                    mean[ij(bi-1, bj-1)] += f[i];
                }
            }
        }
        for (int bij = 0; bij < (*nxbreaks-1) * (*nybreaks-1); bij++) {
            if (number[bij] > 0) {
                mean[bij] = mean[bij] / number[bij];
            } else {
                mean[bij] = NA_REAL;
            }
        }
        if (*fill && *fillgap !=0) { // a logical in R calling functions
            int bad = 0;
            int im, ip, jm, jp;
            // Reminder: ij = j + i * nj, for column-order matrices, so i corresponds to x
            // FIXME: is upper limit in the next loops correct?
            for (int i = 0; i < *nxbreaks-1; i++) {
                for (int j = 0; j < *nybreaks-1; j++) {
                    if (ISNA(mean[ij(i,j)])) {
                        for (im=i-1; im > -1; im--) if (!ISNA(mean[ij(im, j)])) break;
                        for (jm=j-1; jm > -1; jm--) if (!ISNA(mean[ij(i, jm)])) break;
                        // FIXME: is the limit correct on next ... maybe nxbreaks-1 ???
                        for (ip=i+1; ip < *nxbreaks-1; ip++) if (!ISNA(mean[ij(ip, j)])) break;
                        for (jp=j+1; jp < *nybreaks-1; jp++) if (!ISNA(mean[ij(i, jp)])) break;
                        int N=0;
                        double SUM=0.0;
                        if (0 <= im && ip < *(nxbreaks)-1) {
                            if ((*fillgap) < 0 || (*fillgap) >= (ip-im)) {
                                double interpolant = mean[ij(im,j)]+(mean[ij(ip,j)]-mean[ij(im,j)])*(i-im)/(ip-im);
                                SUM += interpolant;
                                N++;
                            }
                        }
                        if (0 <= jm && jp < *(nybreaks)-1) {
                            if ((*fillgap) < 0 || (*fillgap) >= (jp-jm)) {
                                double interpolant = mean[ij(i,jm)]+(mean[ij(i,jp)]-mean[ij(i,jm)])*(j-jm)/(jp-jm);
                                SUM += interpolant;
                                N++;
                            }
                        }
                        if (N > 0) {
                            mean[ij(i, j)] = SUM / N;
                            number[ij(i, j)] = 1; // doesn't have much meaning
                        }
                        bad++;
                    }
                }
            }
#ifdef DEBUG
            Rprintf("nxbreaks: %d, nybreaks: %d\n", *nxbreaks, *nybreaks);
            Rprintf("number of gaps filled: %d\n", bad);
#endif
        }
    }
}
#undef ij

