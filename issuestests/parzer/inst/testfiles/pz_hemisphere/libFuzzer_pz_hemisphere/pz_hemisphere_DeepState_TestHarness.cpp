#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

CharacterVector pz_hemisphere(CharacterVector lon, CharacterVector lat);

TEST(parzer_deepstate_test,pz_hemisphere_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  CharacterVector lon  = RcppDeepState_CharacterVector();
  std::string lon_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/parzer/inst/testfiles/pz_hemisphere/libFuzzer_pz_hemisphere/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lon.qs";
  qs::c_qsave(lon,lon_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lon values: "<< lon << std::endl;
  CharacterVector lat  = RcppDeepState_CharacterVector();
  std::string lat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/parzer/inst/testfiles/pz_hemisphere/libFuzzer_pz_hemisphere/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lat.qs";
  qs::c_qsave(lat,lat_t,
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
