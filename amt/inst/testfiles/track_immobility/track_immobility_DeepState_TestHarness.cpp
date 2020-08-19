#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector track_immobility(NumericVector t, NumericVector x, NumericVector y, double period, double tol);
TEST(amt_deepstate_test,track_immobility_test){
std::ofstream  t_stream;
std::ofstream  x_stream;
std::ofstream  y_stream;
std::ofstream  period_stream;
std::ofstream  tol_stream;
 RInside();
 NumericVector t = RcppDeepState_NumericVector ();
  t_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/track_immobility/inputs/ t");
 t_stream<< t;
std::cout <<"t values: "<< t << std::endl;
 t_stream.close();
 NumericVector x = RcppDeepState_NumericVector ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/track_immobility/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 NumericVector y = RcppDeepState_NumericVector ();
  y_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/track_immobility/inputs/ y");
 y_stream<< y;
std::cout <<"y values: "<< y << std::endl;
 y_stream.close();
 double period = RcppDeepState_double ();
  period_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/track_immobility/inputs/ period");
 period_stream<< period;
std::cout <<"period values: "<< period << std::endl;
 period_stream.close();
 double tol = RcppDeepState_double ();
  tol_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/track_immobility/inputs/ tol");
 tol_stream<< tol;
std::cout <<"tol values: "<< tol << std::endl;
 tol_stream.close();
 std::cout << "input ends" << std::endl;
 try{
track_immobility( t, x, y, period, tol);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
