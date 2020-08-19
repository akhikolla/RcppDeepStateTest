#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector gen_worley2d_c(NumericVector x, NumericVector y, double freq, int seed, int dist, int value, IntegerVector dist2ind, double jitter);
TEST(ambient_deepstate_test,gen_worley2d_c_test){
std::ofstream  x_stream;
std::ofstream  y_stream;
std::ofstream  freq_stream;
std::ofstream  seed_stream;
std::ofstream  dist_stream;
std::ofstream  value_stream;
std::ofstream  dist2ind_stream;
std::ofstream  jitter_stream;
 RInside();
 NumericVector x = RcppDeepState_NumericVector ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/gen_worley2d_c/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 NumericVector y = RcppDeepState_NumericVector ();
  y_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/gen_worley2d_c/inputs/ y");
 y_stream<< y;
std::cout <<"y values: "<< y << std::endl;
 y_stream.close();
 double freq = RcppDeepState_double ();
  freq_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/gen_worley2d_c/inputs/ freq");
 freq_stream<< freq;
std::cout <<"freq values: "<< freq << std::endl;
 freq_stream.close();
 int seed = RcppDeepState_int ();
  seed_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/gen_worley2d_c/inputs/ seed");
 seed_stream<< seed;
std::cout <<"seed values: "<< seed << std::endl;
 seed_stream.close();
 int dist = RcppDeepState_int ();
  dist_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/gen_worley2d_c/inputs/ dist");
 dist_stream<< dist;
std::cout <<"dist values: "<< dist << std::endl;
 dist_stream.close();
 int value = RcppDeepState_int ();
  value_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/gen_worley2d_c/inputs/ value");
 value_stream<< value;
std::cout <<"value values: "<< value << std::endl;
 value_stream.close();
 IntegerVector dist2ind = RcppDeepState_IntegerVector ();
  dist2ind_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/gen_worley2d_c/inputs/ dist2ind");
 dist2ind_stream<< dist2ind;
std::cout <<"dist2ind values: "<< dist2ind << std::endl;
 dist2ind_stream.close();
 double jitter = RcppDeepState_double ();
  jitter_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/gen_worley2d_c/inputs/ jitter");
 jitter_stream<< jitter;
std::cout <<"jitter values: "<< jitter << std::endl;
 jitter_stream.close();
 std::cout << "input ends" << std::endl;
 try{
gen_worley2d_c( x, y, freq, seed, dist, value, dist2ind, jitter);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
