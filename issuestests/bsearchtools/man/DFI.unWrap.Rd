\name{DFI.unWrap}
\alias{DFI.unWrap}
\title{
Unwrap a DFI object returning the original wrapped object 
}
\description{
Extract the original wrapped object (data.frame or matrix) inside a DFI object 
}
\usage{
DFI.unWrap(DFIobj)
}
\arguments{
  \item{DFIobj}{ a DFI object}
}
\value{
A data.frame or matrix according to the class of the original object
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

### get the inner data.frame
DFI.unWrap(DFIobj)

}

