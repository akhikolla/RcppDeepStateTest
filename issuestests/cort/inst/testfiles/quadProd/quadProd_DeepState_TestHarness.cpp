#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double quadProd(const NumericMatrix a, const NumericMatrix b, const NumericVector kern, const NumericMatrix other_a, const NumericMatrix other_b, const NumericVector other_kern);

TEST(cort_deepstate_test,quadProd_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix a  = RcppDeepState_NumericMatrix();
  qs::c_qsave(a,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/quadProd/inputs/a.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  NumericMatrix b  = RcppDeepState_NumericMatrix();
  qs::c_qsave(b,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/quadProd/inputs/b.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "b values: "<< b << std::endl;
  NumericVector kern  = RcppDeepState_NumericVector();
  qs::c_qsave(kern,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/quadProd/inputs/kern.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "kern values: "<< kern << std::endl;
  NumericMatrix other_a  = RcppDeepState_NumericMatrix();
  qs::c_qsave(other_a,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/quadProd/inputs/other_a.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "other_a values: "<< other_a << std::endl;
  NumericMatrix other_b  = RcppDeepState_NumericMatrix();
  qs::c_qsave(other_b,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/quadProd/inputs/other_b.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "other_b values: "<< other_b << std::endl;
  NumericVector other_kern  = RcppDeepState_NumericVector();
  qs::c_qsave(other_kern,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/quadProd/inputs/other_kern.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "other_kern values: "<< other_kern << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    quadProd(a,b,kern,other_a,other_b,other_kern);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
