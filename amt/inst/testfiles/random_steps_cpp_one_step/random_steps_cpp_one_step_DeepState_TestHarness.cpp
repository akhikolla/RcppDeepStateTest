#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericMatrix random_steps_cpp_one_step(const int n_rand_steps, const double start_x, const double start_y, const double rel_angle, const NumericVector rand_sl, const NumericVector rand_ta);
TEST(amt_deepstate_test,random_steps_cpp_one_step_test){
std::ofstream  n_rand_steps_stream;
std::ofstream  start_x_stream;
std::ofstream  start_y_stream;
std::ofstream  rel_angle_stream;
std::ofstream  rand_sl_stream;
std::ofstream  rand_ta_stream;
 RInside();
  int n_rand_steps = RcppDeepState_int ();
  n_rand_steps_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/random_steps_cpp_one_step/inputs/ n_rand_steps");
 n_rand_steps_stream<< n_rand_steps;
std::cout <<"n_rand_steps values: "<< n_rand_steps << std::endl;
 n_rand_steps_stream.close();
  double start_x = RcppDeepState_double ();
  start_x_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/random_steps_cpp_one_step/inputs/ start_x");
 start_x_stream<< start_x;
std::cout <<"start_x values: "<< start_x << std::endl;
 start_x_stream.close();
  double start_y = RcppDeepState_double ();
  start_y_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/random_steps_cpp_one_step/inputs/ start_y");
 start_y_stream<< start_y;
std::cout <<"start_y values: "<< start_y << std::endl;
 start_y_stream.close();
  double rel_angle = RcppDeepState_double ();
  rel_angle_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/random_steps_cpp_one_step/inputs/ rel_angle");
 rel_angle_stream<< rel_angle;
std::cout <<"rel_angle values: "<< rel_angle << std::endl;
 rel_angle_stream.close();
  NumericVector rand_sl = RcppDeepState_NumericVector ();
  rand_sl_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/random_steps_cpp_one_step/inputs/ rand_sl");
 rand_sl_stream<< rand_sl;
std::cout <<"rand_sl values: "<< rand_sl << std::endl;
 rand_sl_stream.close();
  NumericVector rand_ta = RcppDeepState_NumericVector ();
  rand_ta_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/random_steps_cpp_one_step/inputs/ rand_ta");
 rand_ta_stream<< rand_ta;
std::cout <<"rand_ta values: "<< rand_ta << std::endl;
 rand_ta_stream.close();
 std::cout << "input ends" << std::endl;
 try{
random_steps_cpp_one_step( n_rand_steps, start_x, start_y, rel_angle, rand_sl, rand_ta);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
