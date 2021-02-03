#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::List immer_latent_regression_calc_mu_sigma(Rcpp::NumericMatrix X, Rcpp::IntegerVector group, int G, Rcpp::NumericVector beta, Rcpp::NumericVector gamma);

TEST(immer_deepstate_test,immer_latent_regression_calc_mu_sigma_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix X  = RcppDeepState_NumericMatrix();
  std::string X_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_calc_mu_sigma/libFuzzer_immer_latent_regression_calc_mu_sigma/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_X.qs";
  qs::c_qsave(X,X_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X values: "<< X << std::endl;
  IntegerVector group  = RcppDeepState_IntegerVector();
  std::string group_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_calc_mu_sigma/libFuzzer_immer_latent_regression_calc_mu_sigma/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_group.qs";
  qs::c_qsave(group,group_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "group values: "<< group << std::endl;
  IntegerVector G(1);
  G[0]  = RcppDeepState_int();
  std::string G_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_calc_mu_sigma/libFuzzer_immer_latent_regression_calc_mu_sigma/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_G.qs";
  qs::c_qsave(G,G_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "G values: "<< G << std::endl;
  NumericVector beta  = RcppDeepState_NumericVector();
  std::string beta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_calc_mu_sigma/libFuzzer_immer_latent_regression_calc_mu_sigma/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_beta.qs";
  qs::c_qsave(beta,beta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "beta values: "<< beta << std::endl;
  NumericVector gamma  = RcppDeepState_NumericVector();
  std::string gamma_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_calc_mu_sigma/libFuzzer_immer_latent_regression_calc_mu_sigma/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_gamma.qs";
  qs::c_qsave(gamma,gamma_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "gamma values: "<< gamma << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    immer_latent_regression_calc_mu_sigma(X,group,G[0],beta,gamma);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
