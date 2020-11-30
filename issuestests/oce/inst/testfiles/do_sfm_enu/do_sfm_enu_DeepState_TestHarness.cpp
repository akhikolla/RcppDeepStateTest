#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List do_sfm_enu(NumericVector heading, NumericVector pitch, NumericVector roll, NumericVector starboard, NumericVector forward, NumericVector mast);

TEST(oce_deepstate_test,do_sfm_enu_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector heading  = RcppDeepState_NumericVector();
  qs::c_qsave(heading,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_sfm_enu/inputs/heading.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "heading values: "<< heading << std::endl;
  NumericVector pitch  = RcppDeepState_NumericVector();
  qs::c_qsave(pitch,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_sfm_enu/inputs/pitch.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pitch values: "<< pitch << std::endl;
  NumericVector roll  = RcppDeepState_NumericVector();
  qs::c_qsave(roll,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_sfm_enu/inputs/roll.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "roll values: "<< roll << std::endl;
  NumericVector starboard  = RcppDeepState_NumericVector();
  qs::c_qsave(starboard,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_sfm_enu/inputs/starboard.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "starboard values: "<< starboard << std::endl;
  NumericVector forward  = RcppDeepState_NumericVector();
  qs::c_qsave(forward,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_sfm_enu/inputs/forward.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "forward values: "<< forward << std::endl;
  NumericVector mast  = RcppDeepState_NumericVector();
  qs::c_qsave(mast,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_sfm_enu/inputs/mast.qs",
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
