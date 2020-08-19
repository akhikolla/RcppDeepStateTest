#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector apply_minlplus_cpp(NumericMatrix s, int y1, int y2, int n1, int n2, double mu_beta, double sigma_beta, double mu_psi, double sigma_psi);
TEST(abtest_deepstate_test,apply_minlplus_cpp_test){
std::ofstream  s_stream;
std::ofstream  y1_stream;
std::ofstream  y2_stream;
std::ofstream  n1_stream;
std::ofstream  n2_stream;
std::ofstream  mu_beta_stream;
std::ofstream  sigma_beta_stream;
std::ofstream  mu_psi_stream;
std::ofstream  sigma_psi_stream;
 RInside();
 NumericMatrix s = RcppDeepState_NumericMatrix ();
  s_stream.open("/home/akhila/Documents/compileAttributescheck/abtest/inst/testfiles/apply_minlplus_cpp/inputs/ s");
 s_stream<< s;
std::cout <<"s values: "<< s << std::endl;
 s_stream.close();
 int y1 = RcppDeepState_int ();
  y1_stream.open("/home/akhila/Documents/compileAttributescheck/abtest/inst/testfiles/apply_minlplus_cpp/inputs/ y1");
 y1_stream<< y1;
std::cout <<"y1 values: "<< y1 << std::endl;
 y1_stream.close();
 int y2 = RcppDeepState_int ();
  y2_stream.open("/home/akhila/Documents/compileAttributescheck/abtest/inst/testfiles/apply_minlplus_cpp/inputs/ y2");
 y2_stream<< y2;
std::cout <<"y2 values: "<< y2 << std::endl;
 y2_stream.close();
 int n1 = RcppDeepState_int ();
  n1_stream.open("/home/akhila/Documents/compileAttributescheck/abtest/inst/testfiles/apply_minlplus_cpp/inputs/ n1");
 n1_stream<< n1;
std::cout <<"n1 values: "<< n1 << std::endl;
 n1_stream.close();
 int n2 = RcppDeepState_int ();
  n2_stream.open("/home/akhila/Documents/compileAttributescheck/abtest/inst/testfiles/apply_minlplus_cpp/inputs/ n2");
 n2_stream<< n2;
std::cout <<"n2 values: "<< n2 << std::endl;
 n2_stream.close();
 double mu_beta = RcppDeepState_double ();
  mu_beta_stream.open("/home/akhila/Documents/compileAttributescheck/abtest/inst/testfiles/apply_minlplus_cpp/inputs/ mu_beta");
 mu_beta_stream<< mu_beta;
std::cout <<"mu_beta values: "<< mu_beta << std::endl;
 mu_beta_stream.close();
 double sigma_beta = RcppDeepState_double ();
  sigma_beta_stream.open("/home/akhila/Documents/compileAttributescheck/abtest/inst/testfiles/apply_minlplus_cpp/inputs/ sigma_beta");
 sigma_beta_stream<< sigma_beta;
std::cout <<"sigma_beta values: "<< sigma_beta << std::endl;
 sigma_beta_stream.close();
 double mu_psi = RcppDeepState_double ();
  mu_psi_stream.open("/home/akhila/Documents/compileAttributescheck/abtest/inst/testfiles/apply_minlplus_cpp/inputs/ mu_psi");
 mu_psi_stream<< mu_psi;
std::cout <<"mu_psi values: "<< mu_psi << std::endl;
 mu_psi_stream.close();
 double sigma_psi = RcppDeepState_double ();
  sigma_psi_stream.open("/home/akhila/Documents/compileAttributescheck/abtest/inst/testfiles/apply_minlplus_cpp/inputs/ sigma_psi");
 sigma_psi_stream<< sigma_psi;
std::cout <<"sigma_psi values: "<< sigma_psi << std::endl;
 sigma_psi_stream.close();
 try{
apply_minlplus_cpp( s, y1, y2, n1, n2, mu_beta, sigma_beta, mu_psi, sigma_psi);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
