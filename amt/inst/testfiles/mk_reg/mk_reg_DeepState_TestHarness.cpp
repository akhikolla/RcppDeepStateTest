#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector mk_reg(NumericVector t1, int time_dist, int time_tol, int start);
TEST(amt_deepstate_test,mk_reg_test){
std::ofstream  t1_stream;
std::ofstream  time_dist_stream;
std::ofstream  time_tol_stream;
std::ofstream  start_stream;
 RInside();
 NumericVector t1 = RcppDeepState_NumericVector ();
  t1_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/mk_reg/inputs/ t1");
 t1_stream<< t1;
std::cout <<"t1 values: "<< t1 << std::endl;
 t1_stream.close();
 int time_dist = RcppDeepState_int ();
  time_dist_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/mk_reg/inputs/ time_dist");
 time_dist_stream<< time_dist;
std::cout <<"time_dist values: "<< time_dist << std::endl;
 time_dist_stream.close();
 int time_tol = RcppDeepState_int ();
  time_tol_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/mk_reg/inputs/ time_tol");
 time_tol_stream<< time_tol;
std::cout <<"time_tol values: "<< time_tol << std::endl;
 time_tol_stream.close();
 int start = RcppDeepState_int ();
  start_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/mk_reg/inputs/ start");
 start_stream<< start;
std::cout <<"start values: "<< start << std::endl;
 start_stream.close();
 std::cout << "input ends" << std::endl;
 try{
mk_reg( t1, time_dist, time_tol, start);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
