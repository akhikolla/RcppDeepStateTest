#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix UserSimil(NumericMatrix x, int damp);

TEST(rrecsys_deepstate_test,UserSimil_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix x  = RcppDeepState_NumericMatrix();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/UserSimil/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector damp(1);
  damp[0]  = RcppDeepState_int();
  qs::c_qsave(damp,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/UserSimil/inputs/damp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "damp values: "<< damp << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    UserSimil(x,damp[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
