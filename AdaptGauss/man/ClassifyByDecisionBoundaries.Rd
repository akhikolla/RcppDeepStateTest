\name{ClassifyByDecisionBoundaries}
\alias{ClassifyByDecisionBoundaries}

\title{Classify Data according to decision Boundaries}
\description{
The Decision Boundaries calculated through Bayes Theorem.
}
\usage{
ClassifyByDecisionBoundaries(Data,DecisionBoundaries,ClassLabels)
}

\arguments{
  \item{Data}{vector of Data}
  \item{DecisionBoundaries}{decision boundaries, \code{\link{BayesDecisionBoundaries}}}
  \item{ClassLabels}{Optional numbered class labels that are assigned to the classes. default (1:L), L number of different components of gaussian mixture model}

}

\value{
Cls(1:n,1:d)               classiffication of Data, such that 1= first component of gaussian mixture model, 2= second component of gaussian mixture model and so on. For Every datapoint a number is returned.
}

\author{Michael Thrun}
\references{Duda, R. O., Hart, P. E., & Stork, D. G. (2001). Pattern classification. 2nd. Edition. New York, p. 512ff}
\seealso{\code{\link{BayesDecisionBoundaries}}, \code{\link{Bayes4Mixtures}}}

\keyword{ClassifyByDecisionBoundaries}

