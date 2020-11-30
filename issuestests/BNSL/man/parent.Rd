\name{parent.set}
\alias{parent.set}
\title{Parent Set}
\usage{
 parent.set(df, h, tw=0, proc=1)
}
\arguments{
\item{df}{a data frame.}
\item{h}{an integer from 0 to p-1, where p is the number of columns in df.}
\item{tw}{an integer from 0 to p-1, where p is the number of columns in df.}
\item{proc}{the parent sets are estimated based on Jeffreys' (proc=0,1) [1], MDL (proc=2) [2,3], and BDeu (proc=3) [4].} 
}
\description{
This function estimates a parent set of h in each subset w as follows:
Suppose we are given a subset w of the p-1 variables excluding h, where p is the number of columns in df.
Then, a score is defined for each subset w, where
the score expresses how well the subset is likely to be the true parent set of h in w. 
Currently, a Bayesian score (Jeffreys' prior) is applied. 
This function computes the maximum score z and its subset y of w. 
This function computes y and z for all w, where w and y are exprssed by binary sequences of length p, respectively.
When the computation is heavy, it can be reduced by specifying the maximum size of w, 
If tw is zero (default), the tw value is set to p-1, Otherwise, the tw value expresses the maximum size.
}
\value{
the data frame in which each row consists of the triples (w,y,z):
w is a subset of the p-1 variables excluding h; y is the parent set for w; and
z is the score of the parent set.
}
\author{
Joe Suzuki and Jun Kawahara
}
\references{
[1]  Suzuki, J., ``An Efficient Bayesian Network Structure Learning Strategy", New Generation Computing, December 2016.
[2]  Suzuki, A., ``Construction of Bayesian Networks from Databases Based on an MDL Principle", 
Proceedings of the Ninth Annual Conference on Uncertainty in Artificial Intelligence, 
The Catholic University of America, Providence, Washington, DC, USA, July 9-11, 1993.
[3]  Suzuki, J., ``Learning Bayesian Belief Networks Based on the Minimum Description Length Principle: An Efficient Algorithm Using the B & B Technique.",
Proceedings of the Thirteenth International Conference (ICML '96), Bari, Italy, July 3-6, 1996.
[4]  Suzuki, J., ``A theoretical analysis of the BDeu scores in Bayesian network structure learning", Behaviormetrika, 2017.
}
\seealso{cmi}
\examples{
library(bnlearn)
df=asia
parent.set(df,7)
parent.set(df,7,1)
parent.set(df,7,2)
}
