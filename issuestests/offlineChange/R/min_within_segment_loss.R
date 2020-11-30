#' Detect Number and Location of Change Points of Independent Data
#'
#' Detect the number and locations of change points based on minimizing within
#' segment quadratic loss and applying penalized model selection approach with
#' restriction of largest candidate number of change points.
#'
#' The K change points form K+1 segments (1 2 ... change_point(1)) ...
#' (change_point(K) ... N).
#'
#' @references J. Ding, Y. Xiang, L. Shen, and V. Tarokh, \emph{Multiple Change
#' Point Analysis: Fast Implementation and Strong Consistency}. IEEE
#' Transactions on Signal Processing, vol. 65, no. 17, pp. 4495-4510, 2017.
#'
#' @param x The data to find change points.
#' @param point_max The largest candidate number of change points.
#' @param penalty Penalty type term. Default is "bic". Users can use other penalty term.
#' @param seg_min Minimal segment size between change points at transformed sacle, 
#'   must be positive integer.
#' @param num_init The number of repetition times, in order to avoid local
#'   minimum. Default is squared root of number of observations. Must be integer.
#' @param cpp Option to accelerate using rcpp. Default is TRUE.
#'
#' @useDynLib offlineChange
#'
#' @import stats
#' @importFrom Rcpp evalCpp
#'
#' @return
#'   \item{num_change_point}{optimal number of change points.}
#'   \item{change_point}{location of change points.}
#' @exportPattern ^[[:alpha:]]+
#' @export
#' @examples
#' a<-matrix(rnorm(40,mean=-1,sd=1),nrow=20,ncol=2)
#' b<-matrix(rnorm(120,mean=0,sd=1),nrow=60,ncol=2)
#' c<-matrix(rnorm(40,mean=1,sd=1),nrow=20,ncol=2)
#' x<-rbind(a,b,c)
#' ChangePoints(x,point_max=5)
#' ChangePoints(x,point_max=5,penalty="hq")

ChangePoints <- function(x,point_max=5,penalty="bic",seg_min=1,num_init=NULL,cpp=TRUE){
  N <- dim(x)[1]
  D <- dim(x)[2]
  best_wgss_penalty <- Inf
  # Make sure the number of change points is no larger than N-1.
  point_max <- min(point_max,N-1)
  # Set the lower bound of number of change points as 1.
  point_max <- max(point_max, 1)

  # K = number of change points
  if (penalty == "bc") {
    bc_part = 0
    best_wgss_penalty_bc <- Inf
  }
  # set the random initialization times
  if (is.null(num_init)) {
    num_init <- floor(sqrt(dim(x)[1]))
  }
  for (K in 1:point_max) {
    if (cpp == TRUE) {
      res <- OrderKmeansCpp(x,K,num_init=num_init)
    } else {
      res <- OrderKmeans(x,K,num_init=num_init)
    }
    wgss <- res$wgss
    num_each <- res$num_each
    change_point <- res$change_point
    #if size of the smallest segment is less than minimal segment size, end the loop
    if (min(num_each) < seg_min) {
      break
    }

    #get the within segment sum of residual plus penalty
    if (penalty == "bic") {
      wgss_penalty <- N * log(sum(wgss)/N) + D * K * log(N)
    } else if (penalty == "aic") {
      wgss_penalty <- N * log(sum(wgss)/N) + 2 * D * K
    } else if (penalty == "bc") {
      wgss_penalty <- N * log(sum(wgss)/N) + 2 * D * K
      for (p in (D * (K-1) + 1): (D * K)) {
        bc_part <- bc_part + 1/p
      }
      wgss_penalty_bc <- N * log(sum(wgss)/N) + N^(2/3)*bc_part
      #print(wgss)
      #print(change_point)
      #print(wgss_penalty_bc)
      #print(sum(num_each * log(wgss/num_each))+ N^(2/3)*bc_part)
    } else if (penalty == "hq") {
      wgss_penalty <- N * log(sum(wgss)/N) + D * K * log(log(N))
    } else {
      wgss_penalty <- do.call(penalty,list(num_each, wgss, D, K, N))
    }
    if (penalty == "bc") {
      if (wgss_penalty_bc < best_wgss_penalty_bc) {
        best_wgss_penalty_bc <- wgss_penalty_bc
        best_change_point_bc <- change_point
        best_num_bc <- K
      }
    }

    #if the new wgss plus penalty is smaller than the previous one, store the new value,
    #get the smallest wgss among different changepoint numbers
    if (wgss_penalty < best_wgss_penalty) {
      best_wgss_penalty <- wgss_penalty
      best_change_point <- change_point
      best_num <- K
      if (penalty == "bc") {
        best_wgss_penalty_bc_aic <- best_wgss_penalty_bc
        best_change_point_bc_aic <- best_change_point_bc
        best_num_bc_aic <- best_num_bc
      }
    }
  }
  if (penalty == "bc") {
    best_wgss_penalty <- best_wgss_penalty_bc_aic
    best_change_point <- best_change_point_bc_aic
    best_num <- best_num_bc_aic
  }
  m_change_point <- list(num_change_point=best_num,change_point=best_change_point)
  return(m_change_point)
}

