#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector find_internal_nodes_gs(NumericMatrix treetable);
TEST(bartBMA_deepstate_test,find_internal_nodes_gs_test){
std::ofstream  treetable_stream;
 RInside();
 NumericMatrix treetable = RcppDeepState_NumericMatrix ();
  treetable_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/find_internal_nodes_gs/inputs/ treetable");
 treetable_stream<< treetable;
std::cout <<"treetable values: "<< treetable << std::endl;
 treetable_stream.close();
 std::cout << "input ends" << std::endl;
 try{
find_internal_nodes_gs( treetable);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
