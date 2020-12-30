\name{mi_matrix}
\alias{mi_matrix}
\title{Generating its Mutual Information Estimations Matrix}
\usage{
mi_matrix(df, proc=0)
}
\arguments{
\item{df}{a data frame.}
\item{proc}{given two discrete vectors of equal length, the function estimates the mutual information
based on Jeffrey's prior, the MDL principle, and BDeu for proc=0,1,2, respectively. If one of the columns is continuous, proc=10 should be chosen.
If the argument proc is missing, proc=0 (Jeffreys') is assumed.}
}
\description{
The estimators in this package detect independence as well as consistently estimates 
the true conditional mutual information value as the length grows based on Jeffrey's prior,
Bayesian Dirichlet equivalent uniform (BDeu [1]), 
and the MDL principle. It also estimates the conditional mutual information value 
even when one of the pair is continuous (see [2]).
Given a data frame each column of which may be either discrete or continuous, this function generates its mutual information estimation matrix. 
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
[3]   Suzuki. J.,  ``A novel Chow?Liu algorithm and its application to gene differential analysis", 
International Journal of Approximate Reasoning, Vol. 80, 2017.
}
\seealso{mi}
\examples{
library(bnlearn)
mi_matrix(asia)
mi_matrix(asia,proc=1)
mi_matrix(asia,proc=2)
mi_matrix(asia,proc=3)
}
