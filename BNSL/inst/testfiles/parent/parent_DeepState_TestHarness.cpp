#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 DataFrame parent(NumericMatrix df0, int h, int tw, int proc);
TEST(BNSL_deepstate_test,parent_test){
std::ofstream  df0_stream;
std::ofstream  h_stream;
std::ofstream  tw_stream;
std::ofstream  proc_stream;
RInside();
std::cout << "input starts" << std::endl;
 NumericMatrix df0 = RcppDeepState_NumericMatrix ();
  df0_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/parent/inputs/ df0");
 df0_stream<< df0;
std::cout <<"df0 values: "<< df0 << std::endl;
 df0_stream.close();
 int h = RcppDeepState_int ();
  h_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/parent/inputs/ h");
 h_stream<< h;
std::cout <<"h values: "<< h << std::endl;
 h_stream.close();
 int tw = RcppDeepState_int ();
  tw_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/parent/inputs/ tw");
 tw_stream<< tw;
std::cout <<"tw values: "<< tw << std::endl;
 tw_stream.close();
 int proc = RcppDeepState_int ();
  proc_stream.open("/home/akhila/Documents/compileAttributescheck/BNSL/inst/testfiles/parent/inputs/ proc");
 proc_stream<< proc;
std::cout <<"proc values: "<< proc << std::endl;
 proc_stream.close();
 std::cout << "input ends" << std::endl;
 try{
parent( df0, h, tw, proc);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
