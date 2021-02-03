#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector znorm(NumericVector ts, double threshold);

TEST(jmotif_deepstate_test,znorm_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector ts  = RcppDeepState_NumericVector();
  std::string ts_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/znorm/AFL_znorm/afl_inputs/" + std::to_string(t) + "_ts.qs";
  qs::c_qsave(ts,ts_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ts values: "<< ts << std::endl;
  NumericVector threshold(1);
  threshold[0]  = RcppDeepState_double();
  std::string threshold_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/jmotif/inst/testfiles/znorm/AFL_znorm/afl_inputs/" + std::to_string(t) + "_threshold.qs";
  qs::c_qsave(threshold,threshold_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "threshold values: "<< threshold << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    znorm(ts,threshold[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
