#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List p_updateMean(NumericMatrix Xm, NumericMatrix U1m, NumericMatrix U2m, NumericVector I, NumericVector Mv);

TEST(CMF_deepstate_test,p_updateMean_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix Xm  = RcppDeepState_NumericMatrix();
  std::string Xm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updateMean/libFuzzer_p_updateMean/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Xm.qs";
  qs::c_qsave(Xm,Xm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xm values: "<< Xm << std::endl;
  NumericMatrix U1m  = RcppDeepState_NumericMatrix();
  std::string U1m_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updateMean/libFuzzer_p_updateMean/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_U1m.qs";
  qs::c_qsave(U1m,U1m_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "U1m values: "<< U1m << std::endl;
  NumericMatrix U2m  = RcppDeepState_NumericMatrix();
  std::string U2m_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updateMean/libFuzzer_p_updateMean/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_U2m.qs";
  qs::c_qsave(U2m,U2m_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "U2m values: "<< U2m << std::endl;
  NumericVector I  = RcppDeepState_NumericVector();
  std::string I_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updateMean/libFuzzer_p_updateMean/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_I.qs";
  qs::c_qsave(I,I_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "I values: "<< I << std::endl;
  NumericVector Mv  = RcppDeepState_NumericVector();
  std::string Mv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updateMean/libFuzzer_p_updateMean/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Mv.qs";
  qs::c_qsave(Mv,Mv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Mv values: "<< Mv << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    p_updateMean(Xm,U1m,U2m,I,Mv);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
