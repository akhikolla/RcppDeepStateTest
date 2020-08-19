#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericMatrix dispersal_kernel_cpp(int cur_x, int cur_y, int nc, int nr, NumericMatrix dk, NumericVector coefs, int standardize, IntegerVector first_order_terms, IntegerVector second_order_terms, NumericMatrix hab, NumericMatrix other_covars, IntegerVector other_covars_indicator, int stop);
TEST(amt_deepstate_test,dispersal_kernel_cpp_test){
std::ofstream  cur_x_stream;
std::ofstream  cur_y_stream;
std::ofstream  nc_stream;
std::ofstream  nr_stream;
std::ofstream  dk_stream;
std::ofstream  coefs_stream;
std::ofstream  standardize_stream;
std::ofstream  first_order_terms_stream;
std::ofstream  second_order_terms_stream;
std::ofstream  hab_stream;
std::ofstream  other_covars_stream;
std::ofstream  other_covars_indicator_stream;
std::ofstream  stop_stream;
 RInside();
 int cur_x = RcppDeepState_int ();
  cur_x_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/dispersal_kernel_cpp/inputs/ cur_x");
 cur_x_stream<< cur_x;
std::cout <<"cur_x values: "<< cur_x << std::endl;
 cur_x_stream.close();
 int cur_y = RcppDeepState_int ();
  cur_y_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/dispersal_kernel_cpp/inputs/ cur_y");
 cur_y_stream<< cur_y;
std::cout <<"cur_y values: "<< cur_y << std::endl;
 cur_y_stream.close();
 int nc = RcppDeepState_int ();
  nc_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/dispersal_kernel_cpp/inputs/ nc");
 nc_stream<< nc;
std::cout <<"nc values: "<< nc << std::endl;
 nc_stream.close();
 int nr = RcppDeepState_int ();
  nr_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/dispersal_kernel_cpp/inputs/ nr");
 nr_stream<< nr;
std::cout <<"nr values: "<< nr << std::endl;
 nr_stream.close();
 NumericMatrix dk = RcppDeepState_NumericMatrix ();
  dk_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/dispersal_kernel_cpp/inputs/ dk");
 dk_stream<< dk;
std::cout <<"dk values: "<< dk << std::endl;
 dk_stream.close();
 NumericVector coefs = RcppDeepState_NumericVector ();
  coefs_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/dispersal_kernel_cpp/inputs/ coefs");
 coefs_stream<< coefs;
std::cout <<"coefs values: "<< coefs << std::endl;
 coefs_stream.close();
 int standardize = RcppDeepState_int ();
  standardize_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/dispersal_kernel_cpp/inputs/ standardize");
 standardize_stream<< standardize;
std::cout <<"standardize values: "<< standardize << std::endl;
 standardize_stream.close();
 IntegerVector first_order_terms = RcppDeepState_IntegerVector ();
  first_order_terms_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/dispersal_kernel_cpp/inputs/ first_order_terms");
 first_order_terms_stream<< first_order_terms;
std::cout <<"first_order_terms values: "<< first_order_terms << std::endl;
 first_order_terms_stream.close();
 IntegerVector second_order_terms = RcppDeepState_IntegerVector ();
  second_order_terms_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/dispersal_kernel_cpp/inputs/ second_order_terms");
 second_order_terms_stream<< second_order_terms;
std::cout <<"second_order_terms values: "<< second_order_terms << std::endl;
 second_order_terms_stream.close();
 NumericMatrix hab = RcppDeepState_NumericMatrix ();
  hab_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/dispersal_kernel_cpp/inputs/ hab");
 hab_stream<< hab;
std::cout <<"hab values: "<< hab << std::endl;
 hab_stream.close();
 NumericMatrix other_covars = RcppDeepState_NumericMatrix ();
  other_covars_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/dispersal_kernel_cpp/inputs/ other_covars");
 other_covars_stream<< other_covars;
std::cout <<"other_covars values: "<< other_covars << std::endl;
 other_covars_stream.close();
 IntegerVector other_covars_indicator = RcppDeepState_IntegerVector ();
  other_covars_indicator_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/dispersal_kernel_cpp/inputs/ other_covars_indicator");
 other_covars_indicator_stream<< other_covars_indicator;
std::cout <<"other_covars_indicator values: "<< other_covars_indicator << std::endl;
 other_covars_indicator_stream.close();
 int stop = RcppDeepState_int ();
  stop_stream.open("/home/akhila/Documents/compileAttributescheck/amt/inst/testfiles/dispersal_kernel_cpp/inputs/ stop");
 stop_stream<< stop;
std::cout <<"stop values: "<< stop << std::endl;
 stop_stream.close();
 std::cout << "input ends" << std::endl;
 try{
dispersal_kernel_cpp( cur_x, cur_y, nc, nr, dk, coefs, standardize, first_order_terms, second_order_terms, hab, other_covars, other_covars_indicator, stop);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
