#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 IntegerVector ecount(IntegerVector states, int statearity, IntegerVector residues, int resarity);
TEST(aphid_deepstate_test,ecount_test){
std::ofstream  states_stream;
std::ofstream  statearity_stream;
std::ofstream  residues_stream;
std::ofstream  resarity_stream;
 RInside();
 IntegerVector states = RcppDeepState_IntegerVector ();
  states_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/ecount/inputs/ states");
 states_stream<< states;
std::cout <<"states values: "<< states << std::endl;
 states_stream.close();
 int statearity = RcppDeepState_int ();
  statearity_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/ecount/inputs/ statearity");
 statearity_stream<< statearity;
std::cout <<"statearity values: "<< statearity << std::endl;
 statearity_stream.close();
 IntegerVector residues = RcppDeepState_IntegerVector ();
  residues_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/ecount/inputs/ residues");
 residues_stream<< residues;
std::cout <<"residues values: "<< residues << std::endl;
 residues_stream.close();
 int resarity = RcppDeepState_int ();
  resarity_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/ecount/inputs/ resarity");
 resarity_stream<< resarity;
std::cout <<"resarity values: "<< resarity << std::endl;
 resarity_stream.close();
 std::cout << "input ends" << std::endl;
 try{
ecount( states, statearity, residues, resarity);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
