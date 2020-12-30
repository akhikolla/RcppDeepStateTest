\name{midquantile}
\alias{midecdf}
\alias{midquantile}

\title{
Mid-distribution Functions
}

\description{
Compute mid-cumulative probabilities and mid-quantiles
}

\usage{
midecdf(x, na.rm = FALSE)
midquantile(x, probs = 1:3/4, na.rm = FALSE)
}

\arguments{
  \item{x}{
numeric vector of observations used to estimate the mid-cumulative distribution or the mid-quantiles.
}
  \item{probs}{
numeric vector of probabilities with values in [0,1].
}
  \item{na.rm}{
logical value indicating whether NA values should be stripped before the computation proceeds.
}

}

\value{
An object of class \code{\link{class}} \code{midecdf} or \code{midquantile} with mid-cumulative probabilities and mid-quantiles. For \code{midecdf}, this is a list that contains:

\item{x}{unique values of the vector \code{x} at which mid-cumulative probabilities are calculated.}
\item{y}{estimated mid-cumulative probabilities.}
\item{fn}{interpolating function of the points \code{(x,y)}.}
\item{data}{input values.}

For \code{midquantile}, this is a list that contains:

\item{x}{probabilities \code{probs} at which mid-quantiles are calculated.}
\item{y}{estimated mid-cumulative probabilities.}
\item{fn}{interpolating function of the points \code{(x,y)}.}
\item{data}{input values.}


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
midquantile(x)

}

\seealso{
\code{\link{confint.midquantile}}, \code{\link{plot.midquantile}}
}


\keyword{ unconditional quantiles }
