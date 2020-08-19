#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 int find_term_cols(NumericMatrix tree_matrix_temp, int terminal_node);
TEST(bartBMA_deepstate_test,find_term_cols_test){
std::ofstream  tree_matrix_temp_stream;
std::ofstream  terminal_node_stream;
 RInside();
 NumericMatrix tree_matrix_temp = RcppDeepState_NumericMatrix ();
  tree_matrix_temp_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/find_term_cols/inputs/ tree_matrix_temp");
 tree_matrix_temp_stream<< tree_matrix_temp;
std::cout <<"tree_matrix_temp values: "<< tree_matrix_temp << std::endl;
 tree_matrix_temp_stream.close();
 int terminal_node = RcppDeepState_int ();
  terminal_node_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/find_term_cols/inputs/ terminal_node");
 terminal_node_stream<< terminal_node;
std::cout <<"terminal_node values: "<< terminal_node << std::endl;
 terminal_node_stream.close();
 std::cout << "input ends" << std::endl;
 try{
find_term_cols( tree_matrix_temp, terminal_node);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
