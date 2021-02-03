#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector sSAC1_C(NumericVector x, NumericVector y, IntegerVector id_spec);

TEST(mobsim_deepstate_test,sSAC1_C_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mobsim/inst/testfiles/sSAC1_C/AFL_sSAC1_C/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mobsim/inst/testfiles/sSAC1_C/AFL_sSAC1_C/afl_inputs/" + std::to_string(t) + "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  IntegerVector id_spec  = RcppDeepState_IntegerVector();
  std::string id_spec_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mobsim/inst/testfiles/sSAC1_C/AFL_sSAC1_C/afl_inputs/" + std::to_string(t) + "_id_spec.qs";
  qs::c_qsave(id_spec,id_spec_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "id_spec values: "<< id_spec << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    sSAC1_C(x,y,id_spec);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
