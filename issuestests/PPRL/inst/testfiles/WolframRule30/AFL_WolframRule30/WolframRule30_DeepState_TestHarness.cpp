#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

CharacterVector WolframRule30(CharacterVector ID, CharacterVector data, int lenBloom, int t);

TEST(PPRL_deepstate_test,WolframRule30_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  CharacterVector ID  = RcppDeepState_CharacterVector();
  std::string ID_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PPRL/inst/testfiles/WolframRule30/AFL_WolframRule30/afl_inputs/" + std::to_string(t) + "_ID.qs";
  qs::c_qsave(ID,ID_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ID values: "<< ID << std::endl;
  CharacterVector data  = RcppDeepState_CharacterVector();
  std::string data_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PPRL/inst/testfiles/WolframRule30/AFL_WolframRule30/afl_inputs/" + std::to_string(t) + "_data.qs";
  qs::c_qsave(data,data_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "data values: "<< data << std::endl;
  IntegerVector lenBloom(1);
  lenBloom[0]  = RcppDeepState_int();
  std::string lenBloom_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PPRL/inst/testfiles/WolframRule30/AFL_WolframRule30/afl_inputs/" + std::to_string(t) + "_lenBloom.qs";
  qs::c_qsave(lenBloom,lenBloom_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lenBloom values: "<< lenBloom << std::endl;
  IntegerVector t(1);
  t[0]  = RcppDeepState_int();
  std::string t_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PPRL/inst/testfiles/WolframRule30/AFL_WolframRule30/afl_inputs/" + std::to_string(t) + "_t.qs";
  qs::c_qsave(t,t_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t values: "<< t << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    WolframRule30(ID,data,lenBloom[0],t[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
