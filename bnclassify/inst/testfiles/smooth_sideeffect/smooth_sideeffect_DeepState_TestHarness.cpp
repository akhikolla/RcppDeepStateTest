#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector smooth_sideeffect(NumericVector ctgt, double smooth);
TEST(bnclassify_deepstate_test,smooth_sideeffect_test){
std::ofstream  ctgt_stream;
std::ofstream  smooth_stream;
RInside();
std::cout << "input starts" << std::endl;
 NumericVector ctgt = RcppDeepState_NumericVector ();
  ctgt_stream.open("/home/akhila/Documents/compileAttributescheck/bnclassify/inst/testfiles/smooth_sideeffect/inputs/ ctgt");
 ctgt_stream<< ctgt;
std::cout <<"ctgt values: "<< ctgt << std::endl;
 ctgt_stream.close();
 double smooth = RcppDeepState_double ();
  smooth_stream.open("/home/akhila/Documents/compileAttributescheck/bnclassify/inst/testfiles/smooth_sideeffect/inputs/ smooth");
 smooth_stream<< smooth;
std::cout <<"smooth values: "<< smooth << std::endl;
 smooth_stream.close();
 std::cout << "input ends" << std::endl;
 try{
smooth_sideeffect( ctgt, smooth);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
