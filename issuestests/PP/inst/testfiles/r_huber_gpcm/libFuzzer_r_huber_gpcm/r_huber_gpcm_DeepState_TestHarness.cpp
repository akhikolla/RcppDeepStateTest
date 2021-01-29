#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double r_huber_gpcm(NumericVector delta, double alpha, double theta, double H);

TEST(PP_deepstate_test,r_huber_gpcm_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector delta  = RcppDeepState_NumericVector();
  std::string delta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/r_huber_gpcm/libFuzzer_r_huber_gpcm/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_delta.qs";
  qs::c_qsave(delta,delta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta values: "<< delta << std::endl;
  NumericVector alpha(1);
  alpha[0]  = RcppDeepState_double();
  std::string alpha_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/r_huber_gpcm/libFuzzer_r_huber_gpcm/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_alpha.qs";
  qs::c_qsave(alpha,alpha_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  NumericVector theta(1);
  theta[0]  = RcppDeepState_double();
  std::string theta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/r_huber_gpcm/libFuzzer_r_huber_gpcm/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_theta.qs";
  qs::c_qsave(theta,theta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta values: "<< theta << std::endl;
  NumericVector H(1);
  H[0]  = RcppDeepState_double();
  std::string H_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/r_huber_gpcm/libFuzzer_r_huber_gpcm/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_H.qs";
  qs::c_qsave(H,H_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "H values: "<< H << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    r_huber_gpcm(delta,alpha[0],theta[0],H[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
