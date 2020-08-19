\name{AdaptGauss-package}
\alias{AdaptGauss-package}
\alias{MultiModal-package}
\alias{MultiModal}
\docType{package}
\title{
\packageTitle{AdaptGauss}
}
\description{
\packageDescription{AdaptGauss}
}
\details{
Multimodal distributions can be modelled as a mixture of components. The model is derived using the Pareto Density Estimation (PDE) for an estimation of the pdf [Ultsch 2005]. PDE has been designed in particular to identify groups/classes in a dataset. The expectation maximization algorithm estimates a Gaussian mixture model of density states [Bishop 2006] and the limits between the different states are defined by Bayes decision boundaries [Duda 2001]. The model can be verified with Chi-squared test, Kolmogorov-Smirnov test and QQ plot.

The correct number of modes may be found with AIC or BIC.

\packageIndices{DataVisualizations}
}

\author{
Michael Thrun, Onno Hansen-Goos, Rabea Griese, Catharina Lippmann, Florian Lerch, Jorn Lotsch, Alfred Ultsch
Maintainer: \packageMaintainer{AdaptGauss}
}
\examples{
## Statistically  significant GMM
\donttest{
data=c(rnorm(3000,2,1),rnorm(3000,7,3),rnorm(3000,-2,0.5))

gmm=AdaptGauss::AdaptGauss(data,

Means = c(-2, 2, 7),

SDs = c(0.5, 1, 4),

Weights = c(0.3333, 0.3333, 0.3333))

AdaptGauss::Chi2testMixtures(data,

gmm$Means,gmm$SDs,gmm$Weights,PlotIt=T)

AdaptGauss::QQplotGMM(data,gmm$Means,gmm$SDs,gmm$Weights)
}

## Statistically non significant GMM
\donttest{
data('LKWFahrzeitSeehafen2010')

gmm=AdaptGauss::AdaptGauss(LKWFahrzeitSeehafen2010,

Means = c(52.74, 385.38, 619.46, 162.08),

SDs = c(38.22, 93.21, 57.72, 48.36),

Weights = c(0.2434, 0.5589, 0.1484, 0.0749))

AdaptGauss::Chi2testMixtures(LKWFahrzeitSeehafen2010,

gmm$Means,gmm$SDs,gmm$Weights,PlotIt=T)

AdaptGauss::QQplotGMM(LKWFahrzeitSeehafen2010,gmm$Means,gmm$SDs,gmm$Weights)
}

}
\references{
Ultsch, A., Thrun, M.C., Hansen-Goos, O., Loetsch, J.: Identification of Molecular Fingerprints in Human Heat Pain Thresholds by Use of an Interactive Mixture Model R Toolbox(AdaptGauss), International Journal of Molecular Sciences, doi:10.3390/ijms161025897, 2015.

Duda, R.O., P.E. Hart, and D.G. Stork, Pattern classification. 2nd. Edition. New York, 2001, p 512 ff

Bishop, Christopher M. Pattern recognition and machine learning. springer, 2006, p 435 ff

Ultsch, A.: Pareto density estimation: A density estimation for knowledge discovery, in  Baier, D.; Werrnecke, K. D., (Eds), Innovations in classification, data science, and information systems, Proc Gfkl 2003, pp 91-100, Springer, Berlin, 2005. 

Thrun M.C., Ultsch, A.: Models of Income Distributions for Knowledge Discovery, European Conference on Data Analysis, DOI 10.13140/RG.2.1.4463.0244, Colchester 2015.
}

\keyword{Multimodal}
\keyword{AdaptGauss}
\keyword{EM}
\keyword{expectation maximization}
\keyword{pareto density estimation}
\keyword{pdf}
\keyword{mixture of components}
\keyword{GMM}
\keyword{gaussian mixture model}
\keyword{mixture}