#include <Rcpp.h>
using namespace Rcpp;

#include "gc.h"

double empirical_mi(NumericVector, NumericVector);
double mi(NumericVector, NumericVector, int);
double MDL_mi(NumericVector, NumericVector, int, int);
double Jeffreys_mi(NumericVector, NumericVector, int, int);
double BDeu_mi(NumericVector, NumericVector, int, int, double);
double empirical_cmi(NumericVector, NumericVector, NumericVector);
double cmi(NumericVector, NumericVector, NumericVector, int);
double MDL_cmi(NumericVector, NumericVector, NumericVector, int, int, int);
double Jeffreys_cmi(NumericVector, NumericVector, NumericVector, int, int, int);
double BDeu_cmi(NumericVector, NumericVector, NumericVector, int, int, int, double);
NumericMatrix mi_matrix(DataFrame, int);
double cont_mi(NumericVector, NumericVector);
double cont_cmi(NumericVector, NumericVector, NumericVector);
NumericVector intervals(int, NumericVector);
int binary_search(NumericVector, double);


// [[Rcpp::export]]
double empirical_mi(NumericVector x, NumericVector y)
{
	int n=x.size();
	NumericVector c_x,c_y,c_xy;
	c_x=table(x); c_y=table(y); c_xy=table(x+1000*y);
	return(-sum(c_x/n*log(c_x/n))-sum(c_y/n*log(c_y/n))+sum(c_xy/n*log(c_xy/n)));
}

// [[Rcpp::export]]
double mi(NumericVector x, NumericVector y, int proc=0){
	if(proc==0)return(Jeffreys_mi(x,y,0,0));
	else if(proc==1)return(MDL_mi(x,y,0,0));
	else if(proc==2)return(BDeu_mi(x,y,0,0,1));
	else if(proc==3)return(empirical_mi(x,y));	
	else if(proc==9)return(empirical_mi(x,y));
	else if(proc==10)return(cont_mi(x,y));
	else return(Jeffreys_mi(x,y,0,0));
}

// [[Rcpp::export]]
double MDL_mi(NumericVector x, NumericVector y, int m_x=0, int m_y=0)
{
	if(m_x==0)m_x=table(x).size(); if(m_y==0)m_y=table(y).size();
	int n=x.size();
	double S=empirical_mi(x,y)-0.5*(m_x-1)*(m_y-1)*log(1.0*n)/n;
	if (S<=0) return(0); else return (S);
}

// [[Rcpp::export]]
double Jeffreys_mi(NumericVector x, NumericVector y, int m_x=0, int m_y=0)
{
	IntegerVector c_x=table(x);
        IntegerVector c_y=table(y);
        IntegerVector c_xy=table(x+y);
	if(m_x==0)m_x=c_x.size(); if(m_y==0)m_y=c_y.size();
	int n=x.size();
	double S_x=gc(n,0.5*m_x)-gc_all(c_x,0.5), S_y=gc(n,0.5*m_y)-gc_all(c_y,0.5), S_xy=gc(n,0.5*m_x*m_y)-gc_all(c_xy,0.5), S=(S_x+S_y-S_xy)/n;
	if (S<=0) return(0); else return (S);
}

// [[Rcpp::export]]
double BDeu_mi(NumericVector x, NumericVector y, int m_x=0, int m_y=0, double d=1)
{
        IntegerVector c_x=table(x), c_y=table(y), c_xy=table(x+1000*y);
        if(m_x==0)m_x=c_x.size(); if(m_y==0)m_y=c_y.size();
	int n=x.size();
	double S_x=gc(n,d)-gc_all(c_x,d/m_x), S_y=gc(n,d)-gc_all(c_y,d/m_y), S_xy=gc(n,d)-gc_all(c_xy,d/m_x/m_y), S=(S_x+S_y-S_xy)/n;
	if (S<=0) return(0); else return (S);
}

// [[Rcpp::export]]
double empirical_cmi(NumericVector x, NumericVector y, NumericVector z)
{
	int n=x.size();
	NumericVector c_xz, c_yz, c_xyz, c_z;
	c_xz=table(x+100*z); c_yz=table(y+100*z); c_xyz=table(x+100*y+10000*z); c_z=table(z);
	return(-sum(c_xz/n*log(c_xz/n))-sum(c_yz/n*log(c_yz/n))+sum(c_xyz/n*log(c_xyz/n))+sum(c_z/n*log(c_z/n)));
}

// [[Rcpp::export]]
double cmi(NumericVector x, NumericVector y, NumericVector z, int proc=0){
	if(proc==1)return(MDL_cmi(x,y,z,0,0,0));
	else if(proc==2)return(BDeu_cmi(x,y,z,0,0,0,1));
	else if(proc==3)return(empirical_cmi(x,y,z));
	else if(proc==10)return(cont_cmi(x,y,z));
	else return(Jeffreys_cmi(x,y,z,0,0,0));
}

// [[Rcpp::export]]
double MDL_cmi(NumericVector x, NumericVector y, NumericVector z, int m_x=0, int m_y=0, int m_z=0)
{
	if(m_x==0)m_x=table(x).size(); if(m_y==0)m_y=table(y).size(); if(m_z==0)m_z=table(z).size();
	int n=x.size();
	double S=empirical_cmi(x,y,z)-0.5*(m_x-1)*(m_y-1)*m_z*log((double)n)/n;
	if (S<=0) return(0); else return (S);
}

