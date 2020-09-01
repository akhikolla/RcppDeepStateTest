#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector aster_cpp(NumericMatrix matrix, int tree_width, int proc, double s, int n, int ss);
TEST(BNSL_deepstate_test,aster_cpp_test){
std::ofstream  matrix_stream;
std::ofstream  tree_width_stream;
std::ofstream  proc_stream;
std::ofstream  s_stream;
std::ofstream  n_stream;
std::ofstream  ss_stream;
RInside();
std::cout << "input starts" << std::endl;
 NumericMatrix matrix = RcppDeepState_NumericMatrix ();
  matrix_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/aster_cpp/inputs/ matrix");
 matrix_stream<< matrix;
std::cout <<"matrix values: "<< matrix << std::endl;
 matrix_stream.close();
 int tree_width = RcppDeepState_int ();
  tree_width_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/aster_cpp/inputs/ tree_width");
 tree_width_stream<< tree_width;
std::cout <<"tree_width values: "<< tree_width << std::endl;
 tree_width_stream.close();
 int proc = RcppDeepState_int ();
  proc_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/aster_cpp/inputs/ proc");
 proc_stream<< proc;
std::cout <<"proc values: "<< proc << std::endl;
 proc_stream.close();
 double s = RcppDeepState_double ();
  s_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/aster_cpp/inputs/ s");
 s_stream<< s;
std::cout <<"s values: "<< s << std::endl;
 s_stream.close();
 int n = RcppDeepState_int ();
  n_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/aster_cpp/inputs/ n");
 n_stream<< n;
std::cout <<"n values: "<< n << std::endl;
 n_stream.close();
 int ss = RcppDeepState_int ();
  ss_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/aster_cpp/inputs/ ss");
 ss_stream<< ss;
std::cout <<"ss values: "<< ss << std::endl;
 ss_stream.close();
 std::cout << "input ends" << std::endl;
 try{
aster_cpp( matrix, tree_width, proc, s, n, ss);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
