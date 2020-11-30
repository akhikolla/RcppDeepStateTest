\name{qlss}
\alias{qlss.default}
\alias{qlss.formula}
\alias{qlss.numeric}
\alias{qlss}

\title{
Quantile-based Summary Statistics for Location, Scale and Shape
}

\description{
This function calculates quantile-based summary statistics for location, scale and shape of a distribution, unconditional or conditional.
}

\usage{
qlss(...)
\method{qlss}{default}(fun = "qnorm", probs = 0.1, ...)
\method{qlss}{numeric}(x, probs = 0.1, ...)
\method{qlss}{formula}(formula, probs = 0.1, data = sys.frame(sys.parent()), subset, weights,
	na.action, contrasts = NULL, method = "fn", type = "rq", tsf = "mcjI",
	symm = TRUE, dbounded = FALSE, lambda = NULL, conditional = FALSE, ...)
}

\arguments{
  \item{fun}{
quantile function.
}
\item{x}{
a numeric vector.
}
  \item{formula}{
an object of class \code{\link{formula}}: a symbolic description of the model to be fitted. The details of model specification are given under "Details".
}
  \item{probs}{
a vector of probabilities.
}
  \item{data}{
an optional data frame, list or environment (or object coercible by as.data.frame to a data frame) containing the variables in the model. By default the variables are taken from the environment from which the call is made.
}
  \item{subset}{
an optional vector specifying a subset of observations to be used in the fitting process.
}
  \item{weights}{
an optional vector of weights to be used in the fitting process. Should be NULL or a numeric vector. 
}
  \item{na.action}{
a function which indicates what should happen when the data contain \code{NA}s.
}
  \item{contrasts}{
an optional list. See the \code{contrasts.arg} of \code{\link{model.matrix.default}}.
}

  \item{method}{
the algorithm used to solve the linear program. See \code{\link{rq}} for further details. The Frisch-Newton interior point method is the default.
}

  \item{type}{
possible options are \code{rq} for linear quantile regression (default) or \code{rqt} for transformation-based quantile regression.
}
  \item{tsf}{
transformation to be used. Possible options are \code{mcjI} for Proposal I transformation models (default), \code{bc} for Box-Cox and \code{ao} for Aranda-Ordaz transformation models. See \code{\link{tsrq}} for further details.
}
  \item{symm}{
logical flag. If \code{TRUE} (default) a symmetric transformation is used.
}
  \item{dbounded}{
logical flag. If \code{TRUE} the response is assumed to be doubly bounded on [a,b]. If \code{FALSE} the response is assumed to be singly bounded (ie, strictly positive).
}

  \item{lambda}{
values of transformation parameters for grid search.
}
  \item{conditional}{
logical flag. If \code{TRUE}, the transformation parameter is assumed to be known and this must be provided via the arguments \code{lambda} using a vector of length \code{3 + 2 x length(probs)} (see details).
}

  \item{\dots}{
other arguments for \code{fun}, \code{rq} or \code{tsrq}.
}
}

\details{
This function computes a number of quantile-based summary statistics for location (median), scale (inter-quartile range and inter-quantile range), and shape (Bowley skewness and shape index) of a distribution. These statistics can be computed for unconditional and conditional distributions.

Let \eqn{Y} be a continuous random variable and let \eqn{Q(p)} be its \emph{p}th quantile. The function \code{qlss} computes the median \eqn{Q(0.5)}, the inter-quartile range \eqn{IQR = Q(0.75) - Q(0.25)}, the inter-quantile range \eqn{IPR(p) = Q(1-p) - Q(p)}, the Bowley skewness index \eqn{A(p) = (Q(1-p) + Q(p) - 2Q(0.5))/IPR(p)}, and the shape index \eqn{T(p) = IPR(p)/IQR(p)}, for \eqn{0 < p < 0.25}.

The default \code{qlss} function computes the summary statistics of a standard normal distribution or any other theoretical distribution via the argument \code{fun}. The latter must be a function with \code{p} as its probability argument (see for example \code{\link{qnorm}}, \code{\link{qt}}, \code{\link{qchisq}}, \code{\link{qgamma}}, etc.). When a variable \code{x} is provided, LSS measures are computed using empirical (sample) quantiles.

The argument \code{formula} specifies a quantile function for \eqn{Y} conditional on predictors \eqn{X}. Linear models are fitted via standard quantile regression with \code{type = "rq"}. Nonlinear models are fitted via transformation-based quantile regression with \code{type = "rqt"} (proposal II transformation models are not available.). When \code{conditional = TRUE}, \code{lambda} is a vector of transformation parameters of length \code{3 + 2 x np}, where \code{np = length(probs)} (3 quartiles, \code{np} quantiles at level \eqn{p}, \code{np} quantiles at level \eqn{1 - p}).

}

\value{
\code{qlss} returns an object of \code{\link{class}} \code{qlss}. This is a list that contains at least three elements:

\item{location}{summary statistic(s) for location.}
\item{scale}{summary statistic(s) for scale.}
\item{shape}{summary statistic(s) for shape.}

}

\references{
Geraci M and Jones MC. Improved transformation-based quantile regression. Canadian Journal of Statistics 2015;43(1):118-132.

Gilchrist W. Statistical modelling with quantile functions. Chapman and Hall/CRC; 2000.
}

\author{
Marco Geraci
}

\examples{

# Compute summary statistics of a normal distribution
qlss()

# Compute summary statistics of a t distribution with 3 df
qlss(fun = "qt", df = 3, probs = 0.05)

# Compute summary statistics for a sample using a sequence of probabilities
x <- rnorm(1000)
qlss(x, probs = c(0.1, 0.2, 0.3, 0.4))

# Compute summary statistics for Volume conditional on Height
trees2 <- trees[order(trees$Height),]
fit <- qlss(Volume ~ Height, data = trees2)
plot(fit, z = trees2$Height, xlab = "height")

# Use a quadratic model for Height
fit <- qlss(Volume ~ poly(Height,2), data = trees2)
plot(fit, z = trees2$Height, xlab = "height")


}

\seealso{
\code{\link{predict.qlss}}, \code{\link{plot.qlss}}
}

\keyword{conditional quantiles}
\keyword{unconditional quantiles}
\keyword{location-scale-shape}
