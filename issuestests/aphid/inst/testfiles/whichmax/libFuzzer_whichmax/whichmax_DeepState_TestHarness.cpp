#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

int whichmax(NumericVector x, int start);

TEST(aphid_deepstate_test,whichmax_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/whichmax/libFuzzer_whichmax/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector start(1);
  start[0]  = RcppDeepState_int();
  std::string start_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/whichmax/libFuzzer_whichmax/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_start.qs";
  qs::c_qsave(start,start_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "start values: "<< start << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    whichmax(x,start[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
