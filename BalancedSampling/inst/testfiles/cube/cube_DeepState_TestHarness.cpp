#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 IntegerVector cube(NumericVector prob, NumericMatrix Xbal);
TEST(BalancedSampling_deepstate_test,cube_test){
std::ofstream  prob_stream;
std::ofstream  Xbal_stream;
 RInside();
 NumericVector prob = RcppDeepState_NumericVector ();
  prob_stream.open("/home/akhila/Documents/compileAttributescheck/BalancedSampling/inst/testfiles/cube/inputs/ prob");
 prob_stream<< prob;
std::cout <<"prob values: "<< prob << std::endl;
 prob_stream.close();
 NumericMatrix Xbal = RcppDeepState_NumericMatrix ();
  Xbal_stream.open("/home/akhila/Documents/compileAttributescheck/BalancedSampling/inst/testfiles/cube/inputs/ Xbal");
 Xbal_stream<< Xbal;
std::cout <<"Xbal values: "<< Xbal << std::endl;
 Xbal_stream.close();
 std::cout << "input ends" << std::endl;
 try{
cube( prob, Xbal);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
