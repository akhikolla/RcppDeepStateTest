#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericMatrix var_pillars(NumericVector arr3d);
TEST(autothresholdr_deepstate_test,var_pillars_test){
std::ofstream  arr3d_stream;
 RInside();
 NumericVector arr3d = RcppDeepState_NumericVector ();
  arr3d_stream.open("/home/akhila/Documents/compileAttributescheck/autothresholdr/inst/testfiles/var_pillars/inputs/ arr3d");
 arr3d_stream<< arr3d;
std::cout <<"arr3d values: "<< arr3d << std::endl;
 arr3d_stream.close();
 std::cout << "input ends" << std::endl;
 try{
var_pillars( arr3d);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
