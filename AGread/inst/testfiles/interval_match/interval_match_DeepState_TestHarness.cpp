#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 int interval_match(double proportion, NumericVector references);
TEST(AGread_deepstate_test,interval_match_test){
std::ofstream  proportion_stream;
std::ofstream  references_stream;
 RInside();
 double proportion = RcppDeepState_double ();
  proportion_stream.open("/home/akhila/Documents/compileAttributescheck/AGread/inst/testfiles/interval_match/inputs/ proportion");
 proportion_stream<< proportion;
std::cout <<"proportion values: "<< proportion << std::endl;
 proportion_stream.close();
 NumericVector references = RcppDeepState_NumericVector ();
  references_stream.open("/home/akhila/Documents/compileAttributescheck/AGread/inst/testfiles/interval_match/inputs/ references");
 references_stream<< references;
std::cout <<"references values: "<< references << std::endl;
 references_stream.close();
 try{
interval_match( proportion, references);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
