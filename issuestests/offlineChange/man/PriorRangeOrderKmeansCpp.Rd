\name{PriorRangeOrderKmeansCpp}
\alias{PriorRangeOrderKmeansCpp}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
Detect Location of Change Points of Independent Data with Prior Ranges using Rcpp
}
\usage{
PriorRangeOrderKmeansCpp(x, prior_range_x, num_init = 10)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
\item{x}{The data to find change points with dimension N x D, must be matrix}

\item{prior_range_x}{The prior ranges that contain change points.}

\item{num_init}{The number of repetition times, in order to avoid local minimal.
Default is 10. Must be integer.}
}
\value{
\item{num_change_point}{optimal number of change points.}
 \item{change_point}{location of change points.}
}
\description{
Detect the location of change points based on minimizing within segment quadratic
loss with restriction of prior ranges that contaion change points.
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
l1<-c(15,25)
l2<-c(75,100)
prior_range_x<-list(l1,l2)
PriorRangeOrderKmeansCpp(x,prior_range_x=list(l1,l2))
}
\references{
J. Ding, Y. Xiang, L. Shen, and V. Tarokh, \emph{Multiple Change Point Analysis:
Fast Implementation and Strong Consistency}. IEEE Transactions on Signal
Processing, vol. 65, no. 17, pp. 4495-4510, 2017.
}



