#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector pbivnorm_drezner(Rcpp::NumericVector a, Rcpp::NumericVector b, Rcpp::NumericVector rho);

TEST(immer_deepstate_test,pbivnorm_drezner_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector a  = RcppDeepState_NumericVector();
  qs::c_qsave(a,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/pbivnorm_drezner/inputs/a.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  NumericVector b  = RcppDeepState_NumericVector();
  qs::c_qsave(b,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/pbivnorm_drezner/inputs/b.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "b values: "<< b << std::endl;
  NumericVector rho  = RcppDeepState_NumericVector();
  qs::c_qsave(rho,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/pbivnorm_drezner/inputs/rho.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rho values: "<< rho << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    pbivnorm_drezner(a,b,rho);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
