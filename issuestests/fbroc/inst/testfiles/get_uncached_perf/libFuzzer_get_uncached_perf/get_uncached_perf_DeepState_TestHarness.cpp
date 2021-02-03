#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector get_uncached_perf(NumericVector pred, IntegerVector true_class, NumericVector param, int n_boot, int measure);

TEST(fbroc_deepstate_test,get_uncached_perf_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector pred  = RcppDeepState_NumericVector();
  std::string pred_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/get_uncached_perf/libFuzzer_get_uncached_perf/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_pred.qs";
  qs::c_qsave(pred,pred_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pred values: "<< pred << std::endl;
  IntegerVector true_class  = RcppDeepState_IntegerVector();
  std::string true_class_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/get_uncached_perf/libFuzzer_get_uncached_perf/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_true_class.qs";
  qs::c_qsave(true_class,true_class_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "true_class values: "<< true_class << std::endl;
  NumericVector param  = RcppDeepState_NumericVector();
  std::string param_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/get_uncached_perf/libFuzzer_get_uncached_perf/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_param.qs";
  qs::c_qsave(param,param_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "param values: "<< param << std::endl;
  IntegerVector n_boot(1);
  n_boot[0]  = RcppDeepState_int();
  std::string n_boot_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/get_uncached_perf/libFuzzer_get_uncached_perf/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_n_boot.qs";
  qs::c_qsave(n_boot,n_boot_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_boot values: "<< n_boot << std::endl;
  IntegerVector measure(1);
  measure[0]  = RcppDeepState_int();
  std::string measure_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/fbroc/inst/testfiles/get_uncached_perf/libFuzzer_get_uncached_perf/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_measure.qs";
  qs::c_qsave(measure,measure_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "measure values: "<< measure << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    get_uncached_perf(pred,true_class,param,n_boot[0],measure[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
