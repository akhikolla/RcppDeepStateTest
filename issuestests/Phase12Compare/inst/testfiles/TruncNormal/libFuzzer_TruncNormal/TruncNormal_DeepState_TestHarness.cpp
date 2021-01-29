#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double TruncNormal(double rho, double c1);

TEST(Phase12Compare_deepstate_test,TruncNormal_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector rho(1);
  rho[0]  = RcppDeepState_double();
  std::string rho_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Phase12Compare/inst/testfiles/TruncNormal/libFuzzer_TruncNormal/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_rho.qs";
  qs::c_qsave(rho,rho_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rho values: "<< rho << std::endl;
  NumericVector c1(1);
  c1[0]  = RcppDeepState_double();
  std::string c1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Phase12Compare/inst/testfiles/TruncNormal/libFuzzer_TruncNormal/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_c1.qs";
  qs::c_qsave(c1,c1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "c1 values: "<< c1 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    TruncNormal(rho[0],c1[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
