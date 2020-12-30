#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
IntegerMatrix kruskal(NumericMatrix W)
{
        int i,j, N=W.ncol();
        for(i=0; i<N-1; i++)for(j=i+1;j<N;j++)W(j,i)=W(i,j);
        for(i=0; i<N; i++)W(i,i)=0;
        IntegerVector parent(N);
        IntegerVector u(N); for(i=0; i<N; i++)u(i)=0;
        NumericVector v(N); for(i=0; i<N; i++)v(i)=-10000;
        j=0;
        parent(0)=-1;
        while(j<N){
                u(j)=1;
                for(i=1; i<N; i++)if(u(i)==0&&W(j,i)>v(i)){v(i)=W(j,i); parent(i)=j;}
                double max=0; for(i=1; i<N; i++) if(u(i)==0&&v(i)>max){j=i; max=v(i);}
                if(max==0){j=0; while(j<N&&u(j)==1)j++; if(j<N)parent(j)=-1;}
        }
        IntegerMatrix M(N,2); i=0; for(j=0; j<N; j++)if(parent(j)!=-1){M(i,0)=parent(j)+1; M(i++,1)=j+1;}
        return(M(Range(0,i-1),_));
}
