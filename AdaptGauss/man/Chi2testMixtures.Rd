\name{Chi2testMixtures}
\alias{Chi2testMixtures}

\title{Pearson's chi-squared goodness of fit test}
\description{
	Chi2testMixtures is goodness of fit test which establishes whether an observed distribution (data) differs from a Gauss Mixture Model (GMM).
  Returns a P value of a special case of a chi-square test and visualizes data versus a given GMM.
}

\arguments{
  \item{Data}{vector of data points (1:n)}
  \item{Means}{vector of Means of Gaussians (1:c)}
  \item{SDs}{vector of standard deviations, estimated Gaussian Kernels (1:c)}
  \item{Weights}{vector of relative number of points in Gaussians (prior probabilities) (1:c)}
  \item{IsLogDistribution}{Optional, if IsLogDistribution(i)==1, then mixture is lognormal, default vector of zeros of length 1:L}
  \item{PlotIt}{Optional, Default: FALSE, do a Plot of the compared cdfs and the KS-test distribution (Diff)}
  \item{UpperLimit}{Optional. test only for Data <= UpperLimit, Default = max(Data) i.e all Data.}
	\item{VarName}{If PlotIt=TRUE, the name of the inspected variable, default 'Data'}
	\item{MonteCarloSampling}{If MonteCarloSampling = T montecarlo-sampling will be done for generation of a test statistic.}
}
\details{
	The null hypothesis is that the estimated data distribution does not differ significantly from the GMM.
  Let O_i be the observed features and E_i be the expected number E,
  than the test statistic is defined with the minimum chi-square estimate T=sum((O_i-E_i)^2/E_i)*1/m, where m the number of data points.
	The expected number Ei may be derived for each bin.  If there is a significant difference between the O_i
	and the E_i, the Pvalue is small and the null hypothesis can be rejected.
	
	Further details, see [Thrun & Ultsch, 2015].
}
\note{The statistic assumption is that the the test statistic follows a chi square distribution.
   The number of degrees of freedom is equal to the number of datapoints n-1-3*c
	}
\value{
List with
  \item{Pvalue }{Pvalue of a suiting chi-square , Pvalue ==0 if Pvalue <0.001}
  \item{BinCenters }{bin centers}
  \item{ObsNrInBin }{No. of data in bin}
	\item{ExpectedNrInBin }{No. of data that should be in bin according to GMM}
	\item{Chi2Value }{the  TestStatistic T i.e.: sum((ObsNrInBin(Ind)-ExpectedNrInBin(Ind))^2/ExpectedNrInBin(Ind)) with
                                 Ind = find(ExpectedNrInBin>=10)
																 The value of \code{Chi2Value} is compared to a chi-squared distribution.
																 }
}
\references{Hartung, J., Elpelt, B., and Kloesener, K.H.: Statistik, 8. Aufl. Verlag Oldenburg (1991).

Thrun, M. C., Ultsch, A.: Models of Income Distributions for Knowledge Discovery, European Conference on Data Analysis, DOI 10.13140/RG.2.1.4463.0244, pp. 28-29, Colchester 2015.

 
}
\author{Rabea Griese, Michael Thrun}

\keyword{Pearson's chi-squared test}
\keyword{chi-squared test}
\keyword{chi-square goodness-of-fit}
\keyword{chi-square test for independence}
\keyword{Minimum chi-square estimation}
\keyword{chi-square estimation}
\keyword{chi-square}