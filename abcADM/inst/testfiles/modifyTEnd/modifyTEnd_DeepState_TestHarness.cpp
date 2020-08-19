#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 void modifyTEnd(const double newEndT, const int verbose);
TEST(abcADM_deepstate_test,modifyTEnd_test){
std::ofstream  newEndT_stream;
std::ofstream  verbose_stream;
 RInside();
  double newEndT = RcppDeepState_double ();
  newEndT_stream.open("/home/akhila/Documents/compileAttributescheck/abcADM/inst/testfiles/modifyTEnd/inputs/ newEndT");
 newEndT_stream<< newEndT;
std::cout <<"newEndT values: "<< newEndT << std::endl;
 newEndT_stream.close();
  int verbose = RcppDeepState_int ();
  verbose_stream.open("/home/akhila/Documents/compileAttributescheck/abcADM/inst/testfiles/modifyTEnd/inputs/ verbose");
 verbose_stream<< verbose;
std::cout <<"verbose values: "<< verbose << std::endl;
 verbose_stream.close();
 try{
modifyTEnd( newEndT, verbose);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
