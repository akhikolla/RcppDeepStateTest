\name{QQplotGMM}
\alias{QQplotGMM}

\title{Quantile Quantile Plot of Data}
\description{
  Quantile Quantile plot of data against gaussian distribution mixture model with optional best-fit-line
}
\usage{
QQplotGMM(Data,Means,SDs,Weights,IsLogDistribution,Line,
PlotSymbol,xug,xog,LineWidth,PointWidth, ylab,main, ...)
}

\arguments{
  \item{Data}{vector (1:N) of data points}
  \item{Means}{vector[1:L] of Means of Gaussians (of GMM),L ==  Number of Gaussians}
  \item{SDs}{vector of standard deviations, estimated Gaussian Kernels, has to be the same length as Means}
  \item{Weights}{vector of relative number of points in Gaussians (prior probabilities), has to be the same length as Means}
  \item{IsLogDistribution}{Optional, ==1 if distribution(i) is a LogNormal, default Zeros of Length L}
  \item{Line}{ Optional, Default: TRUE=Regression Line is drawn}
  \item{xug}{ Optional, lower limit of the interval [xug, xog], in which a line will be interpolated }
  \item{xog}{ Optional, upper limit of the interval [xug, xog], in which a line will be interpolated }
  \item{PlotSymbol}{ Optional, plot symbol. Default is 20. }
  \item{LineWidth}{ Optional, width of regression line, if Line==TRUE }
  \item{PointWidth}{Optional, width of points}
	\item{ylab}{Optional, see \code{\link{plot}}}
	\item{main}{Optional, see \code{\link{plot}}}
	\item{...}{Note: xlab cannot be changed, other parameters see \code{\link{qqplot}}}
}
\value{   
List with
\item{x}{The x coordinates of the points that were plotted}

\item{y}{The original data vector, i.e., the corresponding y coordinates}
}
\details{
Only verified for a Gaussian Mixture Model, usage of IsLogDistribution for LogNormal Modes is experimental!
}
\references{Michael, J. R. (1983). The stabilized probability plot. Biometrika, 70(1), 11-17.}
\author{Michael Thrun}

\examples{
data=c(rnorm(1000),rnorm(2000)+2,rnorm(1000)*2-1)
QQplotGMM(data,c(-1,0,2),c(2,1,1),c(0.25,0.25,0.5))

}
\seealso{\code{\link{qqplot}}}

\keyword{ plot }
\keyword{ qqplot }
\keyword{ qq-plot }
\keyword{ quantile/quantile-plot }
\keyword{ best-fit-line }