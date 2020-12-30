#include <Rcpp.h>
using namespace Rcpp;

///////////////////////////////////////////////////////////////////////////////
/// log-likelihood function and its gradient function using parameterization
/// of phi (log of survival function or cumulative hazard function)
///////////////////////////////////////////////////////////////////////////////
double loglik(NumericVector phi, NumericMatrix Dm, NumericVector eta) {
  int J = Dm.ncol()-1, nsub = Dm.nrow();
  double result = 0.0;
  for (int i = 0; i < nsub; i++) {
    double templik = Dm(i, 0);
    for (int j = 0; j < J; j++) 
      templik += Dm(i, j+1)*exp(-phi[j]*exp(eta[i]));
    result += log(templik);
  }
  return result;  
}

NumericVector gradlik(NumericVector phi, NumericMatrix Dm, NumericVector eta) {
  int J = Dm.ncol()-1, nsub = Dm.nrow(), i, j;
  NumericVector Dphi(J, 0.0), Dphitemp(J);
  double templik, temp1, temp2, temp3;
  for (i = 0; i<nsub; i++) {
    Dphitemp.fill(0.0);
    templik = Dm(i, 0);
    temp1 = exp(eta[i]);
    for (j=0; j<J; j++) {
      temp2 = -phi[j]*temp1;
      temp3 = Dm(i, j+1)*exp(temp2);
      templik += temp3;
      Dphitemp[j] = -temp3*temp1;
    }
    for (j=0; j<J; j++) Dphi[j] += Dphitemp[j]/templik;
  }
  return Dphi;
}


NumericVector tophi(int J, NumericVector par) {
  NumericVector phi(J);
  double temp = 0.0;
  for (int i = 0; i < J; i++) {
    temp += exp(par[i]);
    phi[i] = temp;
  }   
  return phi;
}

// [[Rcpp::export]]
double loglik_lamb(NumericVector par, NumericMatrix Dm, NumericVector eta) {
  int J = Dm.ncol()-1;
  NumericVector phi = tophi(J, par);
  double result = loglik(phi, Dm, eta);
  return -result;  
}

// [[Rcpp::export]]
NumericVector gradlik_lamb(NumericVector par, NumericMatrix Dm, NumericVector eta) {
  int J = Dm.ncol()-1;
  NumericVector phi = tophi(J, par);
  NumericVector Dphi = gradlik(phi, Dm, eta);
  int j;
  NumericVector gr(J, 0.0);
  for (j=0; j<J; j++) 
    for (int k=0; k<=j; k++)
      gr[k] += -Dphi[j]*exp(par[k]);
  return gr;
}

/////////////////////////////////////////////////////////////////////////////////
///// FITSURV FUNCTION ASSUMING PIECEWISE EXPONENTIAL
/////////////////////////////////////////////////////////////////////////////////
NumericVector expand_par(int J, NumericVector par, IntegerVector breaks) {
  NumericVector par1(J);
  int k = 0;
  for (int j=0; j<J; j++) {
    if (j > breaks[k]) k++;
    par1[j] = par[k];
  }
  return par1;
}

void expand_par(int J, NumericVector par, NumericVector par1, IntegerVector breaks) {
  int k = 0;
  for (int j=0; j<J; j++) {
    if (j > breaks[k]) k++;
    par1[j] = par[k];
  }
}

// [[Rcpp::export]]
double loglik_pw(NumericVector par, NumericMatrix Dm, NumericVector eta, IntegerVector breaks) {
  int J=Dm.ncol()-1;
  NumericVector par1 = expand_par(J, par, breaks);
  NumericVector phi = tophi(J, par1);
  double result = loglik(phi, Dm, eta);
  return -result; 
}

// [[Rcpp::export]]
NumericVector gradlik_pw(NumericVector par, NumericMatrix Dm, NumericVector eta, IntegerVector breaks) {
  int J=Dm.ncol()-1, JS=breaks.size(), j, k;
  NumericVector par1 = expand_par(J, par, breaks);
  NumericVector phi = tophi(J, par1);
  NumericVector Dphi = gradlik(phi, Dm, eta);
  NumericVector gr1(J, 0.0);
  for (j=0; j<J; j++) 
    for (k=0; k<=j; k++)
      gr1[k] += -Dphi[j]*exp(par1[k]);
  NumericVector gr(JS, 0.0);
  k = 0;
  for (j=0; j<J; j++) {
    if (j > breaks[k]) k++;
    gr[k] += gr1[j];
  }
  return gr;
}

//////////////////////////////////////////////////////////////////////////////
///   LASSO FIT
//////////////////////////////////////////////////////////////////////////////
NumericVector compute_eta(NumericVector beta, NumericMatrix Xmat) {
  int nbeta = Xmat.ncol(), nsub = Xmat.nrow();
  NumericVector result(nsub, 0.0);
  for (int i = 0; i < nsub; i++) {
    for (int j = 0; j < nbeta; j++)
      result[i] += Xmat(i, j)*beta[j];
  }
  return result;
}

// Function to update w and z given eta, par, and Dm
void updatewz(NumericVector w, NumericVector z, NumericVector par, 
              NumericMatrix Dm, NumericVector eta) {
  int nsub = Dm.nrow(), J = Dm.ncol()-1, i, j;
  NumericVector eta1(nsub), eta2(nsub);
  NumericVector phi = tophi(J, par);
  for (i=0; i<nsub; i++) {
    double templik = Dm(i, 0);
    double dlik = 0.0, dlik1=0.0, dlik2=0.0;
    for (j=0; j<J;j++) {
      double ly = -phi[j]*exp(eta[i]);
      double y = exp(ly);
      templik += Dm(i, j+1)*y;
      dlik += Dm(i, j+1)*y*ly;
      dlik1 += Dm(i, j+1)*y*ly;
      dlik2 += Dm(i, j+1)*y*ly*(1+ly);      
    }
    eta1[i] = dlik/templik;
    eta2[i] = -dlik1*dlik1/(templik*templik) + dlik2/templik;
    w[i] = -eta2[i];
    z[i] = eta[i] - eta1[i]/eta2[i];
  }
}

