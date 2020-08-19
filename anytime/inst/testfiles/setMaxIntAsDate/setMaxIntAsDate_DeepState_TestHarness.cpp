#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 void setMaxIntAsDate(const int val);
TEST(anytime_deepstate_test,setMaxIntAsDate_test){
std::ofstream  val_stream;
 RInside();
  int val = RcppDeepState_int ();
  val_stream.open("/home/akhila/Documents/compileAttributescheck/anytime/inst/testfiles/setMaxIntAsDate/inputs/ val");
 val_stream<< val;
std::cout <<"val values: "<< val << std::endl;
 val_stream.close();
 std::cout << "input ends" << std::endl;
 try{
setMaxIntAsDate( val);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
