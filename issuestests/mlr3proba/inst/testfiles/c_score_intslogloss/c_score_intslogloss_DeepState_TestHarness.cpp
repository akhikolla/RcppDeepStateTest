#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix c_score_intslogloss(NumericMatrix truth, NumericVector unique_times, NumericMatrix cdf, double eps);

TEST(mlr3proba_deepstate_test,c_score_intslogloss_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix truth  = RcppDeepState_NumericMatrix();
  qs::c_qsave(truth,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_score_intslogloss/inputs/truth.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "truth values: "<< truth << std::endl;
  NumericVector unique_times  = RcppDeepState_NumericVector();
  qs::c_qsave(unique_times,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_score_intslogloss/inputs/unique_times.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "unique_times values: "<< unique_times << std::endl;
  NumericMatrix cdf  = RcppDeepState_NumericMatrix();
  qs::c_qsave(cdf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_score_intslogloss/inputs/cdf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cdf values: "<< cdf << std::endl;
  NumericVector eps(1);
  eps[0]  = RcppDeepState_double();
  qs::c_qsave(eps,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_score_intslogloss/inputs/eps.qs",
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
