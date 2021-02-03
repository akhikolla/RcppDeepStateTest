#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix CompRateP(NumericMatrix pi_inv, NumericMatrix Y, NumericMatrix z, NumericMatrix u_bin, IntegerVector n_rank, NumericVector rate0);

TEST(PLMIX_deepstate_test,CompRateP_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix pi_inv  = RcppDeepState_NumericMatrix();
  std::string pi_inv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/CompRateP/AFL_CompRateP/afl_inputs/" + std::to_string(t) + "_pi_inv.qs";
  qs::c_qsave(pi_inv,pi_inv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pi_inv values: "<< pi_inv << std::endl;
  NumericMatrix Y  = RcppDeepState_NumericMatrix();
  std::string Y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/CompRateP/AFL_CompRateP/afl_inputs/" + std::to_string(t) + "_Y.qs";
  qs::c_qsave(Y,Y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Y values: "<< Y << std::endl;
  NumericMatrix z  = RcppDeepState_NumericMatrix();
  std::string z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/CompRateP/AFL_CompRateP/afl_inputs/" + std::to_string(t) + "_z.qs";
  qs::c_qsave(z,z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  NumericMatrix u_bin  = RcppDeepState_NumericMatrix();
  std::string u_bin_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/CompRateP/AFL_CompRateP/afl_inputs/" + std::to_string(t) + "_u_bin.qs";
  qs::c_qsave(u_bin,u_bin_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "u_bin values: "<< u_bin << std::endl;
  IntegerVector n_rank  = RcppDeepState_IntegerVector();
  std::string n_rank_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/CompRateP/AFL_CompRateP/afl_inputs/" + std::to_string(t) + "_n_rank.qs";
  qs::c_qsave(n_rank,n_rank_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_rank values: "<< n_rank << std::endl;
  NumericVector rate0  = RcppDeepState_NumericVector();
  std::string rate0_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/CompRateP/AFL_CompRateP/afl_inputs/" + std::to_string(t) + "_rate0.qs";
  qs::c_qsave(rate0,rate0_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rate0 values: "<< rate0 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    CompRateP(pi_inv,Y,z,u_bin,n_rank,rate0);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
