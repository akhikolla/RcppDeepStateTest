#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector sSAC1_C(NumericVector x, NumericVector y, IntegerVector id_spec);

TEST(mobsim_deepstate_test,sSAC1_C_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mobsim/inst/testfiles/sSAC1_C/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mobsim/inst/testfiles/sSAC1_C/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  IntegerVector id_spec  = RcppDeepState_IntegerVector();
  qs::c_qsave(id_spec,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mobsim/inst/testfiles/sSAC1_C/inputs/id_spec.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "id_spec values: "<< id_spec << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    sSAC1_C(x,y,id_spec);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
