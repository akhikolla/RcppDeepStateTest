#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 List getRank(IntegerVector classi);
TEST(aricode_deepstate_test,getRank_test){
std::ofstream  classi_stream;
 RInside();
 IntegerVector classi = RcppDeepState_IntegerVector ();
  classi_stream.open("/home/akhila/Documents/compileAttributescheck/aricode/inst/testfiles/getRank/inputs/ classi");
 classi_stream<< classi;
std::cout <<"classi values: "<< classi << std::endl;
 classi_stream.close();
 std::cout << "input ends" << std::endl;
 try{
getRank( classi);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
