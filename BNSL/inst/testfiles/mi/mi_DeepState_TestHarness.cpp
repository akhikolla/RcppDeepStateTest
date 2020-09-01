#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double mi(NumericVector x, NumericVector y, int proc);
TEST(BNSL_deepstate_test,mi_test){
std::ofstream  x_stream;
std::ofstream  y_stream;
std::ofstream  proc_stream;
RInside();
std::cout << "input starts" << std::endl;
 NumericVector x = RcppDeepState_NumericVector ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/mi/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 NumericVector y = RcppDeepState_NumericVector ();
  y_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/mi/inputs/ y");
 y_stream<< y;
std::cout <<"y values: "<< y << std::endl;
 y_stream.close();
 int proc = RcppDeepState_int ();
  proc_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/mi/inputs/ proc");
 proc_stream<< proc;
std::cout <<"proc values: "<< proc << std::endl;
 proc_stream.close();
 std::cout << "input ends" << std::endl;
 try{
mi( x, y, proc);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
