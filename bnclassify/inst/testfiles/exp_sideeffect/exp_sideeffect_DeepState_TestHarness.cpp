#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector exp_sideeffect(NumericVector p);
TEST(bnclassify_deepstate_test,exp_sideeffect_test){
std::ofstream  p_stream;
RInside();
std::cout << "input starts" << std::endl;
 NumericVector p = RcppDeepState_NumericVector ();
  p_stream.open("/home/akhila/Documents/compileAttributescheck/bnclassify/inst/testfiles/exp_sideeffect/inputs/ p");
 p_stream<< p;
std::cout <<"p values: "<< p << std::endl;
 p_stream.close();
 std::cout << "input ends" << std::endl;
 try{
exp_sideeffect( p);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
