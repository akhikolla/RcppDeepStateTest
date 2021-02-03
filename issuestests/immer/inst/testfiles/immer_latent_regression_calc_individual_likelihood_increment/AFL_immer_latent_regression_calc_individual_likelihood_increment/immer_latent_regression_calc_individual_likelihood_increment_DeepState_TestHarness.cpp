#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector immer_latent_regression_calc_individual_likelihood_increment(Rcpp::NumericMatrix X, Rcpp::IntegerVector group, int G, Rcpp::NumericVector pars, Rcpp::NumericVector theta, Rcpp::NumericVector weights, Rcpp::NumericMatrix like, int pos1, double h1, int pos2, double h2);

TEST(immer_deepstate_test,immer_latent_regression_calc_individual_likelihood_increment_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix X  = RcppDeepState_NumericMatrix();
  std::string X_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_calc_individual_likelihood_increment/AFL_immer_latent_regression_calc_individual_likelihood_increment/afl_inputs/" + std::to_string(t) + "_X.qs";
  qs::c_qsave(X,X_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X values: "<< X << std::endl;
  IntegerVector group  = RcppDeepState_IntegerVector();
  std::string group_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_calc_individual_likelihood_increment/AFL_immer_latent_regression_calc_individual_likelihood_increment/afl_inputs/" + std::to_string(t) + "_group.qs";
  qs::c_qsave(group,group_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "group values: "<< group << std::endl;
  IntegerVector G(1);
  G[0]  = RcppDeepState_int();
  std::string G_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_calc_individual_likelihood_increment/AFL_immer_latent_regression_calc_individual_likelihood_increment/afl_inputs/" + std::to_string(t) + "_G.qs";
  qs::c_qsave(G,G_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "G values: "<< G << std::endl;
  NumericVector pars  = RcppDeepState_NumericVector();
  std::string pars_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_calc_individual_likelihood_increment/AFL_immer_latent_regression_calc_individual_likelihood_increment/afl_inputs/" + std::to_string(t) + "_pars.qs";
  qs::c_qsave(pars,pars_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pars values: "<< pars << std::endl;
  NumericVector theta  = RcppDeepState_NumericVector();
  std::string theta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_calc_individual_likelihood_increment/AFL_immer_latent_regression_calc_individual_likelihood_increment/afl_inputs/" + std::to_string(t) + "_theta.qs";
  qs::c_qsave(theta,theta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta values: "<< theta << std::endl;
  NumericVector weights  = RcppDeepState_NumericVector();
  std::string weights_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_calc_individual_likelihood_increment/AFL_immer_latent_regression_calc_individual_likelihood_increment/afl_inputs/" + std::to_string(t) + "_weights.qs";
  qs::c_qsave(weights,weights_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "weights values: "<< weights << std::endl;
  NumericMatrix like  = RcppDeepState_NumericMatrix();
  std::string like_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_calc_individual_likelihood_increment/AFL_immer_latent_regression_calc_individual_likelihood_increment/afl_inputs/" + std::to_string(t) + "_like.qs";
  qs::c_qsave(like,like_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "like values: "<< like << std::endl;
  IntegerVector pos1(1);
  pos1[0]  = RcppDeepState_int();
  std::string pos1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_calc_individual_likelihood_increment/AFL_immer_latent_regression_calc_individual_likelihood_increment/afl_inputs/" + std::to_string(t) + "_pos1.qs";
  qs::c_qsave(pos1,pos1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pos1 values: "<< pos1 << std::endl;
  NumericVector h1(1);
  h1[0]  = RcppDeepState_double();
  std::string h1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_calc_individual_likelihood_increment/AFL_immer_latent_regression_calc_individual_likelihood_increment/afl_inputs/" + std::to_string(t) + "_h1.qs";
  qs::c_qsave(h1,h1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "h1 values: "<< h1 << std::endl;
  IntegerVector pos2(1);
  pos2[0]  = RcppDeepState_int();
  std::string pos2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_calc_individual_likelihood_increment/AFL_immer_latent_regression_calc_individual_likelihood_increment/afl_inputs/" + std::to_string(t) + "_pos2.qs";
  qs::c_qsave(pos2,pos2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pos2 values: "<< pos2 << std::endl;
  NumericVector h2(1);
  h2[0]  = RcppDeepState_double();
  std::string h2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_latent_regression_calc_individual_likelihood_increment/AFL_immer_latent_regression_calc_individual_likelihood_increment/afl_inputs/" + std::to_string(t) + "_h2.qs";
  qs::c_qsave(h2,h2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "h2 values: "<< h2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    immer_latent_regression_calc_individual_likelihood_increment(X,group,G[0],pars,theta,weights,like,pos1[0],h1[0],pos2[0],h2[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
