#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix twostep_grm_cpp(NumericMatrix genotype, NumericVector freq, NumericMatrix est0);

TEST(rres_deepstate_test,twostep_grm_cpp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix genotype  = RcppDeepState_NumericMatrix();
  std::string genotype_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rres/inst/testfiles/twostep_grm_cpp/AFL_twostep_grm_cpp/afl_inputs/" + std::to_string(t) + "_genotype.qs";
  qs::c_qsave(genotype,genotype_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "genotype values: "<< genotype << std::endl;
  NumericVector freq  = RcppDeepState_NumericVector();
  std::string freq_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rres/inst/testfiles/twostep_grm_cpp/AFL_twostep_grm_cpp/afl_inputs/" + std::to_string(t) + "_freq.qs";
  qs::c_qsave(freq,freq_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "freq values: "<< freq << std::endl;
  NumericMatrix est0  = RcppDeepState_NumericMatrix();
  std::string est0_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rres/inst/testfiles/twostep_grm_cpp/AFL_twostep_grm_cpp/afl_inputs/" + std::to_string(t) + "_est0.qs";
  qs::c_qsave(est0,est0_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "est0 values: "<< est0 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    twostep_grm_cpp(genotype,freq,est0);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
