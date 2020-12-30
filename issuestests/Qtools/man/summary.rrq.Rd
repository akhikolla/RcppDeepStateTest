\name{summary.rrq}
\alias{summary.rrq}

\title{
Summary for Restricted Quantile Regression Models
}
\description{
This functions gives a summary list for a restricted quantile regression model.
}

\usage{
\method{summary}{rrq}(object, alpha = 0.05, se = "boot", R = 50,
	sim = "ordinary", stype = "i", ...)
}

\arguments{
  \item{object}{
an object of \code{\link{class}} \code{rrq}.
}
  \item{alpha}{
numeric value to determine the confidence level \code{(1-alpha)} of the required interval.
}
  \item{se}{
specifies the method used to compute standard errors. Currently, bootstrap is the only method available.
}
  \item{R}{
number of boostrap replications.
}
  \item{sim}{
see argument \code{sim} in \code{\link{boot}}.
}
  \item{stype}{
see argument \code{stype} in \code{\link{boot}}.
}
  \item{\dots}{
additional arguments for \code{\link{boot}} in package \code{boot}.
}
}

\details{
A bootstrap approach is used for inference. Future developments of this function will include asymptotic standard errors.
}

\references{
Canty A and Ripley B (2014). boot: Bootstrap R (S-Plus) Functions. R package version 1.3-15.

Davison AC and Hinkley DV (1997). Bootstrap Methods and Their Applications. Cambridge University Press, Cambridge.

He X (1997). Quantile Curves without Crossing. The American Statistician, 51(2), 186-192.
}


\author{
Marco Geraci
}

\keyword{ bootstrap }
\keyword{ summary }
