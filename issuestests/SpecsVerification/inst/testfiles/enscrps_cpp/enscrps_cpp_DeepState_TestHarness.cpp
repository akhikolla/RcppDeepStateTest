#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector enscrps_cpp(NumericMatrix ens, NumericVector obs, double R_new);

TEST(SpecsVerification_deepstate_test,enscrps_cpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix ens  = RcppDeepState_NumericMatrix();
  qs::c_qsave(ens,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpecsVerification/inst/testfiles/enscrps_cpp/inputs/ens.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ens values: "<< ens << std::endl;
  NumericVector obs  = RcppDeepState_NumericVector();
  qs::c_qsave(obs,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpecsVerification/inst/testfiles/enscrps_cpp/inputs/obs.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "obs values: "<< obs << std::endl;
  NumericVector R_new(1);
  R_new[0]  = RcppDeepState_double();
  qs::c_qsave(R_new,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpecsVerification/inst/testfiles/enscrps_cpp/inputs/R_new.qs",
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
