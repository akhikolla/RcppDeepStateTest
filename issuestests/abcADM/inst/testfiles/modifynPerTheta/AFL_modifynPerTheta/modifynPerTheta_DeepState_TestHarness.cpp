#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

void modifynPerTheta(const int newnPerTheta, const int verbose);

TEST(abcADM_deepstate_test,modifynPerTheta_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector newnPerTheta(1);
  newnPerTheta[0]  = RcppDeepState_int();
  std::string newnPerTheta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/abcADM/inst/testfiles/modifynPerTheta/AFL_modifynPerTheta/afl_inputs/" + std::to_string(t) + "_newnPerTheta.qs";
  qs::c_qsave(newnPerTheta,newnPerTheta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "newnPerTheta values: "<< newnPerTheta << std::endl;
  IntegerVector verbose(1);
  verbose[0]  = RcppDeepState_int();
  std::string verbose_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/abcADM/inst/testfiles/modifynPerTheta/AFL_modifynPerTheta/afl_inputs/" + std::to_string(t) + "_verbose.qs";
  qs::c_qsave(verbose,verbose_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "verbose values: "<< verbose << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    modifynPerTheta(newnPerTheta[0],verbose[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
