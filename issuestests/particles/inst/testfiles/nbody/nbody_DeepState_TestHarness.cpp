#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix nbody(NumericMatrix pos, NumericVector strength, double theta, double min_dist, double max_dist, double alpha);

TEST(particles_deepstate_test,nbody_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix pos  = RcppDeepState_NumericMatrix();
  qs::c_qsave(pos,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/nbody/inputs/pos.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pos values: "<< pos << std::endl;
  NumericVector strength  = RcppDeepState_NumericVector();
  qs::c_qsave(strength,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/nbody/inputs/strength.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "strength values: "<< strength << std::endl;
  NumericVector theta(1);
  theta[0]  = RcppDeepState_double();
  qs::c_qsave(theta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/nbody/inputs/theta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta values: "<< theta << std::endl;
  NumericVector min_dist(1);
  min_dist[0]  = RcppDeepState_double();
  qs::c_qsave(min_dist,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/nbody/inputs/min_dist.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "min_dist values: "<< min_dist << std::endl;
  NumericVector max_dist(1);
  max_dist[0]  = RcppDeepState_double();
  qs::c_qsave(max_dist,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/nbody/inputs/max_dist.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max_dist values: "<< max_dist << std::endl;
  NumericVector alpha(1);
  alpha[0]  = RcppDeepState_double();
  qs::c_qsave(alpha,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/particles/inst/testfiles/nbody/inputs/alpha.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "alpha values: "<< alpha << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    nbody(pos,strength,theta[0],min_dist[0],max_dist[0],alpha[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
