#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector get_gnp(NumericVector nodes_at_depth, int grow_node);
TEST(bartBMA_deepstate_test,get_gnp_test){
std::ofstream  nodes_at_depth_stream;
std::ofstream  grow_node_stream;
 RInside();
 NumericVector nodes_at_depth = RcppDeepState_NumericVector ();
  nodes_at_depth_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/get_gnp/inputs/ nodes_at_depth");
 nodes_at_depth_stream<< nodes_at_depth;
std::cout <<"nodes_at_depth values: "<< nodes_at_depth << std::endl;
 nodes_at_depth_stream.close();
 int grow_node = RcppDeepState_int ();
  grow_node_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/get_gnp/inputs/ grow_node");
 grow_node_stream<< grow_node;
std::cout <<"grow_node values: "<< grow_node << std::endl;
 grow_node_stream.close();
 std::cout << "input ends" << std::endl;
 try{
get_gnp( nodes_at_depth, grow_node);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
