#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List do_sfm_enu(NumericVector heading, NumericVector pitch, NumericVector roll, NumericVector starboard, NumericVector forward, NumericVector mast);

TEST(oce_deepstate_test,do_sfm_enu_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector heading  = RcppDeepState_NumericVector();
  std::string heading_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_sfm_enu/AFL_do_sfm_enu/afl_inputs/" + std::to_string(t) + "_heading.qs";
  qs::c_qsave(heading,heading_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "heading values: "<< heading << std::endl;
  NumericVector pitch  = RcppDeepState_NumericVector();
  std::string pitch_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_sfm_enu/AFL_do_sfm_enu/afl_inputs/" + std::to_string(t) + "_pitch.qs";
  qs::c_qsave(pitch,pitch_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pitch values: "<< pitch << std::endl;
  NumericVector roll  = RcppDeepState_NumericVector();
  std::string roll_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_sfm_enu/AFL_do_sfm_enu/afl_inputs/" + std::to_string(t) + "_roll.qs";
  qs::c_qsave(roll,roll_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "roll values: "<< roll << std::endl;
  NumericVector starboard  = RcppDeepState_NumericVector();
  std::string starboard_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_sfm_enu/AFL_do_sfm_enu/afl_inputs/" + std::to_string(t) + "_starboard.qs";
  qs::c_qsave(starboard,starboard_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "starboard values: "<< starboard << std::endl;
  NumericVector forward  = RcppDeepState_NumericVector();
  std::string forward_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_sfm_enu/AFL_do_sfm_enu/afl_inputs/" + std::to_string(t) + "_forward.qs";
  qs::c_qsave(forward,forward_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "forward values: "<< forward << std::endl;
  NumericVector mast  = RcppDeepState_NumericVector();
  std::string mast_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_sfm_enu/AFL_do_sfm_enu/afl_inputs/" + std::to_string(t) + "_mast.qs";
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
