#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List myfitConGraphC(NumericMatrix amat, NumericMatrix S, double n, double tol);

TEST(robFitConGraph_deepstate_test,myfitConGraphC_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix amat  = RcppDeepState_NumericMatrix();
  std::string amat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/robFitConGraph/inst/testfiles/myfitConGraphC/AFL_myfitConGraphC/afl_inputs/" + std::to_string(t) + "_amat.qs";
  qs::c_qsave(amat,amat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "amat values: "<< amat << std::endl;
  NumericMatrix S  = RcppDeepState_NumericMatrix();
  std::string S_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/robFitConGraph/inst/testfiles/myfitConGraphC/AFL_myfitConGraphC/afl_inputs/" + std::to_string(t) + "_S.qs";
  qs::c_qsave(S,S_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "S values: "<< S << std::endl;
  NumericVector n(1);
  n[0]  = RcppDeepState_double();
  std::string n_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/robFitConGraph/inst/testfiles/myfitConGraphC/AFL_myfitConGraphC/afl_inputs/" + std::to_string(t) + "_n.qs";
  qs::c_qsave(n,n_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  NumericVector tol(1);
  tol[0]  = RcppDeepState_double();
  std::string tol_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/robFitConGraph/inst/testfiles/myfitConGraphC/AFL_myfitConGraphC/afl_inputs/" + std::to_string(t) + "_tol.qs";
  qs::c_qsave(tol,tol_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tol values: "<< tol << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    myfitConGraphC(amat,S,n[0],tol[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
