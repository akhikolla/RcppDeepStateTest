#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double AnIn2(NumericVector knot);

TEST(bsplinePsd_deepstate_test,AnIn2_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector knot  = RcppDeepState_NumericVector();
  std::string knot_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/bsplinePsd/inst/testfiles/AnIn2/AFL_AnIn2/afl_inputs/" + std::to_string(t) + "_knot.qs";
  qs::c_qsave(knot,knot_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "knot values: "<< knot << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    AnIn2(knot);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
