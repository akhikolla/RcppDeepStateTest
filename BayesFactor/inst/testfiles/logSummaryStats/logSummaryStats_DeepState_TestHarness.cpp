#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 List logSummaryStats(NumericVector x);
TEST(BayesFactor_deepstate_test,logSummaryStats_test){
std::ofstream  x_stream;
RInside();
std::cout << "input starts" << std::endl;
 NumericVector x = RcppDeepState_NumericVector ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/BayesFactor/inst/testfiles/logSummaryStats/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 std::cout << "input ends" << std::endl;
 try{
logSummaryStats( x);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
