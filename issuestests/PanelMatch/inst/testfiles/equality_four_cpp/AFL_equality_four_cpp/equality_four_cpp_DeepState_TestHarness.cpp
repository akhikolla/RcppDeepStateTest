#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector equality_four_cpp(Rcpp::NumericMatrix Wit_vals, Rcpp::NumericVector y, Rcpp::NumericVector z);

TEST(PanelMatch_deepstate_test,equality_four_cpp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix Wit_vals  = RcppDeepState_NumericMatrix();
  std::string Wit_vals_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/equality_four_cpp/AFL_equality_four_cpp/afl_inputs/" + std::to_string(t) + "_Wit_vals.qs";
  qs::c_qsave(Wit_vals,Wit_vals_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Wit_vals values: "<< Wit_vals << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/equality_four_cpp/AFL_equality_four_cpp/afl_inputs/" + std::to_string(t) + "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector z  = RcppDeepState_NumericVector();
  std::string z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/equality_four_cpp/AFL_equality_four_cpp/afl_inputs/" + std::to_string(t) + "_z.qs";
  qs::c_qsave(z,z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    equality_four_cpp(Wit_vals,y,z);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
