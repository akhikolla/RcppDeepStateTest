#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

std::vector<double> computeNorm(double r);

TEST(mousetrap_deepstate_test,computeNorm_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector r(1);
  r[0]  = RcppDeepState_double();
  qs::c_qsave(r,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/computeNorm/inputs/r.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "r values: "<< r << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    computeNorm(r[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