double Mfunc(NumericVector w, NumericVector z, NumericVector eta, 
             NumericVector beta, double lambda) {
  int nsub = eta.size(), nbeta = beta.size();
  double lik = 0;
  for (int i = 0; i < nsub; i++) {
    lik += w[i]*(z[i] - eta[i])*(z[i] - eta[i]);
  }
  lik = lik/nsub;
  for (int k=0; k<nbeta; k++)
    lik += lambda*std::abs(beta[k]);
  return lik;
}

double sfunc(double beta, double lambda) {
  if (beta > lambda) {
    return beta - lambda;
  } else if (beta < -lambda) {
    return beta + lambda;
  } else {
    return 0;
  }
}

void fitbeta(NumericVector beta, NumericVector eta, int id, NumericVector w, 
             NumericVector z, NumericMatrix Xmat, double lambda) {
  int nsub = Xmat.nrow();
  double num = 0.0, dem = 0.0;
  for (int i = 0; i < nsub; i++) {
    double prog = eta[i] - Xmat(i, id)*beta[id];
    num += w[i]*Xmat(i, id)*(z[i] - prog);
    dem += w[i]*Xmat(i, id)*Xmat(i, id);
  }
  num = sfunc(num/nsub, lambda);
  dem = dem/nsub;
  double newbeta = num/dem;
  double delta = newbeta - beta[id];
  for (int i=0; i<nsub; i++) eta[i] += Xmat(i, id)*delta;
  beta[id] = newbeta;
}

void optMfunc(NumericVector beta, NumericVector eta, NumericVector w,
              NumericVector z, NumericMatrix Xmat, double lambda) {
  int nbeta = Xmat.ncol();
  double liknew = Mfunc(w, z, eta, beta, lambda), diff = 100;
  while (diff > 1e-8) {
    for (int i = 0; i < nbeta; i++) { 
      fitbeta(beta, eta, i, w, z, Xmat, lambda);
    }  
    double likold = liknew;
    liknew = Mfunc(w, z, eta, beta, lambda);
    diff  = std::abs((likold - liknew)/likold);
  }
}

double objfun(NumericVector par, NumericMatrix Dm, NumericVector beta, NumericVector eta, double lambda) {
  int nsub = Dm.nrow(), J = Dm.ncol()-1, nbeta=beta.size(), i;
  NumericVector phi = tophi(J, par);
  double lik = loglik(phi, Dm, eta);
  lik = lik*2/nsub;
  for (i=0; i<nbeta; i++)
    lik += -lambda*std::abs(beta[i]);
  return lik;
}

// [[Rcpp::export]]
double maxlambda(NumericMatrix Dm, NumericMatrix Xmat, NumericVector parm, Function fitsurv) {
  int nsub = Dm.nrow(), nbeta = Xmat.ncol(), i, j;
  NumericVector w(nsub), z(nsub), eta(nsub, 0.0);
  NumericVector par = clone(parm);
  par = fitsurv(par, Dm, eta);
  updatewz(w, z, par, Dm, eta);
  double max = 0.0;
  for (j=0; j<nbeta; j++) {
    double lam = 0;
    for (i=0; i<nsub; i++) {
      lam += w[i]*Xmat(i, j)*z[i];
    }
    lam = lam/nsub;
    if (lam > max) max = lam;
  }
  return max;
}

// [[Rcpp::export]]
NumericVector iclasso(NumericMatrix Dm, NumericMatrix Xmat, NumericVector parmi, double lambda, Function fitsurv, double tol) {
  int nsub = Dm.nrow(), J = Dm.ncol() - 1, nbeta = Xmat.ncol(), i, j;
  NumericVector par(J);
  NumericVector beta(nbeta);
  for (i = 0; i<J; i++) par[i] = parmi[i];
  for (j = 0; j<nbeta; j++) beta[j] = parmi[J+j];
  NumericVector eta = compute_eta(beta, Xmat);
  NumericVector w(nsub), z(nsub);
  double objnew = objfun(par, Dm, beta, eta, lambda), diff = 100;
  while (diff > tol) {
    par = fitsurv(par, Dm, eta);
    updatewz(w, z, par, Dm, eta);
    optMfunc(beta, eta, w, z, Xmat, lambda);
    double objold = objnew;
    objnew = objfun(par, Dm, beta, eta, lambda);
    diff = std::abs((objold - objnew)/objold);
  }
  NumericVector parm(J+nbeta);
  for (i = 0; i<J; i++) parm[i] = par[i];
  for (j = 0; j<nbeta; j++) parm[J+j] = beta[j];
  return parm;
}


//////////////////////////////////////////////////////////////////////////////
///   LASSO FIT ASSUMING PIECEWISE EXPONENTIAL
//////////////////////////////////////////////////////////////////////////////
// [[Rcpp::export]]
double maxlambda_pw(NumericMatrix Dm, NumericMatrix Xmat, NumericVector parm,
                    IntegerVector breaks, Function fitsurv_pw) {
  int nsub = Dm.nrow(), J = Dm.ncol() - 1, JS=breaks.size(), nbeta = Xmat.ncol(), i, j;
  if (J != breaks[JS-1] +1) stop("wrong input for breaks");
  NumericVector w(nsub), z(nsub), eta(nsub, 0.0);
  NumericVector par = clone(parm);
  par = fitsurv_pw(par, Dm, eta, breaks);
  NumericVector par1 = expand_par(J, par, breaks);
  updatewz(w, z, par1, Dm, eta);
  double max = 0.0;
  for (j=0; j<nbeta; j++) {
    double lam = 0;
    for (i=0; i<nsub; i++) {
      lam += w[i]*Xmat(i, j)*z[i];
    }
    lam = lam/nsub;
    if (lam > max) max = lam;
  }
  return max;
}

