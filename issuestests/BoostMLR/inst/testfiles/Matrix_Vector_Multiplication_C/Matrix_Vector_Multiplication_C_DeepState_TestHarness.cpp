#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector Matrix_Vector_Multiplication_C(NumericVector x, arma::mat y);

TEST(BoostMLR_deepstate_test,Matrix_Vector_Multiplication_C_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BoostMLR/inst/testfiles/Matrix_Vector_Multiplication_C/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  std::ofstream y_stream;
  arma::mat y  = RcppDeepState_mat();
  y_stream.open("/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BoostMLR/inst/testfiles/Matrix_Vector_Multiplication_C/inputs/y");
  y_stream << y;
  std::cout << "y values: "<< y << std::endl;
  y_stream.close();
  std::cout << "input ends" << std::endl;
  try{
    Matrix_Vector_Multiplication_C(x,y);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
