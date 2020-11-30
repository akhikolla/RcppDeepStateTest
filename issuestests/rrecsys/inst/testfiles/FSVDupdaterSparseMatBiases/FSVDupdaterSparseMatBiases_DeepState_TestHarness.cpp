#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List FSVDupdaterSparseMatBiases(NumericMatrix sparseRatingMat, double learningRate, double regCoef, int nrfeat, int steps, int nr_users, int nr_items, double globalbaseline);

TEST(rrecsys_deepstate_test,FSVDupdaterSparseMatBiases_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix sparseRatingMat  = RcppDeepState_NumericMatrix();
  qs::c_qsave(sparseRatingMat,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/FSVDupdaterSparseMatBiases/inputs/sparseRatingMat.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sparseRatingMat values: "<< sparseRatingMat << std::endl;
  NumericVector learningRate(1);
  learningRate[0]  = RcppDeepState_double();
  qs::c_qsave(learningRate,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/FSVDupdaterSparseMatBiases/inputs/learningRate.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "learningRate values: "<< learningRate << std::endl;
  NumericVector regCoef(1);
  regCoef[0]  = RcppDeepState_double();
  qs::c_qsave(regCoef,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/FSVDupdaterSparseMatBiases/inputs/regCoef.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "regCoef values: "<< regCoef << std::endl;
  IntegerVector nrfeat(1);
  nrfeat[0]  = RcppDeepState_int();
  qs::c_qsave(nrfeat,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/FSVDupdaterSparseMatBiases/inputs/nrfeat.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nrfeat values: "<< nrfeat << std::endl;
  IntegerVector steps(1);
  steps[0]  = RcppDeepState_int();
  qs::c_qsave(steps,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/FSVDupdaterSparseMatBiases/inputs/steps.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "steps values: "<< steps << std::endl;
  IntegerVector nr_users(1);
  nr_users[0]  = RcppDeepState_int();
  qs::c_qsave(nr_users,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/FSVDupdaterSparseMatBiases/inputs/nr_users.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nr_users values: "<< nr_users << std::endl;
  IntegerVector nr_items(1);
  nr_items[0]  = RcppDeepState_int();
  qs::c_qsave(nr_items,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/FSVDupdaterSparseMatBiases/inputs/nr_items.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nr_items values: "<< nr_items << std::endl;
  NumericVector globalbaseline(1);
  globalbaseline[0]  = RcppDeepState_double();
  qs::c_qsave(globalbaseline,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/FSVDupdaterSparseMatBiases/inputs/globalbaseline.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "globalbaseline values: "<< globalbaseline << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    FSVDupdaterSparseMatBiases(sparseRatingMat,learningRate[0],regCoef[0],nrfeat[0],steps[0],nr_users[0],nr_items[0],globalbaseline[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
