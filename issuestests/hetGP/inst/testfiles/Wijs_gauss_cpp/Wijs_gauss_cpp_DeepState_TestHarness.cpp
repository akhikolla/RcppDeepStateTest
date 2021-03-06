#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix Wijs_gauss_cpp(NumericMatrix Mu1, NumericMatrix Mu2, NumericVector sigma);

TEST(hetGP_deepstate_test,Wijs_gauss_cpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix Mu1  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Mu1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/Wijs_gauss_cpp/inputs/Mu1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Mu1 values: "<< Mu1 << std::endl;
  NumericMatrix Mu2  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Mu2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/Wijs_gauss_cpp/inputs/Mu2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Mu2 values: "<< Mu2 << std::endl;
  NumericVector sigma  = RcppDeepState_NumericVector();
  qs::c_qsave(sigma,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/Wijs_gauss_cpp/inputs/sigma.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sigma values: "<< sigma << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    Wijs_gauss_cpp(Mu1,Mu2,sigma);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