// [[Rcpp::export]]
NumericVector iclasso_pw(NumericMatrix Dm, NumericMatrix Xmat, NumericVector parmi,
                         IntegerVector breaks, double lambda, Function fitsurv_pw, double tol) {
  int nsub = Dm.nrow(), J = Dm.ncol() - 1, JS=breaks.size(), nbeta = Xmat.ncol(), i, j;
  if (J != breaks[JS-1] +1) stop("wrong input for breaks");
  NumericVector par1(J);
  NumericVector par(JS);
  NumericVector beta(nbeta);
  for (i = 0; i<JS; i++) par[i] = parmi[i];
  expand_par(J, par, par1, breaks);
  for (j = 0; j<nbeta; j++) beta[j] = parmi[JS+j];
  NumericVector eta = compute_eta(beta, Xmat);
  NumericVector w(nsub), z(nsub);
  double objnew = objfun(par1, Dm, beta, eta, lambda), diff = 100;
  while (diff > tol) {
    par = fitsurv_pw(par, Dm, eta, breaks);
    expand_par(J, par, par1, breaks);
    updatewz(w, z, par1, Dm, eta);
    optMfunc(beta, eta, w, z, Xmat, lambda);
    double objold = objnew;
    objnew = objfun(par1, Dm, beta, eta, lambda);
    diff = std::abs((objold - objnew)/objold);
  }
  NumericVector parm(JS+nbeta);
  for (i = 0; i<JS; i++) parm[i] = par1[i];
  for (j = 0; j<nbeta; j++) parm[JS+j] = beta[j];
  return parm;
}

///////////////////////////////////////////////////////////////////////////////////////////
///                                                                                    ////
///   Bayes Model                                                                      //// 
///                                                                                    ////
///////////////////////////////////////////////////////////////////////////////////////////
void updateeta(NumericVector eta, NumericVector beta, int j, double newbeta,
               NumericMatrix Xmat, NumericVector neweta) {
  int nsub = Xmat.nrow();
  for (int i=0; i<nsub; i++) 
    neweta[i] = eta[i] + Xmat(i, j)*(newbeta - beta[j]);
}

//' Bayesian method for high-dimensional variable selection
//' 
//' @param Dm the D matrix
//' @param Xmat the design matrix
//' @param b the prior distribution parameter for beta, normal std
//' @param om1 the prior distribution parameter for omega
//' @param om2 the piror distribution parameter for omega
//' @param niter number of iteration
//' @param psample the sampling probability for updading regresson coefficient
//' @param initsurv initial survival probabilities at end of study
//' @param nreport every how many iterations to output parameters
//' @param fitsurv the survival parameters optimization function
//' @export
// [[Rcpp::export]]
IntegerVector bayesmc(NumericMatrix Dm, NumericMatrix Xmat, double b, double om1, double om2,
                      int niter, double psample, double initsurv, int nreport, Function fitsurv) {
  int J = Dm.ncol() - 1, nsub = Xmat.nrow(), nbeta = Xmat.ncol(), i, j, newgamma, k, nselect;
  double newbeta, newlik, deltagamma, deltapost, deltabeta, deltac, rv;
  // initialization
  double omega;
  GetRNGstate();
  omega = R::rbeta(om1, om2);
  PutRNGstate();
  IntegerVector gamma(nbeta, 0);
  NumericVector beta(nbeta, 0.0);
  NumericVector eta(nsub, 0.0);
  NumericVector neweta(nsub);
  NumericVector par(J), newpar(J);
  for (i=0; i<J; i++) par[i] = log(-log(initsurv)/J);
  par = fitsurv(par, Dm, eta);
  double lik = -loglik_lamb(par, Dm, eta);
  //data to store gamma
  IntegerVector outgamma(2*niter + 1);
  outgamma[0] = nbeta;
  for (int iter=0; iter < niter; iter++) {
    //update one gamma
    GetRNGstate();
    j = nbeta*R::runif(0.0, 1.0);
    PutRNGstate();
    newgamma = 1 - gamma[j];
    //newbeta = newgamma == 0 ? 0.0 :  R::rnorm(0.0, b);
    // above replaced by below
    if (newgamma == 0) {
      newbeta = 0.0;
    } else {
      GetRNGstate();
      newbeta = R::rnorm(0.0, b);
      PutRNGstate();
    }
    updateeta(eta, beta, j, newbeta, Xmat, neweta);
    newpar = fitsurv(par, Dm, neweta);
    newlik = -loglik_lamb(newpar, Dm, neweta);
    deltagamma = newgamma == 1 ? log(omega/(1-omega)) : log((1-omega)/omega);
    deltapost = newlik - lik + deltagamma;
    GetRNGstate();
    deltac = R::runif(0.0, 1.0);
    PutRNGstate();
    if (log(deltac) < deltapost) {
      lik = newlik;
      for (k=0; k<nsub; k++) eta[k] = neweta[k];
      beta[j] = newbeta;
      gamma[j] = newgamma;
      par = newpar;
      outgamma[2*iter+1] = j;
      outgamma[2*iter+2] = 1;
    } else {
      outgamma[2*iter+1] = j;
      outgamma[2*iter+2] = 0;        
    }
    // updage regression coefficients
    for (int p = 0; p < nbeta; p++) {
      if (gamma[p] == 1) {
        GetRNGstate();
        rv = R::runif(0.0, 1.0);
        PutRNGstate();
        if (rv < psample) {
          // propose a new beta
          GetRNGstate();
          newbeta = R::rnorm(beta[p], b);
          PutRNGstate();
          updateeta(eta, beta, p, newbeta, Xmat, neweta);
          // get the optimized par
          newpar = fitsurv(par, Dm, neweta);
          newlik = -loglik_lamb(newpar, Dm, neweta);
          deltabeta = R::dnorm(newbeta, 0.0, b, 1) - R::dnorm(beta[p], 0.0, b, 1);
          deltapost = newlik - lik + deltabeta;
          GetRNGstate();
          deltac = R::runif(0.0, 1.0);
          PutRNGstate();
          if (log(deltac) < deltapost) {
            lik = newlik;
            for (k=0; k<nsub; k++) eta[k] = neweta[k];
            beta[p] = newbeta;
            par = newpar;
          }            
        }
      }
    }
    // update lambda
    //par = fitsurv(par, Dm, eta);
    //update omega
    nselect = 0;
    for (k=0; k<nbeta; k++) nselect += gamma[k]; 
    GetRNGstate();
    omega = R::rbeta(om1 + nselect, om2 + nbeta - nselect);
    PutRNGstate();
    //report
    if (iter % nreport == 0) {
      //       std::cout << "At iteration " << iter <<".  Model size: " << nselect <<"\n";
      //       std::cout << "Survival parameters:";
      //       for (k=0;k < J; k++) std::cout << par[k] << ",  ";
      //       std::cout << "\n";      
      Rprintf("At iteration %d, model size is: %d. \n", iter, nselect);
      Rprintf("Survival parameters:");
      for (k=0;k < J; k++) Rprintf("   %f8", par[k]);
      Rprintf("\n\n");
    }
  }
  return outgamma;    
}    

