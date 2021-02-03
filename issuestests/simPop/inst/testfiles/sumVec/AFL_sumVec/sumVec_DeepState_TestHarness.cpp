#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector sumVec(IntegerVector init_weight, int sizefactor);

TEST(simPop_deepstate_test,sumVec_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector init_weight  = RcppDeepState_IntegerVector();
  std::string init_weight_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/sumVec/AFL_sumVec/afl_inputs/" + std::to_string(t) + "_init_weight.qs";
  qs::c_qsave(init_weight,init_weight_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "init_weight values: "<< init_weight << std::endl;
  IntegerVector sizefactor(1);
  sizefactor[0]  = RcppDeepState_int();
  std::string sizefactor_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/sumVec/AFL_sumVec/afl_inputs/" + std::to_string(t) + "_sizefactor.qs";
  qs::c_qsave(sizefactor,sizefactor_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sizefactor values: "<< sizefactor << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    sumVec(init_weight,sizefactor[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
