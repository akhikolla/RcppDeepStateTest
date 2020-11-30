#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
double ds_eqp_1(Rcpp::NumericVector y, double lambda)
{
	int len = y.size();
	double lpd = -lambda * log((double)len);
	double unit = 1.0 / len;
	const double epsilon = 1e-6;

	Rcpp::NumericVector ctab(len+1);  //  cumulated unit counts
	ctab[0] = 0;
	int l = 1;
	double flagf = unit;
	for(int i = 0; i < len; ++i){
		while(y[i] > flagf){
			ctab[l++] = i;
			flagf += unit;
		}
	}
	for(; l < len+1; ++l){
		ctab[l] = len;
	}
	Rcpp::NumericVector score(len+1);
	Rcpp::IntegerVector idx(len+1);
	for(int k = 0; k < len+1; ++k){
		score[k] = 0;
		idx[k] = -1;
	}
	int cutpos;
	double dq, dc, tpcut, cutsc;
	for(int i = 1; i < len+1; ++i){
		cutsc = lpd + score[0];
		dq = i;
		dc = ctab[i] - ctab[0];
		if(dc > epsilon){
			cutsc +=  dc * log(dc / dq);
		}
		cutpos = 0;
		for(int j = 1; j < i; ++j){
			tpcut = lpd + score[j];
			dq = i - j;
			dc = ctab[i] - ctab[j];
			if(dc > epsilon){
				tpcut +=  dc * log(dc / dq);
			}
			if(cutsc < tpcut){
				cutsc = tpcut;
				cutpos = j;
			}
		}
		score[i] = cutsc;
		idx[i] = cutpos;
	}
	double mlik = score[len] - lpd;
	dq = len;
	dc = ctab[len];
	mlik -= dc * log(dc / dq);
	return mlik;  //  maximized log-likelihood
}
