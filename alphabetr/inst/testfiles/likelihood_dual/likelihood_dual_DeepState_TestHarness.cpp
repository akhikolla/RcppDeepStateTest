#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double likelihood_dual(double est, double err, NumericVector numb_wells, NumericVector numb_cells, NumericVector numb_sample);
TEST(alphabetr_deepstate_test,likelihood_dual_test){
std::ofstream  est_stream;
std::ofstream  err_stream;
std::ofstream  numb_wells_stream;
std::ofstream  numb_cells_stream;
std::ofstream  numb_sample_stream;
 RInside();
 double est = RcppDeepState_double ();
  est_stream.open("/home/akhila/Documents/compileAttributescheck/alphabetr/inst/testfiles/likelihood_dual/inputs/ est");
 est_stream<< est;
std::cout <<"est values: "<< est << std::endl;
 est_stream.close();
 double err = RcppDeepState_double ();
  err_stream.open("/home/akhila/Documents/compileAttributescheck/alphabetr/inst/testfiles/likelihood_dual/inputs/ err");
 err_stream<< err;
std::cout <<"err values: "<< err << std::endl;
 err_stream.close();
 NumericVector numb_wells = RcppDeepState_NumericVector ();
  numb_wells_stream.open("/home/akhila/Documents/compileAttributescheck/alphabetr/inst/testfiles/likelihood_dual/inputs/ numb_wells");
 numb_wells_stream<< numb_wells;
std::cout <<"numb_wells values: "<< numb_wells << std::endl;
 numb_wells_stream.close();
 NumericVector numb_cells = RcppDeepState_NumericVector ();
  numb_cells_stream.open("/home/akhila/Documents/compileAttributescheck/alphabetr/inst/testfiles/likelihood_dual/inputs/ numb_cells");
 numb_cells_stream<< numb_cells;
std::cout <<"numb_cells values: "<< numb_cells << std::endl;
 numb_cells_stream.close();
 NumericVector numb_sample = RcppDeepState_NumericVector ();
  numb_sample_stream.open("/home/akhila/Documents/compileAttributescheck/alphabetr/inst/testfiles/likelihood_dual/inputs/ numb_sample");
 numb_sample_stream<< numb_sample;
std::cout <<"numb_sample values: "<< numb_sample << std::endl;
 numb_sample_stream.close();
 try{
likelihood_dual( est, err, numb_wells, numb_cells, numb_sample);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
