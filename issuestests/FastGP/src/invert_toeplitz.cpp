//March 18th, 2014
//The purpose of this C-code is to implement Algorithm 4.7.3 from Matrix Computations by Golub and Van Loan for inverting a Toeplitz, symetric positive definite matrix
//Giri Gopalan
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector durbin(NumericVector r, int N){
  NumericVector y(N);
  NumericVector z(N);
  y(0) = -r(0);
  double Beta = 1;
  double alpha = -r(0); 
  double temp = 0;
  for(int i = 0; i < N-1; i++)
  {
    temp = 0;
    Beta = (1-alpha*alpha)*Beta;
    for(int j = 0; j <= i; j++)
    {
      temp += r(i-j)*y(j);
    }
    alpha = -(r(i+1)+temp)/Beta;
    for(int j = 0; j <= i; j++)
    {
      z(j) = y(j)+alpha*y(i-j);
    }
    for(int j = 0; j <= i;j++)
    {
      y(j) = z(j);
    }
    y(i+1) = alpha;
  }
  return(y);
}

// [[Rcpp::export]]
NumericVector trench(NumericVector r, NumericVector y, int N)
{
  NumericMatrix B(N,N);
  NumericVector v(N-1);
  double gamma = 0;
  double temp = 0;
  for(int i = 0; i < N-1; i++)
  {
    temp += r(i)*y(i);
  }
  gamma = 1/(1+temp);
  for(int i = 0; i < N-1; i++)
  {
    v(i) = gamma*y(N-2-i);
  }
  B(0,0) = gamma;
  for(int i=1; i < N; i++)
  {
    B(0,i) = v(N-1-i);
    B(i,0) = B(0,i);
  }
  for(int i = 1; i <= ceil((N-1)/2.0); i++)
  {
   int j = i;
   for(j=1;j <= N-i-1;j++)
    {
      B(i,j) = B(i-1,j-1)+(v(N-1-j)*v(N-1-i)-v(i-1)*v(j-1))/gamma;
      B(j,i) = B(i,j);
    }
  }
  for(int i = N-1; i >= ceil(N/2.0); i--)
  {
    for(int j = N-i; j <= N-1; j++)
    {
      B(i,j) = B(N-1-i,N-1-j);
      B(j,i) = B(i,j);
    }
  }
  return(B);
}
