#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector RcppSpecialOwenCDF2(int nu, double t, NumericVector delta, int algo);

TEST(OwenQ_deepstate_test,RcppSpecialOwenCDF2_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector nu(1);
  nu[0]  = RcppDeepState_int();
  qs::c_qsave(nu,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppSpecialOwenCDF2/inputs/nu.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nu values: "<< nu << std::endl;
  NumericVector t(1);
  t[0]  = RcppDeepState_double();
  qs::c_qsave(t,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppSpecialOwenCDF2/inputs/t.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t values: "<< t << std::endl;
  NumericVector delta  = RcppDeepState_NumericVector();
  qs::c_qsave(delta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppSpecialOwenCDF2/inputs/delta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "delta values: "<< delta << std::endl;
  IntegerVector algo(1);
  algo[0]  = RcppDeepState_int();
  qs::c_qsave(algo,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/OwenQ/inst/testfiles/RcppSpecialOwenCDF2/inputs/algo.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "algo values: "<< algo << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    RcppSpecialOwenCDF2(nu[0],t[0],delta,algo[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
