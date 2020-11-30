\name{BNSL-package}
\alias{BNSL-package}
\alias{BNSL}
\docType{package}
\title{
  Bayesian Network Structure Learning
}
\description{
  From a given dataframe,this package learn a Bayesian network structure based on a seletcted score.
}
\details{
  Currently,this package estimates of mutual information and conditional mutual information,
and combines them to construct either a Bayesian network or a undirected forest, 
any undirected forest can be a Bayesian network by adding appropriate directions. 
}
\author{
Joe Suzuki and Jun Kawahara

Maintainer: Joe Suzuki <j-suzuki@sigmath.es.osaka-u.ac.jp>
}
\references{
[1]   Suzuki, J., ``A theoretical analysis of the BDeu scores in Bayesian network structure learning", Behaviormetrika, 2017.
[2]   Suzuki, J., ``A novel Chow-Liu algorithm and its application to gene differential analysis", International Journal of Approximate Reasoning, 2017.
[3]   Suzuki, J., ``Efficient Bayesian network structure learning for maximizing the posterior probability", Next-Generation Computing, 2017.
[4]   Suzuki, J., ``An estimator of mutual information and its application to independence testing", Entropy, Vol.18, No.4, 2016. 
[5]   Suzuki, J., ``Consistency of learning Bayesian network structures with continuous variables: An information theoretic approach". Entropy, Vol.17, No.8, 5752-5770, 2015.
[6]   Suzuki. J.,  ``Learning Bayesian network structures when discrete and continuous variables are present. In Lecture Note on Artificial Intelligence, the sixth European workshop on Probabilistic Graphical Models, Vol. 8754, pp. 471-486,Utrecht, Netherlands, Sept. 2014. Springer-Verlag.
[7]   Suzuki. J.,  ``The Bayesian Chow-Liu algorithms", In the sixth European workshop on Probabilistic Graphical Models, pp. 315-322, Granada, Spain, Sept.2012.
[8] Suzuki, J.  and Kawahara, J., ``Branch and Bound for Regular Bayesian Network Structure learning", Uncertainty in Artificial Intelligence, pages 212-221,  Sydney, Australia, August 2017.
[9] Suzuki, J. ``Forest Learning from Data and its Universal Coding", IEEE Transactions on Information Theory, Dec. 2018.
January 2017.
}
\keyword{ package }
