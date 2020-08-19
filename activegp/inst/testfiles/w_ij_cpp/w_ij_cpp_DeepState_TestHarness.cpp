#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double w_ij_cpp(double a, double b, double t, int ct);
TEST(activegp_deepstate_test,w_ij_cpp_test){
std::ofstream  a_stream;
std::ofstream  b_stream;
std::ofstream  t_stream;
std::ofstream  ct_stream;
 RInside();
 double a = RcppDeepState_double ();
  a_stream.open("/home/akhila/Documents/compileAttributescheck/activegp/inst/testfiles/w_ij_cpp/inputs/ a");
 a_stream<< a;
std::cout <<"a values: "<< a << std::endl;
 a_stream.close();
 double b = RcppDeepState_double ();
  b_stream.open("/home/akhila/Documents/compileAttributescheck/activegp/inst/testfiles/w_ij_cpp/inputs/ b");
 b_stream<< b;
std::cout <<"b values: "<< b << std::endl;
 b_stream.close();
 double t = RcppDeepState_double ();
  t_stream.open("/home/akhila/Documents/compileAttributescheck/activegp/inst/testfiles/w_ij_cpp/inputs/ t");
 t_stream<< t;
std::cout <<"t values: "<< t << std::endl;
 t_stream.close();
 int ct = RcppDeepState_int ();
  ct_stream.open("/home/akhila/Documents/compileAttributescheck/activegp/inst/testfiles/w_ij_cpp/inputs/ ct");
 ct_stream<< ct;
std::cout <<"ct values: "<< ct << std::endl;
 ct_stream.close();
 try{
w_ij_cpp( a, b, t, ct);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
