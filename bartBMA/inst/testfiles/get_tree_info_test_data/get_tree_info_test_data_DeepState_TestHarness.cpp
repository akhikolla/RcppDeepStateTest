#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 List get_tree_info_test_data(NumericMatrix test_data, NumericMatrix tree_data);
TEST(bartBMA_deepstate_test,get_tree_info_test_data_test){
std::ofstream  test_data_stream;
std::ofstream  tree_data_stream;
 RInside();
 NumericMatrix test_data = RcppDeepState_NumericMatrix ();
  test_data_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/get_tree_info_test_data/inputs/ test_data");
 test_data_stream<< test_data;
std::cout <<"test_data values: "<< test_data << std::endl;
 test_data_stream.close();
 NumericMatrix tree_data = RcppDeepState_NumericMatrix ();
  tree_data_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/get_tree_info_test_data/inputs/ tree_data");
 tree_data_stream<< tree_data;
std::cout <<"tree_data values: "<< tree_data << std::endl;
 tree_data_stream.close();
 std::cout << "input ends" << std::endl;
 try{
get_tree_info_test_data( test_data, tree_data);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
