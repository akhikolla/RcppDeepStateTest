#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix spatialize4d(NumericVector x, NumericVector y, NumericVector z1, NumericVector z2, int npts);

TEST(mousetrap_deepstate_test,spatialize4d_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/spatialize4d/libFuzzer_spatialize4d/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/spatialize4d/libFuzzer_spatialize4d/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector z1  = RcppDeepState_NumericVector();
  std::string z1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/spatialize4d/libFuzzer_spatialize4d/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_z1.qs";
  qs::c_qsave(z1,z1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z1 values: "<< z1 << std::endl;
  NumericVector z2  = RcppDeepState_NumericVector();
  std::string z2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/spatialize4d/libFuzzer_spatialize4d/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_z2.qs";
  qs::c_qsave(z2,z2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z2 values: "<< z2 << std::endl;
  IntegerVector npts(1);
  npts[0]  = RcppDeepState_int();
  std::string npts_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/spatialize4d/libFuzzer_spatialize4d/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_npts.qs";
  qs::c_qsave(npts,npts_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "npts values: "<< npts << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    spatialize4d(x,y,z1,z2,npts[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
