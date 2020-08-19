#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector latch_accel(int vector_size, NumericVector accel_input, int samp_rate);
TEST(AGread_deepstate_test,latch_accel_test){
std::ofstream  vector_size_stream;
std::ofstream  accel_input_stream;
std::ofstream  samp_rate_stream;
 RInside();
 int vector_size = RcppDeepState_int ();
  vector_size_stream.open("/home/akhila/Documents/compileAttributescheck/AGread/inst/testfiles/latch_accel/inputs/ vector_size");
 vector_size_stream<< vector_size;
std::cout <<"vector_size values: "<< vector_size << std::endl;
 vector_size_stream.close();
 NumericVector accel_input = RcppDeepState_NumericVector ();
  accel_input_stream.open("/home/akhila/Documents/compileAttributescheck/AGread/inst/testfiles/latch_accel/inputs/ accel_input");
 accel_input_stream<< accel_input;
std::cout <<"accel_input values: "<< accel_input << std::endl;
 accel_input_stream.close();
 int samp_rate = RcppDeepState_int ();
  samp_rate_stream.open("/home/akhila/Documents/compileAttributescheck/AGread/inst/testfiles/latch_accel/inputs/ samp_rate");
 samp_rate_stream<< samp_rate;
std::cout <<"samp_rate values: "<< samp_rate << std::endl;
 samp_rate_stream.close();
 try{
latch_accel( vector_size, accel_input, samp_rate);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
