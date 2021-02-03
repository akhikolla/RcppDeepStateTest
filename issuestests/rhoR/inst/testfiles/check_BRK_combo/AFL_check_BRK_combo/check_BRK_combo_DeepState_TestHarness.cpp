#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

bool check_BRK_combo(double BR, double P, double K);

TEST(rhoR_deepstate_test,check_BRK_combo_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector BR(1);
  BR[0]  = RcppDeepState_double();
  std::string BR_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/check_BRK_combo/AFL_check_BRK_combo/afl_inputs/" + std::to_string(t) + "_BR.qs";
  qs::c_qsave(BR,BR_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "BR values: "<< BR << std::endl;
  NumericVector P(1);
  P[0]  = RcppDeepState_double();
  std::string P_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/check_BRK_combo/AFL_check_BRK_combo/afl_inputs/" + std::to_string(t) + "_P.qs";
  qs::c_qsave(P,P_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "P values: "<< P << std::endl;
  NumericVector K(1);
  K[0]  = RcppDeepState_double();
  std::string K_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/check_BRK_combo/AFL_check_BRK_combo/afl_inputs/" + std::to_string(t) + "_K.qs";
  qs::c_qsave(K,K_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "K values: "<< K << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    check_BRK_combo(BR[0],P[0],K[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
