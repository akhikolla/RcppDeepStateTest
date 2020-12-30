\name{summary.mlteqc}
\alias{summary.mlteqc}
\title{
	Summarizing Estimated Equating Coefficients
}
\description{
	\code{summary} method for class \code{mlteqc}.
}
\usage{
\method{summary}{mlteqc}(object, ...)
}
\arguments{
	\item{object}{
		an object of the class \code{mlteqc} returned by function 
		\code{\link{multiec}}.
	}
	\item{\dots}{
		further arguments passed to or from other methods.
	}
}
\author{
	Michela Battauz
}
\seealso{
	\code{\link{multiec}}
}
\examples{
data(est2pl)
# prepare the data
mods <- modIRT(coef = est2pl$coef, var = est2pl$var, display = FALSE)
# Estimation of the equating coefficients with the multiple mean-mean method
eqMM <- multiec(mods = mods, base = 1, method = "mean-mean")
summary(eqMM)
}
