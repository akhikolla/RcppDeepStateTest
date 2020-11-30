#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector RcppOwenStudent(double q, int nu, NumericVector delta);

TEST(OwenQ_deepstate_test,RcppOwenStudent_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector q(1);
  q[0]  = RcppDeepState_double();
  qs::c_qsave(q,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppOwenStudent/inputs/q.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "q values: "<< q << std::endl;
  IntegerVector nu(1);
  nu[0]  = RcppDeepState_int();
  qs::c_qsave(nu,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppOwenStudent/inputs/nu.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nu values: "<< nu << std::endl;
  NumericVector delta  = RcppDeepState_NumericVector();
  qs::c_qsave(delta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppOwenStudent/inputs/delta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta values: "<< delta << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    RcppOwenStudent(q[0],nu[0],delta);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
