#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix c_score_graf_schmid(NumericVector truth, NumericVector unique_times, NumericMatrix cdf, int power);

TEST(mlr3proba_deepstate_test,c_score_graf_schmid_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector truth  = RcppDeepState_NumericVector();
  std::string truth_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_score_graf_schmid/AFL_c_score_graf_schmid/afl_inputs/" + std::to_string(t) + "_truth.qs";
  qs::c_qsave(truth,truth_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "truth values: "<< truth << std::endl;
  NumericVector unique_times  = RcppDeepState_NumericVector();
  std::string unique_times_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_score_graf_schmid/AFL_c_score_graf_schmid/afl_inputs/" + std::to_string(t) + "_unique_times.qs";
  qs::c_qsave(unique_times,unique_times_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "unique_times values: "<< unique_times << std::endl;
  NumericMatrix cdf  = RcppDeepState_NumericMatrix();
  std::string cdf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_score_graf_schmid/AFL_c_score_graf_schmid/afl_inputs/" + std::to_string(t) + "_cdf.qs";
  qs::c_qsave(cdf,cdf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cdf values: "<< cdf << std::endl;
  IntegerVector power(1);
  power[0]  = RcppDeepState_int();
  std::string power_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_score_graf_schmid/AFL_c_score_graf_schmid/afl_inputs/" + std::to_string(t) + "_power.qs";
  qs::c_qsave(power,power_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "power values: "<< power << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    c_score_graf_schmid(truth,unique_times,cdf,power[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
