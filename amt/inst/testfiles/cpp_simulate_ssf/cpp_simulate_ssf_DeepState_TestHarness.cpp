#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 IntegerVector cpp_simulate_ssf(int n_steps, int start, int nc, int nr, NumericMatrix mk, NumericMatrix hk);
TEST(amt_deepstate_test,cpp_simulate_ssf_test){
std::ofstream  n_steps_stream;
std::ofstream  start_stream;
std::ofstream  nc_stream;
std::ofstream  nr_stream;
std::ofstream  mk_stream;
std::ofstream  hk_stream;
 RInside();
 int n_steps = RcppDeepState_int ();
  n_steps_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/cpp_simulate_ssf/inputs/ n_steps");
 n_steps_stream<< n_steps;
std::cout <<"n_steps values: "<< n_steps << std::endl;
 n_steps_stream.close();
 int start = RcppDeepState_int ();
  start_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/cpp_simulate_ssf/inputs/ start");
 start_stream<< start;
std::cout <<"start values: "<< start << std::endl;
 start_stream.close();
 int nc = RcppDeepState_int ();
  nc_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/cpp_simulate_ssf/inputs/ nc");
 nc_stream<< nc;
std::cout <<"nc values: "<< nc << std::endl;
 nc_stream.close();
 int nr = RcppDeepState_int ();
  nr_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/cpp_simulate_ssf/inputs/ nr");
 nr_stream<< nr;
std::cout <<"nr values: "<< nr << std::endl;
 nr_stream.close();
 NumericMatrix mk = RcppDeepState_NumericMatrix ();
  mk_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/cpp_simulate_ssf/inputs/ mk");
 mk_stream<< mk;
std::cout <<"mk values: "<< mk << std::endl;
 mk_stream.close();
 NumericMatrix hk = RcppDeepState_NumericMatrix ();
  hk_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/cpp_simulate_ssf/inputs/ hk");
 hk_stream<< hk;
std::cout <<"hk values: "<< hk << std::endl;
 hk_stream.close();
 std::cout << "input ends" << std::endl;
 try{
cpp_simulate_ssf( n_steps, start, nc, nr, mk, hk);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
