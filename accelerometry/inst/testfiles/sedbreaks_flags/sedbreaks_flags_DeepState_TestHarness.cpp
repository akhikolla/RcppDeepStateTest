#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 IntegerVector sedbreaks_flags(IntegerVector counts, IntegerVector weartime, int thresh);
TEST(accelerometry_deepstate_test,sedbreaks_flags_test){
std::ofstream  counts_stream;
std::ofstream  weartime_stream;
std::ofstream  thresh_stream;
 RInside();
 IntegerVector counts = RcppDeepState_IntegerVector ();
  counts_stream.open("/home/akhila/Documents/compileAttributescheck/accelerometry/inst/testfiles/sedbreaks_flags/inputs/ counts");
 counts_stream<< counts;
std::cout <<"counts values: "<< counts << std::endl;
 counts_stream.close();
 IntegerVector weartime = RcppDeepState_IntegerVector ();
  weartime_stream.open("/home/akhila/Documents/compileAttributescheck/accelerometry/inst/testfiles/sedbreaks_flags/inputs/ weartime");
 weartime_stream<< weartime;
std::cout <<"weartime values: "<< weartime << std::endl;
 weartime_stream.close();
 int thresh = RcppDeepState_int ();
  thresh_stream.open("/home/akhila/Documents/compileAttributescheck/accelerometry/inst/testfiles/sedbreaks_flags/inputs/ thresh");
 thresh_stream<< thresh;
std::cout <<"thresh values: "<< thresh << std::endl;
 thresh_stream.close();
 try{
sedbreaks_flags( counts, weartime, thresh);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
