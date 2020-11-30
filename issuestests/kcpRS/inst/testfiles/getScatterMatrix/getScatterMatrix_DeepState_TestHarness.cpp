#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List getScatterMatrix(NumericMatrix II_, NumericMatrix X_, NumericMatrix H_);

TEST(kcpRS_deepstate_test,getScatterMatrix_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix II_  = RcppDeepState_NumericMatrix();
  qs::c_qsave(II_,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/kcpRS/inst/testfiles/getScatterMatrix/inputs/II_.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "II_ values: "<< II_ << std::endl;
  NumericMatrix X_  = RcppDeepState_NumericMatrix();
  qs::c_qsave(X_,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/kcpRS/inst/testfiles/getScatterMatrix/inputs/X_.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X_ values: "<< X_ << std::endl;
  NumericMatrix H_  = RcppDeepState_NumericMatrix();
  qs::c_qsave(H_,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/kcpRS/inst/testfiles/getScatterMatrix/inputs/H_.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "H_ values: "<< H_ << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    getScatterMatrix(II_,X_,H_);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
