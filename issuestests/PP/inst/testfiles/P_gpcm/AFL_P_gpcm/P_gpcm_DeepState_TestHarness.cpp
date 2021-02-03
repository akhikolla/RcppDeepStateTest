#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double P_gpcm(NumericVector delta, double alpha, double theta, int resp);

TEST(PP_deepstate_test,P_gpcm_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector delta  = RcppDeepState_NumericVector();
  std::string delta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/P_gpcm/AFL_P_gpcm/afl_inputs/" + std::to_string(t) + "_delta.qs";
  qs::c_qsave(delta,delta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta values: "<< delta << std::endl;
  NumericVector alpha(1);
  alpha[0]  = RcppDeepState_double();
  std::string alpha_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/P_gpcm/AFL_P_gpcm/afl_inputs/" + std::to_string(t) + "_alpha.qs";
  qs::c_qsave(alpha,alpha_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  NumericVector theta(1);
  theta[0]  = RcppDeepState_double();
  std::string theta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/P_gpcm/AFL_P_gpcm/afl_inputs/" + std::to_string(t) + "_theta.qs";
  qs::c_qsave(theta,theta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta values: "<< theta << std::endl;
  IntegerVector resp(1);
  resp[0]  = RcppDeepState_int();
  std::string resp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/P_gpcm/AFL_P_gpcm/afl_inputs/" + std::to_string(t) + "_resp.qs";
  qs::c_qsave(resp,resp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "resp values: "<< resp << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    P_gpcm(delta,alpha[0],theta[0],resp[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
