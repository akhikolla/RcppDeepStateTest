#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List getRank(IntegerVector classi);

TEST(aricode_deepstate_test,getRank_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector classi  = RcppDeepState_IntegerVector();
  std::string classi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aricode/inst/testfiles/getRank/AFL_getRank/afl_inputs/" + std::to_string(t) + "_classi.qs";
  qs::c_qsave(classi,classi_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "classi values: "<< classi << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    getRank(classi);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
