#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector dcovU_stats(NumericMatrix Dx, NumericMatrix Dy);

TEST(energy_deepstate_test,dcovU_stats_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix Dx  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Dx,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/energy/inst/testfiles/dcovU_stats/inputs/Dx.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Dx values: "<< Dx << std::endl;
  NumericMatrix Dy  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Dy,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/energy/inst/testfiles/dcovU_stats/inputs/Dy.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Dy values: "<< Dy << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    dcovU_stats(Dx,Dy);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
