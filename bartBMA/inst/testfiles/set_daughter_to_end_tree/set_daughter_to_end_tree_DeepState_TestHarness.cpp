#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericMatrix set_daughter_to_end_tree(int grow_node, NumericMatrix prior_tree_table_temp, double left_daughter);
TEST(bartBMA_deepstate_test,set_daughter_to_end_tree_test){
std::ofstream  grow_node_stream;
std::ofstream  prior_tree_table_temp_stream;
std::ofstream  left_daughter_stream;
 RInside();
 int grow_node = RcppDeepState_int ();
  grow_node_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/set_daughter_to_end_tree/inputs/ grow_node");
 grow_node_stream<< grow_node;
std::cout <<"grow_node values: "<< grow_node << std::endl;
 grow_node_stream.close();
 NumericMatrix prior_tree_table_temp = RcppDeepState_NumericMatrix ();
  prior_tree_table_temp_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/set_daughter_to_end_tree/inputs/ prior_tree_table_temp");
 prior_tree_table_temp_stream<< prior_tree_table_temp;
std::cout <<"prior_tree_table_temp values: "<< prior_tree_table_temp << std::endl;
 prior_tree_table_temp_stream.close();
 double left_daughter = RcppDeepState_double ();
  left_daughter_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/set_daughter_to_end_tree/inputs/ left_daughter");
 left_daughter_stream<< left_daughter;
std::cout <<"left_daughter values: "<< left_daughter << std::endl;
 left_daughter_stream.close();
 std::cout << "input ends" << std::endl;
 try{
set_daughter_to_end_tree( grow_node, prior_tree_table_temp, left_daughter);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
