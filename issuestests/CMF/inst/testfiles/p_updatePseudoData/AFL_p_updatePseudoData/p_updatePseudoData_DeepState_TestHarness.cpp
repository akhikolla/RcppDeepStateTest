#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

void p_updatePseudoData(NumericMatrix Xm, NumericMatrix U1m, NumericMatrix U2m, NumericVector Rv, NumericVector Cv);

TEST(CMF_deepstate_test,p_updatePseudoData_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix Xm  = RcppDeepState_NumericMatrix();
  std::string Xm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updatePseudoData/AFL_p_updatePseudoData/afl_inputs/" + std::to_string(t) + "_Xm.qs";
  qs::c_qsave(Xm,Xm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xm values: "<< Xm << std::endl;
  NumericMatrix U1m  = RcppDeepState_NumericMatrix();
  std::string U1m_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updatePseudoData/AFL_p_updatePseudoData/afl_inputs/" + std::to_string(t) + "_U1m.qs";
  qs::c_qsave(U1m,U1m_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "U1m values: "<< U1m << std::endl;
  NumericMatrix U2m  = RcppDeepState_NumericMatrix();
  std::string U2m_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updatePseudoData/AFL_p_updatePseudoData/afl_inputs/" + std::to_string(t) + "_U2m.qs";
  qs::c_qsave(U2m,U2m_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "U2m values: "<< U2m << std::endl;
  NumericVector Rv  = RcppDeepState_NumericVector();
  std::string Rv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updatePseudoData/AFL_p_updatePseudoData/afl_inputs/" + std::to_string(t) + "_Rv.qs";
  qs::c_qsave(Rv,Rv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Rv values: "<< Rv << std::endl;
  NumericVector Cv  = RcppDeepState_NumericVector();
  std::string Cv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updatePseudoData/AFL_p_updatePseudoData/afl_inputs/" + std::to_string(t) + "_Cv.qs";
  qs::c_qsave(Cv,Cv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Cv values: "<< Cv << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    p_updatePseudoData(Xm,U1m,U2m,Rv,Cv);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
