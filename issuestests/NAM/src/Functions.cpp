#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
SEXP emBA(NumericVector y, NumericMatrix gen, double df = 10, double R2 = 0.5){
  int it = 200;
  int p = gen.ncol();
  int n = gen.nrow();
  double ve = 1;
  NumericVector d(p);
  NumericVector b(p);
  NumericVector vb = b+1;
  NumericVector Lmb = ve/vb;
  double vy = var(y);
  NumericVector xx(p);
  NumericVector vx(p);
  for(int i=0; i<p; i++){
    xx[i] = sum(gen(_,i)*gen(_,i));
    vx[i] = var(gen(_,i));}
  double MSx = sum(vx);
  double Sb = R2*df*vy/MSx;
  double Se = (1-R2)*df*vy;
  double mu = mean(y);
  NumericVector e = y-mu;
  double b0,b1,eM,h2;
  for(int i=0; i<it; i++){
    for(int j=0; j<p; j++){
      b0 = b[j];
      b1 = (sum(gen(_,j)*e)+xx[j]*b0)/(xx[j]+Lmb[j]);
      e = e-gen(_,j)*(b1-b0);
      b[j] = b1;
      vb[j] = (Sb+b[j]*b[j])/(df+1);
      e = e - gen(_,j)*(b1-b0);}
    ve = (sum(e*e)+Se)/(n+df);
    Lmb = ve/vb;
    eM = mean(e);
    mu = mu+eM;
    e = e-eM;}
  h2 = 1-ve/vy;
  NumericVector fit(n);
  for(int k=0; k<n; k++){fit[k] = sum(gen(k,_)*b)+mu;}
  return List::create(Named("mu") = mu,
                      Named("b") = b,
                      Named("hat") = fit,
                      Named("Vb") = vb,
                      Named("Ve") = ve,
                      Named("h2") = h2);}

// [[Rcpp::export]]
SEXP emBB(NumericVector y, NumericMatrix gen, double df = 10, double R2 = 0.5, double Pi = 0.75){
  int it = 200;
  int p = gen.ncol();
  int n = gen.nrow();
  double ve = 1;
  NumericVector d(p);
  NumericVector b(p);
  NumericVector vb = b+1;
  NumericVector Lmb = ve/vb;
  double vy = var(y);
  if(Pi>0.5){Pi = 1-Pi;} 
  NumericVector xx(p);
  NumericVector vx(p);
  for(int i=0; i<p; i++){
    xx[i] = sum(gen(_,i)*gen(_,i));
    vx[i] = var(gen(_,i));}
  double MSx = sum(vx)*Pi;
  double Sb = R2*df*vy/MSx;
  double Se = (1-R2)*df*vy;
  double mu = mean(y);
  NumericVector e = y-mu;
  NumericVector e1(n);
  NumericVector e2(n);
  double b0,b1,LR,eM,h2,C;
  double Pi0 = (1-Pi)/Pi;
  for(int i=0; i<it; i++){
    C = -0.5/ve;
    for(int j=0; j<p; j++){
      b0 = b[j];
      b1 = (sum(gen(_,j)*e)+xx[j]*b0)/(xx[j]+Lmb[j]);
      e1 = e-gen(_,j)*(b1-b0);
      e2 = e-gen(_,j)*(0-b0);
      LR = Pi0*exp(C*(sum(e2*e2)-sum(e1*e1)));
      d[j] = (1/(1+LR));
      b[j] = b1*d[j];
      vb[j] = (Sb+b[j]*b[j])/(df+1);
      e = e - gen(_,j)*(b[j]-b0);}
    ve = (sum(e*e)+Se)/(n+df);
    Lmb = ve/vb;
    eM = mean(e);
    mu = mu+eM;
    e = e-eM;}
  h2 = 1-ve/vy;
  NumericVector fit(n);
  for(int k=0; k<n; k++){fit[k] = sum(gen(k,_)*b)+mu;}
  return List::create(Named("mu") = mu,
                      Named("b") = b,
                      Named("d") = d,
                      Named("hat") = fit,
                      Named("Vb") = vb,
                      Named("Ve") = ve,
                      Named("h2") = h2);}

// [[Rcpp::export]]
SEXP emBC(NumericVector y, NumericMatrix gen, double df = 10, double R2 = 0.5, double Pi = 0.75){
  int it = 200;
  int p = gen.ncol();
  int n = gen.nrow();
  NumericVector d(p);
  NumericVector b(p);
  double vy = var(y);
  if(Pi>0.5){Pi = 1-Pi;} 
  NumericVector xx(p);
  NumericVector vx(p);
  for(int i=0; i<p; i++){
    xx[i] = sum(gen(_,i)*gen(_,i));
    vx[i] = var(gen(_,i));
  }
  double MSx = sum(vx)*Pi*(1-Pi);
  double Sa = R2*df*vy/MSx;
  double Se = (1-R2)*df*vy;
  double mu = mean(y);
  NumericVector e = y-mu;
  NumericVector e1(n);
  NumericVector e2(n);
  double ve = Sa;
  double va = Se;
  double Lmb = ve/va;
  double b0,b1,LR,eM,h2,C;
  double Pi0 = (1-Pi)/Pi;
  for(int i=0; i<it; i++){
    C = -0.5/ve;
    for(int j=0; j<p; j++){
      b0 = b[j];
      b1 = (sum(gen(_,j)*e)+xx[j]*b0)/(xx[j]+Lmb);
      e1 = e-gen(_,j)*(b1-b0);
      e2 = e-gen(_,j)*(0-b0);
      LR = Pi0*exp(C*(sum(e2*e2)-sum(e1*e1)));
      d[j] = (1/(1+LR));
      b[j] = b1*d[j];
      e = e - gen(_,j)*(b[j]-b0);
    }
    ve = (sum(e*e)+Se)/(n+df);
    va = (sum(b*b)+Sa)/(p+df)/(mean(d)-Pi);
    Lmb = ve/va;
    eM = mean(e);
    mu = mu+eM;
    e = e-eM;
  }
  h2 = 1-ve/vy;
  NumericVector fit(n);
  for(int k=0; k<n; k++){fit[k] = sum(gen(k,_)*b)+mu;}
  return List::create(Named("mu") = mu,
                      Named("b") = b,
                      Named("d") = d,
                      Named("hat") = fit,
                      Named("Vg") = va*MSx,
                      Named("Va") = va,
                      Named("Ve") = ve,
                      Named("h2") = h2);
}

// [[Rcpp::export]]
SEXP emBD(NumericVector y, NumericMatrix gen, double df = 10, double R2 = 0.5){
  int it = 200;
  int p = gen.ncol();
  int n = gen.nrow();
  double ve = 1;
  NumericVector d(p);
  NumericVector b(p);
  NumericVector vb = b+1;
  NumericVector Lmb = ve/vb;
  double vy = var(y);
  double Pi = 0.50;
  NumericVector xx(p);
  NumericVector vx(p);
  for(int i=0; i<p; i++){
    xx[i] = sum(gen(_,i)*gen(_,i));
    vx[i] = var(gen(_,i));}
  double MSx = sum(vx)*Pi;
  double Sb = R2*(df+2)*vy/MSx;
  double Se = (1-R2)*(df+2)*vy;
  double mu = mean(y);
  NumericVector e = y-mu;
  NumericVector e1(n);
  NumericVector e2(n);
  double b0,b1,LR,eM,h2,C;
  double Pi0 = (1-Pi)/Pi;
  for(int i=0; i<it; i++){
    C = -0.5/ve;
    for(int j=0; j<p; j++){
      b0 = b[j];
      b1 = (sum(gen(_,j)*e)+xx[j]*b0)/(xx[j]+Lmb[j]);
      e1 = e-gen(_,j)*(b1-b0);
      e2 = e-gen(_,j)*(0-b0);
      LR = Pi0*exp(C*(sum(e2*e2)-sum(e1*e1)));
      d[j] = (1/(1+LR));
      b[j] = b1*d[j];
      vb[j] = (Sb+b[j]*b[j])/(df+1);
      e = e - gen(_,j)*(b[j]-b0);}
    ve = (sum(e*e)+Se)/(n+df);
    R2 = 1-(sum(e*y)/(n-1))/vy;
    Pi = mean(d);
    Sb = R2*(df+2)*vy/MSx/Pi;
    Se = (1-R2)*(df+2)*vy;
    Lmb = ve/vb;
    eM = mean(e);
    mu = mu+eM;
    e = e-eM;}
  h2 = 1-ve/vy;
  NumericVector fit(n);
  for(int k=0; k<n; k++){fit[k] = sum(gen(k,_)*b)+mu;}
  return List::create(Named("mu") = mu,
                      Named("b") = b,
                      Named("d") = d,
                      Named("pi") = 1-Pi,
                      Named("hat") = fit,
                      Named("Vb") = vb,
                      Named("Ve") = ve,
                      Named("h2") = h2);}

// [[Rcpp::export]]
SEXP emRR(NumericVector y, NumericMatrix gen, double df = 10, double R2 = 0.5){
  int it = 200;
  int p = gen.ncol();
  int n = gen.nrow();
  NumericVector xx(p);
  NumericVector vx(p);
  for(int k=0; k<p; k++){
    xx[k] = sum(gen(_,k)*gen(_,k));
    vx[k] = var(gen(_,k));}
  double MSx = sum(vx);
  double Lmb = MSx;
  double Rho = MSx*(1-R2)/R2;
  double vy = var(y);
  double ve = 0.5*vy;
  double vb = ve/MSx;
  double Se = (1-R2)*df*vy;
  double Sb = R2*df*vy/MSx;
  double mu = mean(y);
  NumericVector b(p);
  NumericVector e = y-mu;
  double b0,eM,h2;
  df = df*100;
  for(int i=0; i<it; i++){
    for(int j=0; j<p; j++){
      b0 = b[j];
      b[j] = (sum(gen(_,j)*e)+xx[j]*b0)/(xx[j]+Lmb);
      e = e-gen(_,j)*(b[j]-b0);
    }
    vb = (sum(b*b)+Sb)/(p+df);
    ve = (sum(e*e)+Se)/(n+df);
    Lmb = sqrt(Rho*ve/vb);
    eM = mean(e);
    mu = mu+eM;
    e = e-eM;
  }
  h2 = 1-ve/vy;
  NumericVector fit(n);
  for(int k=0; k<n; k++){ fit[k] = sum(gen(k,_)*b)+mu;}
  return List::create(Named("mu") = mu,
                      Named("b") = b,
                      Named("hat") = fit,
                      Named("Va") = vb,
                      Named("Ve") = ve,
                      Named("h2") = h2);
}

