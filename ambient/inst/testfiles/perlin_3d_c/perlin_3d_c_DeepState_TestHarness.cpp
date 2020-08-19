#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericMatrix perlin_3d_c(int height, int width, int depth, int seed, double freq, int interp, int fractal, int octaves, double lacunarity, double gain, int pertube, double pertube_amp);
TEST(ambient_deepstate_test,perlin_3d_c_test){
std::ofstream  height_stream;
std::ofstream  width_stream;
std::ofstream  depth_stream;
std::ofstream  seed_stream;
std::ofstream  freq_stream;
std::ofstream  interp_stream;
std::ofstream  fractal_stream;
std::ofstream  octaves_stream;
std::ofstream  lacunarity_stream;
std::ofstream  gain_stream;
std::ofstream  pertube_stream;
std::ofstream  pertube_amp_stream;
 RInside();
 int height = RcppDeepState_int ();
  height_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/perlin_3d_c/inputs/ height");
 height_stream<< height;
std::cout <<"height values: "<< height << std::endl;
 height_stream.close();
 int width = RcppDeepState_int ();
  width_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/perlin_3d_c/inputs/ width");
 width_stream<< width;
std::cout <<"width values: "<< width << std::endl;
 width_stream.close();
 int depth = RcppDeepState_int ();
  depth_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/perlin_3d_c/inputs/ depth");
 depth_stream<< depth;
std::cout <<"depth values: "<< depth << std::endl;
 depth_stream.close();
 int seed = RcppDeepState_int ();
  seed_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/perlin_3d_c/inputs/ seed");
 seed_stream<< seed;
std::cout <<"seed values: "<< seed << std::endl;
 seed_stream.close();
 double freq = RcppDeepState_double ();
  freq_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/perlin_3d_c/inputs/ freq");
 freq_stream<< freq;
std::cout <<"freq values: "<< freq << std::endl;
 freq_stream.close();
 int interp = RcppDeepState_int ();
  interp_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/perlin_3d_c/inputs/ interp");
 interp_stream<< interp;
std::cout <<"interp values: "<< interp << std::endl;
 interp_stream.close();
 int fractal = RcppDeepState_int ();
  fractal_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/perlin_3d_c/inputs/ fractal");
 fractal_stream<< fractal;
std::cout <<"fractal values: "<< fractal << std::endl;
 fractal_stream.close();
 int octaves = RcppDeepState_int ();
  octaves_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/perlin_3d_c/inputs/ octaves");
 octaves_stream<< octaves;
std::cout <<"octaves values: "<< octaves << std::endl;
 octaves_stream.close();
 double lacunarity = RcppDeepState_double ();
  lacunarity_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/perlin_3d_c/inputs/ lacunarity");
 lacunarity_stream<< lacunarity;
std::cout <<"lacunarity values: "<< lacunarity << std::endl;
 lacunarity_stream.close();
 double gain = RcppDeepState_double ();
  gain_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/perlin_3d_c/inputs/ gain");
 gain_stream<< gain;
std::cout <<"gain values: "<< gain << std::endl;
 gain_stream.close();
 int pertube = RcppDeepState_int ();
  pertube_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/perlin_3d_c/inputs/ pertube");
 pertube_stream<< pertube;
std::cout <<"pertube values: "<< pertube << std::endl;
 pertube_stream.close();
 double pertube_amp = RcppDeepState_double ();
  pertube_amp_stream.open("/home/akhila/Documents/compileAttributescheck/ambient/inst/testfiles/perlin_3d_c/inputs/ pertube_amp");
 pertube_amp_stream<< pertube_amp;
std::cout <<"pertube_amp values: "<< pertube_amp << std::endl;
 pertube_amp_stream.close();
 std::cout << "input ends" << std::endl;
 try{
perlin_3d_c( height, width, depth, seed, freq, interp, fractal, octaves, lacunarity, gain, pertube, pertube_amp);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
