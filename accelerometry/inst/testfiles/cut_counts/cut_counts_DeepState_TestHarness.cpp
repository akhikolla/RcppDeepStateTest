#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 IntegerVector cut_counts(IntegerVector counts, IntegerVector int_cuts);
TEST(accelerometry_deepstate_test,cut_counts_test){
std::ofstream  counts_stream;
std::ofstream  int_cuts_stream;
 RInside();
 IntegerVector counts = RcppDeepState_IntegerVector ();
  counts_stream.open("/home/akhila/Documents/compileAttributescheck/accelerometry/inst/testfiles/cut_counts/inputs/ counts");
 counts_stream<< counts;
std::cout <<"counts values: "<< counts << std::endl;
 counts_stream.close();
 IntegerVector int_cuts = RcppDeepState_IntegerVector ();
  int_cuts_stream.open("/home/akhila/Documents/compileAttributescheck/accelerometry/inst/testfiles/cut_counts/inputs/ int_cuts");
 int_cuts_stream<< int_cuts;
std::cout <<"int_cuts values: "<< int_cuts << std::endl;
 int_cuts_stream.close();
 try{
cut_counts( counts, int_cuts);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
