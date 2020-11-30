\name{DFI.subset}
\alias{DFI.subset}
\title{
Subset a DFI object
}
\description{
Function to subset a DFI object efficiently (using binary search) by creating complex filters on indexed columns.
For details about column indexes, refer to \code{\link[bsearchtools]{DFI}}, for information about \code{NA} handling, refer to \code{\link[bsearchtools]{rowfilters.DFI}}.

}
\usage{
DFI.subset(DFIobj, filter=NULL, return.indexes=FALSE, 
           sort.indexes=TRUE, colFilter=NULL, drop=NULL)
}
\arguments{
  \item{DFIobj}{a DFI object.}
  \item{filter}{a filter object created by functions \code{EQ,RG,IN,AND,OR,NOT}.}
  \item{return.indexes}{if TRUE, the row indexes satisfying the filter are returned instead of the DFI subset.}
  \item{sort.indexes}{if FALSE the order of the rows or row.index returned will not be necessarily equal to the original order in the DFI object. If TRUE, subsetting will keep the original row/row.indexes order.
                      FALSE usually gives a better performance.}
  \item{colFilter}{if \code{return.indexes==TRUE} is ignored; otherwise, if not NULL, it will be passed as second argument of data.frame/matrix subset operator i.e. \code{[,colFilter]}  }
  \item{drop}{if different from \code{NULL} is passed as \code{drop} argument of data.frame and matrix subset (ignored if \code{return.indexes=TRUE}).}
}
\value{
A subset of the data.frame or matrix wrapped by the DFI object, unless \code{return.indexes==TRUE} in which case an integer vector with the row indexes will be returned.
}
\seealso{
\code{\link[bsearchtools]{DFI}},
\code{\link[bsearchtools]{EQ}},
\code{\link[bsearchtools]{IN}},
\code{\link[bsearchtools]{RG}},
\code{\link[bsearchtools]{NOT}},
\code{\link[bsearchtools]{AND}},
\code{\link[bsearchtools]{OR}}
}
\examples{

### create a simple DFIobj
DF <- data.frame(Foo=c(3,5,7,1,5,8,7,10),
                 Bar=c("A","B","B","C","B","B","C","A"),
                 Baz=c(TRUE,FALSE),
                 stringsAsFactors=FALSE)
DFIobj <- DFI(DF, c("Foo","Bar")) # create a DFI from DF with indexes on "Foo" and "Bar" columns

DFI.subset(DFIobj, filter=OR(EQ('Foo',5),EQ('Bar','B')))

}
