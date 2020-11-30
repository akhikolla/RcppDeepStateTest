\name{ao}
\alias{bc}
\alias{mcjI}
\alias{mcjII}
\alias{invao}
\alias{invbc}
\alias{invmcjI}
\alias{invmcjII}
\alias{ao}

\title{
Transformations
}

\description{
Functions used in quantile regression transformation models
}

\usage{
ao(theta, lambda, symm = TRUE, omega = 0.001)
invao(x, lambda, symm = TRUE, replace = TRUE)
bc(x, lambda)
invbc(x, lambda, replace = TRUE)
mcjI(x, lambda, symm = TRUE, dbounded = FALSE, omega = 0.001)
invmcjI(x, lambda, symm = TRUE, dbounded = FALSE)
mcjII(x, lambda, delta, dbounded = FALSE, omega = 0.001)
invmcjII(x, lambda, delta, dbounded = FALSE)
}

\arguments{
  \item{x, theta}{
numeric vector of singly (\code{x}) or doubly (\code{theta}) bounded observations; \code{theta} must be between 0 and 1 (see \code{\link{map}} to map generic [a,b] intervals to [0,1]).
}
  \item{lambda, delta}{
transformation parameters.
}
  \item{symm}{
logical flag. If \code{TRUE} (default) a symmetric transformation is used.
}
  \item{dbounded}{
logical flag. If \code{TRUE} the argument \code{x} is assumed to be bounded between 0 and 1.
}
  \item{omega}{
small constant to avoid numerical problems when \code{theta} is exactly 0 or 1.
}
  \item{replace}{
logical flag. If \code{TRUE} (default), values that are outside the admissible range after the Box-Cox or the Aranda-Ordaz back-transformations are replaced by the range bounds.
}

}

\details{
These functions transform (back-transform) \code{x} or \code{theta} conditional on the parameters \code{lambda} and \code{theta}, using the Box--Cox (\code{bc}), Aranda-Ordaz (\code{ao}), Proposal I (\code{mcjI}) and Proposal II (\code{mcjII}) transformations. 
}

\value{
Transformed or back-transformed values.
}

\references{
Aranda-Ordaz FJ. On two families of transformations to additivity for binary response data. Biometrika 1981;68(2):357-363.

Box GEP, Cox DR. An analysis of transformations. Journal of the Royal Statistical Society Series B-Statistical Methodology 1964;26(2):211-252.

Dehbi H-M, Cortina-Borja M, and Geraci M. Aranda-Ordaz quantile regression for student performance assessment. Journal of Applied Statistics. 2016;43(1):58-71.

Geraci M and Jones MC. Improved transformation-based quantile regression. Canadian Journal of Statistics 2015;43(1):118-132.

Jones MC. Connecting distributions with power tails on the real line, the half line and the interval. International Statistical Review 2007;75(1):58-69.
}

\author{
Marco Geraci
}

\seealso{
\code{\link{tsrq}}, \code{\link{tsrq2}}, \code{\link{rcrq}}, \code{\link{nlrq2}}
}

\keyword{ transformations }