#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 arma::vec rowVars(arma::mat mat_in);
TEST(BAMBI_deepstate_test,rowVars_test){
std::ofstream  mat_in_stream;
 RInside();
 arma::mat mat_in = RcppDeepState_mat ();
  mat_in_stream.open("/home/akhila/Documents/compileAttributescheck/BAMBI/inst/testfiles/rowVars/inputs/ mat_in");
 mat_in_stream<< mat_in;
std::cout <<"mat_in values: "<< mat_in << std::endl;
 mat_in_stream.close();
 std::cout << "input ends" << std::endl;
 try{
rowVars( mat_in);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
