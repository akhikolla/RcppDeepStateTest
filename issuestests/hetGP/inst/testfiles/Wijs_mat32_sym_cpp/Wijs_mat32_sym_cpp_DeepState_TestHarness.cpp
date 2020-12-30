#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix Wijs_mat32_sym_cpp(NumericMatrix Mu, NumericVector sigma);

TEST(hetGP_deepstate_test,Wijs_mat32_sym_cpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix Mu  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Mu,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/Wijs_mat32_sym_cpp/inputs/Mu.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Mu values: "<< Mu << std::endl;
  NumericVector sigma  = RcppDeepState_NumericVector();
  qs::c_qsave(sigma,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/Wijs_mat32_sym_cpp/inputs/sigma.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sigma values: "<< sigma << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    Wijs_mat32_sym_cpp(Mu,sigma);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
