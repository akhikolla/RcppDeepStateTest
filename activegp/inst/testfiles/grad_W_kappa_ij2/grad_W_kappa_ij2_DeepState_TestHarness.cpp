#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericMatrix grad_W_kappa_ij2(NumericVector design1, NumericMatrix design2, NumericVector theta, int i1, int i2, int ct);
TEST(activegp_deepstate_test,grad_W_kappa_ij2_test){
std::ofstream  design1_stream;
std::ofstream  design2_stream;
std::ofstream  theta_stream;
std::ofstream  i1_stream;
std::ofstream  i2_stream;
std::ofstream  ct_stream;
 RInside();
 NumericVector design1 = RcppDeepState_NumericVector ();
  design1_stream.open("/home/akhila/Documents/compileAttributescheck/activegp/inst/testfiles/grad_W_kappa_ij2/inputs/ design1");
 design1_stream<< design1;
std::cout <<"design1 values: "<< design1 << std::endl;
 design1_stream.close();
 NumericMatrix design2 = RcppDeepState_NumericMatrix ();
  design2_stream.open("/home/akhila/Documents/compileAttributescheck/activegp/inst/testfiles/grad_W_kappa_ij2/inputs/ design2");
 design2_stream<< design2;
std::cout <<"design2 values: "<< design2 << std::endl;
 design2_stream.close();
 NumericVector theta = RcppDeepState_NumericVector ();
  theta_stream.open("/home/akhila/Documents/compileAttributescheck/activegp/inst/testfiles/grad_W_kappa_ij2/inputs/ theta");
 theta_stream<< theta;
std::cout <<"theta values: "<< theta << std::endl;
 theta_stream.close();
 int i1 = RcppDeepState_int ();
  i1_stream.open("/home/akhila/Documents/compileAttributescheck/activegp/inst/testfiles/grad_W_kappa_ij2/inputs/ i1");
 i1_stream<< i1;
std::cout <<"i1 values: "<< i1 << std::endl;
 i1_stream.close();
 int i2 = RcppDeepState_int ();
  i2_stream.open("/home/akhila/Documents/compileAttributescheck/activegp/inst/testfiles/grad_W_kappa_ij2/inputs/ i2");
 i2_stream<< i2;
std::cout <<"i2 values: "<< i2 << std::endl;
 i2_stream.close();
 int ct = RcppDeepState_int ();
  ct_stream.open("/home/akhila/Documents/compileAttributescheck/activegp/inst/testfiles/grad_W_kappa_ij2/inputs/ ct");
 ct_stream<< ct;
std::cout <<"ct values: "<< ct << std::endl;
 ct_stream.close();
 try{
grad_W_kappa_ij2( design1, design2, theta, i1, i2, ct);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
