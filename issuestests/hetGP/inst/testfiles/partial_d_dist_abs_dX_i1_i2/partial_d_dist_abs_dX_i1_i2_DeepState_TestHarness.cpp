#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix partial_d_dist_abs_dX_i1_i2(NumericMatrix X1, int i1, int i2);

TEST(hetGP_deepstate_test,partial_d_dist_abs_dX_i1_i2_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix X1  = RcppDeepState_NumericMatrix();
  qs::c_qsave(X1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/partial_d_dist_abs_dX_i1_i2/inputs/X1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X1 values: "<< X1 << std::endl;
  IntegerVector i1(1);
  i1[0]  = RcppDeepState_int();
  qs::c_qsave(i1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/partial_d_dist_abs_dX_i1_i2/inputs/i1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "i1 values: "<< i1 << std::endl;
  IntegerVector i2(1);
  i2[0]  = RcppDeepState_int();
  qs::c_qsave(i2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/partial_d_dist_abs_dX_i1_i2/inputs/i2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "i2 values: "<< i2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    partial_d_dist_abs_dX_i1_i2(X1,i1[0],i2[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