// [[Rcpp::export]]
SEXP emBL(NumericVector y, NumericMatrix gen, double R2 = 0.5, double alpha = 0.02){
  int it = 200;
  double h2 = R2;  
  int p = gen.ncol();
  int n = gen.nrow();
  // Beta, mu and epsilon
  NumericVector b(p);
  double b0,eM,Half_L2;
  double mu = mean(y);
  NumericVector e = y-mu;
  // Marker variance
  NumericVector xx(p);
  for(int k=0; k<p; k++){xx[k] = sum(gen(_,k)*gen(_,k));}
  // Regulation coefficients
  double cxx = mean(xx);
  double Lmb1 = cxx*((1-h2)/h2)*alpha*0.5;
  double Lmb2 = cxx*((1-h2)/h2)*(1-alpha);
  double OLS, G;
  // Loop
  for(int i=0; i<it; i++){
    // Regression coefficients loop
    for(int j=0; j<p; j++){
      // Ordinary Least Square
      b0 = b[j];
      OLS = (sum(gen(_,j)*e)+xx[j]*b0);
      Half_L2 = 0.5*OLS/(xx[j]+cxx);
      // Regularization of positive OLS
      if(OLS>0){
        G = 0.5*(OLS-Lmb1)/(Lmb2+xx(j));
        if(G>0){b[j] = G+Half_L2;}else{b[j] = Half_L2;}
      }else{
        // Regularization of negative OLS
        G = 0.5*(OLS+Lmb1)/(Lmb2+xx(j));
        if(G<0){b[j] = G+Half_L2;}else{b[j] = Half_L2;}
      }
      // Residuals update
      e = e-gen(_,j)*(b[j]-b0);}
    // Intercept update
    eM = mean(e);
    mu = mu+eM;
    e = e-eM;}
  // Fitting the model
  NumericVector fit(n); for(int k=0; k<n; k++){ fit[k] = sum(gen(k,_)*b)+mu; }
  h2 = 1 - var(e)/var(y);
  // Output
  return List::create(Named("mu") = mu, Named("b") = b, Named("hat") = fit, Named("h2") = h2); }

// [[Rcpp::export]]
SEXP emDE(NumericVector y, NumericMatrix gen, double R2 = 0.5){
  // Convergence criteria
  int maxit = 300;
  double tol = 10e-6;
  // Functions starts here
  int p = gen.ncol();
  int n = gen.nrow();
  // Beta, mu and epsilon
  double b0,eM;
  double mu = mean(y);
  NumericVector e = y-mu;
  // Marker variance
  NumericVector xx(p);
  for(int k=0; k<p; k++){
    xx[k] = sum(gen(_,k)*gen(_,k));
    if(xx[k]==0) xx[k]=0.1;}
  NumericVector vx(p);
  for(int k=0; k<p; k++){vx[k] = var(gen(_,k));}
  double cxx = sum(vx)*(1-R2)/R2;
  // Regulation coefficients
  double Ve;
  NumericVector Vb(p);
  NumericVector b(p);
  NumericVector Lmb = p+cxx;
  double b1;
  // Convergence control
  NumericVector bc(p);
  int numit = 0;
  double cnv = 1;
  // Loop
  while(numit<maxit){
    // Regression coefficients loop
    bc = b+0;
    for(int j=0; j<p; j++){
      // Ordinary Least Square
      b0 = b[j];
      b1 = (sum(gen(_,j)*e)+xx[j]*b0)/(Lmb(j)+xx(j));
      b[j] = b1;
      // Residuals update
      e = e-gen(_,j)*(b1-b0);}
    // Intercept update
    eM = mean(e);
    mu = mu+eM;
    e = e-eM;
    // Variance components
    Ve = sum(e*y)/(n-1);
    Vb = b*b+(Ve/(xx+Lmb+0.0001));
    Lmb = sqrt(cxx*Ve/Vb);
    // Convergence
    ++numit;
    cnv = sum(abs(bc-b));
    if( cnv<tol ){break;}
  }
  // Fitting the model
  NumericVector fit(n); for(int k=0; k<n; k++){ fit[k] = sum(gen(k,_)*b)+mu; }
  // Output
  return List::create(Named("mu")=mu,
                      Named("b")=b,
                      Named("hat")=fit,
                      Named("Vb")=Vb,
                      Named("Ve")=Ve,
                      Named("h2")=sum(Vb)/(sum(Vb)+Ve));
}

// [[Rcpp::export]]
SEXP emEN(NumericVector y, NumericMatrix gen, double R2 = 0.5, double alpha = 0.02){
  // Convergence criteria
  int maxit = 300;
  double tol = 10e-11;
  // Functions starts here
  int p = gen.ncol();
  int n = gen.nrow();
  // Beta, mu and epsilon
  NumericVector b(p);
  double b0,eM;
  double mu = mean(y);
  NumericVector e = y-mu;
  // Marker variance
  NumericVector xx(p);
  for(int k=0; k<p; k++){xx[k] = sum(gen(_,k)*gen(_,k));}
  NumericVector vx(p);
  for(int k=0; k<p; k++){vx[k] = var(gen(_,k));}
  double cxx = sum(vx)*(1-R2)/R2;
  // Regulation coefficients
  double Ve, Va;
  double Sy = sd(y);
  double Lmb = cxx;
  double Lmb1 = 0.5*Lmb*alpha*Sy;
  double Lmb2 = Lmb*(1-alpha);
  double trAC22 = sum(1/(xx+Lmb));
  double OLS, b1;
  // Convergence control
  NumericVector bc(p);
  int numit = 0;
  double cnv = 1;
  // Loop
  while(numit<maxit){
    // Regression coefficients loop
    bc = b+0;
    for(int j=0; j<p; j++){
      // Ordinary Least Square
      b0 = b[j];
      OLS = (sum(gen(_,j)*e)+xx[j]*b0);
      // Regularization of positive OLS
      if(OLS>0){
        // Regularization of positive OLS
        b1 = (OLS-Lmb1)/(Lmb2+xx(j));if(b1<0){b1=0;};
      }else{
        // Regularization of negative OLS
        b1 = (OLS+Lmb1)/(Lmb2+xx(j));if(b1>0){b1=0;};
      }
      b[j] = b1;
      // Residuals update
      e = e-gen(_,j)*(b1-b0);}
    // Intercept update
    eM = mean(e);
    mu = mu+eM;
    e = e-eM;
    // Variance components
    Ve = sum(e*y)/(n-1);
    Va = (sum(b*b)+trAC22*Ve)/p;
    Lmb = Ve/Va;
    Lmb1 = 0.5*Lmb*alpha*Sy;
    Lmb2 = Lmb*(1-alpha);
    // Convergence
    ++numit;
    cnv = sum(abs(bc-b));
    if( cnv<tol ){break;}
  }
  // Fitting the model
  NumericVector fit(n); for(int k=0; k<n; k++){ fit[k] = sum(gen(k,_)*b)+mu; }
  // Output
  return List::create(Named("mu")=mu,
                      Named("b")=b,
                      Named("hat")=fit,
                      Named("Va")=Va*cxx,
                      Named("Ve")=Ve,
                      Named("h2")=Va*cxx/(Va*cxx+Ve));
}

// [[Rcpp::export]]
SEXP emML(NumericVector y, NumericMatrix gen,
          Rcpp::Nullable<Rcpp::NumericVector> D = R_NilValue){
  int maxit = 300;
  double tol = 10e-8;
  // Functions starts here
  int p = gen.ncol();
  int n = gen.nrow();
  // Weights
  bool P_WEIGHTS = FALSE;
  NumericVector d(p);
  if (D.isNotNull()){P_WEIGHTS = TRUE; d=D;}
  // Beta, mu and epsilon
  double b0, eM, ve, vb, h2, mu = mean(y), vy = var(y);
  NumericVector b(p), e = y-mu;
  // Marker variance
  NumericVector xx(p), vx(p);
  for(int i=0; i<p; i++){
    xx[i] = sum(gen(_,i)*gen(_,i));
    vx[i] = var(gen(_,i));}
  double MSx = sum(vx), Lmb=MSx;
  // Convergence control
  NumericVector bc(p);
  int numit = 0;
  double cnv = 1;
  // Loop
  while(numit<maxit){
    // Regression coefficients loop
    bc = b+0;
    for(int j=0; j<p; j++){
      b0 = b[j];
      if(P_WEIGHTS){
        b[j] = (sum(gen(_,j)*e)+xx[j]*b0)/(xx[j]+Lmb/d[j]);
      }else{
        b[j] = (sum(gen(_,j)*e)+xx[j]*b0)/(xx[j]+Lmb);}
      e = e-gen(_,j)*(b[j]-b0);}
    // Variance components update
    ve = sum(e*y)/(n-1);
    vb = (vy-ve)/MSx;
    Lmb = ve/vb;
    // Intercept update
    eM = mean(e);
    mu = mu+eM;
    e = e-eM;
    // Convergence
    ++numit;
    cnv = sum(abs(bc-b));
    if( cnv<tol ){break;}}
  // Fitting the model
  NumericVector fit(n);
  for(int k=0; k<n; k++){ fit[k] = sum(gen(k,_)*b)+mu; }
  h2 = vb*MSx/(vb*MSx+ve);
  // Output
  return List::create(Named("mu")=mu, Named("b")=b,
                      Named("h2")=h2, Named("hat")=fit,
                      Named("Vb")=vb, Named("Ve")=ve);}

