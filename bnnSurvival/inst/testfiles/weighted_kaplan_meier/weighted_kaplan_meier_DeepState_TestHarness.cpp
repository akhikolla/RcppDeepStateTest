#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 Rcpp::NumericVector weighted_kaplan_meier(Rcpp::NumericMatrix response, Rcpp::NumericVector weights, Rcpp::NumericVector timepoints);
TEST(bnnSurvival_deepstate_test,weighted_kaplan_meier_test){
std::ofstream  response_stream;
std::ofstream  weights_stream;
std::ofstream  timepoints_stream;
RInside();
std::cout << "input starts" << std::endl;
 NumericMatrix response = RcppDeepState_NumericMatrix ();
  response_stream.open("/home/akhila/Documents/compileAttributescheck/bnnSurvival/inst/testfiles/weighted_kaplan_meier/inputs/ response");
 response_stream<< response;
std::cout <<"response values: "<< response << std::endl;
 response_stream.close();
 NumericVector weights = RcppDeepState_NumericVector ();
  weights_stream.open("/home/akhila/Documents/compileAttributescheck/bnnSurvival/inst/testfiles/weighted_kaplan_meier/inputs/ weights");
 weights_stream<< weights;
std::cout <<"weights values: "<< weights << std::endl;
 weights_stream.close();
 NumericVector timepoints = RcppDeepState_NumericVector ();
  timepoints_stream.open("/home/akhila/Documents/compileAttributescheck/bnnSurvival/inst/testfiles/weighted_kaplan_meier/inputs/ timepoints");
 timepoints_stream<< timepoints;
std::cout <<"timepoints values: "<< timepoints << std::endl;
 timepoints_stream.close();
 std::cout << "input ends" << std::endl;
 try{
weighted_kaplan_meier( response, weights, timepoints);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
