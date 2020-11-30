#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector CgenerateTau_root(NumericVector U, NumericVector t, double a, int d);

TEST(RGeode_deepstate_test,CgenerateTau_root_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector U  = RcppDeepState_NumericVector();
  qs::c_qsave(U,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RGeode/inst/testfiles/CgenerateTau_root/inputs/U.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "U values: "<< U << std::endl;
  NumericVector t  = RcppDeepState_NumericVector();
  qs::c_qsave(t,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RGeode/inst/testfiles/CgenerateTau_root/inputs/t.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t values: "<< t << std::endl;
  NumericVector a(1);
  a[0]  = RcppDeepState_double();
  qs::c_qsave(a,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RGeode/inst/testfiles/CgenerateTau_root/inputs/a.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  IntegerVector d(1);
  d[0]  = RcppDeepState_int();
  qs::c_qsave(d,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RGeode/inst/testfiles/CgenerateTau_root/inputs/d.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "d values: "<< d << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    CgenerateTau_root(U,t,a[0],d[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
