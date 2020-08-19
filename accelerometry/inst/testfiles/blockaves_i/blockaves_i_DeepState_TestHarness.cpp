#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector blockaves_i(IntegerVector x, int window);
TEST(accelerometry_deepstate_test,blockaves_i_test){
std::ofstream  x_stream;
std::ofstream  window_stream;
 RInside();
 IntegerVector x = RcppDeepState_IntegerVector ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/accelerometry/inst/testfiles/blockaves_i/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 int window = RcppDeepState_int ();
  window_stream.open("/home/akhila/Documents/compileAttributescheck/accelerometry/inst/testfiles/blockaves_i/inputs/ window");
 window_stream<< window;
std::cout <<"window values: "<< window << std::endl;
 window_stream.close();
 try{
blockaves_i( x, window);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
