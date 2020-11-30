\name{confint.midquantile}
\alias{confint.midquantile}

\title{
Mid-distribution Functions
}

\description{
Compute mid-quantiles confidence intervals 
}

\usage{
\method{confint}{midquantile}(object, parm = NULL, level = 0.95, ...)
}

\arguments{
  \item{object}{
an object of class \code{midquantile}.
}
  \item{parm}{
not used (included for consistency with \code{\link{confint.default}}).
}
  \item{level}{
nominal coverage level of the confidence interval.
}

  \item{...}{
not used.
}

}


\references{
Ma Y., Genton M., and Parzen E. Asymptotic properties of sample quantiles of discrete distributions. Annals of the Institute of Statistical Mathematics 2011;63(2):227-243

Parzen E. Quantile probability and statistical data modeling. Statistical Science 2004;19(4):652-62.
}

\author{
Marco Geraci
}

\examples{

x <- rpois(100, lambda = 3)
mq <- midquantile(x)
confint(mq, level = 0.95)

# print standard errors
attributes(confint(mq, level = 0.95))$stderr

}


\keyword{ unconditional quantiles }
