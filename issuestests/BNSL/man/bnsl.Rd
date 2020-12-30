\name{bnsl}
\alias{bnsl}
\title{Bayesian Network Structure Learning}
\usage{
 bnsl(df, tw = 0, proc = 1, s=0, n=0, ss=1)
}
\arguments{
\item{df}{a dataframe.}
\item{tw}{the upper limit of the parent set.}
\item{proc}{the criterion based on which the BNSL solution is sought.
proc=1,2, and 3 indicates that the structure learning is based on Jeffreys [1], MDL [2,3], and BDeu [3]}
\item{s}{The value computed when obtaining the bound.}
\item{n}{The number of samples.}
\item{ss}{The BDeu parameter.}
}
\description{The function outputs the Bayesian network structure given a dataset based on 
an assumed criterion.  
}
\value{
The Bayesian network structure in the bn class of bnlearn.
}
\author{
Joe Suzuki and Jun Kawahara
}
\references{
[1] Suzuki, J. ``An Efficient Bayesian Network Structure Learning Strategy", New Generation Computing, December 2016.
[2] Suzuki, J. ``A construction of Bayesian networks from databases based on an MDL principle", 
Uncertainty in Artificial Intelligence, pages 266-273, Washington D.C. July, 1993.
[3] Suzuki, J. ``Learning Bayesian Belief Networks Based on the Minimum Description Length Principle: An Efficient Algorithm Using the B & B Technique",
International Conference on Machine Learning, Bali, Italy, July 1996"
[4] Suzuki, J. ``A Theoretical Analysis of the BDeu Scores in Bayesian Network Structure Learning", Behaviormetrika 1(1):1-20,
[5] Suzuki, J.  and Kawahara, J., ``Branch and Bound for Regular Bayesian Network Structure learning", Uncertainty in Artificial Intelligence, pages 212-221,  Sydney, Australia, August 2017.
[6] Suzuki, J. ``Forest Learning from Data and its Universal Coding", IEEE Transactions on Information Theory, Dec. 2018.
January 2017.
}
\seealso{parent}
\examples{
library(bnlearn)
bnsl(asia)
}
