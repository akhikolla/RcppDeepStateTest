#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 List ViterbiPP(NumericMatrix Ax, NumericMatrix Ay, NumericMatrix Ex, NumericMatrix Ey, NumericVector qe, int type, IntegerVector windowspace, double offset);
TEST(aphid_deepstate_test,ViterbiPP_test){
std::ofstream  Ax_stream;
std::ofstream  Ay_stream;
std::ofstream  Ex_stream;
std::ofstream  Ey_stream;
std::ofstream  qe_stream;
std::ofstream  type_stream;
std::ofstream  windowspace_stream;
std::ofstream  offset_stream;
 RInside();
 NumericMatrix Ax = RcppDeepState_NumericMatrix ();
  Ax_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/ViterbiPP/inputs/ Ax");
 Ax_stream<< Ax;
std::cout <<"Ax values: "<< Ax << std::endl;
 Ax_stream.close();
 NumericMatrix Ay = RcppDeepState_NumericMatrix ();
  Ay_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/ViterbiPP/inputs/ Ay");
 Ay_stream<< Ay;
std::cout <<"Ay values: "<< Ay << std::endl;
 Ay_stream.close();
 NumericMatrix Ex = RcppDeepState_NumericMatrix ();
  Ex_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/ViterbiPP/inputs/ Ex");
 Ex_stream<< Ex;
std::cout <<"Ex values: "<< Ex << std::endl;
 Ex_stream.close();
 NumericMatrix Ey = RcppDeepState_NumericMatrix ();
  Ey_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/ViterbiPP/inputs/ Ey");
 Ey_stream<< Ey;
std::cout <<"Ey values: "<< Ey << std::endl;
 Ey_stream.close();
 NumericVector qe = RcppDeepState_NumericVector ();
  qe_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/ViterbiPP/inputs/ qe");
 qe_stream<< qe;
std::cout <<"qe values: "<< qe << std::endl;
 qe_stream.close();
 int type = RcppDeepState_int ();
  type_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/ViterbiPP/inputs/ type");
 type_stream<< type;
std::cout <<"type values: "<< type << std::endl;
 type_stream.close();
 IntegerVector windowspace = RcppDeepState_IntegerVector ();
  windowspace_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/ViterbiPP/inputs/ windowspace");
 windowspace_stream<< windowspace;
std::cout <<"windowspace values: "<< windowspace << std::endl;
 windowspace_stream.close();
 double offset = RcppDeepState_double ();
  offset_stream.open("/home/akhila/Documents/compileAttributescheck/aphid/inst/testfiles/ViterbiPP/inputs/ offset");
 offset_stream<< offset;
std::cout <<"offset values: "<< offset << std::endl;
 offset_stream.close();
 std::cout << "input ends" << std::endl;
 try{
ViterbiPP( Ax, Ay, Ex, Ey, qe, type, windowspace, offset);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
