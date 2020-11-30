#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

void ipf_step_ref(NumericVector w, IntegerVector classes, NumericVector targets);

TEST(surveysd_deepstate_test,ipf_step_ref_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector w  = RcppDeepState_NumericVector();
  qs::c_qsave(w,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/surveysd/inst/testfiles/ipf_step_ref/inputs/w.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "w values: "<< w << std::endl;
  IntegerVector classes  = RcppDeepState_IntegerVector();
  qs::c_qsave(classes,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/surveysd/inst/testfiles/ipf_step_ref/inputs/classes.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "classes values: "<< classes << std::endl;
  NumericVector targets  = RcppDeepState_NumericVector();
  qs::c_qsave(targets,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/surveysd/inst/testfiles/ipf_step_ref/inputs/targets.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "targets values: "<< targets << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ipf_step_ref(w,classes,targets);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
