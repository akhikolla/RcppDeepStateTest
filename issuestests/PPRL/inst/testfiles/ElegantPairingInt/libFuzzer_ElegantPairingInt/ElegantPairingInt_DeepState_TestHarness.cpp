#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

SEXP ElegantPairingInt(int int1, int int2);

TEST(PPRL_deepstate_test,ElegantPairingInt_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector int1(1);
  int1[0]  = RcppDeepState_int();
  std::string int1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PPRL/inst/testfiles/ElegantPairingInt/libFuzzer_ElegantPairingInt/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_int1.qs";
  qs::c_qsave(int1,int1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "int1 values: "<< int1 << std::endl;
  IntegerVector int2(1);
  int2[0]  = RcppDeepState_int();
  std::string int2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PPRL/inst/testfiles/ElegantPairingInt/libFuzzer_ElegantPairingInt/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_int2.qs";
  qs::c_qsave(int2,int2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "int2 values: "<< int2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ElegantPairingInt(int1[0],int2[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
