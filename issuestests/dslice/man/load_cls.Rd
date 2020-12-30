\name{load_cls}
\alias{load_cls}
\title{
  Load phenotype file
}
\description{
  Load phenotype file from .cls file
}
\usage{
  load_cls(file)
}
\arguments{
  \item{file}{Name of .cls file which contains phenotypes of samples, separared by spaces.}
}
\value{
  A list with components:
  \item{pheotype}{Pheotype of samples}
  \item{value}{A vector with encoded value of pheotypes. If there is \emph{k} pheotypes, it takes values \eqn{0, 1, \ldots, k-1}.}
}
\examples{
# Pheotype files are available after registration at Broad institute GSEA website
# http://www.broadinstitute.org/gsea

\dontrun{
filename <- "P53.cls"
label <- load_cls(filename)
}
}
