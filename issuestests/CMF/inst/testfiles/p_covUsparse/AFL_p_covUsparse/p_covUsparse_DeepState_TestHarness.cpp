#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

void p_covUsparse(NumericMatrix Xm, NumericMatrix Cm, NumericMatrix OUm, NumericMatrix OCm, NumericVector I, NumericVector T);

TEST(CMF_deepstate_test,p_covUsparse_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix Xm  = RcppDeepState_NumericMatrix();
  std::string Xm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_covUsparse/AFL_p_covUsparse/afl_inputs/" + std::to_string(t) + "_Xm.qs";
  qs::c_qsave(Xm,Xm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xm values: "<< Xm << std::endl;
  NumericMatrix Cm  = RcppDeepState_NumericMatrix();
  std::string Cm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_covUsparse/AFL_p_covUsparse/afl_inputs/" + std::to_string(t) + "_Cm.qs";
  qs::c_qsave(Cm,Cm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Cm values: "<< Cm << std::endl;
  NumericMatrix OUm  = RcppDeepState_NumericMatrix();
  std::string OUm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_covUsparse/AFL_p_covUsparse/afl_inputs/" + std::to_string(t) + "_OUm.qs";
  qs::c_qsave(OUm,OUm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "OUm values: "<< OUm << std::endl;
  NumericMatrix OCm  = RcppDeepState_NumericMatrix();
  std::string OCm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_covUsparse/AFL_p_covUsparse/afl_inputs/" + std::to_string(t) + "_OCm.qs";
  qs::c_qsave(OCm,OCm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "OCm values: "<< OCm << std::endl;
  NumericVector I  = RcppDeepState_NumericVector();
  std::string I_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_covUsparse/AFL_p_covUsparse/afl_inputs/" + std::to_string(t) + "_I.qs";
  qs::c_qsave(I,I_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "I values: "<< I << std::endl;
  NumericVector T  = RcppDeepState_NumericVector();
  std::string T_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_covUsparse/AFL_p_covUsparse/afl_inputs/" + std::to_string(t) + "_T.qs";
  qs::c_qsave(T,T_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "T values: "<< T << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    p_covUsparse(Xm,Cm,OUm,OCm,I,T);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
