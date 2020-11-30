\name{rowfilters.DFI}
\alias{EQ}
\alias{RG}
\alias{IN}
\alias{EQNA}
\alias{NOT}
\alias{AND}
\alias{OR}
\alias{print.DFI.FEXPR}
\alias{toString.DFI.FEXPR}
\alias{as.character.DFI.FEXPR}
\title{
Functions for row filters creation in \code{DFI.subset}.
}
\description{
Functions for row filters creation in \code{DFI.subset}.

For information about NAs handling see details section.
}
\usage{
RG(col,from,to)
IN(col,values)
EQ(col,val)
EQNA(col)
NOT(filter)
OR(\dots)
AND(\dots)
\method{print}{DFI.FEXPR}(x,\dots)
\method{toString}{DFI.FEXPR}(x,\dots)
\method{as.character}{DFI.FEXPR}(x,\dots)
}
\details{
Any filter function applied to an indexed column will filter out the NAs present in that column by default (except for \code{EQNA}). So, for example, 
the following filter: \code{EQ("A",3)} is actually equal to : \code{!is.na(A) & A == 3}. The functions \code{print(filterExpr)}, \code{toString(filterExpr)} and \code{as.character(filterExpr)} return the string representation of the filter that you would use in a normal data.frame subset.

\code{RG} function accepts \code{NA} in \code{from,to} arguments, and this "turns off" the part of the filter set to \code{NA}. So, for instance \code{RG("A",NA,to)} will return all values \code{A <= to} (but still filtering out the \code{NA} values).

\code{EQ} function accepts \code{NA} in \code{val} argument, and this simply "turns off" the filter on the column returning all the elements in the column (but still filtering out the \code{NA} values).

\code{IN(colName,values)} function is converted to \code{OR(EQ(colName,values[1]),EQ(colName,value[2]),...)} hence, if \code{values} contains \code{NA}, the filter will return all the elements in the column (but still filtering out the \code{NA} values).

\code{EQNA(colName)} function can be used to select the NAs in the column, which are excluded by the other operators.

}
\arguments{
  \item{col}{column name to be used in the filter condition (must be an indexed column).}
  \item{from}{inclusive lower-bound of the range (RG) filter condition.}
  \item{to}{inclusive upper-bound of the range (RG) filter condition.}
  \item{values}{valid values for the filter condition (used by IN).}
  \item{val}{valid value for the filter condition (used by EQ).}
  \item{filter}{filter condition to be negated (created with RG,IN,EQ,NOT,OR,AND).}
  \item{\dots}{one or more filters conditions to be put in AND or OR (created with RG,IN,EQ,NOT,OR,AND). For \code{print}, \code{toString} and \code{as.character} functions the optional arguments are currently ignored.}
  \item{x}{an object of class DFI.FEXPR}
}
\value{
\code{EQ},\code{RG},\code{IN},\code{EQNA},\code{NOT},\code{AND},\code{OR} functions return an object inheriting from class 'DFI.FEXPR' to be used as row filter in \code{\link[bsearchtools]{DFI.subset}} function.
\code{print},\code{toString},\code{as.character} functions return the string representation of an object of class 'DFI.FEXPR'.
}
\seealso{
\code{\link[bsearchtools]{DFI.subset}}
}
\examples{

# create the following filter: 18 <= Age <= 55 & Married == TRUE
filter <- AND(RG('Age',18,55),EQ('Married',TRUE))

# create the following filter: Age == 25 | Married == TRUE | Name == 'John'
filter <- OR(EQ('Age',25),EQ('Married',TRUE),EQ('Name','John'))

}

