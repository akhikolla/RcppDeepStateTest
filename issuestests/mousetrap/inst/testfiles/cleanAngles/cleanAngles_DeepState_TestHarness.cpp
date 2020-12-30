#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix cleanAngles(NumericMatrix as);

TEST(mousetrap_deepstate_test,cleanAngles_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix as  = RcppDeepState_NumericMatrix();
  qs::c_qsave(as,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/cleanAngles/inputs/as.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "as values: "<< as << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cleanAngles(as);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
