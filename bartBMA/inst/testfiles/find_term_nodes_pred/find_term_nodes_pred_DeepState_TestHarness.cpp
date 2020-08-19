#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector find_term_nodes_pred(NumericMatrix tree_table);
TEST(bartBMA_deepstate_test,find_term_nodes_pred_test){
std::ofstream  tree_table_stream;
 RInside();
 NumericMatrix tree_table = RcppDeepState_NumericMatrix ();
  tree_table_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/find_term_nodes_pred/inputs/ tree_table");
 tree_table_stream<< tree_table;
std::cout <<"tree_table values: "<< tree_table << std::endl;
 tree_table_stream.close();
 std::cout << "input ends" << std::endl;
 try{
find_term_nodes_pred( tree_table);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