// [[Rcpp::export]]
IntegerVector bayesmc_pw(NumericMatrix Dm, NumericMatrix Xmat, IntegerVector breaks, double b, double om1, double om2,
                         int niter, double psample, double initsurv, int nreport, Function fitsurv_pw) {
  RNGScope scope;
  int J = Dm.ncol() - 1, JS=breaks.size(), nsub = Xmat.nrow(), nbeta = Xmat.ncol(), i, j, newgamma, k, nselect;
  if (J != breaks[JS-1] +1) stop("wrong input for breaks");
  double newbeta, newlik, deltagamma, deltapost, deltabeta, deltac, rv;
  // initialization
  double omega;
  GetRNGstate();
  omega = R::rbeta(om1, om2);
  PutRNGstate();
  IntegerVector gamma(nbeta, 0);
  NumericVector beta(nbeta, 0.0);
  NumericVector eta(nsub, 0.0);
  NumericVector neweta(nsub);
  NumericVector par(JS), newpar(JS);
  for (i=0; i<JS; i++) par[i] = log(-log(initsurv)/J);
  par = fitsurv_pw(par, Dm, eta, breaks);
  double lik = -loglik_pw(par, Dm, eta, breaks);
  //data to store gamma
  IntegerVector outgamma(2*niter + 1);
  outgamma[0] = nbeta;
  for (int iter=0; iter < niter; iter++) {
    //update one gamma
    GetRNGstate();
    j = nbeta*R::runif(0.0, 1.0);
    PutRNGstate();
    newgamma = 1 - gamma[j];
    //newbeta = newgamma == 0 ? 0.0 :  R::rnorm(0.0, b);
    // above replaced by below
    if (newgamma == 0) {
      newbeta = 0.0;
    } else {
      GetRNGstate();
      newbeta = R::rnorm(0.0, b);
      PutRNGstate();
    }
    updateeta(eta, beta, j, newbeta, Xmat, neweta);
    newpar = fitsurv_pw(par, Dm, neweta, breaks);
    newlik = -loglik_pw(newpar, Dm, neweta, breaks);
    deltagamma = newgamma == 1 ? log(omega/(1-omega)) : log((1-omega)/omega);
    deltapost = newlik - lik + deltagamma;
    GetRNGstate();
    deltac = R::runif(0.0, 1.0);
    PutRNGstate();
    if (log(deltac) < deltapost) {
      lik = newlik;
      for (k=0; k<nsub; k++) eta[k] = neweta[k];
      beta[j] = newbeta;
      gamma[j] = newgamma;
      outgamma[2*iter+1] = j;
      outgamma[2*iter+2] = 1;
      par = newpar;
    } else {
      outgamma[2*iter+1] = j;
      outgamma[2*iter+2] = 0;        
    }    
    // updage regression coefficients
    for (int p = 0; p < nbeta; p++) {
      if (gamma[p] == 1) {
        GetRNGstate();
        rv = R::runif(0.0, 1.0);
        PutRNGstate();
        if (rv < psample) {
          // propose a new beta
          GetRNGstate();
          newbeta = R::rnorm(beta[p], b);
          PutRNGstate();
          updateeta(eta, beta, p, newbeta, Xmat, neweta);
          // optimized par
          newpar = fitsurv_pw(par, Dm, neweta, breaks);
          newlik = -loglik_pw(newpar, Dm, neweta, breaks);
          deltabeta = R::dnorm(newbeta, 0.0, b, 1) - R::dnorm(beta[p], 0.0, b, 1);
          deltapost = newlik - lik + deltabeta;
          GetRNGstate();
          deltac = R::runif(0.0, 1.0);
          PutRNGstate();
          if (log(deltac) < deltapost) {
            lik = newlik;
            for (k=0; k<nsub; k++) eta[k] = neweta[k];
            beta[p] = newbeta;
            par = newpar;
          }            
        }
      }
    }
    // update lambda
    //par = fitsurv_pw(par, Dm, eta, breaks);
    //update omega
    nselect = 0;
    for (k=0; k<nbeta; k++) nselect += gamma[k]; 
    GetRNGstate();
    omega = R::rbeta(om1 + nselect, om2 + nbeta - nselect);
    PutRNGstate();
    //report
    if (iter % nreport == 0) {
      //       std::cout << "At iteration " << iter <<".  Model size: " << nselect <<"\n";
      //       std::cout << "Survival parameters:";
      //       for (k=0;k < JS; k++) std::cout << par[k] << ",  ";
      //       std::cout << "\n";       
      Rprintf("At iteration %d, model size is: %d. \n", iter, nselect);
      Rprintf("Survival parameters:");
      for (k=0;k < JS; k++) Rprintf("   %f8", par[k]);
      Rprintf("\n\n");
    }
  }
  return outgamma;    
}    

