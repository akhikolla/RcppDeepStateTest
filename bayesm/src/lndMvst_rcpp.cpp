#include "bayesm.h"

// [[Rcpp::export]]
double lndMvst(vec const& x, double nu, vec const& mu, mat const& rooti, bool NORMC = false){

// Wayne Taylor 9/7/2014

// function to evaluate log of MVstudent t density with nu df, mean mu,
// and with sigmai=rooti%*%t(rooti)   note: this is the UL decomp of sigmai not LU!
// rooti is in the inverse of upper triangular chol root of sigma
// or Sigma=root'root   root=inv(rooti)

  int dim = x.size();
  double constant;
  
  if(NORMC){
    constant = (nu/2)*log(nu)+lgamma((nu+dim)/2)-(dim/2.0)*log(M_PI)-lgamma(nu/2);
  } else {
    constant = 0.0;
  }
  
  vec z = vectorise(trans(rooti)*(x-mu));
  
  return((constant-((dim+nu)/2)*log(nu+trans(z)*z)+sum(log(diagvec(rooti))))[0]);
}
