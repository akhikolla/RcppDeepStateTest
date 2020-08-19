#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 arma::mat matrixInverse(arma::mat S);
TEST(acc_deepstate_test,matrixInverse_test){
std::ofstream  S_stream;
 RInside();
 arma::mat S = RcppDeepState_mat ();
  S_stream.open("/home/akhila/Documents/compileAttributescheck/acc/inst/testfiles/matrixInverse/inputs/ S");
 S_stream<< S;
std::cout <<"S values: "<< S << std::endl;
 S_stream.close();
 try{
matrixInverse( S);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
