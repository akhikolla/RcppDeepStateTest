#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector gen_cubic3d_c(NumericVector x, NumericVector y, NumericVector z, double freq, int seed);
TEST(ambient_deepstate_test,gen_cubic3d_c_test){
std::ofstream  x_stream;
std::ofstream  y_stream;
std::ofstream  z_stream;
std::ofstream  freq_stream;
std::ofstream  seed_stream;
 RInside();
 NumericVector x = RcppDeepState_NumericVector ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/gen_cubic3d_c/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 NumericVector y = RcppDeepState_NumericVector ();
  y_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/gen_cubic3d_c/inputs/ y");
 y_stream<< y;
std::cout <<"y values: "<< y << std::endl;
 y_stream.close();
 NumericVector z = RcppDeepState_NumericVector ();
  z_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/gen_cubic3d_c/inputs/ z");
 z_stream<< z;
std::cout <<"z values: "<< z << std::endl;
 z_stream.close();
 double freq = RcppDeepState_double ();
  freq_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/gen_cubic3d_c/inputs/ freq");
 freq_stream<< freq;
std::cout <<"freq values: "<< freq << std::endl;
 freq_stream.close();
 int seed = RcppDeepState_int ();
  seed_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/gen_cubic3d_c/inputs/ seed");
 seed_stream<< seed;
std::cout <<"seed values: "<< seed << std::endl;
 seed_stream.close();
 std::cout << "input ends" << std::endl;
 try{
gen_cubic3d_c( x, y, z, freq, seed);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
