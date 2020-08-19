#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericMatrix use_CANL(const NumericMatrix mat, const int N, const double w0, const double k, const double eps);
TEST(abcADM_deepstate_test,use_CANL_test){
std::ofstream  mat_stream;
std::ofstream  N_stream;
std::ofstream  w0_stream;
std::ofstream  k_stream;
std::ofstream  eps_stream;
 RInside();
  NumericMatrix mat = RcppDeepState_NumericMatrix ();
  mat_stream.open("/home/akhila/Documents/compileAttributescheck/abcADM/inst/testfiles/use_CANL/inputs/ mat");
 mat_stream<< mat;
std::cout <<"mat values: "<< mat << std::endl;
 mat_stream.close();
  int N = RcppDeepState_int ();
  N_stream.open("/home/akhila/Documents/compileAttributescheck/abcADM/inst/testfiles/use_CANL/inputs/ N");
 N_stream<< N;
std::cout <<"N values: "<< N << std::endl;
 N_stream.close();
  double w0 = RcppDeepState_double ();
  w0_stream.open("/home/akhila/Documents/compileAttributescheck/abcADM/inst/testfiles/use_CANL/inputs/ w0");
 w0_stream<< w0;
std::cout <<"w0 values: "<< w0 << std::endl;
 w0_stream.close();
  double k = RcppDeepState_double ();
  k_stream.open("/home/akhila/Documents/compileAttributescheck/abcADM/inst/testfiles/use_CANL/inputs/ k");
 k_stream<< k;
std::cout <<"k values: "<< k << std::endl;
 k_stream.close();
  double eps = RcppDeepState_double ();
  eps_stream.open("/home/akhila/Documents/compileAttributescheck/abcADM/inst/testfiles/use_CANL/inputs/ eps");
 eps_stream<< eps;
std::cout <<"eps values: "<< eps << std::endl;
 eps_stream.close();
 try{
use_CANL( mat, N, w0, k, eps);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
