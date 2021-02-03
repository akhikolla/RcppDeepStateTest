#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector p_updateTau(NumericMatrix Xm, NumericMatrix U1m, NumericMatrix U2m, NumericMatrix cov1m, NumericMatrix cov2m, NumericVector Rv, NumericVector Cv, NumericVector nu1v, NumericVector nu2v);

TEST(CMF_deepstate_test,p_updateTau_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix Xm  = RcppDeepState_NumericMatrix();
  std::string Xm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updateTau/AFL_p_updateTau/afl_inputs/" + std::to_string(t) + "_Xm.qs";
  qs::c_qsave(Xm,Xm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xm values: "<< Xm << std::endl;
  NumericMatrix U1m  = RcppDeepState_NumericMatrix();
  std::string U1m_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updateTau/AFL_p_updateTau/afl_inputs/" + std::to_string(t) + "_U1m.qs";
  qs::c_qsave(U1m,U1m_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "U1m values: "<< U1m << std::endl;
  NumericMatrix U2m  = RcppDeepState_NumericMatrix();
  std::string U2m_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updateTau/AFL_p_updateTau/afl_inputs/" + std::to_string(t) + "_U2m.qs";
  qs::c_qsave(U2m,U2m_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "U2m values: "<< U2m << std::endl;
  NumericMatrix cov1m  = RcppDeepState_NumericMatrix();
  std::string cov1m_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updateTau/AFL_p_updateTau/afl_inputs/" + std::to_string(t) + "_cov1m.qs";
  qs::c_qsave(cov1m,cov1m_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cov1m values: "<< cov1m << std::endl;
  NumericMatrix cov2m  = RcppDeepState_NumericMatrix();
  std::string cov2m_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updateTau/AFL_p_updateTau/afl_inputs/" + std::to_string(t) + "_cov2m.qs";
  qs::c_qsave(cov2m,cov2m_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cov2m values: "<< cov2m << std::endl;
  NumericVector Rv  = RcppDeepState_NumericVector();
  std::string Rv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updateTau/AFL_p_updateTau/afl_inputs/" + std::to_string(t) + "_Rv.qs";
  qs::c_qsave(Rv,Rv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Rv values: "<< Rv << std::endl;
  NumericVector Cv  = RcppDeepState_NumericVector();
  std::string Cv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updateTau/AFL_p_updateTau/afl_inputs/" + std::to_string(t) + "_Cv.qs";
  qs::c_qsave(Cv,Cv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Cv values: "<< Cv << std::endl;
  NumericVector nu1v  = RcppDeepState_NumericVector();
  std::string nu1v_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updateTau/AFL_p_updateTau/afl_inputs/" + std::to_string(t) + "_nu1v.qs";
  qs::c_qsave(nu1v,nu1v_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nu1v values: "<< nu1v << std::endl;
  NumericVector nu2v  = RcppDeepState_NumericVector();
  std::string nu2v_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CMF/inst/testfiles/p_updateTau/AFL_p_updateTau/afl_inputs/" + std::to_string(t) + "_nu2v.qs";
  qs::c_qsave(nu2v,nu2v_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nu2v values: "<< nu2v << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    p_updateTau(Xm,U1m,U2m,cov1m,cov2m,Rv,Cv,nu1v,nu2v);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
