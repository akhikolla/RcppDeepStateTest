#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix collision(NumericMatrix pos, NumericMatrix vel, NumericVector radii, double strength);

TEST(particles_deepstate_test,collision_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix pos  = RcppDeepState_NumericMatrix();
  qs::c_qsave(pos,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/collision/inputs/pos.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pos values: "<< pos << std::endl;
  NumericMatrix vel  = RcppDeepState_NumericMatrix();
  qs::c_qsave(vel,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/collision/inputs/vel.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vel values: "<< vel << std::endl;
  NumericVector radii  = RcppDeepState_NumericVector();
  qs::c_qsave(radii,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/collision/inputs/radii.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "radii values: "<< radii << std::endl;
  NumericVector strength(1);
  strength[0]  = RcppDeepState_double();
  qs::c_qsave(strength,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/collision/inputs/strength.qs",
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
