#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

SEXP KMUP(NumericMatrix X, NumericVector b, NumericVector d, NumericVector xx, NumericVector e, NumericVector L, double Ve, double pi);

TEST(NAM_deepstate_test,KMUP_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix X  = RcppDeepState_NumericMatrix();
  std::string X_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/KMUP/AFL_KMUP/afl_inputs/" + std::to_string(t) + "_X.qs";
  qs::c_qsave(X,X_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X values: "<< X << std::endl;
  NumericVector b  = RcppDeepState_NumericVector();
  std::string b_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/KMUP/AFL_KMUP/afl_inputs/" + std::to_string(t) + "_b.qs";
  qs::c_qsave(b,b_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "b values: "<< b << std::endl;
  NumericVector d  = RcppDeepState_NumericVector();
  std::string d_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/KMUP/AFL_KMUP/afl_inputs/" + std::to_string(t) + "_d.qs";
  qs::c_qsave(d,d_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "d values: "<< d << std::endl;
  NumericVector xx  = RcppDeepState_NumericVector();
  std::string xx_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/KMUP/AFL_KMUP/afl_inputs/" + std::to_string(t) + "_xx.qs";
  qs::c_qsave(xx,xx_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xx values: "<< xx << std::endl;
  NumericVector e  = RcppDeepState_NumericVector();
  std::string e_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/KMUP/AFL_KMUP/afl_inputs/" + std::to_string(t) + "_e.qs";
  qs::c_qsave(e,e_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "e values: "<< e << std::endl;
  NumericVector L  = RcppDeepState_NumericVector();
  std::string L_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/KMUP/AFL_KMUP/afl_inputs/" + std::to_string(t) + "_L.qs";
  qs::c_qsave(L,L_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "L values: "<< L << std::endl;
  NumericVector Ve(1);
  Ve[0]  = RcppDeepState_double();
  std::string Ve_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/KMUP/AFL_KMUP/afl_inputs/" + std::to_string(t) + "_Ve.qs";
  qs::c_qsave(Ve,Ve_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Ve values: "<< Ve << std::endl;
  NumericVector pi(1);
  pi[0]  = RcppDeepState_double();
  std::string pi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/KMUP/AFL_KMUP/afl_inputs/" + std::to_string(t) + "_pi.qs";
  qs::c_qsave(pi,pi_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pi values: "<< pi << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    KMUP(X,b,d,xx,e,L,Ve[0],pi[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
