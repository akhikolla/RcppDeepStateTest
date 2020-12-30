#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

CharacterVector pz_hemisphere(CharacterVector lon, CharacterVector lat);

TEST(parzer_deepstate_test,pz_hemisphere_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  CharacterVector lon  = RcppDeepState_CharacterVector();
  qs::c_qsave(lon,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/parzer/inst/testfiles/pz_hemisphere/inputs/lon.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lon values: "<< lon << std::endl;
  CharacterVector lat  = RcppDeepState_CharacterVector();
  qs::c_qsave(lat,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/parzer/inst/testfiles/pz_hemisphere/inputs/lat.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lat values: "<< lat << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    pz_hemisphere(lon,lat);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
