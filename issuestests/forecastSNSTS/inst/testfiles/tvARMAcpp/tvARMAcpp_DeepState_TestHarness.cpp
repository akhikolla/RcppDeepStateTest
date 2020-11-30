#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector tvARMAcpp(NumericVector z, NumericVector x_init, NumericMatrix A, NumericMatrix B, NumericVector Sigma);

TEST(forecastSNSTS_deepstate_test,tvARMAcpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector z  = RcppDeepState_NumericVector();
  qs::c_qsave(z,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/tvARMAcpp/inputs/z.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  NumericVector x_init  = RcppDeepState_NumericVector();
  qs::c_qsave(x_init,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/tvARMAcpp/inputs/x_init.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x_init values: "<< x_init << std::endl;
  NumericMatrix A  = RcppDeepState_NumericMatrix();
  qs::c_qsave(A,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/tvARMAcpp/inputs/A.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "A values: "<< A << std::endl;
  NumericMatrix B  = RcppDeepState_NumericMatrix();
  qs::c_qsave(B,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/tvARMAcpp/inputs/B.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "B values: "<< B << std::endl;
  NumericVector Sigma  = RcppDeepState_NumericVector();
  qs::c_qsave(Sigma,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/tvARMAcpp/inputs/Sigma.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Sigma values: "<< Sigma << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    tvARMAcpp(z,x_init,A,B,Sigma);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
