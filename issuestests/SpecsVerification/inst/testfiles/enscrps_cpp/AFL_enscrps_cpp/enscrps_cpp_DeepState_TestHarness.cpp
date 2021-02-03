#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector enscrps_cpp(NumericMatrix ens, NumericVector obs, double R_new);

TEST(SpecsVerification_deepstate_test,enscrps_cpp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix ens  = RcppDeepState_NumericMatrix();
  std::string ens_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpecsVerification/inst/testfiles/enscrps_cpp/AFL_enscrps_cpp/afl_inputs/" + std::to_string(t) + "_ens.qs";
  qs::c_qsave(ens,ens_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ens values: "<< ens << std::endl;
  NumericVector obs  = RcppDeepState_NumericVector();
  std::string obs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpecsVerification/inst/testfiles/enscrps_cpp/AFL_enscrps_cpp/afl_inputs/" + std::to_string(t) + "_obs.qs";
  qs::c_qsave(obs,obs_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "obs values: "<< obs << std::endl;
  NumericVector R_new(1);
  R_new[0]  = RcppDeepState_double();
  std::string R_new_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpecsVerification/inst/testfiles/enscrps_cpp/AFL_enscrps_cpp/afl_inputs/" + std::to_string(t) + "_R_new.qs";
  qs::c_qsave(R_new,R_new_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "R_new values: "<< R_new << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    enscrps_cpp(ens,obs,R_new[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
