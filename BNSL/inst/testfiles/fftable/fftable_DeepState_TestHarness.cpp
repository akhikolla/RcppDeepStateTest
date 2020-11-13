#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerMatrix fftable(NumericMatrix df, int w);

TEST(BNSL_deepstate_test,fftable_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix df  = RcppDeepState_NumericMatrix();
  qs::c_qsave(df,"/home/akhila/RcppDeepStateTest/BNSL/inst/testfiles/fftable/inputs/df.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "df values: "<< df << std::endl;
  std::ofstream w_stream;
  int w  = RcppDeepState_int();
  w_stream.open("/home/akhila/RcppDeepStateTest/BNSL/inst/testfiles/fftable/inputs/w");
  w_stream << w;
  std::cout << "w values: "<< w << std::endl;
  w_stream.close();
  std::cout << "input ends" << std::endl;
  try{
    fftable(df,w);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
