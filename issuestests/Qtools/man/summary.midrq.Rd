\name{summary.midrq}
\alias{summary.midrq}

\title{
Summary for Mid-Quantile Regression Models
}
\description{
This functions gives a summary list for a mid-quantile regression model.
}

\usage{
\method{summary}{midrq}(object, alpha = 0.05, numerical = FALSE, robust = FALSE, ...)
}

\arguments{
  \item{object}{
an object of \code{\link{class}} \code{midrq}.
}
  \item{alpha}{
numeric value to determine the confidence level \code{(1-alpha)} of the required interval.
}
  \item{numerical}{
logical flag. If \code{TRUE}, the variance-covariance estimate is approximated by the inverse of the numerical Hessian.
}
  \item{robust}{
logical flag. If \code{TRUE}, the Huber-White covariance estimate is computed using the Huberized residuals.
}

  \item{...}{
not used.
}

}


\references{
Geraci, M. and A. Farcomeni. Mid-quantile regression for discrete responses. arXiv:1907.01945 [stat.ME]. URL: \url{https://arxiv.org/abs/1907.01945/}.
}


\author{
Marco Geraci
}

\seealso{
\code{\link{midrq}}
}

\keyword{ summary }
