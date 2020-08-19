\name{PlotMixturesAndBoundaries}
\alias{PlotMixturesAndBoundaries}

\title{Shows GMM with Boundaries}
\description{
  Plots Gaussian Mixture Model with Bayes decision boundaries, such that:
	
	Black is the PDE of Data
	
	Red is color of the GMM
	
	Magenta are the Bayes boundaries
}
\usage{
PlotMixturesAndBoundaries(Data, Means, SDs, Weights, 

IsLogDistribution = rep(FALSE, length(Means)), SingleColor = "blue",

MixtureColor = "red", DataColor = "black",

BoundaryColor = "magenta", xlab, ylab, 
				   
 SingleGausses =TRUE, \dots)
}

\arguments{
      \item{Data}{vector (1:N) of data points}
  \item{Means}{vector[1:L] of Means of Gaussians (of GMM),L ==  Number of Gaussians}
  \item{SDs}{vector of standard deviations, estimated Gaussian Kernels, has to be the same length as Means}
  \item{Weights}{vector of relative number of points in Gaussians (prior probabilities), has to be the same length as Means}
  \item{IsLogDistribution}{Optional, ==1 if distribution(i) is a LogNormal, default vector of zeros of length 1:L}
  
  \item{SingleColor}{Optional, Color for line plot of all the single gaussians, default magenta}
  \item{MixtureColor}{Optional, Color of line plot for the mixture, default red}
	\item{DataColor}{Optional, Color of line plot for the data, default black}
  \item{BoundaryColor}{Optional, Color of bayesian boundaries}
    \item{xlab}{Optional, x label, see \code{\link{plot}}}
	  \item{ylab}{Optional, y label, ee \code{\link{plot}}}
	  \item{SingleGausses}{Optional,  SingleGausses=T than components of the mixture in blue will be shown.}
		\item{...}{Optional, see \code{\link{plot}} for plot properties and for \code{SingleGausses} \code{\link{PlotMixtures}}}
}

\author{Michael Thrun}

\seealso{\code{\link{BayesDecisionBoundaries}},\code{\link{PlotMixtures}}}

\keyword{Bayes}
\keyword{Boundaries}
