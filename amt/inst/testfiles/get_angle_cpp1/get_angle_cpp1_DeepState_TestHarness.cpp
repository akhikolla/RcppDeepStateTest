#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector get_angle_cpp1(NumericMatrix xy, double dir);
TEST(amt_deepstate_test,get_angle_cpp1_test){
std::ofstream  xy_stream;
std::ofstream  dir_stream;
 RInside();
 NumericMatrix xy = RcppDeepState_NumericMatrix ();
  xy_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/get_angle_cpp1/inputs/ xy");
 xy_stream<< xy;
std::cout <<"xy values: "<< xy << std::endl;
 xy_stream.close();
 double dir = RcppDeepState_double ();
  dir_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/get_angle_cpp1/inputs/ dir");
 dir_stream<< dir;
std::cout <<"dir values: "<< dir << std::endl;
 dir_stream.close();
 std::cout << "input ends" << std::endl;
 try{
get_angle_cpp1( xy, dir);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
