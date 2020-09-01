\name{cmi}
\alias{cmi}
\title{Bayesian Estimation of Conditional Mutual Information}
\usage{
 cmi(x, y, z, proc=0L)
}
\arguments{
\item{x}{a numeric vector.}
\item{y}{a numeric vector.}
\item{z}{a numeric vector. x, y and z should have an equal length.}
\item{proc}{the estimation is based on Jeffrey's prior, the MDL principle, and BDeu for proc=0,1,2, respectively. If the argument proc is missing, proc=0 (Jeffreys') is assumed.}
}
\description{
  A standard estimator of conditional mutual information calculates the maximal likelihood value. 
However, the estimator takes positive values even the pair follows a distribution of two independent variables. 
On the other hand, the estimator in this package detects conditional independence as well as consistently estimates 
the true conditional mutual information value as the length grows based on Jeffrey's prior, 
Bayesian Dirichlet equivalent uniform (BDeu [1]), 
and the MDL principle. It also estimates the conditional mutual information value 
even when one of the pair is continuous (see [2]).
}
\value{
the estimation of conditional mutual information between the two numeric vectors based on the selected criterion,
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

x=c(rbinom(n,1,0.2), rbinom(n,1,0.8))
y=c(rbinom(n,1,0.8), rbinom(n,1,0.2))
z=c(rep(1,n),rep(0,n))
cmi(x,y,z,proc=0); cmi(x,y,z,1); cmi(x,y,z,2) 

x=c(rbinom(n,1,0.2), rbinom(n,1,0.8))
u=rbinom(2*n,1,0.1)
y=(x+u)%%2
z=c(rep(1,n),rep(0,n))
cmi(x,y,z); cmi(x,y,z,proc=1); cmi(x,y,z,2) 

}
