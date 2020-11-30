\name{DFI.getIndex}
\alias{DFI.getIndex}
\title{
Extract the index information of a DFI object
}
\description{
Return the index data (i.e. ordered indexes, and sorted values) of an indexed column of a DFI object 
}
\usage{
DFI.getIndex(DFIobj,name)
}
\arguments{
  \item{DFIobj}{ a DFI object}
  \item{name}{ the name of the indexed column in the DFI object }
}
\value{
A list with two values:
\item{idxs}{ the indexes used to sort the column values (as returned by \code{order(colValues,na.last=NA)} }
\item{sorted}{ the sorted values of the column (as returned by \code{colValues[idxs]}) }
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

### get the index data of 'Bar' column
DFI.getIndex(DFIobj,"Bar")

}

