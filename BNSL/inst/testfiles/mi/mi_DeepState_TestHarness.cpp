#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double mi(NumericVector x, NumericVector y, int proc);

TEST(BNSL_deepstate_test,mi_test){
RInside R;              // create an embedded R instance
//RInside R(argc, argv);              // create an embedded R instance 
    //#if defined(RINSIDE_CALLBACKS)
    //R.set_callbacks( new Callbacks() );
    //R.repl() ;
   // #endif
    //exit(0);
   //int argc=0;
  //char *argv[] = nullptr;
  //RInside R(0,nullptr);
 //RInside R;
//RInside::RInside(0,nullptr);
//RInside R(0, nullptr);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/RcppDeepStateTest/BNSL/inst/testfiles/mi/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akhila/RcppDeepStateTest/BNSL/inst/testfiles/mi/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  std::ofstream proc_stream;
  int proc  = RcppDeepState_int();
  proc_stream.open("/home/akhila/RcppDeepStateTest/BNSL/inst/testfiles/mi/inputs/proc");
  proc_stream << proc;
  std::cout << "proc values: "<< proc << std::endl;
  proc_stream.close();
  std::cout << "input ends" << std::endl;
  try{
    mi(x,y,proc);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
