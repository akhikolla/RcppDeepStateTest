#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector subimmer_probs_gpcm_rcpp(Rcpp::NumericVector x, Rcpp::NumericVector theta, Rcpp::NumericVector b, Rcpp::NumericVector a, int K, Rcpp::NumericVector x_ind);

TEST(immer_deepstate_test,subimmer_probs_gpcm_rcpp_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/subimmer_probs_gpcm_rcpp/libFuzzer_subimmer_probs_gpcm_rcpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector theta  = RcppDeepState_NumericVector();
  std::string theta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/subimmer_probs_gpcm_rcpp/libFuzzer_subimmer_probs_gpcm_rcpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_theta.qs";
  qs::c_qsave(theta,theta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta values: "<< theta << std::endl;
  NumericVector b  = RcppDeepState_NumericVector();
  std::string b_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/subimmer_probs_gpcm_rcpp/libFuzzer_subimmer_probs_gpcm_rcpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_b.qs";
  qs::c_qsave(b,b_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "b values: "<< b << std::endl;
  NumericVector a  = RcppDeepState_NumericVector();
  std::string a_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/subimmer_probs_gpcm_rcpp/libFuzzer_subimmer_probs_gpcm_rcpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_a.qs";
  qs::c_qsave(a,a_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  IntegerVector K(1);
  K[0]  = RcppDeepState_int();
  std::string K_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/subimmer_probs_gpcm_rcpp/libFuzzer_subimmer_probs_gpcm_rcpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_K.qs";
  qs::c_qsave(K,K_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "K values: "<< K << std::endl;
  NumericVector x_ind  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/subimmer_probs_gpcm_rcpp/libFuzzer_subimmer_probs_gpcm_rcpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  std::string x_ind_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/subimmer_probs_gpcm_rcpp/libFuzzer_subimmer_probs_gpcm_rcpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x_ind.qs";
  qs::c_qsave(x_ind,x_ind_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x_ind values: "<< x_ind << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    subimmer_probs_gpcm_rcpp(x,theta,b,a,K[0],x_ind);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
