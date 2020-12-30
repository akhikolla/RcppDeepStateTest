#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector DoBlock(const NumericVector weight, const NumericVector response, const double gamma, const double lambda);

TEST(CatReg_deepstate_test,DoBlock_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector weight  = RcppDeepState_NumericVector();
  qs::c_qsave(weight,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CatReg/inst/testfiles/DoBlock/inputs/weight.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "weight values: "<< weight << std::endl;
  NumericVector response  = RcppDeepState_NumericVector();
  qs::c_qsave(response,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CatReg/inst/testfiles/DoBlock/inputs/response.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "response values: "<< response << std::endl;
  NumericVector gamma(1);
  gamma[0]  = RcppDeepState_double();
  qs::c_qsave(gamma,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CatReg/inst/testfiles/DoBlock/inputs/gamma.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "gamma values: "<< gamma << std::endl;
  NumericVector lambda(1);
  lambda[0]  = RcppDeepState_double();
  qs::c_qsave(lambda,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CatReg/inst/testfiles/DoBlock/inputs/lambda.qs",
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
