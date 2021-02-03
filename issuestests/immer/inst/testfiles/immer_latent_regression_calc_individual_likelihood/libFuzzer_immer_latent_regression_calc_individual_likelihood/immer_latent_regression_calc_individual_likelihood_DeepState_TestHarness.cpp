#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector immer_latent_regression_calc_individual_likelihood(Rcpp::NumericMatrix X, Rcpp::IntegerVector group, int G, Rcpp::NumericVector pars, Rcpp::NumericVector theta, Rcpp::NumericVector weights, Rcpp::NumericMatrix like);

TEST(immer_deepstate_test,immer_latent_regression_calc_individual_likelihood_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix X  = RcppDeepState_NumericMatrix();
  std::string X_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_calc_individual_likelihood/libFuzzer_immer_latent_regression_calc_individual_likelihood/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_X.qs";
  qs::c_qsave(X,X_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X values: "<< X << std::endl;
  IntegerVector group  = RcppDeepState_IntegerVector();
  std::string group_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_calc_individual_likelihood/libFuzzer_immer_latent_regression_calc_individual_likelihood/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_group.qs";
  qs::c_qsave(group,group_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "group values: "<< group << std::endl;
  IntegerVector G(1);
  G[0]  = RcppDeepState_int();
  std::string G_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_calc_individual_likelihood/libFuzzer_immer_latent_regression_calc_individual_likelihood/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_G.qs";
  qs::c_qsave(G,G_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "G values: "<< G << std::endl;
  NumericVector pars  = RcppDeepState_NumericVector();
  std::string pars_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_calc_individual_likelihood/libFuzzer_immer_latent_regression_calc_individual_likelihood/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_pars.qs";
  qs::c_qsave(pars,pars_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pars values: "<< pars << std::endl;
  NumericVector theta  = RcppDeepState_NumericVector();
  std::string theta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_calc_individual_likelihood/libFuzzer_immer_latent_regression_calc_individual_likelihood/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_theta.qs";
  qs::c_qsave(theta,theta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta values: "<< theta << std::endl;
  NumericVector weights  = RcppDeepState_NumericVector();
  std::string weights_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_calc_individual_likelihood/libFuzzer_immer_latent_regression_calc_individual_likelihood/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_weights.qs";
  qs::c_qsave(weights,weights_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "weights values: "<< weights << std::endl;
  NumericMatrix like  = RcppDeepState_NumericMatrix();
  std::string like_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_calc_individual_likelihood/libFuzzer_immer_latent_regression_calc_individual_likelihood/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_like.qs";
  qs::c_qsave(like,like_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "like values: "<< like << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    immer_latent_regression_calc_individual_likelihood(X,group,G[0],pars,theta,weights,like);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
