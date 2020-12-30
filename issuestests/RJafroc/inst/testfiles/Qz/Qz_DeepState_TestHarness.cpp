#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double Qz(double zeta1, double zeta2);

TEST(RJafroc_deepstate_test,Qz_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector zeta1(1);
  zeta1[0]  = RcppDeepState_double();
  qs::c_qsave(zeta1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/Qz/inputs/zeta1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "zeta1 values: "<< zeta1 << std::endl;
  NumericVector zeta2(1);
  zeta2[0]  = RcppDeepState_double();
  qs::c_qsave(zeta2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/Qz/inputs/zeta2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "zeta2 values: "<< zeta2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    Qz(zeta1[0],zeta2[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
