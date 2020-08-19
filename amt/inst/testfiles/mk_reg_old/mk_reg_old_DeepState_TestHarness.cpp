#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector mk_reg_old(NumericVector relocs_time, int time_dist, int time_tol, int start);
TEST(amt_deepstate_test,mk_reg_old_test){
std::ofstream  relocs_time_stream;
std::ofstream  time_dist_stream;
std::ofstream  time_tol_stream;
std::ofstream  start_stream;
 RInside();
 NumericVector relocs_time = RcppDeepState_NumericVector ();
  relocs_time_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/mk_reg_old/inputs/ relocs_time");
 relocs_time_stream<< relocs_time;
std::cout <<"relocs_time values: "<< relocs_time << std::endl;
 relocs_time_stream.close();
 int time_dist = RcppDeepState_int ();
  time_dist_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/mk_reg_old/inputs/ time_dist");
 time_dist_stream<< time_dist;
std::cout <<"time_dist values: "<< time_dist << std::endl;
 time_dist_stream.close();
 int time_tol = RcppDeepState_int ();
  time_tol_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/mk_reg_old/inputs/ time_tol");
 time_tol_stream<< time_tol;
std::cout <<"time_tol values: "<< time_tol << std::endl;
 time_tol_stream.close();
 int start = RcppDeepState_int ();
  start_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/mk_reg_old/inputs/ start");
 start_stream<< start;
std::cout <<"start values: "<< start << std::endl;
 start_stream.close();
 std::cout << "input ends" << std::endl;
 try{
mk_reg_old( relocs_time, time_dist, time_tol, start);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
