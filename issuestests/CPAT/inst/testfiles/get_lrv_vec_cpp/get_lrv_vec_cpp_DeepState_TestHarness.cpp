#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector get_lrv_vec_cpp(NumericMatrix Y, NumericVector kern, int max_l);

TEST(CPAT_deepstate_test,get_lrv_vec_cpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix Y  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CPAT/inst/testfiles/get_lrv_vec_cpp/inputs/Y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Y values: "<< Y << std::endl;
  NumericVector kern  = RcppDeepState_NumericVector();
  qs::c_qsave(kern,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CPAT/inst/testfiles/get_lrv_vec_cpp/inputs/kern.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "kern values: "<< kern << std::endl;
  IntegerVector max_l(1);
  max_l[0]  = RcppDeepState_int();
  qs::c_qsave(max_l,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/CPAT/inst/testfiles/get_lrv_vec_cpp/inputs/max_l.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max_l values: "<< max_l << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    get_lrv_vec_cpp(Y,kern,max_l[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
