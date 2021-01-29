#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector get_vit_index(Rcpp::CharacterVector t_id_key, Rcpp::CharacterVector control_treatment_t_ids, Rcpp::NumericVector control_treatment_set_nums);

TEST(PanelMatch_deepstate_test,get_vit_index_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  CharacterVector t_id_key  = RcppDeepState_CharacterVector();
  std::string t_id_key_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/get_vit_index/libFuzzer_get_vit_index/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_t_id_key.qs";
  qs::c_qsave(t_id_key,t_id_key_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t_id_key values: "<< t_id_key << std::endl;
  CharacterVector control_treatment_t_ids  = RcppDeepState_CharacterVector();
  std::string control_treatment_t_ids_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/get_vit_index/libFuzzer_get_vit_index/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_control_treatment_t_ids.qs";
  qs::c_qsave(control_treatment_t_ids,control_treatment_t_ids_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "control_treatment_t_ids values: "<< control_treatment_t_ids << std::endl;
  NumericVector control_treatment_set_nums  = RcppDeepState_NumericVector();
  std::string control_treatment_set_nums_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/PanelMatch/inst/testfiles/get_vit_index/libFuzzer_get_vit_index/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_control_treatment_set_nums.qs";
  qs::c_qsave(control_treatment_set_nums,control_treatment_set_nums_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "control_treatment_set_nums values: "<< control_treatment_set_nums << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    get_vit_index(t_id_key,control_treatment_t_ids,control_treatment_set_nums);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
