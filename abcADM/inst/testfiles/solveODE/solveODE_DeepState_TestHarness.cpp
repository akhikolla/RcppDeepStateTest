#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 List solveODE(NumericMatrix inputTheta, double phi, const int verbose);
TEST(abcADM_deepstate_test,solveODE_test){
std::ofstream  inputTheta_stream;
std::ofstream  phi_stream;
std::ofstream  verbose_stream;
 RInside();
 NumericMatrix inputTheta = RcppDeepState_NumericMatrix ();
  inputTheta_stream.open("/home/akhila/Documents/compileAttributescheck/abcADM/inst/testfiles/solveODE/inputs/ inputTheta");
 inputTheta_stream<< inputTheta;
std::cout <<"inputTheta values: "<< inputTheta << std::endl;
 inputTheta_stream.close();
 double phi = RcppDeepState_double ();
  phi_stream.open("/home/akhila/Documents/compileAttributescheck/abcADM/inst/testfiles/solveODE/inputs/ phi");
 phi_stream<< phi;
std::cout <<"phi values: "<< phi << std::endl;
 phi_stream.close();
  int verbose = RcppDeepState_int ();
  verbose_stream.open("/home/akhila/Documents/compileAttributescheck/abcADM/inst/testfiles/solveODE/inputs/ verbose");
 verbose_stream<< verbose;
std::cout <<"verbose values: "<< verbose << std::endl;
 verbose_stream.close();
 try{
solveODE( inputTheta, phi, verbose);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
