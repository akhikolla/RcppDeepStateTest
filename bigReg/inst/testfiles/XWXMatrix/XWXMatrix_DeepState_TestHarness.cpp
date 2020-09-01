#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 Rcpp::List XWXMatrix(arma::mat X, arma::mat y);
TEST(bigReg_deepstate_test,XWXMatrix_test){
std::ofstream  X_stream;
std::ofstream  y_stream;
RInside();
std::cout << "input starts" << std::endl;
 arma::mat X = RcppDeepState_mat ();
  X_stream.open("/home/akhila/Documents/compileAttributescheck/bigReg/inst/testfiles/XWXMatrix/inputs/ X");
 X_stream<< X;
std::cout <<"X values: "<< X << std::endl;
 X_stream.close();
 arma::mat y = RcppDeepState_mat ();
  y_stream.open("/home/akhila/Documents/compileAttributescheck/bigReg/inst/testfiles/XWXMatrix/inputs/ y");
 y_stream<< y;
std::cout <<"y values: "<< y << std::endl;
 y_stream.close();
 std::cout << "input ends" << std::endl;
 try{
XWXMatrix( X, y);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
