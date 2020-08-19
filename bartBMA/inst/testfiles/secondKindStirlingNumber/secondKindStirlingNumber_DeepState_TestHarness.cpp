#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double secondKindStirlingNumber(int n, int k);
TEST(bartBMA_deepstate_test,secondKindStirlingNumber_test){
std::ofstream  n_stream;
std::ofstream  k_stream;
 RInside();
 int n = RcppDeepState_int ();
  n_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/secondKindStirlingNumber/inputs/ n");
 n_stream<< n;
std::cout <<"n values: "<< n << std::endl;
 n_stream.close();
 int k = RcppDeepState_int ();
  k_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/secondKindStirlingNumber/inputs/ k");
 k_stream<< k;
std::cout <<"k values: "<< k << std::endl;
 k_stream.close();
 std::cout << "input ends" << std::endl;
 try{
secondKindStirlingNumber( n, k);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