// [[Rcpp::export]]
SEXP emMX(NumericVector y, NumericMatrix gen, double R2=0.5){
  int maxit = 250;
  double tol = 10e-8;
  // Functions starts here
  int p = gen.ncol();
  int n = gen.nrow();
  // Beta, mu and epsilon
  double b0, eM, ve, mu = mean(y);
  NumericVector b(p), vb(p), e=y-mu;
  // Marker variance
  NumericVector xx(p);
  for(int k=0; k<p; k++){xx[k] = sum(gen(_,k)*gen(_,k));}
  NumericVector vx(p);
  for(int k=0; k<p; k++){vx[k] = var(gen(_,k));}
  double cxx = sum(vx), mxx = cxx/(R2*R2);
  NumericVector Lmb = vb+cxx;
  // Convergence control
  NumericVector bc(p);
  int numit = 0;
  double cnv = 1;
  // Loop
  while(numit<maxit){
    // Regression coefficients loop
    bc = b+0;
    for(int j=0; j<p; j++){
      b0 = b[j];
      b[j] = (sum(gen(_,j)*e)+xx[j]*b0)/(xx[j]+Lmb[j]);
      e = e-gen(_,j)*(b[j]-b0);}
    // Variance components update
    vb = b*b+ve/(xx+Lmb);
    ve = sum(e*y)/(n-1);
    Lmb = ve/vb;
    Lmb = ifelse(Lmb>mxx,mxx,Lmb);
    // Intercept update
    eM = mean(e);
    mu = mu+eM;
    e = e-eM;
    // Convergence
    ++numit;
    cnv = sum(abs(bc-b));
    if( cnv<tol ){break;}}
  // Fitting the model
  NumericVector fit(n);
  for(int k=0; k<n; k++){ fit[k] = sum(gen(k,_)*b)+mu; }
  double h2 = 1-ve/var(y);
  // Output
  return List::create(Named("mu")=mu, Named("b")=b,
                      Named("hat")=fit, Named("h2")=h2,
                      Named("Vb")=vb, Named("Ve")=ve);}

// [[Rcpp::export]]
int calcSize(NumericVector col, NumericVector fam){
  int scol = col.size();
  int i;
  int finsiz = 0;
  
  for(i=0; i < scol; i++)
  {
    if(col[i] == 1)
    {
      finsiz = finsiz + 2;
    }
    else
    {
      finsiz = finsiz + 1;
    }
  }
  return (finsiz);
}

// [[Rcpp::export]]
NumericVector funI(NumericVector col, int fam, int finsiz, int f){
  int scol = col.size();
  NumericVector vec(finsiz);
  int ct = 0;
  //NumericVector vec(finsiz);
  
  ct = 0;
  
  for(int i=0; i < scol; i++)
  {
    if(col[i] == 2)
    {
      vec[ct] = (i) * f + 1;
    }
    else if(col[i] == 1)
    {
      vec[ct] = (i) * f + 1;
      //  printf("Value I: %d\n", vec[ct]);
      ct++;
      vec[ct] = (i) * f + 1 + fam;
    }
    else if(col[i] == 0)
    {
      vec[ct] = (i) * f + 1 + fam;
    }
    // printf("Value I: %d\n", vec[ct]);
    ct++;
  }
  
  return vec;
}

// [[Rcpp::export]]
NumericVector funX(NumericVector col, int finsiz){
  int scol = col.size();
  int i;
  int ct = 0;
  NumericVector vec2(finsiz);
  
  for(i=0; i < scol; i++)
  {
    if(col[i] == 0 || col[i] == 2)
    {
      vec2[ct] = 2;
    }
    else if(col[i] == 1)
    {
      vec2[ct] = 1;
      ct++;
      vec2[ct] = 1;
    }
    ct++;    
  }
  return (vec2);
}

// [[Rcpp::export]]
void gs(NumericMatrix C, NumericVector g, NumericVector r, int N){
  for(int i=0; i<N; i++){        
    g[i]=((r[i]-sum(C(i,_)*g)+C(i,i)*g(i))/C(i,i));
  } 
}

// [[Rcpp::export]]
NumericVector inputRow(NumericVector x, int exp, int n){  
  int i;
  
  // IF THE FIRST IS MISSING
  if(x[0] == 5 && x[1] == 5)
  {
    x[0] = exp;
  }
  else if(x[0] == 5)
  {
    x[0] = x[1];
  }
  // IF ANY OTHER IS MISSING
  for(i = 1; i < n; i++)
  {
    if(x[i] == 5 && x[i+1] == 5)
    {
      x[i] = x[i-1];
    }
    else if(x[i] == 5 && (x[i-1] == x[i+1]))
    {
      x[i] = x[i-1];
    }
    else if(x[i] == 5 && x[i-1] != x[i+1])
    {
      x[i] = 1;
    }
    
  }
  
  return x;
}

// [[Rcpp::export]]
SEXP KMUP(NumericMatrix X, NumericVector b, NumericVector d, NumericVector xx, NumericVector e, NumericVector L, double Ve, double pi){  
  int p = X.ncol();
  NumericVector e1 = e+0;
  NumericVector e2 = e+0;
  double b0,b1,cj,dj,pj;
  double C = -0.5/Ve;
  //
  for(int j=0; j<p; j++){
    b0 = b[j];
    b1 = R::rnorm( (sum(X(_,j)*e)+xx[j]*b0)/(xx[j]+L[j]),
                   sqrt(Ve/(xx[j]+L[j]))  );
    e1 = e-X(_,j)*(b1-b0); // with marker
    if(pi>0){
      e2 = e-X(_,j)*(0-b0); // without marker
      //
      cj = (1-pi)*exp(C*sum(e1*e1));
      dj = (pi)*exp(C*sum(e2*e2));
      pj = cj/(cj+dj);
      //
      if(R::rbinom(1,pj)==1){
        b[j] = b1;
        d[j] = 1;
        e = e1;
      }else{
        b[j] = 0;
        d[j] = 0;
        e = e2;
      }
    }else{
      // WO Variable Selection
      d[j] = 1;
      b[j] = b1;
      e = e1;
    }
    //e = e - X(_,j)*(b[j]-b0);
  }
  //
  return List::create(Named("b") = b,Named("d") = d,Named("e") = e);
}

// [[Rcpp::export]]
SEXP KMUP2(NumericMatrix X, NumericVector Use, NumericVector b,  NumericVector d, NumericVector xx, NumericVector E, NumericVector L, double Ve, double pi){  
  int p = X.ncol();
  int n0 = X.nrow();
  int n = Use.size();
  NumericVector e1 = E+0;
  NumericVector e2 = E+0;
  double b0,b1,cj,dj,pj;
  double C = -0.5/Ve;
  //
  double bg = n0/n;
  NumericVector e0(n);
  NumericVector H(n);
  //
  for(int k=0; k<n; k++){
    e0[k] = E[Use[k]];
  }
  //
  for(int j=0; j<p; j++){
    //
    for(int x=0; x<n; x++){
      H[x] = X(Use[x],j);
    }
    //
    b0 = b[j];
    b1 = R::rnorm((sum(H*e0)+b0)/(xx(j)*bg+L(j)),sqrt(Ve/(xx(j)*bg+L(j))));
    e1 = e0 - H*(b1-b0);
    //
    if(pi>0){
      e2 = e0 - H*(b1-b0);
      //
      cj = (1-pi)*exp(C*sum(e1*e1));
      dj = (pi)*exp(C*sum(e2*e2));
      pj = cj/(cj+dj);
      //
      if(R::rbinom(1,pj)==1){
        b[j] = b1;
        d[j] = 1;
        e0 = e1;
      }else{
        b[j] = 0;
        d[j] = 0;
        e0 = e2;
      }
      //
    }else{
      d[j] = 1;
      b[j] = b1;
      e0 = e1;
    }
    //
  }  
  return List::create(Named("b") = b,
                      Named("d") = d,
                      Named("e") = e0);
}

// [[Rcpp::export]]
void SAMP(NumericMatrix C, NumericVector g, NumericVector r, int N, double Ve){
  RNGScope scope;
  for(int i=0; i<N; i++){        
    g[i]=R::rnorm(((r[i]-sum(C(i,_)*g)+C(i,i)*g(i))/C(i,i)),sqrt(Ve/C(i,i)));
  } 
}

// [[Rcpp::export]]
void SAMP2(NumericMatrix X, NumericVector g, NumericVector y, NumericVector xx, NumericVector E, NumericVector L, int N, double Ve){
  RNGScope scope; 
  double G;
  for(int i=0; i<N; i++){
    G = g[i];
    g[i] = R::rnorm(
      (sum(X(_,i)*E) + xx(i)*G)/(xx(i)+L(i)),
      sqrt(Ve/(xx(i)+L(i))));
    E = E - X(_,i) * (g[i]-G);
  }
}

// [[Rcpp::export]]
NumericMatrix timesMatrix(NumericMatrix ma1, NumericVector h, NumericMatrix ma2, int rows, int cols){
  int i;
  int j;
  NumericMatrix resul(rows,cols);
  
  for(i = 0; i < rows; i++)
  {
    for(j = 0; j < cols; j++)
    {
      resul(i,j) = sum(ma1(_,i)*h*ma2(_,j)); 
    }
  }
  
  return (resul);
}

// [[Rcpp::export]]
NumericMatrix timesVec(NumericVector aa, NumericVector h, NumericMatrix bb, int q){
  int i;
  NumericMatrix resul(q,1);
  
  for(i = 0; i < q; i++)
  {
    resul[i] = sum(aa*h*bb(_,i));
  }
  
  return(resul);
}

// [[Rcpp::export]]
NumericMatrix CNT(NumericMatrix X){for(int j=0;j<X.ncol();j++){X(_,j)=X(_,j)-mean(X(_,j));}; return(X);}

