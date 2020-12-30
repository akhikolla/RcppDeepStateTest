\name{plot.qlss}
\alias{plot.qlss}

\title{
Quantile-based Summary Statistics for Location, Scale and Shape
}

\description{
This function plots location, scale and shape of a conditional distribution.
}

\usage{
\method{plot}{qlss}(x, z, whichp = NULL, interval = FALSE, type = "l", ...)
}

\arguments{
  \item{x}{
an object of class \code{qlss} as returned by \code{\link{qlss.formula}}.
}
  \item{z}{
numeric vector of values against which LSS measures are plotted. This argument is required.
}
  \item{whichp}{
when \code{probs} in \code{qlss} is a vector, the argument \code{whichp} specifies one of the probabilities (and one only) in \code{probs} that should be used for plotting. If \code{whichp = NULL} (default), the first value in \code{probs} is used.
}
 \item{interval}{
logical flag. If \code{TRUE}, confidence intervals for the predictions are plotted.
}
  \item{type}{
1-character string giving the type of plot desired. See \code{\link{plot.default}}.
}
\item{\dots}{
other arguments for \code{\link{plot.default}}.
}

}

\details{

This function plots a \code{qlss} object from \code{\link{qlss}} or \code{\link{predict.qlss}}.


}

\author{
Marco Geraci
}

\examples{

trees2 <- trees[order(trees$Height),]
fit <- qlss(Volume ~ Height, data = trees2, probs = c(.05, .1))
# Plot the results for probs = 0.1
plot(fit, z = trees2$Height, whichp = 0.1, xlab = "height")

}

\seealso{
\code{\link{qlss}}
}

\keyword{ plot }