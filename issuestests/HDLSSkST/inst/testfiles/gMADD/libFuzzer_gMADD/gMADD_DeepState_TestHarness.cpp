#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

/*-----Modified K-means clustering algorithm with known cluster number based on MADD------*/ Rcpp::NumericVector gMADD(int s_fn, int n_clust, int lb, Rcpp::NumericMatrix M);

TEST(HDLSSkST_deepstate_test,gMADD_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector s_fn(1);
  s_fn[0]  = RcppDeepState_int();
  std::string s_fn_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/HDLSSkST/inst/testfiles/gMADD/libFuzzer_gMADD/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_s_fn.qs";
  qs::c_qsave(s_fn,s_fn_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "s_fn values: "<< s_fn << std::endl;
  IntegerVector n_clust(1);
  n_clust[0]  = RcppDeepState_int();
  std::string n_clust_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/HDLSSkST/inst/testfiles/gMADD/libFuzzer_gMADD/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_n_clust.qs";
  qs::c_qsave(n_clust,n_clust_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_clust values: "<< n_clust << std::endl;
  IntegerVector lb(1);
  lb[0]  = RcppDeepState_int();
  std::string lb_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/HDLSSkST/inst/testfiles/gMADD/libFuzzer_gMADD/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lb.qs";
  qs::c_qsave(lb,lb_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lb values: "<< lb << std::endl;
  NumericMatrix M  = RcppDeepState_NumericMatrix();
  std::string M_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/HDLSSkST/inst/testfiles/gMADD/libFuzzer_gMADD/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_M.qs";
  qs::c_qsave(M,M_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "M values: "<< M << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    gMADD(s_fn[0],n_clust[0],lb[0],M);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
