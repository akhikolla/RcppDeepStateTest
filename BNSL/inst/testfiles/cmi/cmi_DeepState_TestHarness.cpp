#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double cmi(NumericVector x, NumericVector y, NumericVector z, int proc);
TEST(BNSL_deepstate_test,cmi_test){
std::ofstream  x_stream;
std::ofstream  y_stream;
std::ofstream  z_stream;
std::ofstream  proc_stream;
RInside();
std::cout << "input starts" << std::endl;
 NumericVector x = RcppDeepState_NumericVector ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/cmi/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 NumericVector y = RcppDeepState_NumericVector ();
  y_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/cmi/inputs/ y");
 y_stream<< y;
std::cout <<"y values: "<< y << std::endl;
 y_stream.close();
 NumericVector z = RcppDeepState_NumericVector ();
  z_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/cmi/inputs/ z");
 z_stream<< z;
std::cout <<"z values: "<< z << std::endl;
 z_stream.close();
 int proc = RcppDeepState_int ();
  proc_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/cmi/inputs/ proc");
 proc_stream<< proc;
std::cout <<"proc values: "<< proc << std::endl;
 proc_stream.close();
 std::cout << "input ends" << std::endl;
 try{
cmi( x, y, z, proc);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
