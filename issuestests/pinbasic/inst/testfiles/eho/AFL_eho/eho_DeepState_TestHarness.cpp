#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double eho(NumericVector param, NumericVector numbuys, NumericVector numsells);

TEST(pinbasic_deepstate_test,eho_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector param  = RcppDeepState_NumericVector();
  std::string param_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/pinbasic/inst/testfiles/eho/AFL_eho/afl_inputs/" + std::to_string(t) + "_param.qs";
  qs::c_qsave(param,param_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "param values: "<< param << std::endl;
  NumericVector numbuys  = RcppDeepState_NumericVector();
  std::string numbuys_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/pinbasic/inst/testfiles/eho/AFL_eho/afl_inputs/" + std::to_string(t) + "_numbuys.qs";
  qs::c_qsave(numbuys,numbuys_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "numbuys values: "<< numbuys << std::endl;
  NumericVector numsells  = RcppDeepState_NumericVector();
  std::string numsells_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/pinbasic/inst/testfiles/eho/AFL_eho/afl_inputs/" + std::to_string(t) + "_numsells.qs";
  qs::c_qsave(numsells,numsells_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "numsells values: "<< numsells << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    eho(param,numbuys,numsells);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
