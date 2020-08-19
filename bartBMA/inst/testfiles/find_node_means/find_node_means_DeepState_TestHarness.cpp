#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector find_node_means(NumericMatrix sum_tree, NumericVector term_nodes);
TEST(bartBMA_deepstate_test,find_node_means_test){
std::ofstream  sum_tree_stream;
std::ofstream  term_nodes_stream;
 RInside();
 NumericMatrix sum_tree = RcppDeepState_NumericMatrix ();
  sum_tree_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/find_node_means/inputs/ sum_tree");
 sum_tree_stream<< sum_tree;
std::cout <<"sum_tree values: "<< sum_tree << std::endl;
 sum_tree_stream.close();
 NumericVector term_nodes = RcppDeepState_NumericVector ();
  term_nodes_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/find_node_means/inputs/ term_nodes");
 term_nodes_stream<< term_nodes;
std::cout <<"term_nodes values: "<< term_nodes << std::endl;
 term_nodes_stream.close();
 std::cout << "input ends" << std::endl;
 try{
find_node_means( sum_tree, term_nodes);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
