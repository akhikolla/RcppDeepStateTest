\name{itm.mlteqc}
\alias{itm.mlteqc}
\title{
	Extract Item Parameters
}
\description{
	\code{itm} is a generic function which extracts a data frame containing the
	item parameters of multiple forms being equated in the original scale and 
	the item parameters converted to the scale of the base form.
}
\usage{
\method{itm}{mlteqc}(x, \dots)
}
\arguments{
	\item{x}{object of the class \code{mlteqc} returned by function 
	  \code{\link{multiec}}} 
	\item{\dots}{further arguments passed to or from other methods.}
}
\value{
	A data frame containing item names (\code{Item}), 
	item parameters of all the forms (e.g. \code{T1}, \dots, \code{T3}), 
	and item parameters of all the forms converted 
	in the scale of the base form (e.g. \code{T3.as.T1}).	
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

# extract item parameters
itm(eqIRF)
}
