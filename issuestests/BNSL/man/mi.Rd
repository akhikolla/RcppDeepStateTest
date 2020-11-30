\name{mi}
\alias{mi}
\title{Bayesian Estimation of Mutual Information}
\usage{
 mi(x, y, proc=0)
}
\arguments{
\item{x}{a numeric vector.}
\item{y}{a numeric vector. x and y should have a equal length.}
\item{proc}{the estimation is based on Jeffrey's prior, the MDL principle, and BDeu for proc=0,1,2, respectively. 
If one of the two is continuous, proc=10 should be chosen.
If the argument proc is missing, proc=0 (Jeffreys') is assumed.}
}
\description{
  A standard estimator of mutual information calculates the maximal likelihood value. However, the estimator takes positive values
even the pair follows a distribution of two independent variables. On the other hand, the estimator in this package detects independence as well as consistently estimates 
the true mutual information value as the length grows based on Jeffrey's prior, Bayesian Dirichlet equivalent uniform (BDeu [1]), 
and the MDL principle. It also estimates the mutual information value even when one of the pair is continuous (see [2]).
}
\value{
the estimation of mutual information between the two numeric vectors based on the selected criterion,
where the natural logarithm base is assumed.
}
\author{
Joe Suzuki and Jun Kawahara
}
\references{
[1]   Suzuki, J., ``A theoretical analysis of the BDeu scores in Bayesian network structure learning", Behaviormetrika, 2017.
[2]   Suzuki, J., ``An estimator of mutual information and its application to independence testing", Entropy, Vol.18, No.4, 2016. 
[3]   Suzuki. J.  ``The Bayesian Chow-Liu algorithms", In the sixth European workshop on Probabilistic Graphical Models, pp. 315-322, Granada, Spain, Sept.2012.
}
\seealso{cmi}
\examples{
n=100

x=rbinom(n,1,0.5); y=rbinom(n,1,0.5); mi(x,y)

z=rbinom(n,1,0.1); y=(x+z)%%2

mi(x,y); mi(x,y,proc=1); mi(x,y,2) 

x=rnorm(n); y=rnorm(n); mi(x,y,proc=10)

x=rnorm(n); z=rnorm(n); y=0.9*x+sqrt(1-0.9^2)*z; mi(x,y,proc=10)

}
