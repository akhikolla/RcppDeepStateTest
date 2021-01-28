#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector DoBlock(const NumericVector weight, const NumericVector response, const double gamma, const double lambda);

TEST(CatReg_deepstate_test,DoBlock_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector weight  = RcppDeepState_NumericVector();
  std::string weight_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CatReg/inst/testfiles/DoBlock/libFuzzer_DoBlock/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_weight.qs";
  qs::c_qsave(weight,weight_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "weight values: "<< weight << std::endl;
  NumericVector response  = RcppDeepState_NumericVector();
  std::string response_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CatReg/inst/testfiles/DoBlock/libFuzzer_DoBlock/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_response.qs";
  qs::c_qsave(response,response_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "response values: "<< response << std::endl;
  NumericVector gamma(1);
  gamma[0]  = RcppDeepState_double();
  std::string gamma_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CatReg/inst/testfiles/DoBlock/libFuzzer_DoBlock/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_gamma.qs";
  qs::c_qsave(gamma,gamma_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "gamma values: "<< gamma << std::endl;
  NumericVector lambda(1);
  lambda[0]  = RcppDeepState_double();
  std::string lambda_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CatReg/inst/testfiles/DoBlock/libFuzzer_DoBlock/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lambda.qs";
  qs::c_qsave(lambda,lambda_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lambda values: "<< lambda << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    DoBlock(weight,response,gamma[0],lambda[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
