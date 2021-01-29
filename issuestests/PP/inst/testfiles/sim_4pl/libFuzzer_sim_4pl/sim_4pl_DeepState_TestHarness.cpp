#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerMatrix sim_4pl(NumericVector beta, NumericVector alpha, NumericVector lowerA, NumericVector upperA, NumericVector theta);

TEST(PP_deepstate_test,sim_4pl_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector beta  = RcppDeepState_NumericVector();
  std::string beta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/sim_4pl/libFuzzer_sim_4pl/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_beta.qs";
  qs::c_qsave(beta,beta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "beta values: "<< beta << std::endl;
  NumericVector alpha  = RcppDeepState_NumericVector();
  std::string alpha_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/sim_4pl/libFuzzer_sim_4pl/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_alpha.qs";
  qs::c_qsave(alpha,alpha_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  NumericVector lowerA  = RcppDeepState_NumericVector();
  std::string lowerA_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/sim_4pl/libFuzzer_sim_4pl/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lowerA.qs";
  qs::c_qsave(lowerA,lowerA_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lowerA values: "<< lowerA << std::endl;
  NumericVector upperA  = RcppDeepState_NumericVector();
  std::string upperA_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/sim_4pl/libFuzzer_sim_4pl/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_upperA.qs";
  qs::c_qsave(upperA,upperA_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "upperA values: "<< upperA << std::endl;
  NumericVector theta  = RcppDeepState_NumericVector();
  std::string theta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/sim_4pl/libFuzzer_sim_4pl/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_theta.qs";
  qs::c_qsave(theta,theta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta values: "<< theta << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    sim_4pl(beta,alpha,lowerA,upperA,theta);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
