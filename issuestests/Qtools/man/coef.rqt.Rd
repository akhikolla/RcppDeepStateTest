\name{coef.rqt}
\alias{coefficients.rqt}
\alias{coef.rqt}

\title{
Extract Coefficients
}

\description{
\code{coef} extracts model coefficients from \code{rqt} objects.
}

\usage{
\method{coef}{rqt}(object, all = FALSE, ...)
\method{coefficients}{rqt}(object, all = FALSE, ...)
}

\arguments{
  \item{object}{
an \code{rqt} object.
}
  \item{all}{
logical flag. If \code{FALSE} (default), only the regression coefficients are returned. If \code{TRUE}, the transformation parameter(s) too is returned.
}
  \item{\dots}{
not used.
}
}

\value{
a vector for single quantiles or a matrix for multiple quantiles. 
}

\author{
Marco Geraci
}

\seealso{
\code{\link{tsrq}}
}

\keyword{coefficients}
