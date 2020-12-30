//March 18th, 2014
//The purpose of this C-code is to write essential functions for sampling from a GP, using RCpp and RCppEigen
//Giri Gopalan
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericMatrix rcpp_distance(NumericMatrix l,int m, int N) {
  NumericMatrix out(m,m);
	for (int i = 0; i < m; i++) {
		for(int j = 0; j < m; j++){
		  for(int k = 0; k < N; k++){
		    out(i,j) = pow(l(i,k)-l(j,k),2)+out(i,j);
		  }
		  out(i,j) = sqrt(out(i,j));
		}
	}
	return(out);
}
