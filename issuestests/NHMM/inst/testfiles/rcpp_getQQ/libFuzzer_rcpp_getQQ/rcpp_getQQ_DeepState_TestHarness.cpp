#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector rcpp_getQQ(int K, Rcpp::NumericVector z, Rcpp::NumericMatrix dirprior, Rcpp::NumericVector subseqy);

TEST(NHMM_deepstate_test,rcpp_getQQ_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector K(1);
  K[0]  = RcppDeepState_int();
  std::string K_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getQQ/libFuzzer_rcpp_getQQ/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_K.qs";
  qs::c_qsave(K,K_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "K values: "<< K << std::endl;
  NumericVector z  = RcppDeepState_NumericVector();
  std::string z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getQQ/libFuzzer_rcpp_getQQ/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_z.qs";
  qs::c_qsave(z,z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  NumericMatrix dirprior  = RcppDeepState_NumericMatrix();
  std::string dirprior_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getQQ/libFuzzer_rcpp_getQQ/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_dirprior.qs";
  qs::c_qsave(dirprior,dirprior_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dirprior values: "<< dirprior << std::endl;
  NumericVector subseqy  = RcppDeepState_NumericVector();
  std::string subseqy_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NHMM/inst/testfiles/rcpp_getQQ/libFuzzer_rcpp_getQQ/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_subseqy.qs";
  qs::c_qsave(subseqy,subseqy_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "subseqy values: "<< subseqy << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rcpp_getQQ(K[0],z,dirprior,subseqy);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
