#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix collision(NumericMatrix pos, NumericMatrix vel, NumericVector radii, double strength);

TEST(particles_deepstate_test,collision_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix pos  = RcppDeepState_NumericMatrix();
  std::string pos_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/collision/libFuzzer_collision/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_pos.qs";
  qs::c_qsave(pos,pos_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pos values: "<< pos << std::endl;
  NumericMatrix vel  = RcppDeepState_NumericMatrix();
  std::string vel_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/collision/libFuzzer_collision/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_vel.qs";
  qs::c_qsave(vel,vel_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vel values: "<< vel << std::endl;
  NumericVector radii  = RcppDeepState_NumericVector();
  std::string radii_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/collision/libFuzzer_collision/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_radii.qs";
  qs::c_qsave(radii,radii_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "radii values: "<< radii << std::endl;
  NumericVector strength(1);
  strength[0]  = RcppDeepState_double();
  std::string strength_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/collision/libFuzzer_collision/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_strength.qs";
  qs::c_qsave(strength,strength_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "strength values: "<< strength << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    collision(pos,vel,radii,strength[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
