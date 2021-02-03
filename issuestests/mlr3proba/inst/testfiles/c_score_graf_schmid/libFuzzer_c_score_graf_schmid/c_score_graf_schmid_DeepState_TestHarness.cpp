#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix c_score_graf_schmid(NumericVector truth, NumericVector unique_times, NumericMatrix cdf, int power);

TEST(mlr3proba_deepstate_test,c_score_graf_schmid_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector truth  = RcppDeepState_NumericVector();
  std::string truth_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_score_graf_schmid/libFuzzer_c_score_graf_schmid/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_truth.qs";
  qs::c_qsave(truth,truth_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "truth values: "<< truth << std::endl;
  NumericVector unique_times  = RcppDeepState_NumericVector();
  std::string unique_times_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_score_graf_schmid/libFuzzer_c_score_graf_schmid/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_unique_times.qs";
  qs::c_qsave(unique_times,unique_times_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "unique_times values: "<< unique_times << std::endl;
  NumericMatrix cdf  = RcppDeepState_NumericMatrix();
  std::string cdf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_score_graf_schmid/libFuzzer_c_score_graf_schmid/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_cdf.qs";
  qs::c_qsave(cdf,cdf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cdf values: "<< cdf << std::endl;
  IntegerVector power(1);
  power[0]  = RcppDeepState_int();
  std::string power_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mlr3proba/inst/testfiles/c_score_graf_schmid/libFuzzer_c_score_graf_schmid/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_power.qs";
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
