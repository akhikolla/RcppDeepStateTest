#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix clogitl1CV_c(NumericVector n, NumericVector m, NumericMatrix Xmat, NumericVector yvec, NumericVector lambdas, NumericVector keepvec, double alpha);

TEST(clogitL1_deepstate_test,clogitl1CV_c_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector n  = RcppDeepState_NumericVector();
  std::string n_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitL1/inst/testfiles/clogitl1CV_c/AFL_clogitl1CV_c/afl_inputs/" + std::to_string(t) + "_n.qs";
  qs::c_qsave(n,n_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  NumericVector m  = RcppDeepState_NumericVector();
  std::string m_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitL1/inst/testfiles/clogitl1CV_c/AFL_clogitl1CV_c/afl_inputs/" + std::to_string(t) + "_m.qs";
  qs::c_qsave(m,m_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "m values: "<< m << std::endl;
  NumericMatrix Xmat  = RcppDeepState_NumericMatrix();
  std::string Xmat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitL1/inst/testfiles/clogitl1CV_c/AFL_clogitl1CV_c/afl_inputs/" + std::to_string(t) + "_Xmat.qs";
  qs::c_qsave(Xmat,Xmat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xmat values: "<< Xmat << std::endl;
  NumericVector yvec  = RcppDeepState_NumericVector();
  std::string yvec_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitL1/inst/testfiles/clogitl1CV_c/AFL_clogitl1CV_c/afl_inputs/" + std::to_string(t) + "_yvec.qs";
  qs::c_qsave(yvec,yvec_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "yvec values: "<< yvec << std::endl;
  NumericVector lambdas  = RcppDeepState_NumericVector();
  std::string lambdas_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitL1/inst/testfiles/clogitl1CV_c/AFL_clogitl1CV_c/afl_inputs/" + std::to_string(t) + "_lambdas.qs";
  qs::c_qsave(lambdas,lambdas_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lambdas values: "<< lambdas << std::endl;
  NumericVector keepvec  = RcppDeepState_NumericVector();
  std::string keepvec_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitL1/inst/testfiles/clogitl1CV_c/AFL_clogitl1CV_c/afl_inputs/" + std::to_string(t) + "_keepvec.qs";
  qs::c_qsave(keepvec,keepvec_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "keepvec values: "<< keepvec << std::endl;
  NumericVector alpha(1);
  alpha[0]  = RcppDeepState_double();
  std::string alpha_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/clogitL1/inst/testfiles/clogitl1CV_c/AFL_clogitl1CV_c/afl_inputs/" + std::to_string(t) + "_alpha.qs";
  qs::c_qsave(alpha,alpha_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    clogitl1CV_c(n,m,Xmat,yvec,lambdas,keepvec,alpha[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
