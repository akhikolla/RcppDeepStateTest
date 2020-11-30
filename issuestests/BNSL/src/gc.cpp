#include <Rcpp.h>
using namespace Rcpp;

#include <cmath>

#include "gc.h"

// [[Rcpp::export]]
double gc(int n, double a){double S=0; while(n>0){S=S+log(n-1+a); n--;} return(S);}

// [[Rcpp::export]]
double gc_all(IntegerVector cc, double a){
 	int m=cc.size(); double S=0;  
	while(m>0){S=S+gc((int)cc(m-1),a); m--;}
	return(S);
// 	if(m==1)return(gc((int)cc(0),a)); else return(gc_all(tail(cc,m-1),a)+gc((int)cc(0),a));
}
