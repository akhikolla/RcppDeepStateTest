#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 List countPairs(IntegerVector classi1, IntegerVector classi2, IntegerVector order);
TEST(aricode_deepstate_test,countPairs_test){
std::ofstream  classi1_stream;
std::ofstream  classi2_stream;
std::ofstream  order_stream;
 RInside();
 IntegerVector classi1 = RcppDeepState_IntegerVector ();
  classi1_stream.open("/home/akhila/Documents/compileAttributescheck/aricode/inst/testfiles/countPairs/inputs/ classi1");
 classi1_stream<< classi1;
std::cout <<"classi1 values: "<< classi1 << std::endl;
 classi1_stream.close();
 IntegerVector classi2 = RcppDeepState_IntegerVector ();
  classi2_stream.open("/home/akhila/Documents/compileAttributescheck/aricode/inst/testfiles/countPairs/inputs/ classi2");
 classi2_stream<< classi2;
std::cout <<"classi2 values: "<< classi2 << std::endl;
 classi2_stream.close();
 IntegerVector order = RcppDeepState_IntegerVector ();
  order_stream.open("/home/akhila/Documents/compileAttributescheck/aricode/inst/testfiles/countPairs/inputs/ order");
 order_stream<< order;
std::cout <<"order values: "<< order << std::endl;
 order_stream.close();
 std::cout << "input ends" << std::endl;
 try{
countPairs( classi1, classi2, order);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
