#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
double bfslice_eqp_u(Rcpp::NumericVector x, int dim, double lambda, double alpha)
{
	int len = x.size();
	double prior = 1.0 / (1.0 + exp(lambda * log((double)len)));
	int tablen = len + 1;
	Rcpp::NumericVector alphatab(tablen);
	Rcpp::NumericVector betatab(tablen);
	alphatab[0] = 0;
	betatab[0] = 0;
	double beta = alpha / dim;
	for(int k = 1; k < tablen; ++k){
		alphatab[k] = alphatab[k-1] + log(alpha + k - 1);
		betatab[k] = betatab[k-1] + log(beta + k - 1);
	}

	int baselen = (int)sqrt((double)len);
	int ngrp = len / baselen;
	int tail = len % baselen;
	int tabgrp = ngrp + 1;
	
	Rcpp::NumericVector divsch(tabgrp);
	divsch[0] = 0;
	for(int k = 1; k < tabgrp; ++k){
		divsch[k] = divsch[k-1] + baselen;
	}
	if(tail != 0){
		for(int k = 1; k < tail+1; ++k){
			divsch[k] = divsch[k] + k;
		}
		for(int k = tail+1; k < tabgrp; ++k){
			divsch[k] = divsch[k] + tail;
		}
	}

	Rcpp::NumericMatrix ctab(tabgrp, dim);
	for(int j = 0; j < dim; ++j){
		ctab(0, j) = 0;
	}
	for(int k = 1; k < tabgrp; ++k){
		for(int j = 0; j < dim; ++j){
			ctab(k, j) += ctab(k-1, j);
		}
		for(int j = divsch[k-1]; j < divsch[k]; ++j){
			ctab(k, x[j]) += 1;
		}
	}

	//  log Probability that null hypothesis holds
	int counts;
	Rcpp::NumericVector logPr0(tabgrp);
	logPr0[0] = 0;
	for(int i = 1; i < tabgrp; ++i){
		logPr0[i] = 0;
		counts = 0;
		for(int v = 0; v < dim; ++v){
			counts += ctab(i, v);
			logPr0[i] += betatab[ctab(i, v)];
		}
		logPr0[i] -= alphatab[counts];
	}

	//  calculate Bayes factor
	double coef, log_delta_ji;
	int dc;
	Rcpp::NumericVector bf(tabgrp);
	bf[0] = 1 / prior;
	for(int i = 1; i < tabgrp; ++i){
		bf[i] = 0;
		for(int j = 0; j < i; ++j){
			log_delta_ji = 0;
			counts = 0;
			for(int v = 0; v < dim; ++v){
				dc = ctab(i, v) - ctab(j, v);
				counts += dc;
				log_delta_ji += betatab[dc];
			}
			log_delta_ji -= alphatab[counts];
			log_delta_ji += log(prior) - log(1 - prior);
			coef = (i - j) * log(1 - prior) + logPr0[j] - logPr0[i] + log_delta_ji;
			bf[i] += exp(coef) * bf[j];
		}
	}
	double dsbf = bf[ngrp];
	return dsbf;
}
