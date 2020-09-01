#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 arma::mat remove_row(arma::mat x, int which);
TEST(BGGM_deepstate_test,remove_row_test){
std::ofstream  x_stream;
std::ofstream  which_stream;
RInside();
std::cout << "input starts" << std::endl;
 arma::mat x = RcppDeepState_mat ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/BGGM/inst/testfiles/remove_row/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 int which = RcppDeepState_int ();
  which_stream.open("/home/akhila/Documents/compileAttributescheck/BGGM/inst/testfiles/remove_row/inputs/ which");
 which_stream<< which;
std::cout <<"which values: "<< which << std::endl;
 which_stream.close();
 std::cout << "input ends" << std::endl;
 try{
remove_row( x, which);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
