% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/missing_data.R
\name{genObs}
\alias{genObs}
\title{Create an observed data set that includes missing data}
\usage{
genObs(dtName, dtMiss, idvars)
}
\arguments{
\item{dtName}{Name of complete data set}

\item{dtMiss}{Name of missing data matrix}

\item{idvars}{Index variables that cannot be missing}
}
\value{
A data table that represents observed data, including
missing data
}
\description{
Create an observed data set that includes missing data
}
\examples{
def1 <- defData(varname = "m", dist = "binary", formula = .5)
def1 <- defData(def1, "u", dist = "binary", formula = .5)
def1 <- defData(def1, "x1", dist = "normal", formula = "20*m + 20*u", variance = 2)
def1 <- defData(def1, "x2", dist = "normal", formula = "20*m + 20*u", variance = 2)
def1 <- defData(def1, "x3", dist = "normal", formula = "20*m + 20*u", variance = 2)

dtAct <- genData(1000, def1)

defM <- defMiss(varname = "x1", formula = .15, logit.link = FALSE)
defM <- defMiss(defM, varname = "x2", formula = ".05 + m * 0.25", logit.link = FALSE)
defM <- defMiss(defM, varname = "x3", formula = ".05 + u * 0.25", logit.link = FALSE)
defM <- defMiss(defM, varname = "u", formula = 1, logit.link = FALSE) # not observed
defM

# Generate missing data matrix

missMat <- genMiss(dtAct, defM, idvars = "id")
missMat

# Generate observed data from actual data and missing data matrix

dtObs <- genObs(dtAct, missMat, idvars = "id")
dtObs
}
\seealso{
\code{\link{defMiss}}, \code{\link{genMiss}}
}
\concept{missing}
