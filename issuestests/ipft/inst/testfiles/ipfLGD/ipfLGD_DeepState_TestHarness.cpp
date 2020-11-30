#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix ipfLGD(NumericMatrix train, NumericMatrix test, double sd, double epsilon);

TEST(ipft_deepstate_test,ipfLGD_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix train  = RcppDeepState_NumericMatrix();
  qs::c_qsave(train,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ipft/inst/testfiles/ipfLGD/inputs/train.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "train values: "<< train << std::endl;
  NumericMatrix test  = RcppDeepState_NumericMatrix();
  qs::c_qsave(test,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ipft/inst/testfiles/ipfLGD/inputs/test.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "test values: "<< test << std::endl;
  NumericVector sd(1);
  sd[0]  = RcppDeepState_double();
  qs::c_qsave(sd,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ipft/inst/testfiles/ipfLGD/inputs/sd.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sd values: "<< sd << std::endl;
  NumericVector epsilon(1);
  epsilon[0]  = RcppDeepState_double();
  qs::c_qsave(epsilon,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ipft/inst/testfiles/ipfLGD/inputs/epsilon.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "epsilon values: "<< epsilon << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ipfLGD(train,test,sd[0],epsilon[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
