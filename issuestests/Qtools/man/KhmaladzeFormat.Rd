\name{KhmaladzeFormat}
\alias{KhmaladzeFormat}

\title{
Khmaladze Test
}
\description{
This function provides significance levels of the Khmaladze Test using a (hard-coded) table of asymptotic critical values.
}
\usage{
KhmaladzeFormat(object, epsilon)
}

\arguments{
  \item{object}{
an object of \code{\link{class}} "KhmaladzeTest".
}
  \item{epsilon}{
trimming value. One of \code{c(0.05,0.10,0.15,0.20,0.25,0.30)}.
}
}

\details{
This function is applied to an object produced by \code{\link{KhmaladzeTest}}. The Khmaladze test is used to test for location--shift and location-scale--shift hypotheses (Koenker, 2005). The test statistic is computed over the interval \emph{[epsilon, 1 - epsilon]}, where \emph{epsilon} is the trimming value.
}


\references{
Appendix B in Koenker R. Quantile regression. New York, NY: Cambridge University Press; 2005.

Koenker R. and Xiao Z. Inference on the quantile regression process. Avalilable at \url{http://www.econ.uiuc.edu/~roger/research/inference/khmal6ap.pdf}.
}

\author{
Marco Geraci
}

\examples{

data(barro, package = "quantreg")
eps <- 0.05
kt <- quantreg::KhmaladzeTest( y.net ~ lgdp2 + fse2 + gedy2 + Iy2 + gcony2, 
		data = barro, taus = seq(.05,.95,by = .01), trim = c(eps, 1 - eps))
class(kt)
KhmaladzeFormat(kt, epsilon = eps)

}