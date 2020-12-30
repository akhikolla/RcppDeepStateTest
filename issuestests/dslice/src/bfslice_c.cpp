#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
double bfslice_c(Rcpp::NumericVector z, Rcpp::NumericVector x, int zdim, int xdim, double lambda, double alpha)
{
	int len = x.size();
	double prior = 1.0 / (1.0 + exp(lambda * log((double)len)));
	int tablen = len + 1;
	Rcpp::NumericVector gztab(tablen);
	Rcpp::NumericVector gxtab(tablen);
	gztab[0] = 0;
	gxtab[0] = 0;
	double beta = alpha / xdim;
	for(int k = 1; k < tablen; ++k){
		gztab[k] = gztab[k-1] + log(alpha + k - 1);
		gxtab[k] = gxtab[k-1] + log(beta + k - 1);
	}

	int dim = zdim * xdim;
	int colidx;  //  column index
	Rcpp::NumericMatrix ctab(tablen, dim);
	for(int j = 0; j < dim; ++j){
		ctab(0, j) = 0;
	}
	for(int k = 1; k < tablen; ++k){
		for(int j = 0; j < dim; ++j){
			ctab(k, j) += ctab(k-1, j);
		}
		colidx = z[k-1] * xdim + x[k-1];
		ctab(k, colidx) += 1;
	}

	//  log Probability that null hypothesis holds
	Rcpp::NumericVector zcount(zdim);
	Rcpp::NumericVector logPr0(tablen);
	logPr0[0] = 0;
	for(int i = 1; i < tablen; ++i){
		logPr0[i] = 0;
		for(int u = 0; u < zdim; ++u){
			zcount[u] = 0;
			for(int v = 0; v < xdim; ++v){
				colidx = u * xdim + v;
				zcount[u] += ctab(i, colidx);
				logPr0[i] += gxtab[ctab(i, colidx)];
			}
			logPr0[i] -= gztab[zcount[u]];
		}
	}

	//  calculate Bayes factor
	double coef, log_delta_ji;
	int dc;
	Rcpp::NumericVector bf(tablen);
	bf[0] = 1 / prior;
	for(int i = 1; i < tablen; ++i){
		bf[i] = 0;
		for(int j = 0; j < i; ++j){
			log_delta_ji = 0;
			for(int u = 0; u < zdim; ++u){
				zcount[u] = 0;
				for(int v = 0; v < xdim; ++v){
					colidx = u * xdim + v;
					dc = ctab(i, colidx) - ctab(j, colidx);
					zcount[u] += dc;
					log_delta_ji += gxtab[dc];
				}
				log_delta_ji -= gztab[zcount[u]];
			}
			log_delta_ji += log(prior) - log(1 - prior);
			coef = (i - j) * log(1 - prior) + logPr0[j] - logPr0[i] + log_delta_ji;
			bf[i] += exp(coef) * bf[j];
		}
	}
	double dsbf = bf[len];
	return dsbf;
}
