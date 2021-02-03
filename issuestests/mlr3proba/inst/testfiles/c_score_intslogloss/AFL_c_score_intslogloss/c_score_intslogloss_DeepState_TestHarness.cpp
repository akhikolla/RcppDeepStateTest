#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix c_score_intslogloss(NumericMatrix truth, NumericVector unique_times, NumericMatrix cdf, double eps);

TEST(mlr3proba_deepstate_test,c_score_intslogloss_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix truth  = RcppDeepState_NumericMatrix();
  std::string truth_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_score_intslogloss/AFL_c_score_intslogloss/afl_inputs/" + std::to_string(t) + "_truth.qs";
  qs::c_qsave(truth,truth_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "truth values: "<< truth << std::endl;
  NumericVector unique_times  = RcppDeepState_NumericVector();
  std::string unique_times_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_score_intslogloss/AFL_c_score_intslogloss/afl_inputs/" + std::to_string(t) + "_unique_times.qs";
  qs::c_qsave(unique_times,unique_times_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "unique_times values: "<< unique_times << std::endl;
  NumericMatrix cdf  = RcppDeepState_NumericMatrix();
  std::string cdf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_score_intslogloss/AFL_c_score_intslogloss/afl_inputs/" + std::to_string(t) + "_cdf.qs";
  qs::c_qsave(cdf,cdf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cdf values: "<< cdf << std::endl;
  NumericVector eps(1);
  eps[0]  = RcppDeepState_double();
  std::string eps_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_score_intslogloss/AFL_c_score_intslogloss/afl_inputs/" + std::to_string(t) + "_eps.qs";
  qs::c_qsave(eps,eps_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eps values: "<< eps << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    c_score_intslogloss(truth,unique_times,cdf,eps[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
