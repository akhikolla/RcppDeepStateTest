#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 arma::mat RCPPZ(arma::mat S);
TEST(apollo_deepstate_test,RCPPZ_test){
std::ofstream  S_stream;
 RInside();
 arma::mat S = RcppDeepState_mat ();
  S_stream.open("/home/akhila/Documents/compileAttributescheck/apollo/inst/testfiles/RCPPZ/inputs/ S");
 S_stream<< S;
std::cout <<"S values: "<< S << std::endl;
 S_stream.close();
 std::cout << "input ends" << std::endl;
 try{
RCPPZ( S);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