// [[Rcpp::export]]
SEXP MSX(NumericMatrix X){
  int p = X.ncol(); int n = X.nrow(); double m; NumericVector xx(p); NumericVector sx(p);
  for(int k=0; k<p; k++){ xx[k] = sum(X(_,k)*X(_,k)); m = sum(X(_,k)); sx[k] = m*m/n; }
  double cxx = sum(xx-sx)/(n-1); return List::create(Named("cxx")=cxx,Named("xx")=xx);}

// [[Rcpp::export]]
NumericMatrix IMP(NumericMatrix X){
  int p = X.ncol(); int n = X.nrow();
  LogicalVector MIS(n); NumericVector x(n);
  NumericVector z; double EXP;
  for(int j=0; j<p; j++){
    if(is_true(any(is_na(X(_,j))))){
      x = X(_,j); MIS = is_na(x);
      z = x[!MIS]; EXP = mean(z);
      X(_,j) = ifelse(MIS,EXP,x);}
  };return(X);};

// [[Rcpp::export]]
SEXP NOR(NumericVector y, NumericMatrix X, double cxx, NumericVector xx, int maxit = 50, double tol = 10e-6){
  int p = X.ncol(); int n = X.nrow(); double Ve,b0,b1,eM; double mu = mean(y); double Va=1;
  NumericVector b(p), bc(p), fit(n), E(n); NumericVector e = y-mu; double Lmb = cxx;
  int numit = 0; double cnv = 1; while(numit<maxit){bc = b+0; for(int j=0; j<p; j++){
    b0 = b[j]; b1 = (sum(X(_,j)*e)+xx[j]*b0)/(Lmb+xx(j)); b[j]=b1; e = e-X(_,j)*(b1-b0);}
  eM = mean(e); mu = mu+eM; e = e-eM; Ve = sum(e*y)/(n-1); Va = var(b)+mean(Ve/(xx+Lmb));
  Lmb = sqrt(cxx*Ve/Va); ++numit; cnv = sum(abs(bc-b)); if( cnv<tol ){break;};}
  for(int k=0; k<n; k++){ fit[k] = sum(X(k,_)*b); E[k] = y[k]-fit[k];}; Va=Va*cxx;
  return List::create(Named("b")=b,Named("v")=Va,Named("h")=fit,Named("e")=E);}

// [[Rcpp::export]]
NumericMatrix GAU(NumericMatrix X){
  int n = X.nrow(); NumericVector D; NumericMatrix K(n,n); double d2, md;
  for(int i=0; i<n; i++){; for(int j=0; j<n; j++){
    if(i==j){ K(i,j)=0; }else if(j>i){; D = X(i,_)-X(j,_);
    d2 = sum(D*D); K(i,j)=d2; K(j,i)=d2; }}}; md = mean(K);
    for(int i=0; i<n; i++){K(i,_) = exp(-K(i,_)/md);} return K;}

// [[Rcpp::export]]
NumericMatrix GRM(NumericMatrix X, bool Code012 = false){
  int n = X.nrow(), p = X.ncol();
  NumericMatrix K(n,n); NumericVector xx(p); double zz, Sum2pq=0.0;
  for(int i=0; i<p; i++){ xx[i] = mean(X(_,i)); }
  if(Code012){
    for(int i=0; i<p; i++){ Sum2pq = Sum2pq + xx[i]*xx[i]/2;}
  }else{
    for(int i=0; i<p; i++){Sum2pq = Sum2pq + var(X(_,i));}
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(i<=j ){
        zz = sum( (X(i,_)-xx)*(X(j,_)-xx) );
        K(i,j)=zz; K(j,i)=zz;
      }
    }
  }
  return K/Sum2pq;
}

// [[Rcpp::export]]
NumericVector SPC(NumericVector y, NumericVector blk, NumericVector row, NumericVector col, double rN=3, double cN=1){
  int n = y.size(), t1=0, t2=0; NumericVector Cov(n), Phe(n), Obs(n);
  for(int i=0; i<n; i++){; for(int j=0; j<n; j++){
    t1 = row[i]-row[j]; if(t1<0){t1=-t1;}; t2 = col[i]-col[j]; if(t2<0){t2=-t2;};
    if( (i>j) & (blk[i]==blk[j]) & (t1<=rN) & (t2<=cN) ){
      Phe[i] = Phe[i]+y[j]; Obs[i] = Obs[i]+1; Phe[j] = Phe[j]+y[i]; Obs[j] = Obs[j]+1; }}}
  Cov = Phe/Obs; return Cov;}

// [[Rcpp::export]]
NumericMatrix SPM(NumericVector blk, NumericVector row, NumericVector col, double rN=3, double cN=1){
  int n=blk.size(),t1=0,t2=0; NumericMatrix X(n,n); for(int i=0; i<n; i++){; for(int j=0; j<n; j++){
    t1 = row[i]-row[j]; if(t1<0){t1=-t1;}; t2 = col[i]-col[j]; if(t2<0){t2=-t2;};
    if( (blk[i]==blk[j]) & (i>j)  & (t1<=rN) & (t2<=cN) ){ X(i,j) = 1; X(j,i) = 1;
       }else{ X(i,j) = 0; X(j,i) = 0; }}; X(i,i) = 0;}; return X;}

// [[Rcpp::export]]
SEXP BRR2(NumericVector y, NumericMatrix X1, NumericMatrix X2,
             double it = 1500, double bi = 500, double df = 5, double R2 = 0.5){
  // Get dimensions of X
  int n = X1.nrow();
  int p1 = X1.ncol();
  int p2 = X2.ncol();
  // Estimate crossproducts and MSx
  NumericVector xx1(p1), vx1(p1);
  for(int i=0; i<p1; i++){
    xx1[i] = sum(X1(_,i)*X1(_,i));
    vx1[i] = var(X1(_,i));}
  double MSx1 = sum(vx1);
  NumericVector xx2(p2), vx2(p2);
  for(int i=0; i<p2; i++){
    xx2[i] = sum(X2(_,i)*X2(_,i));
    vx2[i] = var(X2(_,i));}
  double MSx2 = sum(vx2);
  // Get priors
  double vy = var(y);
  double Sb1 = (R2)*df*vy/MSx1;
  double Sb2 = (R2)*df*vy/MSx2;
  double Se = (1-R2)*df*vy;
  double mu = mean(y);
  // Create empty objects
  double b_t0,b_t1,eM,h2,MU,VE,vg,vb1,vb2,VB1,VB2,Lmb1=MSx1,Lmb2=MSx2,ve=vy;
  NumericVector b1(p1),B1(p1),b2(p2),B2(p2),e=y-mu,fit(n);
  // MCMC loop
  for(int i=0; i<it; i++){
    // Update marker effects 1
    for(int j=0; j<p1; j++){
      b_t0 = b1[j];
      b_t1 = R::rnorm((sum(X1(_,j)*e)+xx1[j]*b_t0)/(xx1[j]+Lmb1),sqrt(ve/(xx1[j]+Lmb1)));
      b1[j] = b_t1;
      e = e - X1(_,j)*(b_t1-b_t0);
    }
    // Update marker effects 1
    for(int j=0; j<p2; j++){
      b_t0 = b2[j];
      b_t1 = R::rnorm((sum(X2(_,j)*e)+xx2[j]*b_t0)/(xx2[j]+Lmb2),sqrt(ve/(xx2[j]+Lmb2)));
      b2[j] = b_t1;
      e = e - X2(_,j)*(b_t1-b_t0);
    }
    // Update intercept
    eM = R::rnorm(mean(e),sqrt(ve/n));
    mu = mu+eM; e = e-eM;
    // Update residual variance and lambda
    ve = (sum(e*e)+Se)/R::rchisq(n+df);
    vb1 = (Sb1+sum(b1*b1))/R::rchisq(df+p1);
    vb2 = (Sb2+sum(b2*b2))/R::rchisq(df+p2);
    Lmb1 = ve/vb1;
    Lmb2 = ve/vb2;
    // Store posterior sums
    if(i>bi){
      MU=MU+mu; VE=VE+ve;
      B1=B1+b1; VB1=VB1+vb1; 
      B2=B2+b2; VB2=VB2+vb2; 
    }
  }
  // Get posterior means
  double MCMC = it-bi;
  MU = MU/MCMC; VE = VE/MCMC;
  B1 = B1/MCMC; VB1 = VB1/MCMC; 
  B2 = B2/MCMC; VB2 = VB2/MCMC; 
  // Get fitted values and h2
  vg = (VB1*MSx1+VB2*MSx2); h2 = vg/(vg+VE);
  for(int k=0; k<n; k++){fit[k] = sum(X1(k,_)*B1)+sum(X2(k,_)*B2)+MU;}
  // Return output
  return List::create(Named("hat") = fit, Named("mu") = MU,
                      Named("b1") = B1, Named("b2") = B2, 
                      Named("vb1") = VB1, Named("vb2") = VB2,
                      Named("ve") = VE, Named("h2") = h2);}

