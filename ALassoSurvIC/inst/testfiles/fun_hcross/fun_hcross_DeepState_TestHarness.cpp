#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericMatrix fun_hcross(NumericMatrix x);
TEST(ALassoSurvIC_deepstate_test,fun_hcross_test){
std::ofstream  x_stream;
 RInside();
 NumericMatrix x = RcppDeepState_NumericMatrix ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/ALassoSurvIC/inst/testfiles/fun_hcross/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 try{
fun_hcross( x);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
