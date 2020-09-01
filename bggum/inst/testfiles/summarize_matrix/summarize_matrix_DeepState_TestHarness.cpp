#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericMatrix summarize_matrix(NumericMatrix x);
TEST(bggum_deepstate_test,summarize_matrix_test){
std::ofstream  x_stream;
RInside();
std::cout << "input starts" << std::endl;
 NumericMatrix x = RcppDeepState_NumericMatrix ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/bggum/inst/testfiles/summarize_matrix/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 std::cout << "input ends" << std::endl;
 try{
summarize_matrix( x);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
