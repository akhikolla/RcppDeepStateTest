\name{sparsity.rqt}
\alias{sparsity}
\alias{sparsity.rq}
\alias{sparsity.rqs}
\alias{sparsity.rqt}

\title{
Sparsity Estimation
}

\description{
This function estimates the density and sparsity functions of the residuals from a \code{rq} or a \code{rqt} object.
}

\usage{
sparsity(object, se = "nid", hs = TRUE)
\method{sparsity}{rq}(object, se = "nid", hs = TRUE)
\method{sparsity}{rqs}(object, se = "nid", hs = TRUE)
\method{sparsity}{rqt}(object, se = "nid", hs = TRUE)
}

\arguments{
  \item{object}{
a \code{rq}, \code{rqs} or \code{rqt} object.
}
  \item{se}{
"iid" if errors are assumed independent and identically distributed; "nid" (default) if independent but not identically distributed; "ker" which uses a kernel estimate of the sandwich as proposed by Powell (1991).
}
  \item{hs}{
logical flag. If \code{TRUE} (default) the Hall-Sheather rule is used. Otherwise, the Bofinger's rule is used.
}

}

\details{
This function is based on the code from \code{quantreg::summary.rq} and \code{quantreg::bandwidth.rq} to estimate the sparsity function for linear quantile regression models (Koenker and Bassett, 1978) and transformation models of Geraci and Jones (2014).
}

\value{
\code{sparsity} returns an object of \code{\link{class}} \code{list} that contains three elements:

\item{density}{estimate of the density of the residuals.}
\item{sparsity}{estimate of the sparsity of the residuals.}
\item{bandwidth}{bandwidth used for estimation.}

}

\references{

Geraci M and Jones MC. Improved transformation-based quantile regression. Canadian Journal of Statistics 2015;43(1):118-132.

Koenker R. quantreg: Quantile Regression. 2016. R package version 5.29.

Koenker R, Bassett G. Regression quantiles. Econometrica. 1978;46(1):33-50.

Powell JL. Estimation of monotonic regression models under quantile restrictions. In: Barnett W, Powell J, Tauchen G, editors. Nonparametric and Semiparametric Methods in Econometrics and Statistics: Proceedings of the Fifth International Symposium on Economic Theory and Econometrics. New York, NY: Cambridge University Press 1991. p. 357-84.
}

\author{
Marco Geraci
}

\examples{

\dontrun{

data(trees)

# 'rqt' object

fit.rqt <- tsrq(Volume ~ Height, tsf = "bc", symm = FALSE, data = trees,
	lambda = seq(-10, 10, by = 0.01), tau = 0.5)
sparsity(fit.rqt)

# 'rq' object

fit.rq <- rq(Volume ~ Height, data = trees)
sparsity(fit.rq, se = "iid")
sparsity(fit.rq, se = "nid")
sparsity(fit.rq, se = "ker")
}

}

\seealso{
\code{\link{rq}}
}

