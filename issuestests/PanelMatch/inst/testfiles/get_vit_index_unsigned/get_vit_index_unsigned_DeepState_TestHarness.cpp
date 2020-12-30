#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

std::vector<unsigned int> get_vit_index_unsigned(Rcpp::CharacterVector t_id_key, Rcpp::CharacterVector control_treatment_t_ids, Rcpp::NumericVector control_treatment_set_nums);

TEST(PanelMatch_deepstate_test,get_vit_index_unsigned_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  CharacterVector t_id_key  = RcppDeepState_CharacterVector();
  qs::c_qsave(t_id_key,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/get_vit_index_unsigned/inputs/t_id_key.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t_id_key values: "<< t_id_key << std::endl;
  CharacterVector control_treatment_t_ids  = RcppDeepState_CharacterVector();
  qs::c_qsave(control_treatment_t_ids,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/get_vit_index_unsigned/inputs/control_treatment_t_ids.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "control_treatment_t_ids values: "<< control_treatment_t_ids << std::endl;
  NumericVector control_treatment_set_nums  = RcppDeepState_NumericVector();
  qs::c_qsave(control_treatment_set_nums,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/get_vit_index_unsigned/inputs/control_treatment_set_nums.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "control_treatment_set_nums values: "<< control_treatment_set_nums << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    get_vit_index_unsigned(t_id_key,control_treatment_t_ids,control_treatment_set_nums);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
