#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List cpp_coords_polygon_translate_wkb(NumericVector x, NumericVector y, NumericVector z, NumericVector m, IntegerVector featureId, IntegerVector ringId, int endian, int bufferSize);

TEST(wkutils_deepstate_test,cpp_coords_polygon_translate_wkb_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/wkutils/inst/testfiles/cpp_coords_polygon_translate_wkb/AFL_cpp_coords_polygon_translate_wkb/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/wkutils/inst/testfiles/cpp_coords_polygon_translate_wkb/AFL_cpp_coords_polygon_translate_wkb/afl_inputs/" + std::to_string(t) + "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector z  = RcppDeepState_NumericVector();
  std::string z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/wkutils/inst/testfiles/cpp_coords_polygon_translate_wkb/AFL_cpp_coords_polygon_translate_wkb/afl_inputs/" + std::to_string(t) + "_z.qs";
  qs::c_qsave(z,z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  NumericVector m  = RcppDeepState_NumericVector();
  std::string m_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/wkutils/inst/testfiles/cpp_coords_polygon_translate_wkb/AFL_cpp_coords_polygon_translate_wkb/afl_inputs/" + std::to_string(t) + "_m.qs";
  qs::c_qsave(m,m_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "m values: "<< m << std::endl;
  IntegerVector featureId  = RcppDeepState_IntegerVector();
  std::string featureId_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/wkutils/inst/testfiles/cpp_coords_polygon_translate_wkb/AFL_cpp_coords_polygon_translate_wkb/afl_inputs/" + std::to_string(t) + "_featureId.qs";
  qs::c_qsave(featureId,featureId_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "featureId values: "<< featureId << std::endl;
  IntegerVector ringId  = RcppDeepState_IntegerVector();
  std::string ringId_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/wkutils/inst/testfiles/cpp_coords_polygon_translate_wkb/AFL_cpp_coords_polygon_translate_wkb/afl_inputs/" + std::to_string(t) + "_ringId.qs";
  qs::c_qsave(ringId,ringId_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ringId values: "<< ringId << std::endl;
  IntegerVector endian(1);
  endian[0]  = RcppDeepState_int();
  std::string endian_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/wkutils/inst/testfiles/cpp_coords_polygon_translate_wkb/AFL_cpp_coords_polygon_translate_wkb/afl_inputs/" + std::to_string(t) + "_endian.qs";
  qs::c_qsave(endian,endian_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "endian values: "<< endian << std::endl;
  IntegerVector bufferSize(1);
  bufferSize[0]  = RcppDeepState_int();
  std::string bufferSize_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/wkutils/inst/testfiles/cpp_coords_polygon_translate_wkb/AFL_cpp_coords_polygon_translate_wkb/afl_inputs/" + std::to_string(t) + "_bufferSize.qs";
  qs::c_qsave(bufferSize,bufferSize_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bufferSize values: "<< bufferSize << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cpp_coords_polygon_translate_wkb(x,y,z,m,featureId,ringId,endian[0],bufferSize[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
