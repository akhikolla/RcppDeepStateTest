\name{OrderKmeansCpp}
\alias{OrderKmeansCpp}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
Detect Location of Change Points of Independent Data using Rcpp
}
\usage{
OrderKmeansCpp(x, K = 4, num_init = 10)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{x}{The data to find change points with dimension N x D, must be matrix}

\item{K}{The number of change points.}

\item{num_init}{The number of repetition times, in order to avoid local minimal.
Default is 10. Must be integer.}
}
\value{
\item{wgss_sum}{total within segment sum of squared distances to the segment
                 mean (wgss) of all segments.}
        \item{num_each}{number of observations of each segment}
        \item{wgss}{total wgss of each segment.}
        \item{change_point}{location of optimal change points.}
}
\description{
Detect the location of change points based on minimizing within segment quadratic
loss with fixed number of change points.
}
\details{
The K change points form K+1 segments (1 2 ... change_point(1)) ...
(change_point(K) ... N).
}
\examples{
a<-matrix(rnorm(40,mean=-1,sd=1),nrow=20,ncol=2)
b<-matrix(rnorm(120,mean=0,sd=1),nrow=60,ncol=2)
c<-matrix(rnorm(40,mean=1,sd=1),nrow=20,ncol=2)
x<-rbind(a,b,c)
OrderKmeansCpp(x,K=3)
OrderKmeansCpp(x,K=3,num_init=8)
}
\references{
J. Ding, Y. Xiang, L. Shen, and V. Tarokh, \emph{Multiple Change Point Analysis:
Fast Implementation and Strong Consistency}. IEEE Transactions on Signal
Processing, vol. 65, no. 17, pp. 4495-4510, 2017.
}



