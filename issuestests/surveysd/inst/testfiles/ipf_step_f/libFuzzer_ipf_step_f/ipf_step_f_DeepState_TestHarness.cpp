#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector ipf_step_f(NumericVector w, IntegerVector classes, NumericVector targets);

TEST(surveysd_deepstate_test,ipf_step_f_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector w  = RcppDeepState_NumericVector();
  std::string w_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/surveysd/inst/testfiles/ipf_step_f/libFuzzer_ipf_step_f/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_w.qs";
  qs::c_qsave(w,w_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "w values: "<< w << std::endl;
  IntegerVector classes  = RcppDeepState_IntegerVector();
  std::string classes_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/surveysd/inst/testfiles/ipf_step_f/libFuzzer_ipf_step_f/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_classes.qs";
  qs::c_qsave(classes,classes_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "classes values: "<< classes << std::endl;
  NumericVector targets  = RcppDeepState_NumericVector();
  std::string targets_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/surveysd/inst/testfiles/ipf_step_f/libFuzzer_ipf_step_f/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_targets.qs";
  qs::c_qsave(targets,targets_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "targets values: "<< targets << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ipf_step_f(w,classes,targets);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
