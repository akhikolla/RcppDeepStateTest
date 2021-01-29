#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix CompRateYpartial(NumericMatrix p, NumericMatrix pi_inv, NumericVector ref_order, NumericMatrix z, NumericVector n_rank);

TEST(PLMIX_deepstate_test,CompRateYpartial_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix p  = RcppDeepState_NumericMatrix();
  std::string p_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/CompRateYpartial/libFuzzer_CompRateYpartial/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_p.qs";
  qs::c_qsave(p,p_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "p values: "<< p << std::endl;
  NumericMatrix pi_inv  = RcppDeepState_NumericMatrix();
  std::string p_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/CompRateYpartial/libFuzzer_CompRateYpartial/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_p.qs";
  std::string pi_inv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/CompRateYpartial/libFuzzer_CompRateYpartial/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_pi_inv.qs";
  qs::c_qsave(pi_inv,pi_inv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pi_inv values: "<< pi_inv << std::endl;
  NumericVector ref_order  = RcppDeepState_NumericVector();
  std::string ref_order_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/CompRateYpartial/libFuzzer_CompRateYpartial/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ref_order.qs";
  qs::c_qsave(ref_order,ref_order_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ref_order values: "<< ref_order << std::endl;
  NumericMatrix z  = RcppDeepState_NumericMatrix();
  std::string z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/CompRateYpartial/libFuzzer_CompRateYpartial/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_z.qs";
  qs::c_qsave(z,z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  NumericVector n_rank  = RcppDeepState_NumericVector();
  std::string n_rank_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PLMIX/inst/testfiles/CompRateYpartial/libFuzzer_CompRateYpartial/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_n_rank.qs";
  qs::c_qsave(n_rank,n_rank_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_rank values: "<< n_rank << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    CompRateYpartial(p,pi_inv,ref_order,z,n_rank);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
