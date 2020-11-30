#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector gamma_mean(IntegerVector outgamma, int start);

TEST(icensmis_deepstate_test,gamma_mean_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector outgamma  = RcppDeepState_IntegerVector();
  qs::c_qsave(outgamma,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/gamma_mean/inputs/outgamma.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "outgamma values: "<< outgamma << std::endl;
  IntegerVector start(1);
  start[0]  = RcppDeepState_int();
  qs::c_qsave(start,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/gamma_mean/inputs/start.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "start values: "<< start << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    gamma_mean(outgamma,start[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
