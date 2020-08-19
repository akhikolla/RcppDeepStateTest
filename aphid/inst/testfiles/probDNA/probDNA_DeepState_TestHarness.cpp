#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double probDNA(int x, NumericVector probs);
TEST(aphid_deepstate_test,probDNA_test){
std::ofstream  x_stream;
std::ofstream  probs_stream;
 RInside();
 int x = RcppDeepState_int ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/probDNA/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 NumericVector probs = RcppDeepState_NumericVector ();
  probs_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/probDNA/inputs/ probs");
 probs_stream<< probs;
std::cout <<"probs values: "<< probs << std::endl;
 probs_stream.close();
 std::cout << "input ends" << std::endl;
 try{
probDNA( x, probs);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
