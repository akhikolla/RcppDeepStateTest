#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericMatrix remove_curr_col(NumericMatrix predy, int i);
TEST(bartBMA_deepstate_test,remove_curr_col_test){
std::ofstream  predy_stream;
std::ofstream  i_stream;
 RInside();
 NumericMatrix predy = RcppDeepState_NumericMatrix ();
  predy_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/remove_curr_col/inputs/ predy");
 predy_stream<< predy;
std::cout <<"predy values: "<< predy << std::endl;
 predy_stream.close();
 int i = RcppDeepState_int ();
  i_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/remove_curr_col/inputs/ i");
 i_stream<< i;
std::cout <<"i values: "<< i << std::endl;
 i_stream.close();
 std::cout << "input ends" << std::endl;
 try{
remove_curr_col( predy, i);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
