#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::List immer_latent_regression_posterior(Rcpp::NumericMatrix like, Rcpp::NumericMatrix prior, Rcpp::NumericVector weights);

TEST(immer_deepstate_test,immer_latent_regression_posterior_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix like  = RcppDeepState_NumericMatrix();
  std::string like_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_posterior/libFuzzer_immer_latent_regression_posterior/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_like.qs";
  qs::c_qsave(like,like_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "like values: "<< like << std::endl;
  NumericMatrix prior  = RcppDeepState_NumericMatrix();
  std::string prior_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_posterior/libFuzzer_immer_latent_regression_posterior/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_prior.qs";
  qs::c_qsave(prior,prior_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prior values: "<< prior << std::endl;
  NumericVector weights  = RcppDeepState_NumericVector();
  std::string weights_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_posterior/libFuzzer_immer_latent_regression_posterior/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_weights.qs";
  qs::c_qsave(weights,weights_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "weights values: "<< weights << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    immer_latent_regression_posterior(like,prior,weights);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
