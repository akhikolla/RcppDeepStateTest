#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List do_sfm_enu(NumericVector heading, NumericVector pitch, NumericVector roll, NumericVector starboard, NumericVector forward, NumericVector mast);

TEST(oce_deepstate_test,do_sfm_enu_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector heading  = RcppDeepState_NumericVector();
  std::string heading_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_sfm_enu/libFuzzer_do_sfm_enu/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_heading.qs";
  qs::c_qsave(heading,heading_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "heading values: "<< heading << std::endl;
  NumericVector pitch  = RcppDeepState_NumericVector();
  std::string pitch_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_sfm_enu/libFuzzer_do_sfm_enu/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_pitch.qs";
  qs::c_qsave(pitch,pitch_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pitch values: "<< pitch << std::endl;
  NumericVector roll  = RcppDeepState_NumericVector();
  std::string roll_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_sfm_enu/libFuzzer_do_sfm_enu/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_roll.qs";
  qs::c_qsave(roll,roll_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "roll values: "<< roll << std::endl;
  NumericVector starboard  = RcppDeepState_NumericVector();
  std::string starboard_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_sfm_enu/libFuzzer_do_sfm_enu/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_starboard.qs";
  qs::c_qsave(starboard,starboard_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "starboard values: "<< starboard << std::endl;
  NumericVector forward  = RcppDeepState_NumericVector();
  std::string forward_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_sfm_enu/libFuzzer_do_sfm_enu/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_forward.qs";
  qs::c_qsave(forward,forward_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "forward values: "<< forward << std::endl;
  NumericVector mast  = RcppDeepState_NumericVector();
  std::string mast_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_sfm_enu/libFuzzer_do_sfm_enu/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_mast.qs";
  qs::c_qsave(mast,mast_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mast values: "<< mast << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    do_sfm_enu(heading,pitch,roll,starboard,forward,mast);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
