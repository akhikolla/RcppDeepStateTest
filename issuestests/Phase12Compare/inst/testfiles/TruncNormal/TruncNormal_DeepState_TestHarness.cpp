#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double TruncNormal(double rho, double c1);

TEST(Phase12Compare_deepstate_test,TruncNormal_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector rho(1);
  rho[0]  = RcppDeepState_double();
  qs::c_qsave(rho,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Phase12Compare/inst/testfiles/TruncNormal/inputs/rho.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rho values: "<< rho << std::endl;
  NumericVector c1(1);
  c1[0]  = RcppDeepState_double();
  qs::c_qsave(c1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Phase12Compare/inst/testfiles/TruncNormal/inputs/c1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "c1 values: "<< c1 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    TruncNormal(rho[0],c1[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
