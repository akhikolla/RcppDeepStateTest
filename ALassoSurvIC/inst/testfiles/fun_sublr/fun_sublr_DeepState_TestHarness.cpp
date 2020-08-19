#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 LogicalMatrix fun_sublr(NumericVector u, NumericVector l, NumericVector r);
TEST(ALassoSurvIC_deepstate_test,fun_sublr_test){
std::ofstream  u_stream;
std::ofstream  l_stream;
std::ofstream  r_stream;
 RInside();
 NumericVector u = RcppDeepState_NumericVector ();
  u_stream.open("/home/akhila/Documents/compileAttributescheck/ALassoSurvIC/inst/testfiles/fun_sublr/inputs/ u");
 u_stream<< u;
std::cout <<"u values: "<< u << std::endl;
 u_stream.close();
 NumericVector l = RcppDeepState_NumericVector ();
  l_stream.open("/home/akhila/Documents/compileAttributescheck/ALassoSurvIC/inst/testfiles/fun_sublr/inputs/ l");
 l_stream<< l;
std::cout <<"l values: "<< l << std::endl;
 l_stream.close();
 NumericVector r = RcppDeepState_NumericVector ();
  r_stream.open("/home/akhila/Documents/compileAttributescheck/ALassoSurvIC/inst/testfiles/fun_sublr/inputs/ r");
 r_stream<< r;
std::cout <<"r values: "<< r << std::endl;
 r_stream.close();
 try{
fun_sublr( u, l, r);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
