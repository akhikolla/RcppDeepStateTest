#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double wake_CPP(double Rotorf, double wakr, double leA);

TEST(windfarmGA_deepstate_test,wake_CPP_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector Rotorf(1);
  Rotorf[0]  = RcppDeepState_double();
  std::string Rotorf_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/windfarmGA/inst/testfiles/wake_CPP/libFuzzer_wake_CPP/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Rotorf.qs";
  qs::c_qsave(Rotorf,Rotorf_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Rotorf values: "<< Rotorf << std::endl;
  NumericVector wakr(1);
  wakr[0]  = RcppDeepState_double();
  std::string wakr_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/windfarmGA/inst/testfiles/wake_CPP/libFuzzer_wake_CPP/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_wakr.qs";
  qs::c_qsave(wakr,wakr_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "wakr values: "<< wakr << std::endl;
  NumericVector leA(1);
  leA[0]  = RcppDeepState_double();
  std::string leA_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/windfarmGA/inst/testfiles/wake_CPP/libFuzzer_wake_CPP/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_leA.qs";
  qs::c_qsave(leA,leA_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "leA values: "<< leA << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    wake_CPP(Rotorf[0],wakr[0],leA[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
