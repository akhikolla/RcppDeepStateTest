\name{DFI.coercion}
\alias{as.data.frame.DFI}
\alias{as.matrix.DFI}
\title{
Coerce a DFI object
}
\description{
Coerce a DFI object to data.frame or matrix
}
\usage{
\method{as.data.frame}{DFI}(x, \dots)
\method{as.matrix}{DFI}(x, \dots)
}
\arguments{
  \item{x}{a DFI object}
  \item{\dots}{optional arguments passed to inner \code{as.data.frame} and \code{as.matrix} methods.}
}
\value{
A data.frame or matrix object
}
\seealso{
\code{\link[bsearchtools]{DFI}}
}
\examples{
### create a simple DFIobj
DF <- data.frame(Foo=c(3,5,7,1,5,8,7,10),
                 Bar=c("A","B","B","C","B","B","C","A"),
                 Baz=c(TRUE,FALSE),
                 stringsAsFactors=FALSE)
DFIobj <- DFI(DF, c("Foo","Bar")) # create a DFI from DF with indexes on "Foo" and "Bar" columns

### coercion
as.data.frame(DFIobj)
as.matrix(DFIobj)

}

