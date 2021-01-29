#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List do_ldc_ad2cp_in_file(CharacterVector filename, IntegerVector from, IntegerVector to, IntegerVector by);

TEST(oce_deepstate_test,do_ldc_ad2cp_in_file_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  CharacterVector filename  = RcppDeepState_CharacterVector();
  std::string filename_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_ldc_ad2cp_in_file/libFuzzer_do_ldc_ad2cp_in_file/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_filename.qs";
  qs::c_qsave(filename,filename_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "filename values: "<< filename << std::endl;
  IntegerVector from  = RcppDeepState_IntegerVector();
  std::string from_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_ldc_ad2cp_in_file/libFuzzer_do_ldc_ad2cp_in_file/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_from.qs";
  qs::c_qsave(from,from_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "from values: "<< from << std::endl;
  IntegerVector to  = RcppDeepState_IntegerVector();
  std::string to_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_ldc_ad2cp_in_file/libFuzzer_do_ldc_ad2cp_in_file/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_to.qs";
  qs::c_qsave(to,to_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "to values: "<< to << std::endl;
  IntegerVector by  = RcppDeepState_IntegerVector();
  std::string by_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_ldc_ad2cp_in_file/libFuzzer_do_ldc_ad2cp_in_file/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_by.qs";
  qs::c_qsave(by,by_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "by values: "<< by << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    do_ldc_ad2cp_in_file(filename,from,to,by);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
