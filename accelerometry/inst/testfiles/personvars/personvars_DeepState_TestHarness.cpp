#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericMatrix personvars(NumericMatrix dayvars, int rows, int days, int wk, int we);
TEST(accelerometry_deepstate_test,personvars_test){
std::ofstream  dayvars_stream;
std::ofstream  rows_stream;
std::ofstream  days_stream;
std::ofstream  wk_stream;
std::ofstream  we_stream;
 RInside();
 NumericMatrix dayvars = RcppDeepState_NumericMatrix ();
  dayvars_stream.open("/home/akhila/Documents/compileAttributescheck/accelerometry/inst/testfiles/personvars/inputs/ dayvars");
 dayvars_stream<< dayvars;
std::cout <<"dayvars values: "<< dayvars << std::endl;
 dayvars_stream.close();
 int rows = RcppDeepState_int ();
  rows_stream.open("/home/akhila/Documents/compileAttributescheck/accelerometry/inst/testfiles/personvars/inputs/ rows");
 rows_stream<< rows;
std::cout <<"rows values: "<< rows << std::endl;
 rows_stream.close();
 int days = RcppDeepState_int ();
  days_stream.open("/home/akhila/Documents/compileAttributescheck/accelerometry/inst/testfiles/personvars/inputs/ days");
 days_stream<< days;
std::cout <<"days values: "<< days << std::endl;
 days_stream.close();
 int wk = RcppDeepState_int ();
  wk_stream.open("/home/akhila/Documents/compileAttributescheck/accelerometry/inst/testfiles/personvars/inputs/ wk");
 wk_stream<< wk;
std::cout <<"wk values: "<< wk << std::endl;
 wk_stream.close();
 int we = RcppDeepState_int ();
  we_stream.open("/home/akhila/Documents/compileAttributescheck/accelerometry/inst/testfiles/personvars/inputs/ we");
 we_stream<< we;
std::cout <<"we values: "<< we << std::endl;
 we_stream.close();
 try{
personvars( dayvars, rows, days, wk, we);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