// [[Rcpp::export]]
NumericVector gamma_mean(IntegerVector outgamma, int start) {
  int niter = (outgamma.size()-1)/ 2, nbeta = outgamma[0];
  IntegerVector gamma(nbeta, 0);
  NumericVector result(nbeta, 0.0);
  int count = 0;
  for (int i=0; i<niter; i++) {
    int j = outgamma[2*i + 1];
    int change = outgamma[2*i + 2];
    if (change == 1)
      gamma[j] = 1 - gamma[j];
    if (i >= start) {
      for (int k=0; k<nbeta; k++) {
        result[k] += gamma[k];
      }
      count++;
    }  
  }
  return result / count;
}



///////////////////////////////////////////////////////////////////////////////////////////
///                                                                                    ////
///   FOR USE OF Xmat WITH STORAGE OF RAW DATA FORMAT                                  ////
///   Will lose computational efficiency but gaining storage efficiency                ////  
///                                                                                    ////
///////////////////////////////////////////////////////////////////////////////////////////
// Decode Xmat
// 0: missing, 1: aa, 2:Aa, 3: AA

// 3 -> 0, 2 -> 1
// [[Rcpp::export]]
void Xmat_decode(RawMatrix Xmat) {
  int nsub=Xmat.nrow(), nbeta=Xmat.ncol();
  for (int i=0; i<nsub; i++) {
    for (int j=0; j<nbeta; j++) {
      if (Xmat(i, j) == 3) {
        Xmat(i, j) = 0;
      } else if (Xmat(i, j)==2) {
        Xmat(i, j) = 1;
      }
    }
  }
}

// 3->0, 1->2, 2->1
// [[Rcpp::export]]
void Xmat_decode3(RawMatrix Xmat) {
  int nsub=Xmat.nrow(), nbeta=Xmat.ncol();
  for (int i=0; i<nsub; i++) {
    for (int j=0; j<nbeta; j++) {
      if (Xmat(i, j) == 3) {
        Xmat(i, j) = 0;
      } else if (Xmat(i, j) == 2) {
        Xmat(i, j) = 1;
      } else if (Xmat(i, j) == 1) {
        Xmat(i, j) = 2;
      }
    }
  }
}

NumericVector Xmat_mean(RawMatrix Xmat) {
  int nsub = Xmat.nrow(), nbeta = Xmat.ncol();
  NumericVector result(nbeta, 0.0);
  for (int j=0; j<nbeta; j++) {
    for (int i=0; i<nsub; i++)
      result[j] += Xmat(i, j);
    result[j] = result[j]/nsub;
  }
  return result;
}

NumericVector Xmat_sd(RawMatrix Xmat) {
  int nsub = Xmat.nrow(), nbeta = Xmat.ncol();
  NumericVector result(nbeta);
  for (int j=0; j<nbeta; j++) {
    double sum = 0.0, sum2 = 0.0;
    for (int i=0; i<nsub; i++) {
      double temp = (double)Xmat(i, j);
      sum += temp;
      sum2 += temp;
    }
    double avg = sum/nsub;
    result[j] = std::sqrt((sum2 - nsub*avg*avg)/(nsub - 1));
  }
  return result;
}

// This function compute two possible normalized values
// assuming Xmat takes values either 0 or 1
// [[Rcpp::export]]
NumericMatrix Xmat_norm(RawMatrix Xmat) {
  NumericVector mean = Xmat_mean(Xmat);
  NumericVector sd = Xmat_sd(Xmat);
  int nbeta = Xmat.ncol();
  NumericMatrix sdv(2, nbeta);
  for (int i=0; i<nbeta;i++) {
    sdv(0, i) = -mean[i]/sd[i];
    sdv(1, i) = (1-mean[i])/sd[i];
  }
  return sdv;
}

// Modified compute_eta function
NumericVector compute_eta(NumericVector beta, RawMatrix Xmat, NumericMatrix sdv) {
  int nbeta = Xmat.ncol(), nsub = Xmat.nrow();
  NumericVector result(nsub, 0.0);
  for (int i = 0; i < nsub; i++) {
    for (int j = 0; j < nbeta; j++)
      result[i] += sdv(Xmat(i, j), j)*beta[j];
  }
  return result;
}

// Modified fitbeta function
void fitbeta(NumericVector beta, NumericVector eta, int id, NumericVector w, 
             NumericVector z, RawMatrix Xmat, NumericMatrix sdv, double lambda) {
  int nsub = Xmat.nrow();
  double num = 0.0, dem = 0.0;
  for (int i = 0; i < nsub; i++) {
    double prog = eta[i] - sdv(Xmat(i, id), id)*beta[id];
    num += w[i]*sdv(Xmat(i, id), id)*(z[i] - prog);
    dem += w[i]*sdv(Xmat(i, id), id)*sdv(Xmat(i, id), id);
  }
  num = sfunc(num/nsub, lambda);
  dem = dem/nsub;
  double newbeta = num/dem;
  double delta = newbeta - beta[id];
  for (int i=0; i<nsub; i++) eta[i] += sdv(Xmat(i, id), id)*delta;
  beta[id] = newbeta;
}

