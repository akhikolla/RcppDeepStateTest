#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 int Li(IntegerVector data);
TEST(autothresholdr_deepstate_test,Li_test){
std::ofstream  data_stream;
 RInside();
 IntegerVector data = RcppDeepState_IntegerVector ();
  data_stream.open("/home/akhila/Documents/compileAttributescheck/autothresholdr/inst/testfiles/Li/inputs/ data");
 data_stream<< data;
std::cout <<"data values: "<< data << std::endl;
 data_stream.close();
 std::cout << "input ends" << std::endl;
 try{
Li( data);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
