#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix UpPhetpartial(NumericMatrix p, NumericMatrix ref_order, NumericMatrix pi_inv, NumericMatrix u_bin, NumericMatrix z_hat, NumericMatrix shape0, NumericVector rate0, IntegerVector n_rank);

TEST(PLMIX_deepstate_test,UpPhetpartial_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix p  = RcppDeepState_NumericMatrix();
  std::string p_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/UpPhetpartial/libFuzzer_UpPhetpartial/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_p.qs";
  qs::c_qsave(p,p_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "p values: "<< p << std::endl;
  NumericMatrix ref_order  = RcppDeepState_NumericMatrix();
  std::string ref_order_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/UpPhetpartial/libFuzzer_UpPhetpartial/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ref_order.qs";
  qs::c_qsave(ref_order,ref_order_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ref_order values: "<< ref_order << std::endl;
  NumericMatrix pi_inv  = RcppDeepState_NumericMatrix();
  std::string p_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/UpPhetpartial/libFuzzer_UpPhetpartial/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_p.qs";
  std::string pi_inv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/UpPhetpartial/libFuzzer_UpPhetpartial/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_pi_inv.qs";
  qs::c_qsave(pi_inv,pi_inv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pi_inv values: "<< pi_inv << std::endl;
  NumericMatrix u_bin  = RcppDeepState_NumericMatrix();
  std::string u_bin_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/UpPhetpartial/libFuzzer_UpPhetpartial/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_u_bin.qs";
  qs::c_qsave(u_bin,u_bin_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "u_bin values: "<< u_bin << std::endl;
  NumericMatrix z_hat  = RcppDeepState_NumericMatrix();
  std::string z_hat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/UpPhetpartial/libFuzzer_UpPhetpartial/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_z_hat.qs";
  qs::c_qsave(z_hat,z_hat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z_hat values: "<< z_hat << std::endl;
  NumericMatrix shape0  = RcppDeepState_NumericMatrix();
  std::string shape0_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/UpPhetpartial/libFuzzer_UpPhetpartial/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_shape0.qs";
  qs::c_qsave(shape0,shape0_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "shape0 values: "<< shape0 << std::endl;
  NumericVector rate0  = RcppDeepState_NumericVector();
  std::string rate0_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/UpPhetpartial/libFuzzer_UpPhetpartial/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_rate0.qs";
  qs::c_qsave(rate0,rate0_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rate0 values: "<< rate0 << std::endl;
  IntegerVector n_rank  = RcppDeepState_IntegerVector();
  std::string n_rank_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/UpPhetpartial/libFuzzer_UpPhetpartial/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_n_rank.qs";
  qs::c_qsave(n_rank,n_rank_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_rank values: "<< n_rank << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    UpPhetpartial(p,ref_order,pi_inv,u_bin,z_hat,shape0,rate0,n_rank);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