#' Detect Location of Change Points of Independent Data
#'
#' Detect the location of change points based on minimizing within segment quadratic
#' loss with fixed number of change points.
#'
#' The K change points form K+1 segments (1 2 ... change_point(1)) ...
#' (change_point(K) ... N).
#'
#' @references
#' J. Ding, Y. Xiang, L. Shen, and V. Tarokh, \emph{Multiple Change Point Analysis:
#' Fast Implementation and Strong Consistency}. IEEE Transactions on Signal
#' Processing, vol. 65, no. 17, pp. 4495-4510, 2017.
#' @param x The data to find change points with dimension N x D, must be matrix
#' @param K The number of change points.
#' @param num_init The number of repetition times, in order to avoid local minimum.
#'                 Default is 10. Must be integer.
#' @importFrom methods is
#'
#' @return
#'         \item{wgss_sum}{total within segment sum of squared distances to the segment
#'                  mean (wgss) of all segments.}
#'         \item{num_each}{number of observations of each segment}
#'         \item{wgss}{total wgss of each segment.}
#'         \item{change_point}{location of optimal change points.}
#' @export
#' @examples
#' a<-matrix(rnorm(40,mean=-1,sd=1),nrow=20,ncol=2)
#' b<-matrix(rnorm(120,mean=0,sd=1),nrow=60,ncol=2)
#' c<-matrix(rnorm(40,mean=1,sd=1),nrow=20,ncol=2)
#' x<-rbind(a,b,c)
#' OrderKmeans(x,K=3)
#' OrderKmeans(x,K=3,num_init=8)
OrderKmeans <- function(x, K=4, num_init=10) {
  if (!is(x, "matrix")) {
    stop("Dataset must be matrix form!")
  }
  N<-dim(x)[1] # number of observations
  D<-dim(x)[2] # dimension of each observation
  # There are M segments
  M <- K+1
  # Change points number error handling
  if (N < M) {
    stop("Change point number too large or Input dimension error!")
  } else if (M == 1) {
    stop("No change point!")
  }
  # special case, N == M
  if (N == M) {
    best_wgss_sum <- 0
    best_num_each <- matrix(1,nrow=N,ncol=1)
    best_wgss <- rep(0,N)
    best_change_point <- as.numeric(seq(N))
  } else {

    # randomize initial change points several times to avoid local optima
    best_wgss_sum<-Inf

    for (j in 1:num_init) {
      #test
      #cat("j=",j)
      #test

      # store the within segment sum of squared distances to the segment mean (wgss)
      # in each dimension in each segment
      num_each<-matrix(0,nrow=M,ncol=1)
      wgss_each<-matrix(0,nrow=M,ncol=D)
      mean_each<-matrix(0,nrow=M,ncol=D)

      # Initialize change points, add N-th observation as the last change point so
      # there are K+1 change points
      change_point<-floor(1+(N-2)*stats::runif(K))
      change_point<-c(change_point,N)
      change_point<-unique(change_point)

      # make sure change points are unique
      while (length(change_point)<M) {
        change_point<-c(change_point,floor(1+(N-2)*stats::runif(1)))
        change_point<-unique(change_point)
      }
      change_point <- sort(change_point)

      # initialize for each segment the number of points, within segment sum of squares, and mean
      num_each[1] <- change_point[1]
      wgss_each[1,] <- apply(matrix(x[1:change_point[1],],ncol=D),2,stats::var) * (num_each[1]-1)
      if (num_each[1]==1) {
        wgss_each[1,]<-matrix(0,nrow=1,ncol=D)
      }
      mean_each[1,] <- apply(matrix(x[1:change_point[1],],ncol=D),2,mean)

      for (i in 2:M) {
        #i=3
        num_each[i] <- change_point[i] - change_point[i-1]
        wgss_each[i,] <- apply(matrix(x[(change_point[i-1]+1):change_point[i],],ncol=D),2,stats::var) * (num_each[i]-1)
        # special case: one segment only contains one number, avoid get NA for variance
        if (num_each[i]==1) {
          wgss_each[i,]<-matrix(0,nrow=1,ncol=D)
        }
        mean_each[i,] <- apply(matrix(x[(change_point[i-1]+1):change_point[i],],ncol=D),2,mean)

      }

      # scan the middle K change points
      # suppose that we are at the crossing of segments i and i+1
      for (i in 1:K) {
        #test
        #i=1
        #cat("i=",i,"\n")
        #cat("num_each=",num_each,"\n")
        #cat("num_each[i]=",num_each[i],"\n")
        #test

        # consider if we should move the last part of segment i
        best_gain_sum <- -Inf
        if (num_each[i]>1) {

          # scan all possible part that can be transformed form segment i to i+1
          for (ell in 1:(num_each[i]-1)) {
            #test
            #ell=12
            #cat("ell=",ell,"\n")
            #test

            mean_candidatePart<-apply(matrix(x[(change_point[i]-ell+1):change_point[i],],ncol=D),2,mean)
            # the descrease in wgss of segment i
            decrease<-ell*num_each[i]/(num_each[i]-ell)*(mean_each[i,]-mean_candidatePart)^2
            # the increase in wgss of segment i+1
            increase<-ell*num_each[i+1]/(num_each[i+1]+ell)*(mean_each[i+1,]-mean_candidatePart)^2
            # store the best candidate part than can be transformed from segment i to i+1
            if ( sum(decrease) - sum(increase) > best_gain_sum) {
              #test
              #cat("decrease=",sum(decrease),"\n")
              #cat("increase=",sum(increase),"\n")
              #test
              best_gain <- decrease - increase
              best_gain_sum <- sum(best_gain)
              best_ell <- ell
              best_candidatePart <- matrix(x[(change_point[i]-ell+1):change_point[i],],ncol=D)
              #test
              #cat("best_candidatePart=",best_candidatePart,"\n")
              #cat("best_ell =",best_ell,"\n")
              #test
              best_decrease <- decrease
              best_increase <- increase
            }
          }
        }
        # If total wgss decrease, move the best candidate part from segment i to i+1,
        # and get new segment i and i+1, also update the corresponding mean, wgss adn change point.
        # If not, consider if we should move the first part of segment i+1
        if  (best_gain_sum > 0) {
          #test
          #cat("left to right","\n")
          #test
          best_mean_candidatePart <- apply(best_candidatePart,2,mean)
          mean_each[i,] <- (num_each[i]*mean_each[i,]-best_ell*best_mean_candidatePart)/(num_each[i]-best_ell)
          mean_each[i+1,] <- (num_each[i+1]*mean_each[i+1,]+best_ell*best_mean_candidatePart)/(num_each[i+1]+best_ell)
          change_point[i] <- change_point[i] - best_ell
          num_each[i] <- num_each[i] - best_ell
          num_each[i+1] <- num_each[i+1] + best_ell
          #wgss_part <- apply((best_candidatePart - matrix(best_mean_candidatePart,nrow=best_ell,ncol=D,byrow=TRUE))^2,2,sum)
          #wgss_each[i,] <- wgss_each[i,] - best_decrease - wgss_part
          #wgss_each[i+1,] <- wgss_each[i+1,] + best_increase + wgss_part
          if (i == 1) {
            wgss_each[i, ] <- apply(matrix(x[1:change_point[i],],ncol=D),2,stats::var) * (num_each[i]-1)
          } else {
            wgss_each[i,] <- apply(matrix(x[(change_point[i-1]+1):change_point[i],],ncol=D),2,stats::var) * (num_each[i]-1)
          }
          wgss_each[i+1,] <- apply(matrix(x[(change_point[i]+1):change_point[i+1],],ncol=D),2,stats::var) * (num_each[i+1]-1)
          if (num_each[i]==1) {
            wgss_each[i,]<-matrix(0,nrow=num_each[i],ncol=D)
          }
          if (num_each[i+1]==1) {
            wgss_each[i+1,]<-matrix(0,nrow=num_each[i+1],ncol=D)
          }
          #wgss_each[i+1,] <- apply(matrix(x[(change_point[i]+1):change_point[i+1],],ncol=D),2,var) * (num_each[i+1]-1)
          #test
          #cat("change_point[i]",change_point[i],"\n")
          #cat("num_each[i] =",num_each[i],"\n")
          #cat("num_each[i+1] =",num_each[i+1],"\n")
          #test
        } else {
          # consider if we should move the first part of segment i+1
          best_gain_sum<- -Inf
          #test
          #cat("num_each[i+1]=",num_each[i+1],"\n")
          #test
          if (num_each[i+1]>1) {
            for (ell in 1:(num_each[i+1]-1)) {
              #test
              #cat("ell=",ell,"\n")
              #test
              mean_candidatePart<-apply(matrix(x[(change_point[i]+1):(change_point[i]+ell),],ncol=D),2,mean)

              decrease<-ell*num_each[i+1]/(num_each[i+1]-ell)*(mean_each[i+1,]-mean_candidatePart)^2
              increase<-ell*num_each[i]/(num_each[i]+ell)*(mean_each[i,]-mean_candidatePart)^2
              if ( sum(decrease) - sum(increase) > best_gain_sum) {
                #test
                #cat("decrease=",sum(decrease),"\n")
                #cat("increase=",sum(increase),"\n")
                #test
                best_gain <- decrease - increase
                best_gain_sum <- sum(best_gain)
                best_ell <- ell
                best_candidatePart <- matrix(x[(change_point[i]+1):(change_point[i]+ell),],ncol=D)
                #test
                #cat("best_candidatePart=",best_candidatePart,"\n")
                #cat("best_ell =",best_ell,"\n")
                #test
                best_decrease <- decrease
                best_increase <- increase
              }
            }
          }
          if  (best_gain_sum > 0) {
            #test
            #cat("right to left","\n")
            #test
            best_mean_candidatePart = apply(best_candidatePart,2,mean)
            mean_each[i+1,] <- (num_each[i+1]*mean_each[i+1,]-best_ell*best_mean_candidatePart)/(num_each[i+1]-best_ell)
            mean_each[i,] <- (num_each[i]*mean_each[i,]+best_ell*best_mean_candidatePart)/(num_each[i]+best_ell)
            change_point[i] <- change_point[i] + best_ell
            num_each[i] <- num_each[i] + best_ell
            num_each[i+1] <- num_each[i+1] - best_ell
            #wgss_part <- apply((best_candidatePart - matrix(best_mean_candidatePart,nrow=best_ell,ncol=D,byrow=TRUE))^2,2,sum)
            #wgss_each[i,] <- wgss_each[i,] + best_decrease + wgss_part
            #wgss_each[i+1,] <- wgss_each[i+1,] - best_increase - wgss_part
            if (i == 1) {
              wgss_each[i, ] <- apply(matrix(x[1:change_point[i],],ncol=D),2,stats::var) * (num_each[i]-1)
            } else {
              wgss_each[i,] <- apply(matrix(x[(change_point[i-1]+1):change_point[i],],ncol=D),2,stats::var) * (num_each[i]-1)
            }
            wgss_each[i+1,] <- apply(matrix(x[(change_point[i]+1):change_point[i+1],],ncol=D),2,stats::var) * (num_each[i+1]-1)
            if (num_each[i]==1) {
              wgss_each[i,]<-matrix(0,nrow=num_each[i],ncol=D)
            }
            if (num_each[i+1]==1) {
              wgss_each[i+1,]<-matrix(0,nrow=num_each[i+1],ncol=D)
            }
            #test
            #cat("change_point[i]",change_point[i],"\n")
            #cat("num_each[i] =",num_each[i],"\n")
            #cat("num_each[i+1] =",num_each[i+1],"\n")
            #test
          }
        }
        # get the total wgss of each segment
        wgss<-rowSums(wgss_each)
      }
      #get the total wgss of all segments
      wgss_sum<-sum(wgss)
      # store the smallest total wgss among several initializations.
      if (best_wgss_sum>wgss_sum) {
        best_wgss_sum<-wgss_sum
        best_wgss <- wgss
        #test
        #best_wgss_test<-wgss_each
        #test
        best_num_each <- num_each
        best_change_point<-change_point
      }
      #print(wgss_sum)
      #print(change_point)
    }
  }
  # Delete the last observation from change points
  best_change_point=best_change_point[-M]

  k_changepints<-list(wgss_sum=best_wgss_sum,num_each=best_num_each,wgss=best_wgss,change_point=best_change_point)
  return(k_changepints)
}

