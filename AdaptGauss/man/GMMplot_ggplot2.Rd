\name{GMMplot_ggplot2}
\alias{GMMplot_ggplot2}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
Plots the Gaussian Mixture Model (GMM) withing ggplot2
}
\description{
PlotMixtures and PlotMixturesAndBoundaries for ggplot2 
}
\usage{
GMMplot_ggplot2(Data, Means, SDs, Weights,

BayesBoundaries, SingleGausses = TRUE, Hist = FALSE)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
     \item{Data}{vector (1:N) of data points}
  \item{Means}{vector[1:L] of Means of Gaussians (of GMM),L ==  Number of Gaussians}
  \item{SDs}{vector of standard deviations, estimated Gaussian Kernels, has to be the same length as Means}
  \item{Weights}{vector of relative number of points in Gaussians (prior probabilities), has to be the same length as Means}
    \item{BayesBoundaries}{Optional, x values for baye boundaries, if missing 'BayesDecisionBoundaries' is called}
	  \item{SingleGausses}{Optional,  SingleGausses=T than components of the mixture in blue will be shown.}
	  \item{Hist}{Optional, geom_histogram overlayed}
}

\value{
ggplot2 object
}

\author{
Joern Loetsch, Michael Thrun (ctb)
}
\note{
MT standardized code for CRAN and added dec boundaries and doku
}
\seealso{
\code{\link{PlotMixturesAndBoundaries}}, \code{\link{PlotMixtures}}, \code{\link{BayesDecisionBoundaries}}
}
\examples{
data=c(rnorm(1000),rnorm(2000)+2,rnorm(1000)*2-1)
\donttest{
GMMplot_ggplot2(data,c(-1,0,2),c(2,1,1),c(0.25,0.25,0.5),SingleGausses=TRUE)
}
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{GMM}% use one of  RShowDoc("KEYWORDS")
\keyword{ggplot2}% __ONLY ONE__ keyword per line
