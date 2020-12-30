#' @title  Randomized Singular Value Decomposition.
#
#' @description Compute the near-optimal low-rank singular value decomposition (SVD) of
#' a rectangular matrix. The algorithm follows a randomized approach.
#
#' @details
#' Randomized SVD (randSVD) is a fast algorithm to compute the approximate low-rank SVD of
#' a rectangular \eqn{(m,n)} matrix \eqn{A} using a probabilistic algorithm.
#' Given the decided rank \eqn{k << n}, \code{rSVD} factors the input matrix \eqn{A} as
#' \eqn{A = U * diag(S) * V'}, which is the typical SVD form. Precisely, the columns of
#' U are orthonormal, as are the columns of V, the entries of S are all nonnegative,
#' and the only nonzero entries of S appear in non-increasing order on its diagonal. The
#' dimensions are:  U is \eqn{(m,k)}, V is \eqn{(n,k)}, and S is \eqn{(k,k)}, when A
#' is \eqn{(m,n)}.
#'
#' Increasing \eqn{its} or \eqn{l} improves the accuracy of the approximation USV' to A.
#'
#' The parameter \eqn{its} specifies the number of normalized power iterations
#' (subspace iterations) to reduce the approximation error. This is recommended
#' if the the singular values decay slowly. In practice 1 or 2 iterations
#' achieve good results, however, computing power iterations increases the
#' computational time. The number of power iterations is set to \eqn{its=2} by default.
#'
#'
#' @param A       array_like \cr
#'                a real/complex input matrix (or data frame), with dimensions
#'                \eqn{(m, n)}. It is the real/complex matrix being approximated.
#'
#' @param k       int, optional \cr
#'                determines the target rank of the low-rank decomposition and should
#'                satisfy \eqn{k << min(m,n)}. Set by default to 6.
#'
#' @param its     int, optional \cr
#'                number of full iterations of a block Lanczos method to conduct;
#'                \eqn{its} must be a nonnegative integer, and defaults to 2.
#'
#' @param l       int, optional \cr
#'                block size of the block Lanczos iterations; \eqn{l} must be a
#'                positive integer greater than \eqn{k}, and defaults \eqn{l=k+2}.
#'
#' @param sdist   str \eqn{c('normal', 'unif')}, optional \cr
#'                Specifies the sampling distribution. \cr
#'                \eqn{'unif'} : (default) Uniform `[-1,1]`. \cr
#'                \eqn{'normal}' : Normal `~N(0,1)`. \cr
#'
#'
#'
#'
#' @return \code{randSVD} returns a list containing the following three components:
#' \item{d}{
#'           array_like \cr
#'           \eqn{(k,k)} matrix in the rank-k approximation USV' to A, where A is
#'           \eqn{(m,n)}; the entries of \eqn{S} are all nonnegative, and its only
#'           nonzero entries appear in nonincreasing order on the diagonal.
#' }
#'
#' \item{u}{
#'           matrix \cr
#'           \eqn{(m, k)} matrix in the rank-\eqn{k} approximation \eqn{A = U * diag(S) * V'}
#'           to A; the columns of U are orthonormal and are called Left singular vect.
#'           We want to remark that this is the transpose matrix, hence
#'           the vectors are on the rows of our matrix.
#' }
#'
#' \item{v}{
#'           matrix \cr
#'           \eqn{(n, k)} matrix in the rank-\eqn{k} approximation \eqn{A = U * diag(S) * V'}
#'           to A; the columns of V are orthonormal and are called Right singular vect.
#' }
#'
#' @note The singular vectors are not unique and only defined up to sign
#' (a constant of modulus one in the complex case). If a left singular vector
#' has its sign changed, changing the sign of the corresponding right vector
#' gives an equivalent decomposition.
#'
#'
#' @references
#' \itemize{
#'   \item  [1] N. Halko, P. Martinsson, and J. Tropp.\cr
#'          "Finding structure with randomness: probabilistic
#'          algorithms for constructing approximate matrix
#'          decompositions" (2009). \cr
#'          (available at arXiv \url{http://arxiv.org/abs/0909.4061}).
#'   \item  [2] S. Voronin and P.Martinsson.\cr
#'          "RSVDPACK: Subroutines for computing partial singular value
#'          decompositions via randomized sampling on single core, multi core,
#'          and GPU architectures" (2015).\cr
#'          (available at `arXiv \url{http://arxiv.org/abs/1502.05366}).
#'  \item   [3] N. Benjamin Erichson.\cr
#'          "Randomized Singular Value Decomposition (rsvd): R package" (2016).\cr
#'          (available in the CRAN).
#'  \item   [4] Nathan Halko, Per-Gunnar Martinsson, and Joel Tropp.\cr
#'          "Finding structure with randomness: Stochastic algorithms for
#'          constructing approximate matrix decompositions" (2009).\cr
#'          (available at \url{http://arxiv.org}).
#'  \item   [5] V. Rokhlin, A. Szlam, M. Tygert.\cr
#'          "A randomized algorithm for principal component analysis" (2009).\cr
#'          (available at \url{https://arxiv.org/abs/0809.2274}).\cr
#'          The implementation of rand SVD is inspired by the MatLab implementation
#'          of RandPCA by M. Tygert.
#' }
#'
#' @author L. Rimella, \email{lorenzo.rimella@hotmail.it}
#'
#' @examples
#' #Simulate a general matrix with 1000 rows and 1000 columns
#' vy= rnorm(1000*1000,0,1)
#' y= matrix(vy,1000,1000,byrow=TRUE)
#'
#' #Compute the randSVD for the first hundred components of the matrix y and measure the time
#' start.time <- Sys.time()
#' prova1= randSVD(y,k=100)
#' Sys.time()- start.time
#'
#' #Compare with a classical SVD
#' start.time <- Sys.time()
#' prova2= svd(y)
#' Sys.time()- start.time
#'
#'
#' @import stats MASS
#'
#' @export

   randSVD <- function(A, k=NULL, l=NULL, its=2, sdist="unif")
{
  #*************************************************************************
  #***        Author:      L. Rimella <lorenzo.rimella@hotmail.it>       ***
  #***                                                                   ***
  #***        Supervisors: M. Beccuti                                    ***
  #***                     A. Canale                                     ***
  #***                                                                   ***
  #*************************************************************************

  if(nargs()==0) stop("Insert at least a matrix.")

  A <- as.matrix(A)

  #Check if array is real or complex
  if(is.complex(A))
  {
    isreal <- FALSE
  }
  else
  {
    isreal <- TRUE
  }

  #Dim of input matrix
  m <- nrow(A)
  n <- ncol(A)

  #Set target rank
  if(is.null(k)) k=6
  if(k>n | k > m) stop("Target rank is not valid! k must be less than the dimensions of the matrix")
  if(is.character(k)) stop("Target rank is not valid!")
  if(k<1) stop("Target rank is not valid!")

  #Set oversampling parameter
  if(is.null(l)) l =k+2
  if(l<k) stop("The value of l is not valid. The dimension of the Lanczos block must be greater than k.")
  if(l>n) l <- n

  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  # SVD A directly if (its+1)*l >= m/1.25 or (its+1)*l >= n/1.25.
  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  if(((its+1)*l >= m/1.25) | ((its+1)*l >= n/1.25))
  {
    #print('Classic SVD.')
    rsvdObj <- svd(A, nu= k, nv= k)
    rsvdObj$d <- rsvdObj$d[1:k]
   # rsvdObj$u <- rsvdObj$u[,1:k]
   # rsvdObj$v <- rsvdObj$v[,1:k]

    return(rsvdObj)

  }

  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  #CASE 1
  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  if(m >= n)
  {
    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    #Generate a random sampling matrix O
    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    H <- switch(sdist,
                normal = matrix(stats::rnorm(l*n), n, l),
                unif = matrix(stats::runif(l*n,-1,1), n, l),
                stop("Selected sampling distribution is not supported!"))

    if(isreal==FALSE) {
      H <- H + switch(sdist,
                      normal = 1i * matrix(stats::rnorm(l*n), n, l),
                      unif = 1i * matrix(stats::runif(l*n), n, l),
                      stop("Selected sampling distribution is not supported!"))
    }

    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    #Build a sample matrix H : H = A * H
    #Note: H should approximate the range of A
    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    H <- A %*% H


    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    #Initialize F to its final dimension.
    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    F = matrix(0,m,(its+1)*l);
    F[, 1:l] = H;


    for(it in 1:its)
    {
      H= tcrossprod(A,crossprod(H, A))

      F[, (1+it*l):((it+1)*l)] = H;
    }

    remove(H)
    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    #Perform a Q decomposition
    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Q= qr.Q(qr(F, complete = FALSE) , complete = FALSE )

    remove(F)
    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    #Singular Value Decomposition
    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    #Compute SVD
    rsvdObj <- svd(t(Q)%*%A, nu= k, nv= k)

    #rsvdObj$u <- rsvdObj$u[,1:k]
    #rsvdObj$v <- rsvdObj$v[,1:k]

    rsvdObj$u <- Q %*% rsvdObj$u
    rsvdObj$d <- rsvdObj$d[1:k]

    return(rsvdObj)

  }

  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  #CASE 2
  #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  if(m<n)
  {
    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    #Generate a random sampling matrix O
    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    H <- switch(sdist,
                normal = matrix(stats::rnorm(l*m), l, m),
                unif = matrix(stats::runif(l*m,-1,1), l, m),
                stop("Selected sampling distribution is not supported!"))

    if(isreal==FALSE) {
      H <- H + switch(sdist,
                      normal = 1i * matrix(stats::rnorm(l*m), l, m),
                      unif = 1i * matrix(stats::runif(l*m), l, m),
                      stop("Selected sampling distribution is not supported!"))
    }

    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    #Build sample matrix H : H = t(H * A)
    #Note: Y should approximate the range of A
    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    H <- t(H %*% A)

    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    #Initialize F to its final dimension.
    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    F = matrix(0,n,(its+1)*l);
    F[, 1:l] = H;


    for(it in 1:its)
    {
      H= t(t(A %*% H)%*% A)

      F[, (1+it*l):((it+1)*l)] = H;
    }

    remove(H)

    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    #Perform a Q decomposition
    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Q= qr.Q(qr(F, complete = FALSE) , complete = FALSE )

    remove(F)

    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    #Singular Value Decomposition
    #~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    #Compute SVD
    rsvdObj <- svd(A %*% Q, nu= k, nv= k)

    #rsvdObj$u <- rsvdObj$u[,1:k]
    #rsvdObj$v <- rsvdObj$v[,1:k]

    rsvdObj$v <- Q %*% rsvdObj$v
    rsvdObj$d <- rsvdObj$d[1:k]
    return(rsvdObj)
  }


} # End randSVD
