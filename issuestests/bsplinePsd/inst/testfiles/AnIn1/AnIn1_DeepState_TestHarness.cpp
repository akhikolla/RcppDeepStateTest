#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double AnIn1(NumericVector knot);

TEST(bsplinePsd_deepstate_test,AnIn1_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector knot  = RcppDeepState_NumericVector();
  qs::c_qsave(knot,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/bsplinePsd/inst/testfiles/AnIn1/inputs/knot.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "knot values: "<< knot << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    AnIn1(knot);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
