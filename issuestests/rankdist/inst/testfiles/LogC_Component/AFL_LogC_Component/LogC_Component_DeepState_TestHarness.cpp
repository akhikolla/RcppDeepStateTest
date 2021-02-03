#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double LogC_Component(NumericVector fai);

TEST(rankdist_deepstate_test,LogC_Component_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector fai  = RcppDeepState_NumericVector();
  std::string fai_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rankdist/inst/testfiles/LogC_Component/AFL_LogC_Component/afl_inputs/" + std::to_string(t) + "_fai.qs";
  qs::c_qsave(fai,fai_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fai values: "<< fai << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    LogC_Component(fai);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
