#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 SEXP read_matrix_blocks(CharacterVector filePaths, NumericVector size, double ncols);
TEST(bigReg_deepstate_test,read_matrix_blocks_test){
std::ofstream  filePaths_stream;
std::ofstream  size_stream;
std::ofstream  ncols_stream;
RInside();
std::cout << "input starts" << std::endl;
 CharacterVector filePaths = RcppDeepState_CharacterVector ();
  filePaths_stream.open("/home/akhila/Documents/compileAttributescheck/bigReg/inst/testfiles/read_matrix_blocks/inputs/ filePaths");
 filePaths_stream<< filePaths;
std::cout <<"filePaths values: "<< filePaths << std::endl;
 filePaths_stream.close();
 NumericVector size = RcppDeepState_NumericVector ();
  size_stream.open("/home/akhila/Documents/compileAttributescheck/bigReg/inst/testfiles/read_matrix_blocks/inputs/ size");
 size_stream<< size;
std::cout <<"size values: "<< size << std::endl;
 size_stream.close();
 double ncols = RcppDeepState_double ();
  ncols_stream.open("/home/akhila/Documents/compileAttributescheck/bigReg/inst/testfiles/read_matrix_blocks/inputs/ ncols");
 ncols_stream<< ncols;
std::cout <<"ncols values: "<< ncols << std::endl;
 ncols_stream.close();
 std::cout << "input ends" << std::endl;
 try{
read_matrix_blocks( filePaths, size, ncols);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
