\name{PlotMixtures}
\alias{PlotMixtures}

\title{Shows GMM}
\description{
  Plots Gaussian Mixture Model without Bayes decision boundaries, such that:
	
	Black is the PDE of Data
	
	Red is color of the GMM
	
	Blue is the color of components of the mixture
}


\arguments{
      \item{Data}{vector (1:N) of data points}
  \item{Means}{vector[1:L] of Means of Gaussians (of GMM),L ==  Number of Gaussians}
  \item{SDs}{vector of standard deviations, estimated Gaussian Kernels, has to be the same length as Means}
  \item{Weights}{vector of relative number of points in Gaussians (prior probabilities), has to be the same length as Means}
  \item{IsLogDistribution}{Optional, ==1 if distribution(i) is a LogNormal, default vector of zeros of length 1:L}
  \item{SingleColor}{Optional,Color for line plot of all the single gaussians, default magenta}
  \item{MixtureColor}{Optional,Color of line lot for the mixture default red}
	\item{DataColor}{Optional,Color of line plot for the data, default black}
  \item{SingleGausses}{Optional, If TRUE, single gaussians are shown, default FALSE}
    \item{axes}{Optional,Default:TRUE with axis, see argument \code{axis} of \code{\link{plot}}}
    \item{xlab}{Optional, see \code{\link{plot}}}
	 \item{ylab}{Optional, see \code{\link{plot}}}
	\item{xlim}{Optional, see \code{\link{plot}}}
    \item{ylim}{Optional, see \code{\link{plot}}}
    \item{ParetoRad}{Optional: Precalculated Pareto Radius to use}

  \item{...}{other plot arguments like xlim = c(1,10)}
  
}
\details{
Example shows that overlapping variances of gaussians will result in inappropriate decision boundaries.
}
\author{Michael Thrun}
\examples{
data=c(rnorm(1000),rnorm(2000)+2,rnorm(1000)*2-1)
\donttest{
PlotMixtures(data,c(-1,0,2),c(2,1,1),c(0.25,0.25,0.5),SingleColor='blue',SingleGausses=TRUE)
}
}
\seealso{\code{\link{PlotMixturesAndBoundaries}}}


\keyword{GMM}
\keyword{gaussian mixture model}