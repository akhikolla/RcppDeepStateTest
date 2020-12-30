\name{indexesInRange}
\alias{indexesInRange}
\alias{indexesInRangeNumeric}
\alias{indexesInRangeInteger}
\alias{indexesInRangeLogical}
\alias{indexesInRangeCharacter}
\title{Find indexes in a range using binary search}
\description{
Given a sorted vector, it returns the indexes of the vector elements included in range [lbInclusive,ubInclusive].

The functions suffixed with the vector type (indexInRangeNumeric,indexInRangeLogical etc.) can be used ONLY with the specified type, otherwise the vector is coerced, and they are (hopefully negligibly) faster then the generic indexInRange function.

}
\usage{
indexesInRange(sortedValues,lbInclusive, ubInclusive,indexesRemap=NULL)
indexesInRangeNumeric(sortedValues,lbInclusive, ubInclusive,indexesRemap=NULL)
indexesInRangeInteger(sortedValues,lbInclusive, ubInclusive,indexesRemap=NULL)
indexesInRangeLogical(sortedValues,lbInclusive, ubInclusive,indexesRemap=NULL)
indexesInRangeCharacter(sortedValues,lbInclusive, ubInclusive,indexesRemap=NULL)
}
\arguments{
  \item{sortedValues}{A sorted atomic vector of type numeric, integer, logical or character }
  \item{lbInclusive}{The inclusive lower bound of the range}
  \item{ubInclusive}{The inclusive upper bound of the range}
  \item{indexesRemap}{An integer vector to be used to remap the indexes returned by lookup on sortedValues, or NULL (the default). Mostly used internally by DFI. }
}
\value{
The indexes of the vector elements included in range [lbInclusive,ubInclusive].
}
\examples{
indexesInRange(c(1,4,5,5,7,9),5,7) # returns c(3,4,5)
indexesInRange(c(1,4,5,5,7,9),10,11) # returns empty vector
}

