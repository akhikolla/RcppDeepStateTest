#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double AnIn1(NumericVector knot);

TEST(bsplinePsd_deepstate_test,AnIn1_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector knot  = RcppDeepState_NumericVector();
  std::string knot_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/bsplinePsd/inst/testfiles/AnIn1/libFuzzer_AnIn1/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_knot.qs";
  qs::c_qsave(knot,knot_t,
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
