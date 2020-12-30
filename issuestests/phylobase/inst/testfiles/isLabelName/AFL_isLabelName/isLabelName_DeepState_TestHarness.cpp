#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

bool isLabelName(Rcpp::CharacterVector lblToCheck, Rcpp::CharacterVector lbl);

TEST(phylobase_deepstate_test,isLabelName_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  CharacterVector lblToCheck  = RcppDeepState_CharacterVector();
  std::string lblToCheck_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/phylobase/inst/testfiles/isLabelName/AFL_isLabelName/afl_inputs/" + std::to_string(t) + "_lblToCheck.qs";
  std::string lbl_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/phylobase/inst/testfiles/isLabelName/AFL_isLabelName/afl_inputs/" + std::to_string(t) + "_lbl.qs";
  qs::c_qsave(lblToCheck,lblToCheck_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lblToCheck values: "<< lblToCheck << std::endl;
  CharacterVector lbl  = RcppDeepState_CharacterVector();
  std::string lbl_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/phylobase/inst/testfiles/isLabelName/AFL_isLabelName/afl_inputs/" + std::to_string(t) + "_lbl.qs";
  qs::c_qsave(lbl,lbl_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lbl values: "<< lbl << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    isLabelName(lblToCheck,lbl);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
