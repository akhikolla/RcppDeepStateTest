#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List maxcpp(NumericVector tau, int x, int y, int j);

TEST(timma_deepstate_test,maxcpp_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector tau  = RcppDeepState_NumericVector();
  std::string tau_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/timma/inst/testfiles/maxcpp/libFuzzer_maxcpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_tau.qs";
  qs::c_qsave(tau,tau_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tau values: "<< tau << std::endl;
  IntegerVector x(1);
  x[0]  = RcppDeepState_int();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/timma/inst/testfiles/maxcpp/libFuzzer_maxcpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector y(1);
  y[0]  = RcppDeepState_int();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/timma/inst/testfiles/maxcpp/libFuzzer_maxcpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  IntegerVector j(1);
  j[0]  = RcppDeepState_int();
  std::string j_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/timma/inst/testfiles/maxcpp/libFuzzer_maxcpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_j.qs";
  qs::c_qsave(j,j_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "j values: "<< j << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    maxcpp(tau,x[0],y[0],j[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
