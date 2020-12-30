\name{gsa_label}
\alias{gsa_label}
\docType{data}
\title{
  Sample labels in gene set analysis
}
\description{
  P53 NCI-60 data set provided by Subramanian \emph{et al}., (2005). A list with phenotypes vector and a vector of sample label values.
}
\usage{data(gsa_label)}
\format{
  A list on the following 2 variables.
  \describe{
    \item{\code{pheotype}}{a character vector contains two genotypes.}
    \item{\code{value}}{a numeric vector contains sample label 0 and 1, where 0 and 1 stands for ``MUT'' and ``WT'', respectively.}
  }
}
\source{
  http://www.broadinstitute.org/gsea
}
\references{
  Subramanian, A., Tamayo, P., Mootha, V. K., \emph{et al}. Gene set enrichment analysis: a knowledge-based approach for interpreting genome-wide expression profiles. \emph{Proceedings of the National Academy of Sciences of the United States of America}, 2005, 102(43): 15545-15550.
}
\examples{
data(gsa_label)
}
