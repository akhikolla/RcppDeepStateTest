#include <Rcpp.h>
using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
double ds_1(Rcpp::NumericVector y, double lambda, double alpha)
{
	int len = y.size();
	double lpd = -lambda * log((double)len);
	double unit = 1.0 / len;
	Rcpp::NumericVector lscore(len+1);
	Rcpp::NumericVector rscore(len+1);
	Rcpp::IntegerVector idx(2*len+2);
	for(int k = 0; k < len+1; ++k){
		lscore[k] = 0;
		rscore[k] = 0;
		idx[k] = -1;
	}
	int cutpos;
	double dc, dq, lval, rval;
	double tpcut, cutsc;
	//  i = 0, log likelihood = 0 for the left side
	lval = alpha * log(y[0]);
	rval = log(unit) + (alpha - 1) * log(y[0]);	//	log(unit / y[0]) + alpha * log(y[0])
	lscore[0] = lval + lpd;
	rscore[0] = rval + lpd;
	idx[1] = 0;
	idx[2] = 0;
	//  i = 0 end
	for(int i = 1; i < len; ++i){
		//  on left side of i
		lval = i * log(i * unit / y[i]);
		cutsc = lval + lpd + alpha * log(y[i]);
		cutpos = 0;
		for(int j = 0; j < i-1; ++j){
			dc = i - j;
			dq = y[i] - y[j];
			lval = lscore[j] + dc * log(dc * unit / dq);
			rval = rscore[j] + (dc - 1) * log((dc - 1) * unit / dq);
			tpcut = max(lval, rval) + lpd + alpha * log(dq);
			if(cutsc < tpcut){
				cutsc = tpcut;
				cutpos = j;
			}
		}
		//  j = i - 1
		dc = 1;
		dq = y[i] - y[i-1];
		lval = lscore[i-1] + log(unit / dq);
		rval = rscore[i-1];
		tpcut = max(lval, rval) + lpd + alpha * log(dq);
		if(cutsc < tpcut){
			cutsc = tpcut;
			cutpos = i-1;
		}
		//  j = i - 1 end
		lscore[i] = cutsc;
		idx[2*i+1] = cutpos;
		//  on right side of i
		rval = (i + 1) * log((i + 1) * unit / y[i]);
		cutsc = rval + lpd + alpha * log(y[i]);
		cutpos = 0;
		for(int j = 0; j < i; ++j){
			dc = i - j;
			dq = y[i] - y[j];
			lval = lscore[j] + (dc + 1) * log((dc + 1) * unit / dq);
			rval = rscore[j] + dc * log(dc * unit / dq);
			tpcut = max(lval, rval) + lpd + alpha * log(dq);
			if(cutsc < tpcut){
				cutsc = tpcut;
				cutpos = j;
			}
		}
		rscore[i] = cutsc;
		idx[2*i+2] = cutpos;
	}
	//  i = len, i.e. for y_{n+1} = 1.0
	//  on left side of len, no right side
	cutsc = lpd;  //  n*log(n/n /1) + lpd + alpha * log(1)
	cutpos = 0;
	for(int j = 0; j < len-1; ++j){
		dc = len - j;
		dq = 1.0 - y[j];
		lval = lscore[j] + dc * log(dc * unit / dq);
		rval = rscore[j] + (dc - 1) * log((dc - 1) * unit / dq);
		tpcut = max(lval, rval) + lpd + alpha * log(dq);
		if(cutsc < tpcut){
			cutsc = tpcut;
			cutpos = j;
		}
	}
	//  j = len - 1
	dc = 1;
	dq = 1.0 - y[len-1];
	lval = lscore[len-1] + log(unit / dq);
	rval = rscore[len-1];
	tpcut = max(lval, rval) + lpd + alpha * log(dq);
	if(cutsc < tpcut){
		cutsc = tpcut;
		cutpos = len-1;
	}
	//  j = len - 1 end
	lscore[len] = cutsc;
	idx[2*len+1] = cutpos;
	//  i = len end
	double mlik = lscore[len] - lpd;
	return mlik;
}
