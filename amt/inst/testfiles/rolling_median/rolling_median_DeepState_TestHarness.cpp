#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector rolling_median(NumericVector x, int win);
TEST(amt_deepstate_test,rolling_median_test){
std::ofstream  x_stream;
std::ofstream  win_stream;
 RInside();
 NumericVector x = RcppDeepState_NumericVector ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/rolling_median/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 int win = RcppDeepState_int ();
  win_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/rolling_median/inputs/ win");
 win_stream<< win;
std::cout <<"win values: "<< win << std::endl;
 win_stream.close();
 std::cout << "input ends" << std::endl;
 try{
rolling_median( x, win);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
