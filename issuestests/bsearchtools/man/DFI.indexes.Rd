\name{DFI.indexes}
\alias{DFI.indexes}
\title{
Get the indexes names of a DFI object
}
\description{
Method to get the indexes names of a DFI object
}
\usage{
DFI.indexes(DFIobj)
}
\arguments{
  \item{DFIobj}{ A DFI object}
}
\value{
A character vector containing the name of the indexed columns of the DFI object
}
\examples{
### create a simple DFIobj
DF <- data.frame(Foo=c(3,5,7,1,5,8,7,10),
                 Bar=c("A","B","B","C","B","B","C","A"),
                 Baz=c(TRUE,FALSE),
                 stringsAsFactors=FALSE)
DFIobj <- DFI(DF, c("Foo","Bar")) # create a DFI from DF with indexes on "Foo" and "Bar" columns

### get the indexes names (returns c("Foo","Bar"))
DFI.indexes(DFIobj)
}
