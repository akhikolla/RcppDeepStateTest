\name{BayesDecisionBoundaries}
\alias{BayesDecisionBoundaries}
\title{Decision Boundaries calculated through Bayes Theorem}
\description{
	Function finds the intersections of Gaussians or LogNormals
}
\usage{
BayesDecisionBoundaries(Means,SDs,Weights,IsLogDistribution,MinData,MaxData,Ycoor)
}
\arguments{
  \item{Means}{vector[1:L] of Means of Gaussians (of GMM)}
  \item{SDs}{vector of standard deviations, estimated Gaussian Kernels, has to be the same length as Means}
  \item{Weights}{vector of relative number of points in Gaussians (prior probabilities), has to be the same length as Means}
  \item{IsLogDistribution}{Optional, ==1 if distribution(i) is a LogNormal, default vector of zeros of length 1:L}
   \item{MinData}{Optional, Beginning of range, where the Boundaries are searched for, default min(M)}
  \item{MaxData}{Optional, End of range, where the Boundaries are searched for, default max(M)}
	\item{Ycoor}{Optional, Bool, if TRUE instead of vector of DecisionBoundaries
                         list of DecisionBoundaries and DBY is returned}
}

\value{            
  \item{DecisionBoundaries }{vector[1:L-1], Bayes decision boundaries }
  \item{DBY }{if (Ycoor==TRUE), y values at the cross points of the Gaussians is also returned, that the return is a list of DecisionBoundaries and DBY}
}
\references{Duda, R. O., Hart, P. E., & Stork, D. G. (2001). Pattern classification. 2nd. Edition. New York, p. 512ff}
\author{Michael Thrun, Rabea Griese}
\seealso{\code{\link{AdaptGauss}},\code{\link{Intersect2Mixtures}},\code{\link{Bayes4Mixtures}}}
\keyword{Bayes}
\keyword{BayesDecisionBoundaries}
\keyword{Boundaries}