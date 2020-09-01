#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 arma::mat remove_col(arma::mat x, int index);
TEST(BGGM_deepstate_test,remove_col_test){
std::ofstream  x_stream;
std::ofstream  index_stream;
RInside();
std::cout << "input starts" << std::endl;
 arma::mat x = RcppDeepState_mat ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/BGGM/inst/testfiles/remove_col/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 int index = RcppDeepState_int ();
  index_stream.open("/home/akhila/Documents/compileAttributescheck/BGGM/inst/testfiles/remove_col/inputs/ index");
 index_stream<< index;
std::cout <<"index values: "<< index << std::endl;
 index_stream.close();
 std::cout << "input ends" << std::endl;
 try{
remove_col( x, index);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
