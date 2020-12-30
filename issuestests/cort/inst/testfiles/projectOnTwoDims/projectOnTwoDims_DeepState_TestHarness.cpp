#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::List projectOnTwoDims(const NumericMatrix a, const NumericMatrix b, const NumericVector p, const NumericVector f, const NumericVector kern, const NumericVector dims, const NumericMatrix data);

TEST(cort_deepstate_test,projectOnTwoDims_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix a  = RcppDeepState_NumericMatrix();
  qs::c_qsave(a,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/projectOnTwoDims/inputs/a.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  NumericMatrix b  = RcppDeepState_NumericMatrix();
  qs::c_qsave(b,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/projectOnTwoDims/inputs/b.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "b values: "<< b << std::endl;
  NumericVector p  = RcppDeepState_NumericVector();
  qs::c_qsave(p,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/projectOnTwoDims/inputs/p.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "p values: "<< p << std::endl;
  NumericVector f  = RcppDeepState_NumericVector();
  qs::c_qsave(f,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/projectOnTwoDims/inputs/f.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "f values: "<< f << std::endl;
  NumericVector kern  = RcppDeepState_NumericVector();
  qs::c_qsave(kern,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/projectOnTwoDims/inputs/kern.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "kern values: "<< kern << std::endl;
  NumericVector dims  = RcppDeepState_NumericVector();
  qs::c_qsave(dims,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/projectOnTwoDims/inputs/dims.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dims values: "<< dims << std::endl;
  NumericMatrix data  = RcppDeepState_NumericMatrix();
  qs::c_qsave(data,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/cort/inst/testfiles/projectOnTwoDims/inputs/data.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "data values: "<< data << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    projectOnTwoDims(a,b,p,f,kern,dims,data);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
