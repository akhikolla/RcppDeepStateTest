#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double gc_all(IntegerVector cc, double a);
TEST(BNSL_deepstate_test,gc_all_test){
std::ofstream  cc_stream;
std::ofstream  a_stream;
RInside();
std::cout << "input starts" << std::endl;
 IntegerVector cc = RcppDeepState_IntegerVector ();
  cc_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/gc_all/inputs/ cc");
 cc_stream<< cc;
std::cout <<"cc values: "<< cc << std::endl;
 cc_stream.close();
 double a = RcppDeepState_double ();
  a_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/gc_all/inputs/ a");
 a_stream<< a;
std::cout <<"a values: "<< a << std::endl;
 a_stream.close();
 std::cout << "input ends" << std::endl;
 try{
gc_all( cc, a);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
