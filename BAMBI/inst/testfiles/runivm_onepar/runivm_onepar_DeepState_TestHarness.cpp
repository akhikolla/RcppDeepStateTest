#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 arma::vec runivm_onepar(int n, double k, double mu);
TEST(BAMBI_deepstate_test,runivm_onepar_test){
std::ofstream  n_stream;
std::ofstream  k_stream;
std::ofstream  mu_stream;
 RInside();
 int n = RcppDeepState_int ();
  n_stream.open("/home/akhila/Documents/compileAttributescheck/BAMBI/inst/testfiles/runivm_onepar/inputs/ n");
 n_stream<< n;
std::cout <<"n values: "<< n << std::endl;
 n_stream.close();
 double k = RcppDeepState_double ();
  k_stream.open("/home/akhila/Documents/compileAttributescheck/BAMBI/inst/testfiles/runivm_onepar/inputs/ k");
 k_stream<< k;
std::cout <<"k values: "<< k << std::endl;
 k_stream.close();
 double mu = RcppDeepState_double ();
  mu_stream.open("/home/akhila/Documents/compileAttributescheck/BAMBI/inst/testfiles/runivm_onepar/inputs/ mu");
 mu_stream<< mu;
std::cout <<"mu values: "<< mu << std::endl;
 mu_stream.close();
 std::cout << "input ends" << std::endl;
 try{
runivm_onepar( n, k, mu);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
