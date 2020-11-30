\name{Chemistry}
\alias{Chemistry}

\title{A-level Chemistry Scores}
\description{
  The \code{Chemistry} data frame has 31022 rows and 7 columns of the
  A-level scores in Chemistry for England and Wales students, 1997.
}
\format{
  This data frame contains the following columns:
  \describe{
    \item{lea}{
      school district ID.
    }
    \item{school}{
      school ID.
    }
    \item{id}{
      subject ID.
    }
    \item{score}{
      a numeric vector of A-level scores in Chemistry.
    }
    \item{sex}{
      a factor with levels
      \code{male} and
      \code{female} 
    }
    \item{age}{
      a numeric vector of ages of the subjects (months).
    }
    \item{gcse}{
      a numeric vector of average GCSE scores.
    }
  }
}

\source{
  Fielding, A., Yang, M., and Goldstein, H. (2003) ``Multilevel ordinal models
    for examination grades''. Statistical Modelling, 3, 127--53.
}

\keyword{datasets}
