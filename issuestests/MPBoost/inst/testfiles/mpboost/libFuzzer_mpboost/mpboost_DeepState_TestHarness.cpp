#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::IntegerVector mpboost(int N1, int N2, int MTI);

TEST(MPBoost_deepstate_test,mpboost_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector N1(1);
  N1[0]  = RcppDeepState_int();
  std::string N1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/MPBoost/inst/testfiles/mpboost/libFuzzer_mpboost/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_N1.qs";
  qs::c_qsave(N1,N1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N1 values: "<< N1 << std::endl;
  IntegerVector N2(1);
  N2[0]  = RcppDeepState_int();
  std::string N2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/MPBoost/inst/testfiles/mpboost/libFuzzer_mpboost/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_N2.qs";
  qs::c_qsave(N2,N2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N2 values: "<< N2 << std::endl;
  IntegerVector MTI(1);
  MTI[0]  = RcppDeepState_int();
  std::string MTI_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/MPBoost/inst/testfiles/mpboost/libFuzzer_mpboost/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_MTI.qs";
  qs::c_qsave(MTI,MTI_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "MTI values: "<< MTI << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    mpboost(N1[0],N2[0],MTI[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
