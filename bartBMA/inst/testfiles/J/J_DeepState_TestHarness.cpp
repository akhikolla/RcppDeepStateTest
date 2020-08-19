#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 arma::mat J(NumericMatrix obs_to_nodes_temp, NumericVector tree_term_nodes);
TEST(bartBMA_deepstate_test,J_test){
std::ofstream  obs_to_nodes_temp_stream;
std::ofstream  tree_term_nodes_stream;
 RInside();
 NumericMatrix obs_to_nodes_temp = RcppDeepState_NumericMatrix ();
  obs_to_nodes_temp_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/J/inputs/ obs_to_nodes_temp");
 obs_to_nodes_temp_stream<< obs_to_nodes_temp;
std::cout <<"obs_to_nodes_temp values: "<< obs_to_nodes_temp << std::endl;
 obs_to_nodes_temp_stream.close();
 NumericVector tree_term_nodes = RcppDeepState_NumericVector ();
  tree_term_nodes_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/J/inputs/ tree_term_nodes");
 tree_term_nodes_stream<< tree_term_nodes;
std::cout <<"tree_term_nodes values: "<< tree_term_nodes << std::endl;
 tree_term_nodes_stream.close();
 std::cout << "input ends" << std::endl;
 try{
J( obs_to_nodes_temp, tree_term_nodes);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
