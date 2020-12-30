\name{midq2q}
\alias{midq2q}

\title{
Recover Ordinary Conditional Quantiles from Conditional Mid-Quantiles}

\description{
This function recovers ordinary conditional quantile functions based on fitted mid-quantile regression models.
}

\usage{
midq2q(object, newdata, ...)
}

\arguments{
  \item{object}{
	an object of \code{\link{class}} \code{midrq}.
	}

  \item{newdata}{
	a required data frame in which to look for variables with which to predict.
	}
 \item{\dots}{
not used.
}
}


\value{
a vector or a matrix of values.
}


\references{
Geraci, M. and A. Farcomeni. Mid-quantile regression for discrete responses. arXiv:1907.01945 [stat.ME]. URL: \url{https://arxiv.org/abs/1907.01945/}.
}

\author{
Marco Geraci
}


\examples{

\dontrun{
# Esterase data
data(esterase)

# Fit quantiles 0.1, 0.15, ..., 0.85
fit <- midrq(Count ~ Esterase, tau = 2:17/20, data = esterase, type = 3, lambda = 0)

# Recover ordinary quantile function
xx <- seq(min(esterase$Esterase), max(esterase$Esterase), length = 5)
print(Qhat <- midq2q(fit, newdata = data.frame(Esterase = xx)))

# Plot
plot(Qhat, sub = TRUE)

}

}

\seealso{
\code{\link{plot.midq2q}}, \code{\link{predict.midrq}}
}

\keyword{predict}

