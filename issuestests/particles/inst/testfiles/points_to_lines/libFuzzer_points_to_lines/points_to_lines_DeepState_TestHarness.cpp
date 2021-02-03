#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List points_to_lines(NumericMatrix line1, NumericMatrix line2, NumericMatrix point);

TEST(particles_deepstate_test,points_to_lines_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix line1  = RcppDeepState_NumericMatrix();
  std::string line1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/points_to_lines/libFuzzer_points_to_lines/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_line1.qs";
  qs::c_qsave(line1,line1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "line1 values: "<< line1 << std::endl;
  NumericMatrix line2  = RcppDeepState_NumericMatrix();
  std::string line2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/points_to_lines/libFuzzer_points_to_lines/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_line2.qs";
  qs::c_qsave(line2,line2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "line2 values: "<< line2 << std::endl;
  NumericMatrix point  = RcppDeepState_NumericMatrix();
  std::string point_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/points_to_lines/libFuzzer_points_to_lines/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_point.qs";
  qs::c_qsave(point,point_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "point values: "<< point << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    points_to_lines(line1,line2,point);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
