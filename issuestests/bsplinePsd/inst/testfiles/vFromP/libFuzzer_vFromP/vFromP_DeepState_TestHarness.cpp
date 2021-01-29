#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector vFromP(NumericVector p, const double eps);

TEST(bsplinePsd_deepstate_test,vFromP_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector p  = RcppDeepState_NumericVector();
  std::string p_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/bsplinePsd/inst/testfiles/vFromP/libFuzzer_vFromP/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_p.qs";
  qs::c_qsave(p,p_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "p values: "<< p << std::endl;
  NumericVector eps(1);
  eps[0]  = RcppDeepState_double();
  std::string eps_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/bsplinePsd/inst/testfiles/vFromP/libFuzzer_vFromP/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_eps.qs";
  qs::c_qsave(eps,eps_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eps values: "<< eps << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    vFromP(p,eps[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
