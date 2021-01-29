#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector funI(NumericVector col, int fam, int finsiz, int f);

TEST(NAM_deepstate_test,funI_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector col  = RcppDeepState_NumericVector();
  std::string col_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/funI/libFuzzer_funI/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_col.qs";
  qs::c_qsave(col,col_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "col values: "<< col << std::endl;
  IntegerVector fam(1);
  fam[0]  = RcppDeepState_int();
  std::string fam_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/funI/libFuzzer_funI/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_fam.qs";
  std::string f_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/funI/libFuzzer_funI/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_f.qs";
  qs::c_qsave(fam,fam_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fam values: "<< fam << std::endl;
  IntegerVector finsiz(1);
  finsiz[0]  = RcppDeepState_int();
  std::string finsiz_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/funI/libFuzzer_funI/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_finsiz.qs";
  std::string f_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/funI/libFuzzer_funI/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_f.qs";
  qs::c_qsave(finsiz,finsiz_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "finsiz values: "<< finsiz << std::endl;
  IntegerVector f(1);
  f[0]  = RcppDeepState_int();
  std::string f_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/funI/libFuzzer_funI/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_f.qs";
  qs::c_qsave(f,f_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "f values: "<< f << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    funI(col,fam[0],finsiz[0],f[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
