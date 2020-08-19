#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 Rcpp::DataFrame pcf_envelope(Rcpp::NumericVector sim, Rcpp::NumericVector dist, Rcpp::NumericVector ratio, Rcpp::NumericVector rs, double area, int nobj, double stoyan, int nrank);
TEST(apcf_deepstate_test,pcf_envelope_test){
std::ofstream  sim_stream;
std::ofstream  dist_stream;
std::ofstream  ratio_stream;
std::ofstream  rs_stream;
std::ofstream  area_stream;
std::ofstream  nobj_stream;
std::ofstream  stoyan_stream;
std::ofstream  nrank_stream;
 RInside();
 NumericVector sim = RcppDeepState_NumericVector ();
  sim_stream.open("/home/akhila/Documents/compileAttributescheck/apcf/inst/testfiles/pcf_envelope/inputs/ sim");
 sim_stream<< sim;
std::cout <<"sim values: "<< sim << std::endl;
 sim_stream.close();
 NumericVector dist = RcppDeepState_NumericVector ();
  dist_stream.open("/home/akhila/Documents/compileAttributescheck/apcf/inst/testfiles/pcf_envelope/inputs/ dist");
 dist_stream<< dist;
std::cout <<"dist values: "<< dist << std::endl;
 dist_stream.close();
 NumericVector ratio = RcppDeepState_NumericVector ();
  ratio_stream.open("/home/akhila/Documents/compileAttributescheck/apcf/inst/testfiles/pcf_envelope/inputs/ ratio");
 ratio_stream<< ratio;
std::cout <<"ratio values: "<< ratio << std::endl;
 ratio_stream.close();
 NumericVector rs = RcppDeepState_NumericVector ();
  rs_stream.open("/home/akhila/Documents/compileAttributescheck/apcf/inst/testfiles/pcf_envelope/inputs/ rs");
 rs_stream<< rs;
std::cout <<"rs values: "<< rs << std::endl;
 rs_stream.close();
 double area = RcppDeepState_double ();
  area_stream.open("/home/akhila/Documents/compileAttributescheck/apcf/inst/testfiles/pcf_envelope/inputs/ area");
 area_stream<< area;
std::cout <<"area values: "<< area << std::endl;
 area_stream.close();
 int nobj = RcppDeepState_int ();
  nobj_stream.open("/home/akhila/Documents/compileAttributescheck/apcf/inst/testfiles/pcf_envelope/inputs/ nobj");
 nobj_stream<< nobj;
std::cout <<"nobj values: "<< nobj << std::endl;
 nobj_stream.close();
 double stoyan = RcppDeepState_double ();
  stoyan_stream.open("/home/akhila/Documents/compileAttributescheck/apcf/inst/testfiles/pcf_envelope/inputs/ stoyan");
 stoyan_stream<< stoyan;
std::cout <<"stoyan values: "<< stoyan << std::endl;
 stoyan_stream.close();
 int nrank = RcppDeepState_int ();
  nrank_stream.open("/home/akhila/Documents/compileAttributescheck/apcf/inst/testfiles/pcf_envelope/inputs/ nrank");
 nrank_stream<< nrank;
std::cout <<"nrank values: "<< nrank << std::endl;
 nrank_stream.close();
 std::cout << "input ends" << std::endl;
 try{
pcf_envelope( sim, dist, ratio, rs, area, nobj, stoyan, nrank);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
