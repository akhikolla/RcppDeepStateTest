#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double solarConstant(int J);

TEST(meteoland_deepstate_test,solarConstant_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector J(1);
  J[0]  = RcppDeepState_int();
  qs::c_qsave(J,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/solarConstant/inputs/J.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "J values: "<< J << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    solarConstant(J[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
