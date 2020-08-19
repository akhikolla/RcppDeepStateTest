#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericMatrix predictOob_cpp(NumericMatrix origNodes, NumericMatrix inbag, int nobs, int ntree);
TEST(abcrf_deepstate_test,predictOob_cpp_test){
std::ofstream  origNodes_stream;
std::ofstream  inbag_stream;
std::ofstream  nobs_stream;
std::ofstream  ntree_stream;
 RInside();
 NumericMatrix origNodes = RcppDeepState_NumericMatrix ();
  origNodes_stream.open("/home/akhila/Documents/compileAttributescheck/abcrf/inst/testfiles/predictOob_cpp/inputs/ origNodes");
 origNodes_stream<< origNodes;
std::cout <<"origNodes values: "<< origNodes << std::endl;
 origNodes_stream.close();
 NumericMatrix inbag = RcppDeepState_NumericMatrix ();
  inbag_stream.open("/home/akhila/Documents/compileAttributescheck/abcrf/inst/testfiles/predictOob_cpp/inputs/ inbag");
 inbag_stream<< inbag;
std::cout <<"inbag values: "<< inbag << std::endl;
 inbag_stream.close();
 int nobs = RcppDeepState_int ();
  nobs_stream.open("/home/akhila/Documents/compileAttributescheck/abcrf/inst/testfiles/predictOob_cpp/inputs/ nobs");
 nobs_stream<< nobs;
std::cout <<"nobs values: "<< nobs << std::endl;
 nobs_stream.close();
 int ntree = RcppDeepState_int ();
  ntree_stream.open("/home/akhila/Documents/compileAttributescheck/abcrf/inst/testfiles/predictOob_cpp/inputs/ ntree");
 ntree_stream<< ntree;
std::cout <<"ntree values: "<< ntree << std::endl;
 ntree_stream.close();
 try{
predictOob_cpp( origNodes, inbag, nobs, ntree);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
