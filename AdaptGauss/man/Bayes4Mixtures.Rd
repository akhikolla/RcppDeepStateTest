\name{Bayes4Mixtures}
\alias{Bayes4Mixtures}

\title{Posterioris of Bayes Theorem}
\description{
  Calculates the posterioris of Bayes theorem
}
\usage{
Bayes4Mixtures(Data, Means, SDs, Weights, IsLogDistribution,
 PlotIt, CorrectBorders,Color,xlab,lwd)
}
\arguments{
  \item{Data}{vector (1:N) of data points}
  \item{Means}{vector[1:L] of Means of Gaussians (of GMM),L ==  Number of Gaussians}
  \item{SDs}{vector of standard deviations, estimated Gaussian Kernels, has to be the same length as Means}
  \item{Weights}{vector of relative number of points in Gaussians (prior probabilities), has to be the same length as Means}
  \item{IsLogDistribution}{Optional, ==1 if distribution(i) is a LogNormal, default  vector of zeros of length L}
  \item{PlotIt}{Optional, Default: FALSE; TRUE do a Plot }
  \item{CorrectBorders}{Optional, ==TRUE data at right borders of GMM distribution will be  assigned to last gaussian, left border vice versa.
                     (default ==FALSE) normal Bayes Theorem}
	\item{Color}{Optional, character vector of colors, default rainbow()}
	\item{xlab}{Optional, label of x-axis, default 'Data', see intern R documentation}
	\item{lwd}{Width of Line, see intern R documentation}
}

\value{
List with
  \item{Posteriors}{(1:N,1:L) of Posteriors corresponding to Data}
  \item{NormalizationFactor}{(1:N) denominator of Bayes theorem corresponding to Data}
}
\details{
See conference presentation for further explanation.
}
\references{
Thrun M.C.,Ultsch, A.: Models of Income Distributions for Knowledge Discovery, European Conference on Data Analysis, DOI 10.13140/RG.2.1.4463.0244, Colchester 2015.
}
\author{Catharina Lippmann, Onno Hansen-Goos, Michael Thrun}
\seealso{\code{\link{BayesDecisionBoundaries}},\code{\link{AdaptGauss}}}
\keyword{Bayes}
\keyword{Boundaries}
\keyword{posterioris}
\keyword{posterior}