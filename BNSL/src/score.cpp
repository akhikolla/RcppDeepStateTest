#include <Rcpp.h>
using namespace Rcpp;

#include "gc.h"
#include "score.h"

// [[Rcpp::export]]
double Bayes_score(IntegerMatrix T, int m, int proc=0, double s=0, int n=0, int ss=1){
    if(proc==0)return(quotient_Jeffreys_score(T,m,s,n));
    else if(proc==1)return(Jeffreys_score(T,m));
    else if(proc==2)return(MDL_score(T,m,s,n));
    else if(proc==3)return(BDeu_score(T,m,ss));
    else return(quotient_Jeffreys_score(T,m,s,n));
}

// [[Rcpp::export]]
double quotient_Jeffreys_score(IntegerMatrix T, int m, double s, int n){
    int w=T.nrow();
    for(int j=0; j<w; j++)s=s-gc(sum(T(j,_)),0.5)+gc_all(T(j,_),0.5);
    return(s);
}

// [[Rcpp::export]]
double Jeffreys_score(IntegerMatrix T, int m){
    int w=T.nrow();
    double s=0;
    for(int j=0; j<w; j++)s=s-gc(sum(T(j,_)),m*0.5)+gc_all(T(j,_),0.5);
    return(s);
}

// [[Rcpp::export]]
double MDL_score(IntegerMatrix T, int m, double s, int n){
    int w=T.nrow();
    for(int j=0; j<w; j++){
        double n_s=sum(T(j,_));
        for(int k=0; k<m; k++)s=s+T(j,k)*log(T(j,k)/n_s);
    }
    return(s);
}

// [[Rcpp::export]]
double BDeu_score(IntegerMatrix T, int m, int ss){
    int w=T.nrow();
    double s=0;
    for(int j=0; j<w; j++)s=s-gc(sum(T(j,_)),1./ss)+gc_all(T(j,_),1./m/ss);
    return(s);
}

// [[Rcpp::export]]
double bound(IntegerMatrix T, int m, int proc=0, int n=0, int ss=1){
    if(proc==0)return(quotient_Jeffreys_bound(T,m,n,ss));
    else if(proc==1)return(Jeffreys_bound(T,m));
    else if(proc==2)return(MDL_bound(T,m,n,ss));
    else if(proc==3)return(BDeu_bound(T,m));
    else return(Jeffreys_bound(T,m));
}

// [[Rcpp::export]]
double Jeffreys_bound(IntegerMatrix T, int m){
    int w=T.nrow();
    double s=0;
    for(int j=0; j<w; j++)s=s+gc_all(T(j,_),0.5)-gc_all(T(j,_),0.5*m);
    return(s);
}

// [[Rcpp::export]]
double quotient_Jeffreys_bound(IntegerMatrix T, int m, int n, int ss){
    return(gc(n,0.5*ss)-gc(n,0.5*ss*m));
}

// [[Rcpp::export]]
double MDL_bound(IntegerMatrix T, int m, int n, int ss){
    return(-0.5*(m-1)*ss*log(1.0*n));
}

// [[Rcpp::export]]
double BDeu_bound(IntegerMatrix T, int m){
    int w=T.nrow();
    return(-w*log(1.0*m));
}
