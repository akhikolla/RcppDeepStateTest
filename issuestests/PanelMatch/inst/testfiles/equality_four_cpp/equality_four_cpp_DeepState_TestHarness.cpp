#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector equality_four_cpp(Rcpp::NumericMatrix Wit_vals, Rcpp::NumericVector y, Rcpp::NumericVector z);

TEST(PanelMatch_deepstate_test,equality_four_cpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix Wit_vals  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Wit_vals,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/equality_four_cpp/inputs/Wit_vals.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Wit_vals values: "<< Wit_vals << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/equality_four_cpp/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector z  = RcppDeepState_NumericVector();
  qs::c_qsave(z,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/equality_four_cpp/inputs/z.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    equality_four_cpp(Wit_vals,y,z);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
