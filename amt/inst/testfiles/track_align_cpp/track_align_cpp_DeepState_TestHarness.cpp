#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector track_align_cpp(IntegerVector t1, IntegerVector nt, int time_tol, int type);
TEST(amt_deepstate_test,track_align_cpp_test){
std::ofstream  t1_stream;
std::ofstream  nt_stream;
std::ofstream  time_tol_stream;
std::ofstream  type_stream;
 RInside();
 IntegerVector t1 = RcppDeepState_IntegerVector ();
  t1_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/track_align_cpp/inputs/ t1");
 t1_stream<< t1;
std::cout <<"t1 values: "<< t1 << std::endl;
 t1_stream.close();
 IntegerVector nt = RcppDeepState_IntegerVector ();
  nt_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/track_align_cpp/inputs/ nt");
 nt_stream<< nt;
std::cout <<"nt values: "<< nt << std::endl;
 nt_stream.close();
 int time_tol = RcppDeepState_int ();
  time_tol_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/track_align_cpp/inputs/ time_tol");
 time_tol_stream<< time_tol;
std::cout <<"time_tol values: "<< time_tol << std::endl;
 time_tol_stream.close();
 int type = RcppDeepState_int ();
  type_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/track_align_cpp/inputs/ type");
 type_stream<< type;
std::cout <<"type values: "<< type << std::endl;
 type_stream.close();
 std::cout << "input ends" << std::endl;
 try{
track_align_cpp( t1, nt, time_tol, type);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
