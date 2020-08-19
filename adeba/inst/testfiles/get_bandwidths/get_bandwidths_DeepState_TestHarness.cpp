#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericMatrix get_bandwidths(NumericVector pilot, NumericVector alpha, NumericVector beta);
TEST(adeba_deepstate_test,get_bandwidths_test){
std::ofstream  pilot_stream;
std::ofstream  alpha_stream;
std::ofstream  beta_stream;
 RInside();
 NumericVector pilot = RcppDeepState_NumericVector ();
  pilot_stream.open("/home/akhila/Documents/compileAttributescheck/adeba/inst/testfiles/get_bandwidths/inputs/ pilot");
 pilot_stream<< pilot;
std::cout <<"pilot values: "<< pilot << std::endl;
 pilot_stream.close();
 NumericVector alpha = RcppDeepState_NumericVector ();
  alpha_stream.open("/home/akhila/Documents/compileAttributescheck/adeba/inst/testfiles/get_bandwidths/inputs/ alpha");
 alpha_stream<< alpha;
std::cout <<"alpha values: "<< alpha << std::endl;
 alpha_stream.close();
 NumericVector beta = RcppDeepState_NumericVector ();
  beta_stream.open("/home/akhila/Documents/compileAttributescheck/adeba/inst/testfiles/get_bandwidths/inputs/ beta");
 beta_stream<< beta;
std::cout <<"beta values: "<< beta << std::endl;
 beta_stream.close();
 try{
get_bandwidths( pilot, alpha, beta);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
