#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 IntegerMatrix kruskal(NumericMatrix W);
TEST(BNSL_deepstate_test,kruskal_test){
std::ofstream  W_stream;
RInside();
std::cout << "input starts" << std::endl;
 NumericMatrix W = RcppDeepState_NumericMatrix ();
  W_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/kruskal/inputs/ W");
 W_stream<< W;
std::cout <<"W values: "<< W << std::endl;
 W_stream.close();
 std::cout << "input ends" << std::endl;
 try{
kruskal( W);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
