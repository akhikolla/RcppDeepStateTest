#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::IntegerVector matMultinom(Rcpp::NumericMatrix probmatrix);

TEST(simstudy_deepstate_test,matMultinom_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix probmatrix  = RcppDeepState_NumericMatrix();
  qs::c_qsave(probmatrix,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simstudy/inst/testfiles/matMultinom/inputs/probmatrix.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "probmatrix values: "<< probmatrix << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    matMultinom(probmatrix);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
