#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector bilinear(NumericVector x_breaks, NumericVector y_breaks, NumericMatrix grid, NumericVector x, NumericVector y);

TEST(particles_deepstate_test,bilinear_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x_breaks  = RcppDeepState_NumericVector();
  std::string x_breaks_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/bilinear/libFuzzer_bilinear/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x_breaks.qs";
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/bilinear/libFuzzer_bilinear/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x_breaks,x_breaks_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x_breaks values: "<< x_breaks << std::endl;
  NumericVector y_breaks  = RcppDeepState_NumericVector();
  std::string y_breaks_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/bilinear/libFuzzer_bilinear/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y_breaks.qs";
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/bilinear/libFuzzer_bilinear/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y_breaks,y_breaks_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y_breaks values: "<< y_breaks << std::endl;
  NumericMatrix grid  = RcppDeepState_NumericMatrix();
  std::string grid_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/bilinear/libFuzzer_bilinear/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_grid.qs";
  qs::c_qsave(grid,grid_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "grid values: "<< grid << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/bilinear/libFuzzer_bilinear/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/bilinear/libFuzzer_bilinear/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    bilinear(x_breaks,y_breaks,grid,x,y);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
