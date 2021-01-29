#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector Likgpcm(IntegerVector awv, NumericMatrix DELTA, NumericVector ALPHA, NumericVector nodes);

TEST(PP_deepstate_test,Likgpcm_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector awv  = RcppDeepState_IntegerVector();
  std::string awv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/Likgpcm/libFuzzer_Likgpcm/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_awv.qs";
  qs::c_qsave(awv,awv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "awv values: "<< awv << std::endl;
  NumericMatrix DELTA  = RcppDeepState_NumericMatrix();
  std::string DELTA_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/Likgpcm/libFuzzer_Likgpcm/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_DELTA.qs";
  qs::c_qsave(DELTA,DELTA_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "DELTA values: "<< DELTA << std::endl;
  NumericVector ALPHA  = RcppDeepState_NumericVector();
  std::string ALPHA_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/Likgpcm/libFuzzer_Likgpcm/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ALPHA.qs";
  qs::c_qsave(ALPHA,ALPHA_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ALPHA values: "<< ALPHA << std::endl;
  NumericVector nodes  = RcppDeepState_NumericVector();
  std::string nodes_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PP/inst/testfiles/Likgpcm/libFuzzer_Likgpcm/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nodes.qs";
  qs::c_qsave(nodes,nodes_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nodes values: "<< nodes << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    Likgpcm(awv,DELTA,ALPHA,nodes);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
