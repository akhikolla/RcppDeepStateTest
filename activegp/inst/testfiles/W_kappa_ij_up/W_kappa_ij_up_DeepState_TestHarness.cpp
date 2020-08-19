#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 void W_kappa_ij_up(NumericMatrix W, NumericMatrix design, NumericVector theta, int i1, int i2, int start, int ct);
TEST(activegp_deepstate_test,W_kappa_ij_up_test){
std::ofstream  W_stream;
std::ofstream  design_stream;
std::ofstream  theta_stream;
std::ofstream  i1_stream;
std::ofstream  i2_stream;
std::ofstream  start_stream;
std::ofstream  ct_stream;
 RInside();
 NumericMatrix W = RcppDeepState_NumericMatrix ();
  W_stream.open("/home/akhila/Documents/compileAttributescheck/activegp/inst/testfiles/W_kappa_ij_up/inputs/ W");
 W_stream<< W;
std::cout <<"W values: "<< W << std::endl;
 W_stream.close();
 NumericMatrix design = RcppDeepState_NumericMatrix ();
  design_stream.open("/home/akhila/Documents/compileAttributescheck/activegp/inst/testfiles/W_kappa_ij_up/inputs/ design");
 design_stream<< design;
std::cout <<"design values: "<< design << std::endl;
 design_stream.close();
 NumericVector theta = RcppDeepState_NumericVector ();
  theta_stream.open("/home/akhila/Documents/compileAttributescheck/activegp/inst/testfiles/W_kappa_ij_up/inputs/ theta");
 theta_stream<< theta;
std::cout <<"theta values: "<< theta << std::endl;
 theta_stream.close();
 int i1 = RcppDeepState_int ();
  i1_stream.open("/home/akhila/Documents/compileAttributescheck/activegp/inst/testfiles/W_kappa_ij_up/inputs/ i1");
 i1_stream<< i1;
std::cout <<"i1 values: "<< i1 << std::endl;
 i1_stream.close();
 int i2 = RcppDeepState_int ();
  i2_stream.open("/home/akhila/Documents/compileAttributescheck/activegp/inst/testfiles/W_kappa_ij_up/inputs/ i2");
 i2_stream<< i2;
std::cout <<"i2 values: "<< i2 << std::endl;
 i2_stream.close();
 int start = RcppDeepState_int ();
  start_stream.open("/home/akhila/Documents/compileAttributescheck/activegp/inst/testfiles/W_kappa_ij_up/inputs/ start");
 start_stream<< start;
std::cout <<"start values: "<< start << std::endl;
 start_stream.close();
 int ct = RcppDeepState_int ();
  ct_stream.open("/home/akhila/Documents/compileAttributescheck/activegp/inst/testfiles/W_kappa_ij_up/inputs/ ct");
 ct_stream<< ct;
std::cout <<"ct values: "<< ct << std::endl;
 ct_stream.close();
 try{
W_kappa_ij_up( W, design, theta, i1, i2, start, ct);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
