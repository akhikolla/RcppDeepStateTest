\name{dqc}
\alias{dqc.fit}
\alias{dqc}

\title{
Directional Quantile Classification}
\description{
This function is used to classify multivariate observations by means of directional quantiles.
}
\usage{
dqc(formula, data, df.test, subset, weights, na.action, control = list(),
	fit = TRUE)
dqc.fit(x, z, y, control)
}

\arguments{
  \item{formula}{
an object of class \code{\link{formula}}: a two-sided formula of the form \code{y ~ x1 + ... + xn} where \code{y} represents the groups (i.e., labels) for the observations and \code{x1}, ..., \code{xn} are the variables used for classification.
}
  \item{data}{
an optional data frame, list or environment (or object coercible by as.data.frame to a data frame) containing the variables for classification (training). If not found in data, the variables are taken from environment(formula), typically the environment from which \code{dqc} is called.
}
  \item{df.test}{
a required data frame, list or environment (or object coercible by as.data.frame to a data frame) containing the variables for prediction.
}
  \item{subset}{
an optional vector specifying a subset of observations to be used in the fitting process.
}
  \item{weights}{
an optional vector of weights to be used in the fitting process.
}
  \item{na.action}{
a function which indicates what should happen when the data contain \code{NA}s.
}
  \item{control}{
list of control parameters of the fitting process. See \code{\link{dqcControl}}.
}
  \item{fit}{
logical flag. If \code{FALSE} the function returns a list of arguments for fitting.
}

  \item{x}{
design matrix of dimension \eqn{nx * p} for training.
}
  \item{z}{
design matrix of dimension \eqn{nz * p} for prediction.
}
  \item{y}{
vector of labels of length \eqn{nx}.
}

}

\details{Directional quantile classification is described in the article by Viroli et al (2020).} 

\value{
a list of class \code{dqc} containing the following components

\item{call}{the matched call.}
\item{ans}{a data frame with predictions.}
\item{nx}{number of observations in the training dataset.}
\item{nz}{number of observations in the prediction dataset.}
\item{p}{number of variables.}
\item{control}{control parameters used for fitting.}
}


\references{
Viroli C, Farcomeni A, Geraci M (2020). Directional quantile-based classifiers (in preparation).
}

\author{
Marco Geraci with contributions from Cinzia Viroli
}



\examples{

\dontrun{
# Iris data
data(iris)

# Create training and prediction datasets

n <- nrow(iris)
ng <- length(unique(iris$Species))
df1 <- iris[c(1:40, 51:90, 101:140),]
df2 <- iris[c(41:50, 91:100, 141:150),]

# Classify
ctrl <- dqcControl(nt = 10, ndir = 5000, seed = 123)
fit <- dqc(Species ~ Sepal.Length + Petal.Length,
	data = df1, df.test = df2, control = ctrl)

# Data frame with predictions
fit$ans

# Confusion matrix
print(cm <- xtabs( ~ fit$ans$groups + df2$Species))

# Misclassification rate
1-sum(diag(cm))/nrow(df2)
}

}

\seealso{
\code{\link{dqcControl}} 
}

\keyword{directional quantiles}
\keyword{classification}
