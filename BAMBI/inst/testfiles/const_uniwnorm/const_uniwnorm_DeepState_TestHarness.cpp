#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double const_uniwnorm(double k);
TEST(BAMBI_deepstate_test,const_uniwnorm_test){
std::ofstream  k_stream;
 RInside();
 double k = RcppDeepState_double ();
  k_stream.open("/home/akhila/Documents/compileAttributescheck/BAMBI/inst/testfiles/const_uniwnorm/inputs/ k");
 k_stream<< k;
std::cout <<"k values: "<< k << std::endl;
 k_stream.close();
 std::cout << "input ends" << std::endl;
 try{
const_uniwnorm( k);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
