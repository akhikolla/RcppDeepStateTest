#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector diff_rcpp(NumericVector xs);
TEST(amt_deepstate_test,diff_rcpp_test){
std::ofstream  xs_stream;
 RInside();
 NumericVector xs = RcppDeepState_NumericVector ();
  xs_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/diff_rcpp/inputs/ xs");
 xs_stream<< xs;
std::cout <<"xs values: "<< xs << std::endl;
 xs_stream.close();
 std::cout << "input ends" << std::endl;
 try{
diff_rcpp( xs);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
