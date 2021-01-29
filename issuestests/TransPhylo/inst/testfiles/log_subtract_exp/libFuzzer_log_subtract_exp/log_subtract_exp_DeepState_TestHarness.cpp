#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double log_subtract_exp(double u, double v);

TEST(TransPhylo_deepstate_test,log_subtract_exp_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector u(1);
  u[0]  = RcppDeepState_double();
  std::string u_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/log_subtract_exp/libFuzzer_log_subtract_exp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_u.qs";
  qs::c_qsave(u,u_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "u values: "<< u << std::endl;
  NumericVector v(1);
  v[0]  = RcppDeepState_double();
  std::string v_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/TransPhylo/inst/testfiles/log_subtract_exp/libFuzzer_log_subtract_exp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_v.qs";
  qs::c_qsave(v,v_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "v values: "<< v << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    log_subtract_exp(u[0],v[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
