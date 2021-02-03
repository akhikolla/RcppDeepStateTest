#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

SEXP NOR(NumericVector y, NumericMatrix X, double cxx, NumericVector xx, int maxit, double tol);

TEST(NAM_deepstate_test,NOR_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/NOR/AFL_NOR/afl_inputs/" + std::to_string(t) + "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericMatrix X  = RcppDeepState_NumericMatrix();
  std::string X_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/NOR/AFL_NOR/afl_inputs/" + std::to_string(t) + "_X.qs";
  qs::c_qsave(X,X_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X values: "<< X << std::endl;
  NumericVector cxx(1);
  cxx[0]  = RcppDeepState_double();
  std::string cxx_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/NOR/AFL_NOR/afl_inputs/" + std::to_string(t) + "_cxx.qs";
  qs::c_qsave(cxx,cxx_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cxx values: "<< cxx << std::endl;
  NumericVector xx  = RcppDeepState_NumericVector();
  std::string xx_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/NOR/AFL_NOR/afl_inputs/" + std::to_string(t) + "_xx.qs";
  qs::c_qsave(xx,xx_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xx values: "<< xx << std::endl;
  IntegerVector maxit(1);
  maxit[0]  = RcppDeepState_int();
  std::string maxit_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/NOR/AFL_NOR/afl_inputs/" + std::to_string(t) + "_maxit.qs";
  qs::c_qsave(maxit,maxit_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "maxit values: "<< maxit << std::endl;
  NumericVector tol(1);
  tol[0]  = RcppDeepState_double();
  std::string tol_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/NOR/AFL_NOR/afl_inputs/" + std::to_string(t) + "_tol.qs";
  qs::c_qsave(tol,tol_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tol values: "<< tol << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    NOR(y,X,cxx[0],xx,maxit[0],tol[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