// [[Rcpp::export]]
SEXP emGWA(NumericVector y, NumericMatrix gen){
  int maxit = 500;
  double tol = 10e-8;
  // Functions starts here
  int p = gen.ncol();
  int n = gen.nrow();
  // Beta, mu and epsilon
  double b0, eM, ve, vb, h2, mu = mean(y), vy = var(y);
  NumericVector b(p), e = y-mu;
  // Marker variance
  NumericVector xx(p), vx(p);
  for(int i=0; i<p; i++){
    xx[i] = sum(gen(_,i)*gen(_,i));
    vx[i] = var(gen(_,i));}
  double MSx = sum(vx), Lmb=MSx;
  // Convergence control
  NumericVector bc(p);
  int numit = 0;
  double cnv = 1;
  // Loop
  while(numit<maxit){
    // Regression coefficients loop
    bc = b+0;
    for(int j=0; j<p; j++){
      b0 = b[j];
      b[j] = (sum(gen(_,j)*e)+xx[j]*b0)/(xx[j]+Lmb);
      e = e-gen(_,j)*(b[j]-b0);}
    // Variance components update
    ve = sum(e*y)/(n-1);
    vb = (vy-ve)/MSx;
    Lmb = ve/vb;
    // Intercept update
    eM = mean(e);
    mu = mu+eM;
    e = e-eM;
    // Convergence
    ++numit;
    cnv = sum(abs(bc-b));
    if( cnv<tol ){break;}}
  // Fitting the model
  NumericVector fit(n);
  for(int k=0; k<n; k++){ fit[k] = sum(gen(k,_)*b)+mu; }
  h2 = vb*MSx/(vb*MSx+ve);
  // Genome-wide screening
  NumericVector LRT(p),PVAL(p),y0(n),e0(n),e1(n),b_ols(p);
  double ve0, ve1, L0, L1;
  for(int j=0; j<p; j++){
    // Full conditional phenotype
    y0 = e+gen(_,j)*b[j];
    // Fixed effect marker
    b_ols[j] = sum(gen(_,j)*y0)/xx[j];
    // Null model
    e0 = y0-mean(y0);
    // Alternative model
    e1 = y0-gen(_,j)*b_ols[j];
    e1 = e1-mean(e1);
    // ReML variance
    ve0 = sum(y0*e0)/(n-1);
    ve1 = sum(y0*e1)/(n-1);
    // Likelihood ratio
    L0 = -sum(e0*e0)/(2*ve0)-0.5*n*log(6.28*ve0);
    L1 = -sum(e1*e1)/(2*ve1)-0.5*n*log(6.28*ve1);
    LRT[j] = 2*(L1-L0);}
  PVAL = -log10(1-pchisq(LRT,1,true));
  // Output
  return List::create(Named("mu")=mu, Named("b")=b, Named("b_LS")=b_ols,
                      Named("h2")=h2, Named("hat")=fit,
                      Named("Vb")=vb, Named("Ve")=ve,
                      Named("LRT")=LRT, Named("PVAL")=PVAL);}

// [[Rcpp::export]]
SEXP BCpi(NumericVector y, NumericMatrix X,
          double it = 3000, double bi = 500,
          double df = 5, double R2 = 0.5){
  // Get dimensions of X
  int p = X.ncol(), n = X.nrow();
  // Estimate crossproducts and MSx
  NumericVector xx(p), vx(p);
  for(int i=0; i<p; i++){
    xx[i] = sum(X(_,i)*X(_,i));
    vx[i] = var(X(_,i));}
  double MSx = sum(vx);
  // Get priors
  double pi = 0.5;
  double vy = var(y);
  double Sb = df*(R2)*vy/MSx/(1-pi);
  double Se = df*(1-R2)*vy;
  double mu = mean(y);
  // Create empty objects
  double b0,b1,b2,eM,h2,C,MU,VB,VE,vee,Pi,pj,ve=vy,vb=Sb;
  NumericVector d(p),b(p),D(p),B(p),fit(n);
  NumericVector e=y-mu,e1(n),e2(n);
  double Lmb=ve/vb;
  // MCMC loop
  for(int i=0; i<it; i++){
    C = -0.5/ve;
    // Update marker effects
    for(int j=0; j<p; j++){
      b0 = b[j];
      // Sample marker effect
      b1 = R::rnorm((sum(X(_,j)*e)+xx[j]*b0)/(xx[j]+Lmb),sqrt(ve/(xx[j]+Lmb)));
      b2 = R::rnorm(0,sqrt(ve/(xx[j]+Lmb)));
      e1 = e-X(_,j)*(b1-b0); // Pr(with marker)
      e2 = e-X(_,j)*(0-b0); // Pr(without marker)
      // Pr(marker included)
      pj = (1-pi)*exp(C*(sum(e1*e1)-sum(e2*e2)));
      if(pj>1) pj = 1;
      // Smple from Bernoulli
      if(R::rbinom(1,pj)==1){
        b[j] = b1; d[j] = 1;
      }else{
        b[j] = b2; d[j] = 0;
      }
      // Update residuals
      e = e - X(_,j)*(b[j]-b0);
    }
    // Update intercept
    eM = R::rnorm(mean(e),sqrt(ve/n));
    mu = mu+eM; e = e-eM;
    // Update variance components and lambda
    vb = (sum(b*b)+Sb)/R::rchisq(p+df);
    ve = (sum(e*e)+Se)/R::rchisq(n+df);
    Lmb = ve/vb;
    // Update Pi
    pi = mean(d);
    Sb = df*(R2)*vy/MSx/(1-pi);
    // Store posterior sums
    if(i>bi){MU=MU+mu; B=B+b; D=D+d; VB=VB+vb; VE=VE+ve; Pi = Pi+pi;}
  }
  // Get posterior means
  double MCMC = it-bi;
  MU = MU/MCMC; B = B/MCMC; D = D/MCMC;
  VB = VB/MCMC; VE = VE/MCMC; Pi = 1-Pi/MCMC;
  // Getting GWAS results
  NumericVector PVAL = -log(1-D);
  // Get fitted values and h2
  vee = sum(y*e)/(n-1);
  h2 = 1 - vee/vy;
  for(int k=0; k<n; k++){fit[k] = sum(X(k,_)*B)+MU;}
  // Return output
  return List::create(Named("mu") = MU, Named("b") = B,
                      Named("d") = D, Named("pi") = Pi,
                      Named("hat") = fit, Named("h2") = h2,
                      Named("vb") = VB, Named("ve") = VE,
                      Named("PVAL") = PVAL);}

// [[Rcpp::export]]
SEXP emML2(NumericVector y, NumericMatrix X1, NumericMatrix X2,
           Rcpp::Nullable<Rcpp::NumericVector> D1 = R_NilValue,
           Rcpp::Nullable<Rcpp::NumericVector> D2 = R_NilValue){
  int maxit = 350; double tol = 10e-8;
  // Functions starts here
  int p1 = X1.ncol();
  int p2 = X2.ncol();
  int n = X1.nrow();
  // Weights
  bool P1_WEIGHTS = FALSE;
  bool P2_WEIGHTS = FALSE;
  NumericVector d1(p1), d2(p2);
  if (D1.isNotNull()){P1_WEIGHTS = TRUE; d1=D1;}
  if (D2.isNotNull()){P2_WEIGHTS = TRUE; d2=D2;}
  // Beta, mu and epsilon
  double b0, eM, ve, vb1, vb2, h2, mu = mean(y);
  NumericVector b1(p1), b2(p2), u1(n), u2(n), cY(n), e = y-mu;
  // Marker variance
  NumericVector x1x1(p1), vx1(p1);
  for(int i=0; i<p1; i++){
    x1x1[i] = sum(X1(_,i)*X1(_,i));
    vx1[i] = var(X1(_,i));}
  double MSx1 = sum(vx1), Lmb1=MSx1;
  NumericVector x2x2(p2), vx2(p2);
  for(int i=0; i<p2; i++){
    x2x2[i] = sum(X2(_,i)*X2(_,i));
    vx2[i] = var(X2(_,i));}
  double MSx2 = sum(vx2), Lmb2=MSx2;
  // Convergence control
  NumericVector bc1(p1), bc2(p2);
  int numit = 0;
  double cnv = 1;
  // Loop
  while(numit<maxit){
    // Save b(t0)
    bc1 = b1+0;
    bc2 = b2+0;
    // Regression coefficients loop 1
    for(int j=0; j<p1; j++){
      b0 = b1[j];
      if(P1_WEIGHTS){
        b1[j] = (sum(X1(_,j)*e)+x1x1[j]*b0)/(x1x1[j]+Lmb1/d1[j]);
      }else{
        b1[j] = (sum(X1(_,j)*e)+x1x1[j]*b0)/(x1x1[j]+Lmb1);}
      e = e-X1(_,j)*(b1[j]-b0);}
    // Regression coefficients loop 2
    for(int j=0; j<p2; j++){
      b0 = b2[j];
      if(P2_WEIGHTS){
        b2[j] = (sum(X2(_,j)*e)+x2x2[j]*b0)/(x2x2[j]+Lmb2/d2[j]);
      }else{
        b2[j] = (sum(X2(_,j)*e)+x2x2[j]*b0)/(x2x2[j]+Lmb2);}
      e = e-X2(_,j)*(b2[j]-b0);}
    // Fitting the model
    for(int k=0; k<n; k++){
      u1[k] = sum(X1(k,_)*b1);
      u2[k] = sum(X2(k,_)*b2);
    }
    // Intercept update
    eM = mean(e);
    mu = mu+eM;
    e = e-eM;
    // Variance components update
    cY = u1+u2+e;
    ve = sum(e*cY)/n;
    vb1 = (sum(u1*cY)/n)/MSx1;
    vb2 = (sum(u2*cY)/n)/MSx2;
    Lmb1 = ve/vb1;
    Lmb2 = ve/vb2;
    // Convergence
    ++numit;
    cnv = sum(abs(bc1-b1))+sum(abs(bc2-b2));
    if( cnv<tol ){break;}}
  // Fitting the model
  NumericVector fit = mu+u1+u2;
  h2 = 1-ve/var(y);
  // Output
  return List::create(Named("mu")=mu,
                      Named("b1")=b1, Named("b2")=b2, 
                      Named("Vb1")=vb1, Named("Vb2")=vb2, Named("Ve")=ve,
                            Named("u1")=u1, Named("u2")=u2,
                            Named("MSx1")=MSx1, Named("MSx2")=MSx2,
                            Named("h2")=h2, Named("hat")=fit);}

