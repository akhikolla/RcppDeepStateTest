#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 arma::mat RCPPinv(arma::mat M);
TEST(apollo_deepstate_test,RCPPinv_test){
std::ofstream  M_stream;
 RInside();
 arma::mat M = RcppDeepState_mat ();
  M_stream.open("/home/akhila/Documents/compileAttributescheck/apollo/inst/testfiles/RCPPinv/inputs/ M");
 M_stream<< M;
std::cout <<"M values: "<< M << std::endl;
 M_stream.close();
 std::cout << "input ends" << std::endl;
 try{
RCPPinv( M);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
