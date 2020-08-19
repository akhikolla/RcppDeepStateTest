#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 LogicalMatrix fun_subless(NumericVector u, NumericVector lessthan);
TEST(ALassoSurvIC_deepstate_test,fun_subless_test){
std::ofstream  u_stream;
std::ofstream  lessthan_stream;
 RInside();
 NumericVector u = RcppDeepState_NumericVector ();
  u_stream.open("/home/akhila/Documents/compileAttributescheck/ALassoSurvIC/inst/testfiles/fun_subless/inputs/ u");
 u_stream<< u;
std::cout <<"u values: "<< u << std::endl;
 u_stream.close();
 NumericVector lessthan = RcppDeepState_NumericVector ();
  lessthan_stream.open("/home/akhila/Documents/compileAttributescheck/ALassoSurvIC/inst/testfiles/fun_subless/inputs/ lessthan");
 lessthan_stream<< lessthan;
std::cout <<"lessthan values: "<< lessthan << std::endl;
 lessthan_stream.close();
 try{
fun_subless( u, lessthan);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
