#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix c_weight_survival_score(NumericMatrix score, NumericMatrix truth, NumericVector unique_times, NumericMatrix cens);

TEST(mlr3proba_deepstate_test,c_weight_survival_score_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix score  = RcppDeepState_NumericMatrix();
  std::string score_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_weight_survival_score/AFL_c_weight_survival_score/afl_inputs/" + std::to_string(t) + "_score.qs";
  qs::c_qsave(score,score_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "score values: "<< score << std::endl;
  NumericMatrix truth  = RcppDeepState_NumericMatrix();
  std::string truth_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_weight_survival_score/AFL_c_weight_survival_score/afl_inputs/" + std::to_string(t) + "_truth.qs";
  qs::c_qsave(truth,truth_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "truth values: "<< truth << std::endl;
  NumericVector unique_times  = RcppDeepState_NumericVector();
  std::string unique_times_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_weight_survival_score/AFL_c_weight_survival_score/afl_inputs/" + std::to_string(t) + "_unique_times.qs";
  qs::c_qsave(unique_times,unique_times_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "unique_times values: "<< unique_times << std::endl;
  NumericMatrix cens  = RcppDeepState_NumericMatrix();
  std::string cens_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_weight_survival_score/AFL_c_weight_survival_score/afl_inputs/" + std::to_string(t) + "_cens.qs";
  qs::c_qsave(cens,cens_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cens values: "<< cens << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    c_weight_survival_score(score,truth,unique_times,cens);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
