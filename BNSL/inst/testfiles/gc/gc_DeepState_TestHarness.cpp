#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double gc(int n, double a);
TEST(BNSL_deepstate_test,gc_test){
std::ofstream  n_stream;
std::ofstream  a_stream;
RInside();
std::cout << "input starts" << std::endl;
 int n = RcppDeepState_int ();
  n_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/gc/inputs/ n");
 n_stream<< n;
std::cout <<"n values: "<< n << std::endl;
 n_stream.close();
 double a = RcppDeepState_double ();
  a_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/gc/inputs/ a");
 a_stream<< a;
std::cout <<"a values: "<< a << std::endl;
 a_stream.close();
 std::cout << "input ends" << std::endl;
 try{
gc( n, a);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