// [[Rcpp::export]]
SEXP mrr(NumericMatrix Y, NumericMatrix X){
  // Convergence parameters
  int maxit = 200; double tol = 10e-8;
  // Obtain environment containing function
  Rcpp::Environment base("package:base");
  Rcpp::Function solve = base["solve"];
  // Functions starts here
  int k = Y.ncol(), p = X.ncol(), n0 = X.nrow();
  NumericMatrix fit(n0,k),o(n0,k),y(n0,k),e(n0,k);
  for(int i=0; i<k; i++){
    o(_,i) = ifelse(is_na(Y(_,i)),0,1);
    y(_,i) = ifelse(is_na(Y(_,i)),0,Y(_,i));}
  NumericVector n = colSums(o);
  // Marker variance
  NumericMatrix xx(p,k), vx(p,k);
  double tmp;
  for(int i=0; i<p; i++){
    for(int j=0; j<k; j++){
     xx(i,j) = sum(X(_,i)*X(_,i)*o(_,j));
      tmp = sum(X(_,i)*o(_,j))/n(j);
      vx(i,j) = xx(i,j)/n(j)-tmp*tmp;}}
  //NumericVector MSx = colSums(xx);
  NumericVector MSx = colSums(vx);
  // Beta, intersept and residuals
  NumericMatrix b(p,k),vb(k,k),iG(k,k),rho(k,k),LHS(k,k);
  NumericVector b0(k),b1(k),eM(k),mu(k),vy(k),ve(k),RHS(k);
  mu = colSums(y)/n;
  for(int i=0; i<k; i++){for(int j=0; j<k; j++){vb(i,j) = 0;}}
  for(int i=0; i<k; i++){
    e(_,i) = (y(_,i)-mu(i))*o(_,i);
    vy(i) = sum(e(_,i)*e(_,i))/(n(i)-1);
    ve(i) = vy(i)*0.5;
    vb(i,i) = ve(i)/MSx(i);
    rho(i,i) = 1;}
  iG = solve(vb);
  // Convergence control
  NumericMatrix bc(p,k);
  int numit = 0;
  double cnv = 1;
  // Loop
  while(numit<maxit){
    // Gauss-Seidel loop
    bc = b+0;
    for(int j=0; j<p; j++){
      b0 = b(j,_);
      LHS = iG+0;
      for(int i=0; i<k; i++){
        LHS(i,i) = iG(i,i)+(xx(j,i)/ve(i));
        RHS(i) = (sum(e(_,i)*X(_,j))+xx(j,i)*b0(i))/ve(i);}
      // Update effects
      b1 = solve(LHS, RHS);
      b(j,_) = b1;
      // Update residuals
      for(int i=0; i<k; i++){
        e(_,i) = (e(_,i)-X(_,j)*(b1(i)-b0(i)))*o(_,i);}}
    // Intercept update
    eM = colSums(e)/n;
    mu = mu+eM;
    for(int j=0; j<k; j++){e(_,j) = (e(_,j)-eM(j))*o(_,j);}
    // Variance components update
    for(int i=0; i<k; i++){ ve(i) = sum(e(_,i)*y(_,i))/(n(i)-1);}
    for(int i=0; i<n0; i++){ for(int j=0; j<k; j++){ fit(i,j) = sum(X(i,_)*b(_,j));}}
    for(int i=0; i<k; i++){ for(int j=0; j<k; j++){
      vb(i,j) = (sum(fit(_,i)*y(_,j))+sum(fit(_,j)*y(_,i))) / ((n(i)*MSx(i))+(n(j)*MSx(j))) ;}}
    for(int i=0; i<k; i++){vb(i,i)=vb(i,i)*1.01;} // Ridging
    iG = solve(vb);
    // Convergence
    ++numit;
    cnv = sum(abs(bc-b));
    if( cnv<tol ){break;}}
  // Fitting the model
  NumericVector h2(k); 
  for(int i=0; i<n0; i++){for(int j=0; j<k; j++){fit(i,j) = sum(X(i,_)*b(_,j))+mu(j);}}
  for(int i=0; i<k; i++){ h2 = (vb(i,i)*MSx(i))/((vb(i,i)*MSx(i))+ve); }
  // Output
  return List::create(Named("mu")=mu, Named("b")=b,
                      Named("hat")=fit, Named("h2")=h2,
                      Named("Vb")=vb, Named("Ve")=ve);}

// [[Rcpp::export]]
SEXP mrrV2(NumericMatrix Y, NumericMatrix X){
  int maxit = 200;
  double tol = 10e-6;
  // Obtain environment containing function
  Rcpp::Environment base("package:base");
  Rcpp::Function solve = base["solve"];
  // Functions starts here
  int k = Y.ncol(), p = X.ncol(), n0 = X.nrow();
  NumericMatrix fit(n0,k),o(n0,k),y(n0,k),e(n0,k);
  for(int i=0; i<k; i++){
    o(_,i) = ifelse(is_na(Y(_,i)),0,1);
    y(_,i) = ifelse(is_na(Y(_,i)),0,Y(_,i));}
  NumericVector n = colSums(o);
  // Mu
  NumericVector mu = colSums(y)/n;
  for(int j=0; j<k; j++){y(_,j) = (y(_,j)-mu(j))*o(_,j);}
  // Marker variance
  NumericMatrix xx(p,k), vx(p,k);
  double tmp;
  for(int i=0; i<p; i++){
    for(int j=0; j<k; j++){
     xx(i,j) = sum(X(_,i)*X(_,i)*o(_,j));
      tmp = sum(X(_,i)*o(_,j))/n(j);
      vx(i,j) = xx(i,j)/n(j)-tmp*tmp;}}
  //NumericVector MSx = colSums(xx);
  NumericVector MSx = colSums(vx);
  // Beta, intersept and residuals
  NumericMatrix b(p,k),vb(k,k),iG(k,k),rho(k,k),LHS(k,k);
  NumericVector b0(k),b1(k),vy(k),ve(k),RHS(k);
  for(int i=0; i<k; i++){for(int j=0; j<k; j++){vb(i,j) = 0;}}
  for(int i=0; i<k; i++){
    e(_,i) = y(_,i)+0;
    vy(i) = sum(e(_,i)*e(_,i))/(n(i)-1);
    ve(i) = vy(i)*0.5;
    vb(i,i) = ve(i)/MSx(i);
    rho(i,i) = 1;}
  iG = solve(vb);
  // Convergence control
  NumericMatrix bc(p,k);
  int numit = 0;
  double cnv = 1;
  // Loop
  while(numit<maxit){
    // Gauss-Seidel loop
    bc = b+0;
    for(int j=0; j<p; j++){
      b0 = b(j,_);
      LHS = iG+0;
      for(int i=0; i<k; i++){
        LHS(i,i) = iG(i,i)+(xx(j,i)/ve(i));
        RHS(i) = (sum(e(_,i)*X(_,j))+xx(j,i)*b0(i))/ve(i);}
      // Update effects
      b1 = solve(LHS, RHS);
      b(j,_) = b1;
      // Update residuals
      for(int i=0; i<k; i++){
        e(_,i) = (e(_,i)-X(_,j)*(b1(i)-b0(i)))*o(_,i);}
      }
    // Residual variance components update
    for(int i=0; i<k; i++){ ve(i) = (sum(e(_,i)*y(_,i)))/(n(i)-1);}
    // Genetic covariance components update
    for(int i=0; i<n0; i++){ for(int j=0; j<k; j++){fit(i,j) = sum(X(i,_)*b(_,j));}}
    for(int i=0; i<k; i++){ for(int j=0; j<k; j++){
      // Diag VC
      if(i==j){
        vb(i,j) = (1.01*vy(i)-ve(i))/MSx(i);
      }else{
        vb(i,j) = (sum(fit(_,i)*y(_,j))+sum(fit(_,j)*y(_,i))) / ((n(i)*MSx(i))+(n(j)*MSx(j)));
      }}}
    iG = solve(vb);
    // Convergence
    ++numit;
    cnv = sum(abs(bc-b));
    if( cnv<tol ){break;}}
  // Fitting the model
  NumericVector h2(k); 
  for(int i=0; i<n0; i++){for(int j=0; j<k; j++){fit(i,j) = sum(X(i,_)*b(_,j))+mu(j);}}
  h2 = 1-ve/vy;
  // Output
  return List::create(Named("mu")=mu, Named("b")=b,
                      Named("hat")=fit, Named("h2")=h2,
                      Named("Vb")=vb, Named("Ve")=ve);}

