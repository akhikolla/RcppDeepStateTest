#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double vsb(NumericVector probs, NumericVector ys, NumericMatrix xs);
TEST(BalancedSampling_deepstate_test,vsb_test){
std::ofstream  probs_stream;
std::ofstream  ys_stream;
std::ofstream  xs_stream;
 RInside();
 NumericVector probs = RcppDeepState_NumericVector ();
  probs_stream.open("/home/akhila/Documents/compileAttributescheck/BalancedSampling/inst/testfiles/vsb/inputs/ probs");
 probs_stream<< probs;
std::cout <<"probs values: "<< probs << std::endl;
 probs_stream.close();
 NumericVector ys = RcppDeepState_NumericVector ();
  ys_stream.open("/home/akhila/Documents/compileAttributescheck/BalancedSampling/inst/testfiles/vsb/inputs/ ys");
 ys_stream<< ys;
std::cout <<"ys values: "<< ys << std::endl;
 ys_stream.close();
 NumericMatrix xs = RcppDeepState_NumericMatrix ();
  xs_stream.open("/home/akhila/Documents/compileAttributescheck/BalancedSampling/inst/testfiles/vsb/inputs/ xs");
 xs_stream<< xs;
std::cout <<"xs values: "<< xs << std::endl;
 xs_stream.close();
 std::cout << "input ends" << std::endl;
 try{
vsb( probs, ys, xs);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
