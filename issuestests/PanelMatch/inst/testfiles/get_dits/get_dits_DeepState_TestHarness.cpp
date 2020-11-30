#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector get_dits(Rcpp::CharacterVector t_id_key, Rcpp::CharacterVector nonempty_t_ids);

TEST(PanelMatch_deepstate_test,get_dits_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  CharacterVector t_id_key  = RcppDeepState_CharacterVector();
  qs::c_qsave(t_id_key,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/get_dits/inputs/t_id_key.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t_id_key values: "<< t_id_key << std::endl;
  CharacterVector nonempty_t_ids  = RcppDeepState_CharacterVector();
  qs::c_qsave(nonempty_t_ids,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/get_dits/inputs/nonempty_t_ids.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nonempty_t_ids values: "<< nonempty_t_ids << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    get_dits(t_id_key,nonempty_t_ids);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