// [[Rcpp::export]]
SEXP mrr2X(NumericMatrix Y, NumericMatrix X1, NumericMatrix X2){
// Convergence parameters
  int maxit = 200; double tol = 10e-8;
  // Obtain environment containing function
  Rcpp::Environment base("package:base");
  Rcpp::Function solve = base["solve"];
  // Functions starts here
  int k = Y.ncol(), p1 = X1.ncol(), p2 = X2.ncol(), n0 = X1.nrow();
  NumericMatrix fit(n0,k),g1(n0,k),g2(n0,k),o(n0,k),y(n0,k),e(n0,k);
  for(int i=0; i<k; i++){
    o(_,i) = ifelse(is_na(Y(_,i)),0,1);
    y(_,i) = ifelse(is_na(Y(_,i)),0,Y(_,i));}
  NumericVector n = colSums(o);
  // Mu
  NumericVector mu = colSums(y)/n;
  for(int j=0; j<k; j++){y(_,j) = (y(_,j)-mu(j))*o(_,j);}
  // Marker variance
  NumericMatrix xx1(p1,k), vx1(p1,k);
  NumericMatrix xx2(p2,k), vx2(p2,k);
  double tmp;
  for(int i=0; i<p1; i++){
    for(int j=0; j<k; j++){
      xx1(i,j) = sum(X1(_,i)*X1(_,i)*o(_,j));
      tmp = sum(X1(_,i)*o(_,j))/n(j);
      vx1(i,j) = xx1(i,j)/n(j)-tmp*tmp;}}
  for(int i=0; i<p2; i++){
    for(int j=0; j<k; j++){
      xx2(i,j) = sum(X2(_,i)*X2(_,i)*o(_,j));
      tmp = sum(X2(_,i)*o(_,j))/n(j);
      vx2(i,j) = xx2(i,j)/n(j)-tmp*tmp;}}
  NumericVector MSx1 = colSums(vx1);
  NumericVector MSx2 = colSums(vx2);
  // Beta, intersept and residuals
  NumericMatrix b1(p1,k),vb1(k,k),iG1(k,k),LHS1(k,k);
  NumericMatrix b2(p2,k),vb2(k,k),iG2(k,k),LHS2(k,k);
  NumericVector b_0(k),b_1(k),vy(k),ve(k),RHS1(k),RHS2(k);
  for(int i=0; i<k; i++){
    for(int j=0; j<k; j++){
      vb2(i,j) = 0;
      vb1(i,j) = 0;
      }}
  for(int i=0; i<k; i++){
    e(_,i) = y(_,i)+0;
    vy(i) = sum(e(_,i)*e(_,i))/(n(i)-1);
    ve(i) = vy(i)*0.5;
    vb1(i,i) = ve(i)/MSx1(i);
    vb2(i,i) = ve(i)/MSx2(i);
    }
  iG1 = solve(vb1);
  iG2 = solve(vb2);
  // Convergence control
  NumericMatrix bc1(p1,k), bc2(p2,k);
  int numit = 0;
  double cnv = 1;
  // Loop
  while(numit<maxit){
    // Convergence parameter (coef at time zero)
    bc1 = b1+0; bc2 = b2+0;
    // Gauss-Seidel loop 1
    for(int j=0; j<p1; j++){
      b_0 = b1(j,_);
      LHS1 = iG1+0;
      for(int i=0; i<k; i++){
        LHS1(i,i) = iG1(i,i)+(xx1(j,i)/ve(i));
        RHS1(i) = (sum(e(_,i)*X1(_,j))+xx1(j,i)*b_0(i))/ve(i);}
      b_1 = solve(LHS1, RHS1);
      b1(j,_) = b_1;
      for(int i=0; i<k; i++){
        e(_,i) = (e(_,i)-X1(_,j)*(b_1(i)-b_0(i)))*o(_,i);}
    }
    // Gauss-Seidel loop 2
    for(int j=0; j<p2; j++){
      b_0 = b2(j,_);
      LHS2 = iG2+0;
      for(int i=0; i<k; i++){
        LHS2(i,i) = iG2(i,i)+(xx2(j,i)/ve(i));
        RHS2(i) = (sum(e(_,i)*X2(_,j))+xx2(j,i)*b_0(i))/ve(i);}
      b_1 = solve(LHS2, RHS2);
      b2(j,_) = b_1;
      for(int i=0; i<k; i++){
        e(_,i) = (e(_,i)-X2(_,j)*(b_1(i)-b_0(i)))*o(_,i);}
    }
    // Residual variance components update
    for(int i=0; i<k; i++){ ve(i) = (sum(e(_,i)*y(_,i)))/(n(i)-1);}
    // Genetic covariance components update
    for(int i=0; i<n0; i++){
      for(int j=0; j<k; j++){
          g1(i,j) = sum(X1(i,_)*b1(_,j));
          g2(i,j) = sum(X2(i,_)*b2(_,j));  
        }}
    for(int i=0; i<k; i++){
      for(int j=0; j<k; j++){
        vb1(i,j) = (sum(g1(_,i)*y(_,j))+sum(g1(_,j)*y(_,i))) / ((n(i)*MSx1(i))+(n(j)*MSx1(j)));
        vb2(i,j) = (sum(g2(_,i)*y(_,j))+sum(g2(_,j)*y(_,i))) / ((n(i)*MSx2(i))+(n(j)*MSx2(j)));
      }}
    iG1 = solve(vb1);
    iG2 = solve(vb2);
    // Convergence
    ++numit;
    cnv = sum(abs(bc1-b1))+sum(abs(bc2-b2));
    if( cnv<tol ){break;}}
  // Fitting the model
  NumericVector h2(k); 
  for(int j=0; j<k; j++){ fit(_,j) = mu(j)+g1(_,j)+g2(_,j); }
  h2 = 1-ve/vy;
  // Output
  return List::create(Named("mu")=mu,
                      Named("b1")=b1, Named("b2")=b2,
                      Named("hat")=fit,
                      Named("g1")=g1, Named("g2")=g2,
                      Named("Vb1")=vb1, Named("Vb2")=vb2, 
                      Named("MS1")=MSx1, Named("MS2")=MSx2,
                      Named("Ve")=ve, Named("h2")=h2);}

// [[Rcpp::export]]
SEXP mkr(NumericMatrix Y, NumericMatrix K){
  // Convergence parameters
  int maxit = 200; double tol = 10e-8;
  // Obtain environment containing function
  Rcpp::Environment base("package:base");
  Rcpp::Function solve = base["solve"];
  Rcpp::Function eigen = base["eigen"];
  // Eigendecomposition
  List EIG = eigen(K,true);
  NumericMatrix X = EIG[1];
  NumericVector d = EIG[0];
  // Functions starts here
  int k = Y.ncol(), p = X.ncol(), n0 = X.nrow();
  NumericMatrix fit(n0,k),o(n0,k),y(n0,k),e(n0,k);
  for(int i=0; i<k; i++){
    o(_,i) = ifelse(is_na(Y(_,i)),0,1);
    y(_,i) = ifelse(is_na(Y(_,i)),0,Y(_,i));}
  NumericVector n = colSums(o);
  // Mu
  NumericVector mu = colSums(y)/n;
  for(int j=0; j<k; j++){y(_,j) = (y(_,j)-mu(j))*o(_,j);}
  // Marker variance
  NumericMatrix xx(p,k);
  double MSx = mean(d);
  for(int i=0; i<p; i++){ for(int j=0; j<k; j++){
      xx(i,j) = sum(X(_,i)*X(_,i)*o(_,j)); }}
  // Beta, intersept and residuals
  NumericMatrix b(p,k),vb(k,k),iG(k,k),rho(k,k),LHS(k,k);
  NumericVector b0(k),b1(k),vy(k),ve(k),RHS(k);
  for(int i=0; i<k; i++){for(int j=0; j<k; j++){vb(i,j) = 0;}}
  for(int i=0; i<k; i++){
    e(_,i) = y(_,i)+0;
    vy(i) = sum(e(_,i)*e(_,i))/(n(i)-1);
    ve(i) = vy(i)*0.5;
    vb(i,i) = ve(i)/MSx;
    rho(i,i) = 1;}
  iG = solve(vb);
  // Convergence control
  NumericMatrix bc(p,k);
  int numit = 0;
  double cnv = 1;
  // Loop
  while(numit<maxit){
    // Gauss-Seidel loop
    bc = b+0;
    for(int j=0; j<p; j++){
      b0 = b(j,_);
      LHS = iG+0;
      for(int i=0; i<k; i++){
        LHS(i,i) = iG(i,i)+(xx(j,i)/(ve(i)/d(j)) );
        RHS(i) = (sum(e(_,i)*X(_,j))+xx(j,i)*b0(i))/(ve(i)/d(j));}
      // Update effects
      b1 = solve(LHS, RHS);
      b(j,_) = b1;
      // Update residuals
      for(int i=0; i<k; i++){
        e(_,i) = (e(_,i)-X(_,j)*(b1(i)-b0(i)))*o(_,i);}
    }
    // Residual variance components update
    for(int i=0; i<k; i++){ ve(i) = (sum(e(_,i)*y(_,i)))/n(i);}
    // Genetic covariance components update
    for(int i=0; i<n0; i++){ for(int j=0; j<k; j++){fit(i,j) = sum(X(i,_)*b(_,j));}}
    for(int i=0; i<k; i++){ for(int j=0; j<k; j++){
      // Diag VC
      if(i==j){
        vb(i,j) = (1.01*vy(i)-ve(i))/MSx;
      }else{
        vb(i,j) = (sum(fit(_,i)*y(_,j))+sum(fit(_,j)*y(_,i))) / ((n(i)+n(j))*MSx);
      }}}
    iG = solve(vb);
    // Convergence
    ++numit;
    cnv = sum(abs(bc-b));
    if( cnv<tol ){break;}}
  // Fitting the model
  NumericVector h2(k); 
  for(int i=0; i<n0; i++){for(int j=0; j<k; j++){fit(i,j) = sum(X(i,_)*b(_,j))+mu(j);}}
  h2 = 1-ve/vy;
  // Genetic correlations
  NumericMatrix GC(k,k);
  for(int i=0; i<k; i++){ for(int j=0; j<k; j++){GC(i,j)=vb(i,j)/(sqrt(vb(i,i)*vb(j,j)));}}
  // Output
  return List::create(Named("mu")=mu, Named("b")=b,
                      Named("hat")=fit, Named("h2")=h2,
                      Named("Vb")=vb, Named("Ve")=ve,
                      Named("GC")=GC);}

