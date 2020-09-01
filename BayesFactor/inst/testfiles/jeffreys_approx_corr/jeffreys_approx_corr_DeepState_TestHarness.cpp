#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double jeffreys_approx_corr(const double rho, const int n, const double r);
TEST(BayesFactor_deepstate_test,jeffreys_approx_corr_test){
std::ofstream  rho_stream;
std::ofstream  n_stream;
std::ofstream  r_stream;
RInside();
std::cout << "input starts" << std::endl;
  double rho = RcppDeepState_double ();
  rho_stream.open("/home/akhila/Documents/compileAttributescheck/BayesFactor/inst/testfiles/jeffreys_approx_corr/inputs/ rho");
 rho_stream<< rho;
std::cout <<"rho values: "<< rho << std::endl;
 rho_stream.close();
  int n = RcppDeepState_int ();
  n_stream.open("/home/akhila/Documents/compileAttributescheck/BayesFactor/inst/testfiles/jeffreys_approx_corr/inputs/ n");
 n_stream<< n;
std::cout <<"n values: "<< n << std::endl;
 n_stream.close();
  double r = RcppDeepState_double ();
  r_stream.open("/home/akhila/Documents/compileAttributescheck/BayesFactor/inst/testfiles/jeffreys_approx_corr/inputs/ r");
 r_stream<< r;
std::cout <<"r values: "<< r << std::endl;
 r_stream.close();
 std::cout << "input ends" << std::endl;
 try{
jeffreys_approx_corr( rho, n, r);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
