#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix c_weight_survival_score(NumericMatrix score, NumericMatrix truth, NumericVector unique_times, NumericMatrix cens);

TEST(mlr3proba_deepstate_test,c_weight_survival_score_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix score  = RcppDeepState_NumericMatrix();
  qs::c_qsave(score,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_weight_survival_score/inputs/score.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "score values: "<< score << std::endl;
  NumericMatrix truth  = RcppDeepState_NumericMatrix();
  qs::c_qsave(truth,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_weight_survival_score/inputs/truth.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "truth values: "<< truth << std::endl;
  NumericVector unique_times  = RcppDeepState_NumericVector();
  qs::c_qsave(unique_times,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_weight_survival_score/inputs/unique_times.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "unique_times values: "<< unique_times << std::endl;
  NumericMatrix cens  = RcppDeepState_NumericMatrix();
  qs::c_qsave(cens,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_weight_survival_score/inputs/cens.qs",
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
