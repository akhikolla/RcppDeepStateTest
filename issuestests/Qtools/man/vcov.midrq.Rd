\name{vcov.midrq}
\alias{vcov.midrq}

\title{
Variance-Covariance Matrix for a Fitted Mid-Quantile Regression Model Object
}
\description{
This functions returns the variance-covariance matrix of the main parameters of a fitted \code{midrq} model object. The `main' parameters of the model correspond to those returned by \code{\link{coef}}.
}

\usage{
\method{vcov}{midrq}(object, numerical = FALSE, robust = FALSE, ...)
}

\arguments{
  \item{object}{
an object of \code{\link{class}} \code{midrq}.
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
Marco Geraci with contributions from Alessio Farcomeni
}

\seealso{
\code{\link{midrq}}
}

\keyword{ summary }
