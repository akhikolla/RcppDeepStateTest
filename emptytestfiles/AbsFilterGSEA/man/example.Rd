\name{example}
\alias{example}
\docType{data}
\title{Normalized RNA-seq count data}
\description{This is toy example of RNA-seq raw read count table. It containes 5000 genes  and 6 samples (three for case and other three for control group).}
\usage{data("example")}
\format{
  A data frame with 5000 observations on the following 6 variables.
  \describe{
    \item{\code{groupA1}}{a numeric vector for RNA-seq counts for case samples 1.}
	\item{\code{groupA2}}{a numeric vector for RNA-seq counts for case samples 2.}
	\item{\code{groupA3}}{a numeric vector for RNA-seq counts for case samples 3.}
	\item{\code{groupB1}}{a numeric vector for RNA-seq counts for control samples 1.}
	\item{\code{groupB2}}{a numeric vector for RNA-seq counts for control samples 2.}
	\item{\code{groupB3}}{a numeric vector for RNA-seq counts for control samples 3.}
  }
}
\details{
This read count dataset was simulated based on the negative binomial distribution. Mean and dispersion parameters were assessed from TCGA KIRC RNA-seq dataset. Normalization was done by using edgeR package.Geneset_41~45 are up-regulated and Geneset_46~50 are down-regulated gene sets.
}
\source{
Cancer Genome Atlas Research, N. Comprehensive molecular characterization of clear cell renal cell carcinoma. Nature 2013;499(7456):43-49.
}
\references{
Chen, Y., et al. edgeR: differential expression analysis of digital gene expression data User's Guide. 2015.
}
\examples{
data(example)
}
\keyword{datasets}
