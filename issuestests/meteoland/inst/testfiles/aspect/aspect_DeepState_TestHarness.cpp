#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector aspect(NumericVector data, int nrows, int ncols, double cellWidth, double cellHeight);

TEST(meteoland_deepstate_test,aspect_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector data  = RcppDeepState_NumericVector();
  qs::c_qsave(data,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/aspect/inputs/data.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "data values: "<< data << std::endl;
  IntegerVector nrows(1);
  nrows[0]  = RcppDeepState_int();
  qs::c_qsave(nrows,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/aspect/inputs/nrows.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nrows values: "<< nrows << std::endl;
  IntegerVector ncols(1);
  ncols[0]  = RcppDeepState_int();
  qs::c_qsave(ncols,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/aspect/inputs/ncols.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ncols values: "<< ncols << std::endl;
  NumericVector cellWidth(1);
  cellWidth[0]  = RcppDeepState_double();
  qs::c_qsave(cellWidth,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/aspect/inputs/cellWidth.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cellWidth values: "<< cellWidth << std::endl;
  NumericVector cellHeight(1);
  cellHeight[0]  = RcppDeepState_double();
  qs::c_qsave(cellHeight,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/aspect/inputs/cellHeight.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cellHeight values: "<< cellHeight << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    aspect(data,nrows[0],ncols[0],cellWidth[0],cellHeight[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
