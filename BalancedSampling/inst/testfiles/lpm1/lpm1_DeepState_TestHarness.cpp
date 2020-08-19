#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector lpm1(NumericVector prob, NumericMatrix x);
TEST(BalancedSampling_deepstate_test,lpm1_test){
std::ofstream  prob_stream;
std::ofstream  x_stream;
 RInside();
 NumericVector prob = RcppDeepState_NumericVector ();
  prob_stream.open("/home/akhila/Documents/compileAttributescheck/BalancedSampling/inst/testfiles/lpm1/inputs/ prob");
 prob_stream<< prob;
std::cout <<"prob values: "<< prob << std::endl;
 prob_stream.close();
 NumericMatrix x = RcppDeepState_NumericMatrix ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/BalancedSampling/inst/testfiles/lpm1/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 std::cout << "input ends" << std::endl;
 try{
lpm1( prob, x);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
