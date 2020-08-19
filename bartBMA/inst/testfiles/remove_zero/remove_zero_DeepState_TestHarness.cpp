#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector remove_zero(NumericVector nodes_at_depth);
TEST(bartBMA_deepstate_test,remove_zero_test){
std::ofstream  nodes_at_depth_stream;
 RInside();
 NumericVector nodes_at_depth = RcppDeepState_NumericVector ();
  nodes_at_depth_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/remove_zero/inputs/ nodes_at_depth");
 nodes_at_depth_stream<< nodes_at_depth;
std::cout <<"nodes_at_depth values: "<< nodes_at_depth << std::endl;
 nodes_at_depth_stream.close();
 std::cout << "input ends" << std::endl;
 try{
remove_zero( nodes_at_depth);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
