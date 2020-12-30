\name{NHMMdata}
\alias{NHMMdata}
\title{Simulated Datasets}


\description{
The \code{NHMMdata} is a list containing data sets for Gamma (Exponential), Poisson, Normal, and multivariate Normal emission distributions. 
}
\format{A list containing all of the matrices and vectors.}

\details{ Global settings: T=2000 time steps.  J=15 time series. K=3 hidden states. pT=200 predictive chain length.
 \describe{
    \item{tX}{ B=1 by T matrix of inputs. A single input of increasing linear drift from 1/2000 to 1.}
    
    \item{Xp1}{ A=1 by pT. Increasing linear trend from 1/200 to 1. To be used with models already using tX.}
    
    \item{tW}{ A=1 by T by J array. A single input of decreasing linear drift from 1 to 1/2000. Was not used to build any of the emission distrbutions but works with ygamma, ynormal, ypoisson, ymvn but should result as "not significant."}
    
    \item{tW2}{ A=2 by T by J array. 2 harmonic sin/cos terms of period 100 (20 periods per time series). Was used to build the ymvn and should come up significant. It can also be used with the other emissions but should be "not significant."
    
    }
      \item{Wp1}{ B=1 by pT by J. Decreasing linear trend from 1 to 1/200. To be used with models already using tW.}
    \item{zt1}{ a sequence of hidden states that uses tX as an input (NHMM), has no Markov property. Was used to create ygamma and ypoisson. tX should be significant for these data sets but not for ynormal and ymvn. }
    \item{zt2}{ a sequence of hidden states that has no input X variable (HMM) but has a Markov property. Was used to create ynormal and ymvn. tX should not be significant but the Markov terms should be. }
    \item{ygamma}{ T by J. zt1 and tX. no tW or tW2}
    \item{ypoisson}{ T by J. zt1 and tX. no tW or tW2}
    \item{ynormal}{ T by J. zt2. no tW or tW2 or tX.}
    \item{ymvn}{ T by J. zt2 and tW2 as the mean. no tW or tX.}
 }
}



\keyword{datasets}