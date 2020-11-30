#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector gradlik_pw(NumericVector par, NumericMatrix Dm, NumericVector eta, IntegerVector breaks);

TEST(icensmis_deepstate_test,gradlik_pw_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector par  = RcppDeepState_NumericVector();
  qs::c_qsave(par,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/gradlik_pw/inputs/par.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "par values: "<< par << std::endl;
  NumericMatrix Dm  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Dm,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/gradlik_pw/inputs/Dm.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Dm values: "<< Dm << std::endl;
  NumericVector eta  = RcppDeepState_NumericVector();
  qs::c_qsave(eta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/gradlik_pw/inputs/eta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eta values: "<< eta << std::endl;
  IntegerVector breaks  = RcppDeepState_IntegerVector();
  qs::c_qsave(breaks,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/gradlik_pw/inputs/breaks.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "breaks values: "<< breaks << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    gradlik_pw(par,Dm,eta,breaks);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
