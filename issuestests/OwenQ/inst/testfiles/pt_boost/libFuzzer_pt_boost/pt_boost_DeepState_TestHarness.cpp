#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double pt_boost(double q, double nu, double delta);

TEST(OwenQ_deepstate_test,pt_boost_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector q(1);
  q[0]  = RcppDeepState_double();
  std::string q_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/pt_boost/libFuzzer_pt_boost/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_q.qs";
  qs::c_qsave(q,q_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "q values: "<< q << std::endl;
  NumericVector nu(1);
  nu[0]  = RcppDeepState_double();
  std::string nu_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/pt_boost/libFuzzer_pt_boost/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nu.qs";
  qs::c_qsave(nu,nu_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nu values: "<< nu << std::endl;
  NumericVector delta(1);
  delta[0]  = RcppDeepState_double();
  std::string delta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/pt_boost/libFuzzer_pt_boost/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_delta.qs";
  qs::c_qsave(delta,delta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta values: "<< delta << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    pt_boost(q[0],nu[0],delta[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
