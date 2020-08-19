\name{Intersect2Mixtures}
\alias{Intersect2Mixtures}

\title{Intersect of two Gaussians}
\description{
Finds the intersect of two gaussians or log gaussians
}
\usage{
Intersect2Mixtures(Mean1,SD1,Weight1,Mean2,SD2,Weight2,IsLogDistribution,MinData,MaxData)
}

\arguments{

  \item{Mean1}{mean of 1.gaussian}
  \item{SD1}{standard deviations of 1.gaussian}
  \item{Weight1}{weight of 1. guassian}
  \item{Mean2}{mean of 2.gaussian}
  \item{SD2}{standard deviations of 2.gaussian}
  \item{Weight2}{weight of 2. guassian}
  \item{IsLogDistribution}{Optional, ==1 if distribution(i) is a LogNormal, default vector of zeros of length 2}
  \item{MinData}{Optional, Beginning of range, where the intersect is searched for, default min(Mean1,Mean2)}
  \item{MaxData}{Optional, End of range, where the intersect is searched for, default max(Mean1,Mean2)}
}

\value{
  \item{CutX }{x value, where gaussian 1=gaussian2}
  \item{CutY }{y value, where gaussian 1=gaussian2}
}

\author{Michael Thrun, Rabea Griese}

\seealso{\code{\link{BayesDecisionBoundaries}}}
