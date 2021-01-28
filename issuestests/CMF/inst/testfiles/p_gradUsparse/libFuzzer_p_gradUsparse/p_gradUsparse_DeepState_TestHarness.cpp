#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

void p_gradUsparse(NumericMatrix Xm, NumericMatrix Gm, NumericMatrix CUm, NumericMatrix OUm, NumericMatrix Cm, NumericVector I, NumericVector T, NumericVector Rowm, NumericVector Colm);

TEST(CMF_deepstate_test,p_gradUsparse_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix Xm  = RcppDeepState_NumericMatrix();
  std::string Xm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_gradUsparse/libFuzzer_p_gradUsparse/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Xm.qs";
  qs::c_qsave(Xm,Xm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xm values: "<< Xm << std::endl;
  NumericMatrix Gm  = RcppDeepState_NumericMatrix();
  std::string Gm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_gradUsparse/libFuzzer_p_gradUsparse/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Gm.qs";
  qs::c_qsave(Gm,Gm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Gm values: "<< Gm << std::endl;
  NumericMatrix CUm  = RcppDeepState_NumericMatrix();
  std::string CUm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_gradUsparse/libFuzzer_p_gradUsparse/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_CUm.qs";
  qs::c_qsave(CUm,CUm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "CUm values: "<< CUm << std::endl;
  NumericMatrix OUm  = RcppDeepState_NumericMatrix();
  std::string OUm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_gradUsparse/libFuzzer_p_gradUsparse/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_OUm.qs";
  qs::c_qsave(OUm,OUm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "OUm values: "<< OUm << std::endl;
  NumericMatrix Cm  = RcppDeepState_NumericMatrix();
  std::string Cm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_gradUsparse/libFuzzer_p_gradUsparse/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Cm.qs";
  qs::c_qsave(Cm,Cm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Cm values: "<< Cm << std::endl;
  NumericVector I  = RcppDeepState_NumericVector();
  std::string I_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_gradUsparse/libFuzzer_p_gradUsparse/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_I.qs";
  qs::c_qsave(I,I_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "I values: "<< I << std::endl;
  NumericVector T  = RcppDeepState_NumericVector();
  std::string T_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_gradUsparse/libFuzzer_p_gradUsparse/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_T.qs";
  qs::c_qsave(T,T_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "T values: "<< T << std::endl;
  NumericVector Rowm  = RcppDeepState_NumericVector();
  std::string Rowm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_gradUsparse/libFuzzer_p_gradUsparse/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Rowm.qs";
  qs::c_qsave(Rowm,Rowm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Rowm values: "<< Rowm << std::endl;
  NumericVector Colm  = RcppDeepState_NumericVector();
  std::string Colm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_gradUsparse/libFuzzer_p_gradUsparse/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Colm.qs";
  qs::c_qsave(Colm,Colm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Colm values: "<< Colm << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    p_gradUsparse(Xm,Gm,CUm,OUm,Cm,I,T,Rowm,Colm);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
