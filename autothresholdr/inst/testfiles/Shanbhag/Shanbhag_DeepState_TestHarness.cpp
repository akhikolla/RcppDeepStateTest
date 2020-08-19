#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 int Shanbhag(IntegerVector data);
TEST(autothresholdr_deepstate_test,Shanbhag_test){
std::ofstream  data_stream;
 RInside();
 IntegerVector data = RcppDeepState_IntegerVector ();
  data_stream.open("/home/akhila/Documents/compileAttributescheck/autothresholdr/inst/testfiles/Shanbhag/inputs/ data");
 data_stream<< data;
std::cout <<"data values: "<< data << std::endl;
 data_stream.close();
 std::cout << "input ends" << std::endl;
 try{
Shanbhag( data);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
