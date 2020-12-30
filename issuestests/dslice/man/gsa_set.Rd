\name{gsa_set}
\alias{gsa_set}
\docType{data}
\title{
  Gene set list in gene set analysis
}
\description{
  Gene set provided by Subramanian \emph{et al}., (2005). A list with gene set vector, gene set description vector and a list whose elements are vector of genes in each gene set.
}
\usage{data(gsa_set)}
\format{
  A list with three elements: gene set name, gene set description and genes in gene set.
  \describe{
    \item{\code{set_name}}{a character vector of gene set name.}
    \item{\code{set_description}}{a character vector of gene set description.}
    \item{\code{set_description}}{a list whose elements are vector. Each of them contains genes in each gene set.}
  }
}
\source{
  http://www.broadinstitute.org/gsea
}
\references{
  Subramanian, A., Tamayo, P., Mootha, V. K., \emph{et al}. Gene set enrichment analysis: a knowledge-based approach for interpreting genome-wide expression profiles. \emph{Proceedings of the National Academy of Sciences of the United States of America}, 2005, 102(43): 15545-15550.
}
\examples{
data(gsa_set)
}
