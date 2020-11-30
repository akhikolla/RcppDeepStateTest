\name{summary.rqt}
\alias{summary.rqt}

\title{
Summary for Quantile Regression Tranformation Models
}
\description{
This functions gives a summary list for a quantile regression transformation model.
}

\usage{
\method{summary}{rqt}(object, alpha = 0.05, se = "boot", R = 50,
	sim = "ordinary", stype = "i", conditional = FALSE, ...)
}

\arguments{
  \item{object}{
an object of \code{\link{class}} \code{rqt}.
}
  \item{alpha}{
numeric value to determine the confidence level \code{(1-alpha)} of the required interval.
}
  \item{se}{
specifies the method used to compute standard errors. For conditional inference (\code{conditional = TRUE}), see argument \code{se} in \code{\link{summary.rq}}. For unconditional inference (\code{conditional = FALSE}), see details below.
}
  \item{R}{
number of bootstrap replications.
}
  \item{sim}{
see argument \code{sim} in \code{\link{boot}}.
}
  \item{stype}{
see argument \code{stype} in \code{\link{boot}}.
}
  \item{conditional}{
logical flag. If \code{TRUE}, the transformation parameter is assumed to be known and conditional inference is carried out.
}
  \item{\dots}{
if \code{conditional = TRUE}, additional arguments for \code{\link{summary.rq}} in package \code{quantreg}. If \code{conditional = FALSE}, additional arguments for \code{\link{boot}} in package \code{boot}.
}
}

\details{
If inference is carried out conditionally on the transformation parameter (ie, assuming this is \emph{known} rather than estimated), any type of summary for regression quantiles can be used (see \code{\link{summary.rq}}).

For unconditional inference (\code{conditional = FALSE}), there are three methods available: \code{boot} for bootstrap; \code{iid} for large-\emph{n} approximation of the standard errors under IID assumptions; \code{nid} for large-\emph{n} approximation of the standard errors under NID assumptions. See Powell (1991), Chamberlain (1994) and Geraci and Jones (2015).
}

\references{
Canty A and Ripley B (2014). boot: Bootstrap R (S-Plus) Functions. R package version 1.3-11.

Chamberlain G. Quantile regression, censoring, and the structure of wages. In: Sims C, editor. Advances in Econometrics: Sixth World Congress. 1. Cambridge, UK: Cambridge University Press; 1994.

Davison AC and Hinkley DV (1997). Bootstrap Methods and Their Applications. Cambridge University Press, Cambridge.

Geraci M and Jones MC. Improved transformation-based quantile regression. Canadian Journal of Statistics 2015;43(1):118-132.

Mu YM, He XM. Power transformation toward a linear regression quantile. Journal of the American Statistical Association 2007;102(477):269-279.

Powell JL. Estimation of monotonic regression models under quantile restrictions. In: Barnett W, Powell J, Tauchen G, editors. Nonparametric and Semiparametric Methods in Econometrics and Statistics: Proceedings of the Fifth International Symposium on Economic Theory and Econometrics. New York, NY: Cambridge University Press 1991. p. 357-84.
}


\author{
Marco Geraci
}

\seealso{

\code{\link{tsrq}}, \code{\link{rcrq}}, \code{\link{tsrq2}} or \code{\link{nlrq2}}
}

\keyword{ bootstrap }
\keyword{ summary }
