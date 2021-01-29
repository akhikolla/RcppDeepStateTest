#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double c_s_h(double t, double h);

TEST(cgAUC_deepstate_test,c_s_h_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector t(1);
  t[0]  = RcppDeepState_double();
  std::string t_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cgAUC/inst/testfiles/c_s_h/libFuzzer_c_s_h/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_t.qs";
  qs::c_qsave(t,t_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t values: "<< t << std::endl;
  NumericVector h(1);
  h[0]  = RcppDeepState_double();
  std::string h_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cgAUC/inst/testfiles/c_s_h/libFuzzer_c_s_h/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_h.qs";
  qs::c_qsave(h,h_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "h values: "<< h << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    c_s_h(t[0],h[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
