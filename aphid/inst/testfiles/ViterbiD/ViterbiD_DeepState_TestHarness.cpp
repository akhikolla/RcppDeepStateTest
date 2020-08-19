#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 List ViterbiD(IntegerVector x, IntegerVector y, int type, double d, double e, NumericMatrix S, IntegerVector windowspace, double offset);
TEST(aphid_deepstate_test,ViterbiD_test){
std::ofstream  x_stream;
std::ofstream  y_stream;
std::ofstream  type_stream;
std::ofstream  d_stream;
std::ofstream  e_stream;
std::ofstream  S_stream;
std::ofstream  windowspace_stream;
std::ofstream  offset_stream;
 RInside();
 IntegerVector x = RcppDeepState_IntegerVector ();
  x_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/ViterbiD/inputs/ x");
 x_stream<< x;
std::cout <<"x values: "<< x << std::endl;
 x_stream.close();
 IntegerVector y = RcppDeepState_IntegerVector ();
  y_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/ViterbiD/inputs/ y");
 y_stream<< y;
std::cout <<"y values: "<< y << std::endl;
 y_stream.close();
 int type = RcppDeepState_int ();
  type_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/ViterbiD/inputs/ type");
 type_stream<< type;
std::cout <<"type values: "<< type << std::endl;
 type_stream.close();
 double d = RcppDeepState_double ();
  d_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/ViterbiD/inputs/ d");
 d_stream<< d;
std::cout <<"d values: "<< d << std::endl;
 d_stream.close();
 double e = RcppDeepState_double ();
  e_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/ViterbiD/inputs/ e");
 e_stream<< e;
std::cout <<"e values: "<< e << std::endl;
 e_stream.close();
 NumericMatrix S = RcppDeepState_NumericMatrix ();
  S_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/ViterbiD/inputs/ S");
 S_stream<< S;
std::cout <<"S values: "<< S << std::endl;
 S_stream.close();
 IntegerVector windowspace = RcppDeepState_IntegerVector ();
  windowspace_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/ViterbiD/inputs/ windowspace");
 windowspace_stream<< windowspace;
std::cout <<"windowspace values: "<< windowspace << std::endl;
 windowspace_stream.close();
 double offset = RcppDeepState_double ();
  offset_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/ViterbiD/inputs/ offset");
 offset_stream<< offset;
std::cout <<"offset values: "<< offset << std::endl;
 offset_stream.close();
 std::cout << "input ends" << std::endl;
 try{
ViterbiD( x, y, type, d, e, S, windowspace, offset);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
