#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector interpolate_C(NumericVector original_samples, int target_frequency);
TEST(AGread_deepstate_test,interpolate_C_test){
std::ofstream  original_samples_stream;
std::ofstream  target_frequency_stream;
 RInside();
 NumericVector original_samples = RcppDeepState_NumericVector ();
  original_samples_stream.open("/home/akhila/Documents/compileAttributescheck/AGread/inst/testfiles/interpolate_C/inputs/ original_samples");
 original_samples_stream<< original_samples;
std::cout <<"original_samples values: "<< original_samples << std::endl;
 original_samples_stream.close();
 int target_frequency = RcppDeepState_int ();
  target_frequency_stream.open("/home/akhila/Documents/compileAttributescheck/AGread/inst/testfiles/interpolate_C/inputs/ target_frequency");
 target_frequency_stream<< target_frequency;
std::cout <<"target_frequency values: "<< target_frequency << std::endl;
 target_frequency_stream.close();
 try{
interpolate_C( original_samples, target_frequency);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
