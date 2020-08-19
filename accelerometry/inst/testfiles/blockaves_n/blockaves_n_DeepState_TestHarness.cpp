#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector blockaves_n(NumericVector x, int window);
TEST(accelerometry_deepstate_test,blockaves_n_test){
std::ofstream  x_stream;
std::ofstream  window_stream;
 RInside();
 NumericVector x = RcppDeepState_NumericVector ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/accelerometry/inst/testfiles/blockaves_n/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 int window = RcppDeepState_int ();
  window_stream.open("/home/akhila/Documents/compileAttributescheck/accelerometry/inst/testfiles/blockaves_n/inputs/ window");
 window_stream<< window;
std::cout <<"window values: "<< window << std::endl;
 window_stream.close();
 try{
blockaves_n( x, window);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