// Modified optMfunc function
void optMfunc(NumericVector beta, NumericVector eta, NumericVector w,
              NumericVector z, RawMatrix Xmat, NumericMatrix sdv, double lambda) {
  int nbeta = Xmat.ncol();
  double liknew = Mfunc(w, z, eta, beta, lambda), diff = 100;
  while (diff > 1e-8) {
    for (int i = 0; i < nbeta; i++) { 
      fitbeta(beta, eta, i, w, z, Xmat, sdv, lambda);
    }  
    double likold = liknew;
    liknew = Mfunc(w, z, eta, beta, lambda);
    diff  = std::abs((likold - liknew)/likold);
  }
}

// Log-likelihood functions
// [[Rcpp::export]]
double loglik_raw(NumericVector parm, NumericMatrix Dm, RawMatrix Xmat, NumericMatrix sdv) {
  int J = Dm.ncol()-1, nbeta=Xmat.ncol();
  NumericVector par(J);
  NumericVector beta(nbeta);
  for (int i = 0; i<J; i++) par[i] = parm[i];
  for (int j = 0; j<nbeta; j++) beta[j] = parm[J+j];
  NumericVector eta = compute_eta(beta, Xmat, sdv);
  return -loglik_lamb(par, Dm, eta);
}

// [[Rcpp::export]]
double loglik_pw_raw(NumericVector parm,  IntegerVector breaks, NumericMatrix Dm, RawMatrix Xmat, NumericMatrix sdv) {
  int JS = breaks.size(), nbeta=Xmat.ncol();
  NumericVector par(JS);
  NumericVector beta(nbeta);
  for (int i = 0; i<JS; i++) par[i] = parm[i];
  for (int j = 0; j<nbeta; j++) beta[j] = parm[JS+j];
  NumericVector eta = compute_eta(beta, Xmat, sdv);
  return -loglik_pw(par, Dm, eta, breaks);
}

// [[Rcpp::export]]
double maxlambda_raw(NumericMatrix Dm, RawMatrix Xmat, NumericMatrix sdv,
                     NumericVector parm, Function fitsurv) {
  int nsub = Dm.nrow(), nbeta = Xmat.ncol(), i, j;
  NumericVector w(nsub), z(nsub), eta(nsub, 0.0);
  NumericVector par = clone(parm);
  par = fitsurv(par, Dm, eta);
  updatewz(w, z, par, Dm, eta);
  double max = 0.0;
  for (j=0; j<nbeta; j++) {
    double lam = 0;
    for (i=0; i<nsub; i++) {
      lam += w[i]*sdv(Xmat(i, j), j)*z[i];
    }
    lam = lam/nsub;
    if (lam > max) max = lam;
  }
  return max;
}


// [[Rcpp::export]]
NumericVector iclasso_raw(NumericMatrix Dm, RawMatrix Xmat, NumericMatrix sdv, NumericVector parmi,
                          double lambda, Function fitsurv, double tol) {
  int nsub = Dm.nrow(), J = Dm.ncol() - 1, nbeta = Xmat.ncol(), i, j;
  NumericVector par(J);
  NumericVector beta(nbeta);
  for (i = 0; i<J; i++) par[i] = parmi[i];
  for (j = 0; j<nbeta; j++) beta[j] = parmi[J+j];
  NumericVector eta = compute_eta(beta, Xmat, sdv);
  NumericVector w(nsub), z(nsub);
  double objnew = objfun(par, Dm, beta, eta, lambda), diff = 100;
  while (diff > tol) {
    par = fitsurv(par, Dm, eta);
    updatewz(w, z, par, Dm, eta);
    optMfunc(beta, eta, w, z, Xmat, sdv, lambda);
    double objold = objnew;
    objnew = objfun(par, Dm, beta, eta, lambda);
    diff = std::abs((objold - objnew)/objold);
  }
  NumericVector parm(J+nbeta);
  for (i = 0; i<J; i++) parm[i] = par[i];
  for (j = 0; j<nbeta; j++) parm[J+j] = beta[j];
  return parm;
}

// [[Rcpp::export]]
double maxlambda_pw_raw(NumericMatrix Dm, RawMatrix Xmat, NumericMatrix sdv, NumericVector parm,
                        IntegerVector breaks, Function fitsurv_pw) {
  int nsub = Dm.nrow(), J = Dm.ncol() - 1, JS=breaks.size(), nbeta = Xmat.ncol(), i, j;
  if (J != breaks[JS-1] +1) stop("wrong input for breaks");
  NumericVector w(nsub), z(nsub), eta(nsub, 0.0);
  NumericVector par = clone(parm);
  par = fitsurv_pw(par, Dm, eta, breaks);
  NumericVector par1 = expand_par(J, par, breaks);
  updatewz(w, z, par1, Dm, eta);
  double max = 0.0;
  for (j=0; j<nbeta; j++) {
    double lam = 0;
    for (i=0; i<nsub; i++) {
      lam += w[i]*sdv(Xmat(i, j), j)*z[i];
    }
    lam = lam/nsub;
    if (lam > max) max = lam;
  }
  return max;
}

