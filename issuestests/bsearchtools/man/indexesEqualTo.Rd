\name{indexesEqualTo}
\alias{indexesEqualTo}
\alias{indexesEqualToNumeric}
\alias{indexesEqualToInteger}
\alias{indexesEqualToLogical}
\alias{indexesEqualToCharacter}
\title{Find indexes of a value using binary search}
\description{
Given a sorted vector, it returns the indexes of the vector elements equal to valueToSearch.

The functions suffixed with the vector type (indexInRangeNumeric,indexInRangeLogical etc.) can be used ONLY with the specified type, otherwise the vector is coerced, and they are (hopefully negligibly) faster then the generic indexesEqualTo function.

}
\usage{
indexesEqualTo(sortedValues,valueToSearch,indexesRemap=NULL)
indexesEqualToNumeric(sortedValues,valueToSearch,indexesRemap=NULL)
indexesEqualToInteger(sortedValues,valueToSearch,indexesRemap=NULL)
indexesEqualToLogical(sortedValues,valueToSearch,indexesRemap=NULL)
indexesEqualToCharacter(sortedValues,valueToSearch,indexesRemap=NULL)
}
\arguments{
  \item{sortedValues}{A sorted atomic vector of type numeric, integer, logical or character }
  \item{valueToSearch}{The value to search in the vector}
  \item{indexesRemap}{An integer vector to be used to remap the indexes returned by lookup on sortedValues, or NULL (the default). Mostly used internally by DFI. }
}
\value{
The indexes of the vector elements equal to valueToSearch.
}
\examples{
indexesEqualTo(c(1,4,5,5,7,9),5) # returns c(3,4)
indexesEqualTo(c(1,4,5,5,7,9),10) # returns empty vector
}

