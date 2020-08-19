#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericMatrix start_matrix(int n);
TEST(bartBMA_deepstate_test,start_matrix_test){
std::ofstream  n_stream;
 RInside();
 int n = RcppDeepState_int ();
  n_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/start_matrix/inputs/ n");
 n_stream<< n;
std::cout <<"n values: "<< n << std::endl;
 n_stream.close();
 std::cout << "input ends" << std::endl;
 try{
start_matrix( n);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