// [[Rcpp::export]]
NumericVector iclasso_pw_raw(NumericMatrix Dm, RawMatrix Xmat, NumericMatrix sdv, NumericVector parmi,
                             IntegerVector breaks, double lambda, Function fitsurv_pw, double tol) {
  int nsub = Dm.nrow(), J = Dm.ncol() - 1, JS=breaks.size(), nbeta = Xmat.ncol(), i, j;
  if (J != breaks[JS-1] +1) stop("wrong input for breaks");
  NumericVector par1(J);
  NumericVector par(JS);
  NumericVector beta(nbeta);
  for (i = 0; i<JS; i++) par[i] = parmi[i];
  expand_par(J, par, par1, breaks);
  for (j = 0; j<nbeta; j++) beta[j] = parmi[JS+j];
  NumericVector eta = compute_eta(beta, Xmat, sdv);
  NumericVector w(nsub), z(nsub);
  double objnew = objfun(par1, Dm, beta, eta, lambda), diff = 100;
  while (diff > tol) {
    par = fitsurv_pw(par, Dm, eta, breaks);
    expand_par(J, par, par1, breaks);
    updatewz(w, z, par1, Dm, eta);
    optMfunc(beta, eta, w, z, Xmat, sdv, lambda);
    double objold = objnew;
    objnew = objfun(par1, Dm, beta, eta, lambda);
    diff = std::abs((objold - objnew)/objold);
  }
  NumericVector parm(JS+nbeta);
  for (i = 0; i<JS; i++) parm[i] = par1[i];
  for (j = 0; j<nbeta; j++) parm[JS+j] = beta[j];
  return parm;
}


// void updateeta(NumericVector eta, NumericVector beta, int j, double newbeta,
//                RawMatrix Xmat, NumericVector sdv, NumericVector neweta) {
//   int nsub = Xmat.nrow();
//   for (int i=0; i<nsub; i++) 
//     neweta[i] = eta[i] + sdv(Xmat(i, j), j)*(newbeta - beta[j]);
// }

void updateeta(NumericVector eta, NumericVector beta, int j, double newbeta,
               RawMatrix Xmat, NumericVector neweta) {
  int nsub = Xmat.nrow();
  for (int i=0; i<nsub; i++) 
    neweta[i] = eta[i] + Xmat(i, j)*(newbeta - beta[j]);
}

