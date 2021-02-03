#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List countPairs(IntegerVector classi1, IntegerVector classi2, IntegerVector order);

TEST(aricode_deepstate_test,countPairs_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector classi1  = RcppDeepState_IntegerVector();
  std::string classi1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aricode/inst/testfiles/countPairs/AFL_countPairs/afl_inputs/" + std::to_string(t) + "_classi1.qs";
  qs::c_qsave(classi1,classi1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "classi1 values: "<< classi1 << std::endl;
  IntegerVector classi2  = RcppDeepState_IntegerVector();
  std::string classi2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aricode/inst/testfiles/countPairs/AFL_countPairs/afl_inputs/" + std::to_string(t) + "_classi2.qs";
  qs::c_qsave(classi2,classi2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "classi2 values: "<< classi2 << std::endl;
  IntegerVector order  = RcppDeepState_IntegerVector();
  std::string order_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aricode/inst/testfiles/countPairs/AFL_countPairs/afl_inputs/" + std::to_string(t) + "_order.qs";
  qs::c_qsave(order,order_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "order values: "<< order << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    countPairs(classi1,classi2,order);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
