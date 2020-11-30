\name{dqcControl}
\alias{dqcControl}

\title{
Control parameters for dqc estimation
}
\description{
A list of parameters for controlling the fitting process.
}

\usage{
dqcControl(tau.range = c(0.001, 0.999), nt = 10, ndir = 50, seed = NULL)
}

\arguments{
	\item{tau.range}{
		vector with range of quantile probabilities. See details. 
	}

	\item{nt}{
		length of grid of quantiles within \code{tau.range}.
	}

	\item{ndir}{
		number of directions.
	}

	\item{seed}{
		seed for \code{\link{set.seed}}.
	}

}

\details{
A directional quantile classifier (Viroli et al, 2020) is computed over a grid of quantile probabilities. The vector \code{tau.range} must be of length 2, providing a minimum and a maximum for the grid, or of length 1, in which case the grid will have only one probability equal to tau.range. In the latter case \code{nt} is ignored and set equal to 1.
}


\value{
a list of control parameters.
}

\references{
Viroli C, Farcomeni A, Geraci M (2020). Directional quantile-based classifiers (in preparation).
}

\author{
Marco Geraci}

\seealso{
\code{\link{dqc}}
}
\keyword{fitting}
\keyword{control}
