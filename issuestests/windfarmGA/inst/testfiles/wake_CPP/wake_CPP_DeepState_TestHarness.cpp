#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double wake_CPP(double Rotorf, double wakr, double leA);

TEST(windfarmGA_deepstate_test,wake_CPP_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector Rotorf(1);
  Rotorf[0]  = RcppDeepState_double();
  qs::c_qsave(Rotorf,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/windfarmGA/inst/testfiles/wake_CPP/inputs/Rotorf.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Rotorf values: "<< Rotorf << std::endl;
  NumericVector wakr(1);
  wakr[0]  = RcppDeepState_double();
  qs::c_qsave(wakr,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/windfarmGA/inst/testfiles/wake_CPP/inputs/wakr.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "wakr values: "<< wakr << std::endl;
  NumericVector leA(1);
  leA[0]  = RcppDeepState_double();
  qs::c_qsave(leA,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/windfarmGA/inst/testfiles/wake_CPP/inputs/leA.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "leA values: "<< leA << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    wake_CPP(Rotorf[0],wakr[0],leA[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
