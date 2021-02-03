#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector gradlik_lamb(NumericVector par, NumericMatrix Dm, NumericVector eta);

TEST(icensmis_deepstate_test,gradlik_lamb_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector par  = RcppDeepState_NumericVector();
  std::string par_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/gradlik_lamb/AFL_gradlik_lamb/afl_inputs/" + std::to_string(t) + "_par.qs";
  qs::c_qsave(par,par_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "par values: "<< par << std::endl;
  NumericMatrix Dm  = RcppDeepState_NumericMatrix();
  std::string Dm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/gradlik_lamb/AFL_gradlik_lamb/afl_inputs/" + std::to_string(t) + "_Dm.qs";
  qs::c_qsave(Dm,Dm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Dm values: "<< Dm << std::endl;
  NumericVector eta  = RcppDeepState_NumericVector();
  std::string eta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icensmis/inst/testfiles/gradlik_lamb/AFL_gradlik_lamb/afl_inputs/" + std::to_string(t) + "_eta.qs";
  qs::c_qsave(eta,eta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eta values: "<< eta << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    gradlik_lamb(par,Dm,eta);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
