\name{eqc.mlteqc}
\alias{eqc.mlteqc}
\title{
	Extract Equating Coefficients of Multiple Forms
}
\description{
	\code{eqc} is a generic function which extracts the equating coefficients.
}
\usage{
\method{eqc}{mlteqc}(x, \dots)
}
\arguments{
	\item{x}{object of the class \code{mlteqc} returned by function \code{\link{multiec}}}
	\item{\dots}{further arguments passed to or from other methods.}
}
\value{
	A data frame containing the equating coefficients.
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
# Estimation of the equating coefficients with the multiple item response function method
eqIRF <- multiec(mods = mods, base = 1, method = "irf")

# extract equating coefficients
eqc(eqIRF)
}


