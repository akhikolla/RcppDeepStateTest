#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector llrandtruncpoiscpp(NumericVector y, NumericVector lp, NumericVector tau2, NumericMatrix gh);

TEST(robmixglm_deepstate_test,llrandtruncpoiscpp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/robmixglm/inst/testfiles/llrandtruncpoiscpp/AFL_llrandtruncpoiscpp/afl_inputs/" + std::to_string(t) + "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector lp  = RcppDeepState_NumericVector();
  std::string lp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/robmixglm/inst/testfiles/llrandtruncpoiscpp/AFL_llrandtruncpoiscpp/afl_inputs/" + std::to_string(t) + "_lp.qs";
  qs::c_qsave(lp,lp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lp values: "<< lp << std::endl;
  NumericVector tau2  = RcppDeepState_NumericVector();
  std::string tau2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/robmixglm/inst/testfiles/llrandtruncpoiscpp/AFL_llrandtruncpoiscpp/afl_inputs/" + std::to_string(t) + "_tau2.qs";
  qs::c_qsave(tau2,tau2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tau2 values: "<< tau2 << std::endl;
  NumericMatrix gh  = RcppDeepState_NumericMatrix();
  std::string gh_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/robmixglm/inst/testfiles/llrandtruncpoiscpp/AFL_llrandtruncpoiscpp/afl_inputs/" + std::to_string(t) + "_gh.qs";
  qs::c_qsave(gh,gh_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "gh values: "<< gh << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    llrandtruncpoiscpp(y,lp,tau2,gh);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
