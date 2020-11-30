#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
double ds_eqp_k(Rcpp::NumericVector x, int dim, double lambda)
{
	int len = x.size();
	double lpd = -lambda * log((double)len);
	const double epsilon = 1e-6;

	int baselen = (int)sqrt((double)len);
	//  at most "baselen+2" groups with each group has size "baselen" at least
	Rcpp::NumericVector divsch(baselen+3);
	divsch[0] = 0;
	int flagl = baselen;
	int ngrp = 0;
	while(flagl < len){
		if(x[flagl] - x[flagl-1] != 0){
			divsch[++ngrp] = flagl;
			flagl += baselen;
		}else{
			flagl++;
		}
	}
	divsch[++ngrp] = len;
	Rcpp::NumericMatrix ctab(ngrp+1, dim);
	for(int k = 1; k < ngrp+1; ++k){
		for(int j = 0; j < dim; ++j){
			ctab(k, j) += ctab(k-1, j);
		}
		for(int j = divsch[k-1]; j < divsch[k]; ++j){
			ctab(k, x[j]) += 1;
		}
	}
	Rcpp::NumericVector score(ngrp+1);
	Rcpp::IntegerVector idx(ngrp+1);
	for(int k = 0; k < ngrp+1; ++k){
		score[k] = 0;
		idx[k] = -1;
	}
	Rcpp::NumericVector counts(dim);
	int tc, cutpos;
	double tpcut, cutsc;
	for(int i = 1; i < ngrp+1; ++i){
		//  j = 0
		cutsc = lpd + score[0];
		tc = 0;
		for(int u = 0; u < dim; ++u){
			tc += ctab(i, u);
		}
		for(int u = 0; u < dim; ++u){
			counts[u] = ctab(i, u);
			if(counts[u] > epsilon){
				cutsc += counts[u] * log(counts[u] / tc);
			}
		}
		cutpos = 0;
		//  j = 0 end
		for(int j = 1; j < i; ++j){
			tpcut = lpd + score[j];
			tc = 0;
			for(int u = 0; u < dim; ++u){
				tc += ctab(i, u) - ctab(j, u);
			}
			for(int u = 0; u < dim; ++u){
				counts[u] = ctab(i, u) - ctab(j, u);
				if(counts[u] > epsilon){
					tpcut += counts[u] * log(counts[u] / tc);
				}
			}
			if(cutsc < tpcut){
				cutsc = tpcut;
				cutpos = j;
			}
		}
		score[i] = cutsc;
		idx[i] = cutpos;
	}
	double mlik = score[ngrp] - lpd;
	//  substract null log-likelihood (assume one slice, i.e., no cut)
	for(int u = 0; u < dim; ++u){
		if(ctab(ngrp, u) > epsilon){
			mlik -= ctab(ngrp, u) * log(ctab(ngrp, u) / len);
		}
	}
	return mlik;
}
