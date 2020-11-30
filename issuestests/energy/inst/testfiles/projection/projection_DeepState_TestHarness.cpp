#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix projection(NumericMatrix Dx, NumericMatrix Dz);

TEST(energy_deepstate_test,projection_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix Dx  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Dx,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/energy/inst/testfiles/projection/inputs/Dx.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Dx values: "<< Dx << std::endl;
  NumericMatrix Dz  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Dz,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/energy/inst/testfiles/projection/inputs/Dz.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Dz values: "<< Dz << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    projection(Dx,Dz);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
