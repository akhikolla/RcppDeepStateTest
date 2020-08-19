#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericMatrix simplex_2d_c(int height, int width, int seed, double freq, int fractal, int octaves, double lacunarity, double gain, int pertube, double pertube_amp);
TEST(ambient_deepstate_test,simplex_2d_c_test){
std::ofstream  height_stream;
std::ofstream  width_stream;
std::ofstream  seed_stream;
std::ofstream  freq_stream;
std::ofstream  fractal_stream;
std::ofstream  octaves_stream;
std::ofstream  lacunarity_stream;
std::ofstream  gain_stream;
std::ofstream  pertube_stream;
std::ofstream  pertube_amp_stream;
 RInside();
 int height = RcppDeepState_int ();
  height_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/simplex_2d_c/inputs/ height");
 height_stream<< height;
std::cout <<"height values: "<< height << std::endl;
 height_stream.close();
 int width = RcppDeepState_int ();
  width_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/simplex_2d_c/inputs/ width");
 width_stream<< width;
std::cout <<"width values: "<< width << std::endl;
 width_stream.close();
 int seed = RcppDeepState_int ();
  seed_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/simplex_2d_c/inputs/ seed");
 seed_stream<< seed;
std::cout <<"seed values: "<< seed << std::endl;
 seed_stream.close();
 double freq = RcppDeepState_double ();
  freq_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/simplex_2d_c/inputs/ freq");
 freq_stream<< freq;
std::cout <<"freq values: "<< freq << std::endl;
 freq_stream.close();
 int fractal = RcppDeepState_int ();
  fractal_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/simplex_2d_c/inputs/ fractal");
 fractal_stream<< fractal;
std::cout <<"fractal values: "<< fractal << std::endl;
 fractal_stream.close();
 int octaves = RcppDeepState_int ();
  octaves_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/simplex_2d_c/inputs/ octaves");
 octaves_stream<< octaves;
std::cout <<"octaves values: "<< octaves << std::endl;
 octaves_stream.close();
 double lacunarity = RcppDeepState_double ();
  lacunarity_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/simplex_2d_c/inputs/ lacunarity");
 lacunarity_stream<< lacunarity;
std::cout <<"lacunarity values: "<< lacunarity << std::endl;
 lacunarity_stream.close();
 double gain = RcppDeepState_double ();
  gain_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/simplex_2d_c/inputs/ gain");
 gain_stream<< gain;
std::cout <<"gain values: "<< gain << std::endl;
 gain_stream.close();
 int pertube = RcppDeepState_int ();
  pertube_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/simplex_2d_c/inputs/ pertube");
 pertube_stream<< pertube;
std::cout <<"pertube values: "<< pertube << std::endl;
 pertube_stream.close();
 double pertube_amp = RcppDeepState_double ();
  pertube_amp_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/simplex_2d_c/inputs/ pertube_amp");
 pertube_amp_stream<< pertube_amp;
std::cout <<"pertube_amp values: "<< pertube_amp << std::endl;
 pertube_amp_stream.close();
 std::cout << "input ends" << std::endl;
 try{
simplex_2d_c( height, width, seed, freq, fractal, octaves, lacunarity, gain, pertube, pertube_amp);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
