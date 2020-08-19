#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector zero2one(NumericVector samples);
TEST(AGread_deepstate_test,zero2one_test){
std::ofstream  samples_stream;
 RInside();
 NumericVector samples = RcppDeepState_NumericVector ();
  samples_stream.open("/home/akhila/Documents/compileAttributescheck/AGread/inst/testfiles/zero2one/inputs/ samples");
 samples_stream<< samples;
std::cout <<"samples values: "<< samples << std::endl;
 samples_stream.close();
 try{
zero2one( samples);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
