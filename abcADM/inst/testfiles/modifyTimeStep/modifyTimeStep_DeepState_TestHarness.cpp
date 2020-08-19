#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 void modifyTimeStep(const double newdt, const int verbose);
TEST(abcADM_deepstate_test,modifyTimeStep_test){
std::ofstream  newdt_stream;
std::ofstream  verbose_stream;
 RInside();
  double newdt = RcppDeepState_double ();
  newdt_stream.open("/home/akhila/Documents/compileAttributescheck/abcADM/inst/testfiles/modifyTimeStep/inputs/ newdt");
 newdt_stream<< newdt;
std::cout <<"newdt values: "<< newdt << std::endl;
 newdt_stream.close();
  int verbose = RcppDeepState_int ();
  verbose_stream.open("/home/akhila/Documents/compileAttributescheck/abcADM/inst/testfiles/modifyTimeStep/inputs/ verbose");
 verbose_stream<< verbose;
std::cout <<"verbose values: "<< verbose << std::endl;
 verbose_stream.close();
 try{
modifyTimeStep( newdt, verbose);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
