#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix CompProbZpartial(NumericMatrix p, NumericMatrix pi_inv, NumericMatrix Y, NumericMatrix u_bin, IntegerVector n_rank, NumericVector omega);

TEST(PLMIX_deepstate_test,CompProbZpartial_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix p  = RcppDeepState_NumericMatrix();
  std::string p_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/CompProbZpartial/libFuzzer_CompProbZpartial/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_p.qs";
  qs::c_qsave(p,p_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "p values: "<< p << std::endl;
  NumericMatrix pi_inv  = RcppDeepState_NumericMatrix();
  std::string p_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/CompProbZpartial/libFuzzer_CompProbZpartial/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_p.qs";
  std::string pi_inv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/CompProbZpartial/libFuzzer_CompProbZpartial/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_pi_inv.qs";
  qs::c_qsave(pi_inv,pi_inv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pi_inv values: "<< pi_inv << std::endl;
  NumericMatrix Y  = RcppDeepState_NumericMatrix();
  std::string Y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/CompProbZpartial/libFuzzer_CompProbZpartial/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Y.qs";
  qs::c_qsave(Y,Y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Y values: "<< Y << std::endl;
  NumericMatrix u_bin  = RcppDeepState_NumericMatrix();
  std::string u_bin_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/CompProbZpartial/libFuzzer_CompProbZpartial/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_u_bin.qs";
  qs::c_qsave(u_bin,u_bin_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "u_bin values: "<< u_bin << std::endl;
  IntegerVector n_rank  = RcppDeepState_IntegerVector();
  std::string n_rank_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/CompProbZpartial/libFuzzer_CompProbZpartial/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_n_rank.qs";
  qs::c_qsave(n_rank,n_rank_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_rank values: "<< n_rank << std::endl;
  NumericVector omega  = RcppDeepState_NumericVector();
  std::string omega_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/CompProbZpartial/libFuzzer_CompProbZpartial/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_omega.qs";
  qs::c_qsave(omega,omega_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "omega values: "<< omega << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    CompProbZpartial(p,pi_inv,Y,u_bin,n_rank,omega);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
