#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double expected_MI(IntegerVector ni_, IntegerVector n_j);
TEST(aricode_deepstate_test,expected_MI_test){
std::ofstream  ni__stream;
std::ofstream  n_j_stream;
 RInside();
 IntegerVector ni_ = RcppDeepState_IntegerVector ();
  ni__stream.open("/home/akhila/Documents/compileAttributescheck/aricode/inst/testfiles/expected_MI/inputs/ ni_");
 ni__stream<< ni_;
std::cout <<"ni_ values: "<< ni_ << std::endl;
 ni__stream.close();
 IntegerVector n_j = RcppDeepState_IntegerVector ();
  n_j_stream.open("/home/akhila/Documents/compileAttributescheck/aricode/inst/testfiles/expected_MI/inputs/ n_j");
 n_j_stream<< n_j;
std::cout <<"n_j values: "<< n_j << std::endl;
 n_j_stream.close();
 std::cout << "input ends" << std::endl;
 try{
expected_MI( ni_, n_j);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
