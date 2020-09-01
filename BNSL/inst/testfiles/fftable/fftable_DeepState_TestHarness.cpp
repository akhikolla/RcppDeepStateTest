#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 IntegerMatrix fftable(NumericMatrix df, int w);
TEST(BNSL_deepstate_test,fftable_test){
std::ofstream  df_stream;
std::ofstream  w_stream;
RInside();
std::cout << "input starts" << std::endl;
 NumericMatrix df = RcppDeepState_NumericMatrix ();
  df_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/fftable/inputs/ df");
 df_stream<< df;
std::cout <<"df values: "<< df << std::endl;
 df_stream.close();
 int w = RcppDeepState_int ();
  w_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/fftable/inputs/ w");
 w_stream<< w;
std::cout <<"w values: "<< w << std::endl;
 w_stream.close();
 std::cout << "input ends" << std::endl;
 try{
fftable( df, w);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