// // [[Rcpp::export]]
// IntegerVector bayesmc_raw(NumericMatrix Dm, RawMatrix Xmat, double b, double om1, double om2,
//                           int niter, double psample, double initsurv, int nreport, Function fitsurv) {
//   RNGScope scope;
//   NumericVector sdv = Xmat_norm(Xmat);
//   int J = Dm.ncol() - 1, nsub = Xmat.nrow(), nbeta = Xmat.ncol(), i, j, newgamma, k, nselect;
//   double newbeta, newlik, deltagamma, deltapost, deltabeta;
//   // initialization
//   double omega = R::rbeta(om1, om2);
//   IntegerVector gamma(nbeta, 0);
//   NumericVector beta(nbeta, 0.0);
//   NumericVector eta(nsub, 0.0);
//   NumericVector neweta(nsub);
//   NumericVector par(J), newpar(J);
//   for (i=0; i<J; i++) par[i] = log(-log(initsurv)/J);
//   par = fitsurv(par, Dm, eta);
//   double lik = -loglik_lamb(par, Dm, eta);
//   //data to store gamma
//   IntegerVector outgamma(2*niter + 1);
//   outgamma[0] = nbeta;
//   for (int iter=0; iter < niter; iter++) {
//     //update one gamma
//     j = nbeta*R::runif(0.0, 1.0);
//     newgamma = 1 - gamma[j];
//     newbeta = newgamma == 0 ? 0.0 :  R::rnorm(0.0, b);
//     // updateeta(eta, beta, j, newbeta, Xmat, sdv, neweta);
//     updateeta(eta, beta, j, newbeta, Xmat, neweta);
//     newpar = fitsurv(par, Dm, neweta);
//     newlik = -loglik_lamb(newpar, Dm, neweta);
//     deltagamma = newgamma == 1 ? log(omega/(1-omega)) : log((1-omega)/omega);
//     deltapost = newlik - lik + deltagamma;
//     if (log(R::runif(0.0, 1.0)) < deltapost) {
//       lik = newlik;
//       for (k=0; k<nsub; k++) eta[k] = neweta[k];
//       beta[j] = newbeta;
//       gamma[j] = newgamma;
//       par = newpar;
//       outgamma[2*iter+1] = j;
//       outgamma[2*iter+2] = 1;
//     } else {
//       outgamma[2*iter+1] = j;
//       outgamma[2*iter+2] = 0;        
//     }    
//     // updage regression coefficients
//     for (int p = 0; p < nbeta; p++) {
//       if (gamma[p] == 1) {
//         if (R::runif(0.0, 1.0) < psample) {
//           newbeta = R::rnorm(beta[p], b);
//           // updateeta(eta, beta, p, newbeta, Xmat, sdv, neweta);
//           updateeta(eta, beta, p, newbeta, Xmat, neweta);
//           // new optimized par
//           newpar = fitsurv(par, Dm, neweta);
//           newlik = -loglik_lamb(newpar, Dm, neweta);
//           deltabeta = R::dnorm(newbeta, 0.0, b, 1) - R::dnorm(beta[p], 0.0, b, 1);
//           deltapost = newlik - lik + deltabeta;
//           if (log(R::runif(0.0, 1.0)) < deltapost) {
//             lik = newlik;
//             for (k=0; k<nsub; k++) eta[k] = neweta[k];
//             beta[p] = newbeta;
//             newpar = par;
//           }            
//         }
//       }
//     }
//     // update lambda
//     //par = fitsurv(par, Dm, eta);
//     //update omega
//     nselect = 0;
//     for (k=0; k<nbeta; k++) nselect += gamma[k]; 
//     omega = R::rbeta(om1 + nselect, om2 + nbeta - nselect);
//     //report
//     if (iter % nreport == 0) {
//       //        std::cout << "At iteration " << iter <<".  Model size: " << nselect <<"\n";
//       //        std::cout << "Survival parameters:";
//       //        for (k=0;k < J; k++) std::cout << par[k] << ",  ";
//       //        std::cout << "\n";       
//       Rprintf("At iteration %d, model size is: %d. \n", iter, nselect);
//       Rprintf("Survival parameters:");
//       for (k=0;k < J; k++) Rprintf("   %f8", par[k]);
//       Rprintf("\n\n");
//     }
//   }
//   return outgamma;    
// }    
// 
// // [[Rcpp::export]]
// IntegerVector bayesmc_pw_raw(NumericMatrix Dm, RawMatrix Xmat, IntegerVector breaks, double b, double om1, double om2,
//                              int niter, double psample, double initsurv, int nreport, Function fitsurv_pw) {
//   RNGScope scope;
//   NumericVector sdv = Xmat_norm(Xmat);
//   int J = Dm.ncol() - 1, JS=breaks.size(), nsub = Xmat.nrow(), nbeta = Xmat.ncol(), i, j, newgamma, k, nselect;
//   if (J != breaks[JS-1] +1) stop("wrong input for breaks");
//   double newbeta, newlik, deltagamma, deltapost, deltabeta;
//   // initialization
//   double omega = R::rbeta(om1, om2);
//   IntegerVector gamma(nbeta, 0);
//   NumericVector beta(nbeta, 0.0);
//   NumericVector eta(nsub, 0.0);
//   NumericVector neweta(nsub);
//   NumericVector par(JS), newpar(JS);
//   for (i=0; i<JS; i++) par[i] = log(-log(initsurv)/J);
//   par = fitsurv_pw(par, Dm, eta, breaks);
//   double lik = -loglik_pw(par, Dm, eta, breaks);
//   //data to store gamma
//   IntegerVector outgamma(2*niter + 1);
//   outgamma[0] = nbeta;
//   for (int iter=0; iter < niter; iter++) {
//     //update one gamma
//     j = nbeta*R::runif(0.0, 1.0);
//     newgamma = 1 - gamma[j];
//     newbeta = newgamma == 0 ? 0.0 :  R::rnorm(0.0, b);
//     // updateeta(eta, beta, j, newbeta, Xmat, sdv, neweta);
//     updateeta(eta, beta, j, newbeta, Xmat, neweta);
//     newpar = fitsurv_pw(par, Dm, neweta, breaks);
//     newlik = -loglik_pw(newpar, Dm, neweta, breaks);
//     deltagamma = newgamma == 1 ? log(omega/(1-omega)) : log((1-omega)/omega);
//     deltapost = newlik - lik + deltagamma;
//     if (log(R::runif(0.0, 1.0)) < deltapost) {
//       lik = newlik;
//       for (k=0; k<nsub; k++) eta[k] = neweta[k];
//       beta[j] = newbeta;
//       gamma[j] = newgamma;
//       par = newpar;
//       outgamma[2*iter+1] = j;
//       outgamma[2*iter+2] = 1;
//     } else {
//       outgamma[2*iter+1] = j;
//       outgamma[2*iter+2] = 0;        
//     }    
//     // updage regression coefficients
//     for (int p = 0; p < nbeta; p++) {
//       if (gamma[p] == 1) {
//         if (R::runif(0.0, 1.0) < psample) {
//           newbeta = R::rnorm(beta[p], b);
//           // updateeta(eta, beta, p, newbeta, Xmat, sdv, neweta);
//           updateeta(eta, beta, p, newbeta, Xmat, neweta);
//           // get the optimized par
//           newpar = fitsurv_pw(par, Dm, neweta, breaks);
//           newlik = -loglik_pw(newpar, Dm, neweta, breaks);
//           deltabeta = R::dnorm(newbeta, 0.0, b, 1) - R::dnorm(beta[p], 0.0, b, 1);
//           deltapost = newlik - lik + deltabeta;
//           if (log(R::runif(0.0, 1.0)) < deltapost) {
//             lik = newlik;
//             for (k=0; k<nsub; k++) eta[k] = neweta[k];
//             beta[p] = newbeta;
//             par = newpar;
//           }            
//         }
//       }
//     }
//     // update lambda
//     //par = fitsurv_pw(par, Dm, eta, breaks);
//     //update omega
//     nselect = 0;
//     for (k=0; k<nbeta; k++) nselect += gamma[k]; 
//     omega = R::rbeta(om1 + nselect, om2 + nbeta - nselect);
//     //report
//     if (iter % nreport == 0) {
//       //        std::cout << "At iteration " << iter <<".  Model size: " << nselect <<"\n";
//       //        std::cout << "Survival parameters:";
//       //        for (k=0;k < JS; k++) std::cout << par[k] << ",  ";
//       //        std::cout << "\n";
//       Rprintf("At iteration %d, model size is: %d. \n", iter, nselect);
//       Rprintf("Survival parameters:");
//       for (k=0;k < JS; k++) Rprintf("   %f8", par[k]);
//       Rprintf("\n\n");
//     }
//   }
//   return outgamma;    
// }    

// [[Rcpp::export]]
void matrixStandardize(NumericMatrix X) {
  int i, j, I = X.nrow(), J = X.ncol();
  double m, s;
  for (j = 0; j < J; j++) {
    m = 0;
    s = 0;
    for (i = 0; i < I; i++) {
      m += X(i, j);
      s += X(i, j) * X(i, j);
    }
    m = m / I;
    s = std::sqrt((s - m * m * I) / (I - 1));
    for (i = 0; i < I; i++) {
      X(i, j) = (X(i, j) - m) / s;
    }
  }
} 
