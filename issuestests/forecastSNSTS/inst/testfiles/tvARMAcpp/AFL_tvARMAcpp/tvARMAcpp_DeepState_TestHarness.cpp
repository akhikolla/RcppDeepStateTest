#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector tvARMAcpp(NumericVector z, NumericVector x_init, NumericMatrix A, NumericMatrix B, NumericVector Sigma);

TEST(forecastSNSTS_deepstate_test,tvARMAcpp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector z  = RcppDeepState_NumericVector();
  std::string z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/tvARMAcpp/AFL_tvARMAcpp/afl_inputs/" + std::to_string(t) + "_z.qs";
  qs::c_qsave(z,z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  NumericVector x_init  = RcppDeepState_NumericVector();
  std::string x_init_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/tvARMAcpp/AFL_tvARMAcpp/afl_inputs/" + std::to_string(t) + "_x_init.qs";
  qs::c_qsave(x_init,x_init_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x_init values: "<< x_init << std::endl;
  NumericMatrix A  = RcppDeepState_NumericMatrix();
  std::string A_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/tvARMAcpp/AFL_tvARMAcpp/afl_inputs/" + std::to_string(t) + "_A.qs";
  qs::c_qsave(A,A_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "A values: "<< A << std::endl;
  NumericMatrix B  = RcppDeepState_NumericMatrix();
  std::string B_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/tvARMAcpp/AFL_tvARMAcpp/afl_inputs/" + std::to_string(t) + "_B.qs";
  qs::c_qsave(B,B_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "B values: "<< B << std::endl;
  NumericVector Sigma  = RcppDeepState_NumericVector();
  std::string Sigma_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/tvARMAcpp/AFL_tvARMAcpp/afl_inputs/" + std::to_string(t) + "_Sigma.qs";
  qs::c_qsave(Sigma,Sigma_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Sigma values: "<< Sigma << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    tvARMAcpp(z,x_init,A,B,Sigma);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
