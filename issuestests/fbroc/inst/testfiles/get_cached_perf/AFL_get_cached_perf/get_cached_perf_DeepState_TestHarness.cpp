#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector get_cached_perf(NumericMatrix tpr, NumericMatrix fpr, NumericVector param, int measure);

TEST(fbroc_deepstate_test,get_cached_perf_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix tpr  = RcppDeepState_NumericMatrix();
  std::string tpr_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/get_cached_perf/AFL_get_cached_perf/afl_inputs/" + std::to_string(t) + "_tpr.qs";
  qs::c_qsave(tpr,tpr_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tpr values: "<< tpr << std::endl;
  NumericMatrix fpr  = RcppDeepState_NumericMatrix();
  std::string fpr_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/get_cached_perf/AFL_get_cached_perf/afl_inputs/" + std::to_string(t) + "_fpr.qs";
  qs::c_qsave(fpr,fpr_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fpr values: "<< fpr << std::endl;
  NumericVector param  = RcppDeepState_NumericVector();
  std::string param_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/get_cached_perf/AFL_get_cached_perf/afl_inputs/" + std::to_string(t) + "_param.qs";
  qs::c_qsave(param,param_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "param values: "<< param << std::endl;
  IntegerVector measure(1);
  measure[0]  = RcppDeepState_int();
  std::string measure_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/get_cached_perf/AFL_get_cached_perf/afl_inputs/" + std::to_string(t) + "_measure.qs";
  qs::c_qsave(measure,measure_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "measure values: "<< measure << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    get_cached_perf(tpr,fpr,param,measure[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
