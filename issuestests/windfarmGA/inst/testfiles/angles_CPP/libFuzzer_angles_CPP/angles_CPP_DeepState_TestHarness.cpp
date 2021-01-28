#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector angles_CPP(NumericVector Aa, NumericVector Bb, NumericVector Cc);

TEST(windfarmGA_deepstate_test,angles_CPP_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector Aa  = RcppDeepState_NumericVector();
  std::string Aa_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/windfarmGA/inst/testfiles/angles_CPP/libFuzzer_angles_CPP/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Aa.qs";
  qs::c_qsave(Aa,Aa_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Aa values: "<< Aa << std::endl;
  NumericVector Bb  = RcppDeepState_NumericVector();
  std::string Bb_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/windfarmGA/inst/testfiles/angles_CPP/libFuzzer_angles_CPP/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Bb.qs";
  qs::c_qsave(Bb,Bb_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Bb values: "<< Bb << std::endl;
  NumericVector Cc  = RcppDeepState_NumericVector();
  std::string Cc_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/windfarmGA/inst/testfiles/angles_CPP/libFuzzer_angles_CPP/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Cc.qs";
  qs::c_qsave(Cc,Cc_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Cc values: "<< Cc << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    angles_CPP(Aa,Bb,Cc);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
