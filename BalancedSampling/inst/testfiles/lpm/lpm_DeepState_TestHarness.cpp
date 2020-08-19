#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector lpm(NumericVector prob, NumericMatrix x, int h);
TEST(BalancedSampling_deepstate_test,lpm_test){
std::ofstream  prob_stream;
std::ofstream  x_stream;
std::ofstream  h_stream;
 RInside();
 NumericVector prob = RcppDeepState_NumericVector ();
  prob_stream.open("/home/akhila/Documents/compileAttributescheck/BalancedSampling/inst/testfiles/lpm/inputs/ prob");
 prob_stream<< prob;
std::cout <<"prob values: "<< prob << std::endl;
 prob_stream.close();
 NumericMatrix x = RcppDeepState_NumericMatrix ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/BalancedSampling/inst/testfiles/lpm/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 int h = RcppDeepState_int ();
  h_stream.open("/home/akhila/Documents/compileAttributescheck/BalancedSampling/inst/testfiles/lpm/inputs/ h");
 h_stream<< h;
std::cout <<"h values: "<< h << std::endl;
 h_stream.close();
 std::cout << "input ends" << std::endl;
 try{
lpm( prob, x, h);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
