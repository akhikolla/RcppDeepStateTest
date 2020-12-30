\name{GOFTest}
\alias{GOFTest}

\title{
Goodness-of-Fit Tests for Quantile Regression Models
}
\description{
This function calculates a goodness-of-fit test for quantile regression models.
}
\usage{
GOFTest(object, type = "cusum", alpha = 0.05, B = 100, seed = NULL)
}

\arguments{
  \item{object}{
an object of \code{\link{class}} "rq","rqs", "rqt", "rrq", or "rq.counts".
}
  \item{type}{
the type of the test. See details.
}
  \item{alpha}{
the significance level for the test. This argument is relevant for \code{type = "cusum"} only.
}
  \item{B}{
the number of Monte Carlo samples. This argument is relevant for \code{type = "cusum"} only.
}
  \item{seed}{
see for random numbers. This argument is relevant for \code{type = "cusum"} only.
}

}

\details{
This function provides goodness-of-fit tests for quantile regression. Currently, there is only one method available (\code{type = "cusum"}), for a test based on the cusum process of the gradient vector (He and Zhu, 2013). The critical value at level \code{alpha} is obtained by resampling. Other methods will be implemented in future versions of the package.
}

\value{
\code{GOFTest} returns an object of \code{\link{class}} \code{GOFtest}.
}

\references{
He XM, Zhu LX. A lack-of-fit test for quantile regression. Journal of the American Statistical Association (2003);98:1013-1022. 
}

\author{
Marco Geraci
}

\examples{

\dontrun{
data(barro, package = "quantreg")
fit <- quantreg::rq(y.net ~ lgdp2 + fse2 + gedy2 + Iy2 + gcony2, data = barro, tau = c(.1,.5,.9))
GOFTest(fit)
}

}