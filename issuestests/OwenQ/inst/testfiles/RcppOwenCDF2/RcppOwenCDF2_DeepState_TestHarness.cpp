#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector RcppOwenCDF2(int nu, double t1, double t2, NumericVector delta1, NumericVector delta2, int algo);

TEST(OwenQ_deepstate_test,RcppOwenCDF2_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector nu(1);
  nu[0]  = RcppDeepState_int();
  qs::c_qsave(nu,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppOwenCDF2/inputs/nu.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nu values: "<< nu << std::endl;
  NumericVector t1(1);
  t1[0]  = RcppDeepState_double();
  qs::c_qsave(t1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppOwenCDF2/inputs/t1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t1 values: "<< t1 << std::endl;
  NumericVector t2(1);
  t2[0]  = RcppDeepState_double();
  qs::c_qsave(t2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppOwenCDF2/inputs/t2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t2 values: "<< t2 << std::endl;
  NumericVector delta1  = RcppDeepState_NumericVector();
  qs::c_qsave(delta1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppOwenCDF2/inputs/delta1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta1 values: "<< delta1 << std::endl;
  NumericVector delta2  = RcppDeepState_NumericVector();
  qs::c_qsave(delta2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppOwenCDF2/inputs/delta2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta2 values: "<< delta2 << std::endl;
  IntegerVector algo(1);
  algo[0]  = RcppDeepState_int();
  qs::c_qsave(algo,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppOwenCDF2/inputs/algo.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "algo values: "<< algo << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    RcppOwenCDF2(nu[0],t1[0],t2[0],delta1,delta2,algo[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