// [[Rcpp::export]]
SEXP mkr2X(NumericMatrix Y, NumericMatrix K1, NumericMatrix K2){
  // Convergence parameters
  int maxit = 200; double tol = 10e-8;
  // Obtain environment containing function
  Rcpp::Environment base("package:base");
  Rcpp::Function solve = base["solve"];
  Rcpp::Function eigen = base["eigen"];
  // Eigendecomposition
  List EIG1 = eigen(K1,true);
  NumericMatrix X1 = EIG1[1];
  NumericVector d1 = EIG1[0];
  List EIG2 = eigen(K2,true);
  NumericMatrix X2 = EIG2[1];
  NumericVector d2 = EIG2[0];
  // Functions starts here
  int k = Y.ncol(), p1 = X1.ncol(), p2 = X2.ncol(), n0 = X1.nrow();
  NumericMatrix fit(n0,k),g1(n0,k),g2(n0,k),o(n0,k),y(n0,k),e(n0,k);
  for(int i=0; i<k; i++){
    o(_,i) = ifelse(is_na(Y(_,i)),0,1);
    y(_,i) = ifelse(is_na(Y(_,i)),0,Y(_,i));}
  NumericVector n = colSums(o);
  // Mu
  NumericVector mu = colSums(y)/n;
  for(int j=0; j<k; j++){y(_,j) = (y(_,j)-mu(j))*o(_,j);}
  // Marker variance
  NumericMatrix xx1(p1,k), xx2(p2,k);
  for(int i=0; i<p1; i++){
    for(int j=0; j<k; j++){
      xx1(i,j) = sum(X1(_,i)*X1(_,i)*o(_,j));}}
  for(int i=0; i<p2; i++){
    for(int j=0; j<k; j++){
      xx2(i,j) = sum(X2(_,i)*X2(_,i)*o(_,j));}}
  double MSx1 = mean(d1), MSx2 = mean(d2);
  // Beta, intersept and residuals
  NumericMatrix b1(p1,k),vb1(k,k),iG1(k,k),LHS1(k,k);
  NumericMatrix b2(p2,k),vb2(k,k),iG2(k,k),LHS2(k,k);
  NumericVector b_0(k),b_1(k),vy(k),ve(k),RHS1(k),RHS2(k);
  for(int i=0; i<k; i++){
    for(int j=0; j<k; j++){
      vb2(i,j) = 0; vb1(i,j) = 0;}}
  for(int i=0; i<k; i++){
    e(_,i) = y(_,i)+0;
    vy(i) = sum(e(_,i)*e(_,i))/(n(i)-1);
    ve(i) = vy(i)*0.5;
    vb1(i,i) = ve(i)/MSx1;
    vb2(i,i) = ve(i)/MSx2;
  }
  iG1 = solve(vb1);
  iG2 = solve(vb2);
  // Convergence control
  NumericMatrix bc1(p1,k), bc2(p2,k);
  int numit = 0;
  double cnv = 1;
  // Loop
  while(numit<maxit){
    // Convergence parameter (coef at time zero)
    bc1 = b1+0; bc2 = b2+0;
    // Gauss-Seidel loop 1
    for(int j=0; j<p1; j++){
      b_0 = b1(j,_);
      LHS1 = iG1+0;
      for(int i=0; i<k; i++){
        LHS1(i,i) = iG1(i,i)+(xx1(j,i)/(ve(i)/d1(j)));
        RHS1(i) = (sum(e(_,i)*X1(_,j))+xx1(j,i)*b_0(i))/(ve(i)/d1(j));}
      b_1 = solve(LHS1, RHS1);
      b1(j,_) = b_1;
      for(int i=0; i<k; i++){
        e(_,i) = (e(_,i)-X1(_,j)*(b_1(i)-b_0(i)))*o(_,i);}
    }
    // Gauss-Seidel loop 2
    for(int j=0; j<p2; j++){
      b_0 = b2(j,_);
      LHS2 = iG2+0;
      for(int i=0; i<k; i++){
        LHS2(i,i) = iG2(i,i)+(xx2(j,i)/(ve(i)/d2(j)));
        RHS2(i) = (sum(e(_,i)*X2(_,j))+xx2(j,i)*b_0(i))/(ve(i)/d2(j));}
      b_1 = solve(LHS2, RHS2);
      b2(j,_) = b_1;
      for(int i=0; i<k; i++){
        e(_,i) = (e(_,i)-X2(_,j)*(b_1(i)-b_0(i)))*o(_,i);}
    }
    // Residual variance components update
    for(int i=0; i<k; i++){ ve(i) = (sum(e(_,i)*y(_,i)))/n(i);}
    // Genetic covariance components update
    for(int i=0; i<n0; i++){
      for(int j=0; j<k; j++){
        g1(i,j) = sum(X1(i,_)*b1(_,j));
        g2(i,j) = sum(X2(i,_)*b2(_,j));  
      }}
    for(int i=0; i<k; i++){
      for(int j=0; j<k; j++){
        vb1(i,j) = (sum(g1(_,i)*y(_,j))+sum(g1(_,j)*y(_,i))) / ((n(i)+n(j))*MSx1);
        vb2(i,j) = (sum(g2(_,i)*y(_,j))+sum(g2(_,j)*y(_,i))) / ((n(i)+n(j))*MSx2);
      }}
    iG1 = solve(vb1);
    iG2 = solve(vb2);
    // Convergence
    ++numit;
    cnv = sum(abs(bc1-b1))+sum(abs(bc2-b2));
    if( cnv<tol ){break;}}
  // Fitting the model
  NumericVector h2(k); 
  for(int j=0; j<k; j++){ fit(_,j) = mu(j)+g1(_,j)+g2(_,j); }
  h2 = 1-ve/vy;
  // Genetic correlations
  NumericMatrix GC1(k,k),GC2(k,k);
  for(int i=0; i<k; i++){ for(int j=0; j<k; j++){
    GC1(i,j)=vb1(i,j)/(sqrt(vb1(i,i)*vb1(j,j)));
    GC2(i,j)=vb2(i,j)/(sqrt(vb2(i,i)*vb2(j,j)));
    }}
  // Output
  return List::create(Named("mu")=mu,
                      Named("b1")=b1, Named("b2")=b2,
                      Named("hat")=fit,
                      Named("g1")=g1, Named("g2")=g2, 
                      Named("Vb1")=vb1, Named("Vb2")=vb2,
                      Named("GC1")=GC1, Named("GC2")=GC2,
                      Named("Ve")=ve, Named("h2")=h2);}

// [[Rcpp::export]]
SEXP mrrFast(NumericMatrix Y, NumericMatrix X){
  int maxit = 200; double tol = 10e-8;  
  // Obtain environment containing function
  Rcpp::Environment base("package:base");
  Rcpp::Function solve = base["solve"];  
  // Functions starts here
  int k = Y.ncol(), p = X.ncol(), n0 = X.nrow();
  NumericMatrix fit(n0,k),o(n0,k),y(n0,k),e(n0,k);
  for(int i=0; i<k; i++){
    o(_,i) = ifelse(is_na(Y(_,i)),0,1);
    y(_,i) = ifelse(is_na(Y(_,i)),0,Y(_,i));  }
  NumericVector n = colSums(o);  
  // Mu
  NumericVector mu = colSums(y)/n;
  for(int j=0; j<k; j++){
    y(_,j) = (y(_,j)-mu(j))*o(_,j);  }  
  // Marker variance
  NumericMatrix xx(p,k), vx(p,k);
  double tmp;
  for(int i=0; i<p; i++){
    for(int j=0; j<k; j++){
      xx(i,j) = sum(X(_,i)*X(_,i)*o(_,j));
      tmp = sum(X(_,i)*o(_,j))/n(j);
      vx(i,j) = xx(i,j)/n(j)-tmp*tmp;}}
  NumericVector MSx = colSums(vx);  
  // Beta, intersept and residuals
  NumericMatrix b(p,k),vb(k,k),rho(k,k);
  NumericVector b0(k),vy(k),ve(k);
  double b1,lhs,rhs,covs,vb0,lambda;
  for(int i=0; i<k; i++){for(int j=0; j<k; j++){vb(i,j) = 0;}}
  for(int i=0; i<k; i++){
    e(_,i) = y(_,i)+0;
    vy(i) = sum(e(_,i)*e(_,i))/(n(i)-1);
    ve(i) = vy(i)*0.5;
    vb(i,i) = ve(i)/MSx(i);
    rho(i,i) = 1;}
  NumericMatrix iG = solve(vb);  
  // Convergence control
  NumericMatrix bc(p,k);
  int numit = 0;
  double cnv = 1;  
  // Loop
  while(numit<maxit){    
    // Gauss-Seidel loop
    bc = b+0;
    for(int j=0; j<p; j++){      
      // Current marker effect
      b0 = b(j,_);      
      // Update coefficient one trait at a time
      for(int i=0; i<k; i++){        
        // Compute coefficient covariances among traits
        covs = 0.0;
        for(int ii=0; ii<k; ii++){
          if(i!=ii){ covs = covs+iG(i,ii)*b0(ii); } }
        //covs = covs/ve(i);
        covs = covs*ve(i);
        lambda = iG(i,i)*ve(i);        
        // Set LHS RHS
        lhs = xx(j,i) + lambda;
        rhs = sum(e(_,i)*X(_,j)) + xx(j,i)*b0(i) - covs;        
        // Update effects
        b1 = rhs/lhs;
        b(j,i) = b1;        
        // Update residuals
        //e(_,i) = ifelse( o(_,i)==1, (e(_,i)-X(_,j)*(b1-b0(i))), 0 );
        e(_,i) = (e(_,i)-X(_,j)*(b1-b0(i)))*o(_,i); }}    
    // Update variance components every few iterations
    if(numit%3==0){      
      // Get fitted values
      for(int i=0; i<n0; i++){
        for(int j=0; j<k; j++){
          fit(i,j) = sum(X(i,_)*b(_,j));}}      
      // Residual variance components update
      for(int i=0; i<k; i++){ ve(i) = (sum(e(_,i)*y(_,i)))/(n(i)-1); }      
      // Genetic covariance components update
      for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
          if(i==j){
                //vb(i,i) = sum(fit(_,i)*y(_,i))/(n(i)*MSx(i));
                vb(i,i) = (1.1*vy(i)-ve(i))/MSx(i);
              }else{
            if(i>j){
                vb0 = (sum(fit(_,i)*y(_,j))+sum(fit(_,j)*y(_,i))) / ((n(i)*MSx(i))+(n(j)*MSx(j)));
                vb(i,j) = vb0; vb(j,i) = vb0;}}}}      
      // Generalized inverse of G2A_Kernels
      iG = solve(vb);}    
    // Convergence
    ++numit;
    cnv = sum(abs(bc-b));
    if( cnv<tol ){break;}}  
  // Fitting the model
  NumericVector h2(k); 
  for(int i=0; i<n0; i++){for(int j=0; j<k; j++){fit(i,j) = sum(X(i,_)*b(_,j))+mu(j);}}
  h2 = 1-ve/vy;  
  // Genetic correlations
  NumericMatrix GC(k,k);
  for(int i=0; i<k; i++){ for(int j=0; j<k; j++){GC(i,j)=vb(i,j)/(sqrt(vb(i,i)*vb(j,j)));}}  
  // Output
  return List::create(Named("mu")=mu, Named("b")=b,
                      Named("hat")=fit, Named("h2")=h2,
                      Named("Vb")=vb, Named("GC")=GC,
                      Named("Ve")=ve);}
