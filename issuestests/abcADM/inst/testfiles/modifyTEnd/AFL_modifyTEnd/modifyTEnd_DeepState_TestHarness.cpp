#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

void modifyTEnd(const double newEndT, const int verbose);

TEST(abcADM_deepstate_test,modifyTEnd_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector newEndT(1);
  newEndT[0]  = RcppDeepState_double();
  std::string newEndT_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/abcADM/inst/testfiles/modifyTEnd/AFL_modifyTEnd/afl_inputs/" + std::to_string(t) + "_newEndT.qs";
  qs::c_qsave(newEndT,newEndT_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "newEndT values: "<< newEndT << std::endl;
  IntegerVector verbose(1);
  verbose[0]  = RcppDeepState_int();
  std::string verbose_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/abcADM/inst/testfiles/modifyTEnd/AFL_modifyTEnd/afl_inputs/" + std::to_string(t) + "_verbose.qs";
  qs::c_qsave(verbose,verbose_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "verbose values: "<< verbose << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    modifyTEnd(newEndT[0],verbose[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
