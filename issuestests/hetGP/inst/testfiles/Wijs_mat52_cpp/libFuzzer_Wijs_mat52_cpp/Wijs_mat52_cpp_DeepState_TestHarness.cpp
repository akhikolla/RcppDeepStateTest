#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix Wijs_mat52_cpp(NumericMatrix Mu1, NumericMatrix Mu2, NumericVector sigma);

TEST(hetGP_deepstate_test,Wijs_mat52_cpp_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix Mu1  = RcppDeepState_NumericMatrix();
  std::string Mu1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/Wijs_mat52_cpp/libFuzzer_Wijs_mat52_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Mu1.qs";
  qs::c_qsave(Mu1,Mu1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Mu1 values: "<< Mu1 << std::endl;
  NumericMatrix Mu2  = RcppDeepState_NumericMatrix();
  std::string Mu2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/Wijs_mat52_cpp/libFuzzer_Wijs_mat52_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Mu2.qs";
  qs::c_qsave(Mu2,Mu2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Mu2 values: "<< Mu2 << std::endl;
  NumericVector sigma  = RcppDeepState_NumericVector();
  std::string sigma_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hetGP/inst/testfiles/Wijs_mat52_cpp/libFuzzer_Wijs_mat52_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_sigma.qs";
  qs::c_qsave(sigma,sigma_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sigma values: "<< sigma << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    Wijs_mat52_cpp(Mu1,Mu2,sigma);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
