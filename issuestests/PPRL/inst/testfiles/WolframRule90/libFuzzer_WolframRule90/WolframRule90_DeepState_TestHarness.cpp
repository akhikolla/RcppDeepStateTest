#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

CharacterVector WolframRule90(CharacterVector ID, CharacterVector data, int lenBloom, int t);

TEST(PPRL_deepstate_test,WolframRule90_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  CharacterVector ID  = RcppDeepState_CharacterVector();
  std::string ID_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PPRL/inst/testfiles/WolframRule90/libFuzzer_WolframRule90/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ID.qs";
  qs::c_qsave(ID,ID_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ID values: "<< ID << std::endl;
  CharacterVector data  = RcppDeepState_CharacterVector();
  std::string data_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PPRL/inst/testfiles/WolframRule90/libFuzzer_WolframRule90/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_data.qs";
  qs::c_qsave(data,data_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "data values: "<< data << std::endl;
  IntegerVector lenBloom(1);
  lenBloom[0]  = RcppDeepState_int();
  std::string lenBloom_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PPRL/inst/testfiles/WolframRule90/libFuzzer_WolframRule90/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lenBloom.qs";
  qs::c_qsave(lenBloom,lenBloom_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lenBloom values: "<< lenBloom << std::endl;
  IntegerVector t(1);
  t[0]  = RcppDeepState_int();
  std::string t_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PPRL/inst/testfiles/WolframRule90/libFuzzer_WolframRule90/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_t.qs";
  qs::c_qsave(t,t_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t values: "<< t << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    WolframRule90(ID,data,lenBloom[0],t[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
