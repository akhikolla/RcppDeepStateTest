#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double mean_help(NumericVector x, int l, int r);

TEST(mosum_deepstate_test,mean_help_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mosum/inst/testfiles/mean_help/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector l(1);
  l[0]  = RcppDeepState_int();
  qs::c_qsave(l,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mosum/inst/testfiles/mean_help/inputs/l.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "l values: "<< l << std::endl;
  IntegerVector r(1);
  r[0]  = RcppDeepState_int();
  qs::c_qsave(r,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mosum/inst/testfiles/mean_help/inputs/r.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "r values: "<< r << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    mean_help(x,l[0],r[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