// [[Rcpp::export]]
double Jeffreys_cmi(NumericVector x, NumericVector y, NumericVector z, int m_x=0, int m_y=0, int m_z=0)
{
        IntegerVector c_z=table(z), c_xz=table(x+100*z), c_yz=table(y+100*z), c_xyz=table(x+100*y+10000*z);
        if(m_x==0)m_x=table(x).size(); if(m_y==0)m_y=table(y).size(); if(m_z==0)m_z=c_z.size();
	int n=x.size();
	double S_xz=gc(n,0.5*m_x*m_z)-gc_all(c_xz,0.5), S_yz=gc(n,0.5*m_y*m_z)-gc_all(c_yz,0.5), S_xyz=gc(n,0.5*m_x*m_y*m_z)-gc_all(c_xyz,0.5), S_z=gc(n,0.5*m_z)-gc_all(c_z,0.5), S=(S_xz+S_yz-S_xyz-S_z)/n;
	if (S<=0) return(0); else return (S);
}

// [[Rcpp::export]]
double BDeu_cmi(NumericVector x, NumericVector y, NumericVector z, int m_x=0, int m_y=0, int m_z=0, double d=1)
{
        IntegerVector c_z=table(z), c_xz=table(x+100*z), c_yz=table(y+100*z), c_xyz=table(x+100*y+10000*z);
        if(m_x==0)m_x=table(x).size(); if(m_y==0)m_y=table(y).size(); if(m_z==0)m_z=c_z.size();
        int n=x.size();
	double S_xz=gc(n,d)-gc_all(c_xz,d/m_x/m_z), S_yz=gc(n,d)-gc_all(c_yz,d/m_y/m_z), S_xyz=gc(n,d)-gc_all(c_xyz,d/m_x/m_y/m_z), S_z=gc(n,d)-gc_all(c_z,d/m_z), S=(S_xz+S_yz-S_xyz-S_z)/n;
	if (S<=0) return(0); else return (S);
}

// [[Rcpp::export]]
NumericMatrix mi_matrix(DataFrame df, int proc=0){
	int j, k, N=df.size();
	NumericMatrix mi_mat(N,N);
	for(j=0; j<N; j++){
		for(k=0; k<j+1; k++)mi_mat(j,k)=0;
		for(k=j+1; k<N; k++)mi_mat(j,k)=mi(df[j],df[k], proc);
	}
	return(mi_mat);
}

// [[Rcpp::export]]
double cont_mi(NumericVector x, NumericVector y){
	int n=x.size(),size=ceil(log((double)n)/log(2.0))+1,i,j,k;
	NumericVector w(n), xx=sort_unique(x), yy=sort_unique(y);
	NumericMatrix p(n,size),q(n,size);
	for(j=0; j<size; j++){
		w=intervals(j,xx);
		for(i=0; i<n; i++)p(i,j)=binary_search(w,x(i));
		w=intervals(j,yy);
		for(i=0; i<n; i++)q(i,j)=binary_search(w,y(i));
	}
	double mi_value=-100;
	for(j=0;j<size;j++)for(k=0;k<size-j;k++){
		double S=mi(p(_,j),q(_,k),1);
		if(S>mi_value)mi_value=S;
	}
	return(mi_value);
}

// [[Rcpp::export]]
double cont_cmi(NumericVector x, NumericVector y, NumericVector z){
	int n=x.size(),size=ceil(log((double)n)/log(2.0))+1,i,j,k;
	NumericVector w(n), xx=sort_unique(x), yy=sort_unique(y), zz=sort_unique(z);
	NumericMatrix p(n,size),q(n,size), r(n,size);
	for(j=0; j<size; j++){
		w=intervals(j,xx);
		for(i=0; i<n; i++)p(i,j)=binary_search(w,x(i));
		w=intervals(j,yy);
		for(i=0; i<n; i++)q(i,j)=binary_search(w,y(i));
		w=intervals(j,zz);
		for(i=0; i<n; i++)r(i,j)=binary_search(w,z(i));
	}
	double cmi_value=-100;
	for(j=0;j<size;j++)for(k=0;k<size-j;k++)for(i=0;i<size-j-k;i++){
		double S=cmi(p(_,j),q(_,k),r(_,i),1);
		if(S>cmi_value)cmi_value=S;
	}
	return(cmi_value);
}
		
// [[Rcpp::export]]
NumericVector intervals(int level, NumericVector array){
        int n=array.size(), m=n/2;
        NumericVector element=NumericVector::create(array(m));
        if(level==0||n==1)return(element);
        int i=0; while(0<=m-i-1&&array(m-i-1)==array(m))i++;
        int j=0; while(m+j+1<=n-1&&array(m)==array(m+j+1))j++;
        if(i<m)element=union_(intervals(level-1,head(array,m-i)),element);
        if(j<n-m)element=union_(element,intervals(level-1,tail(array,n-m-1-j)));
        return(element.sort());
}

// [[Rcpp::export]]
int binary_search (NumericVector array,  double pattern) {
		int n=array.size(), left=0, right=n-1, mid=n/2;
		if(pattern==array(mid))return(mid+1); else if(pattern<array(mid))right=mid-1; else left=mid+1;
		if(right<0)return(0); else if(left>n-1)return(n); else return(left+binary_search(array[seq(left,right)], pattern));        
}


