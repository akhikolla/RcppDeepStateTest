#' Multi-window Change Points Detection
#'
#' Use a sequence of window sizes to capture ranges of change points.
#'
#' Given time series data y1,y2...yN, a sequence of window sizes w1 > ... > wR
#' can be used to capture any true segment of small size. For each wr, the
#' original data is turned into a sequence of L + 1 dimensional data that can be
#' approximated as independent. Then the change points of independent data can
#' be detected by minimizing penalized quadratic loss. By further mapping these
#' change points back to the original scale, several short ranges (each of size
#' 2wr) that probably contain the desired change points are obtained. After
#' repeating the above procedure for different wr, the detected ranges of change
#' points from each window size are scored by one. The scores are aggregated,
#' and the ranges with highest score or around the highest score (determined by
#' the tolerance parameter) are finally selected.
#'
#' @references J. Ding, Y. Xiang, L. Shen, and V. Tarokh, \emph{Multiple Change
#'   Point Analysis: Fast Implementation and Strong Consistency}. IEEE
#'   Transactions on Signal Processing, vol. 65, no. 17, pp. 4495-4510, 2017.
#'
#' @param y The original data to find change points. Must be one dimensional
#'   data
#' @param window_list The list of window sizes, must be in form
#'   c(100,50,20,10,5), in descending order and each window_size > 2L. L is the
#'   lag order of the dataset.
#' @param point_max The largest candidate number of change points.
#' @param prior_range The prior ranges that considered to contain change
#'   points.Each prior range contains one change point. example:
#'   prior_range=list(c(30,200),c(220,400))
#' @param get_mle The method used to transform dependent data to independent
#'   data.
#' @param penalty Penalty type term. Default is "bic". Users can use other penalty term.
#' @param seg_min Minimal segment size between change points at transformed sacle, 
#'  must be positive integer.
#' @param num_init The number of repetition times, in order to avoid local
#'   minimum. Default is squared root of number of transformed data.
#' @param tolerance The tolerance level. The maximal difference between the score of 
#'   selected peak ranges and highest score.
#' @param cpp Logical value indicating whether to accelerate using rcpp. Default is TRUE.
#' @param ret_score Logical value indicating whether to return score. Default is FALSE.
#' 
#' @importFrom Rcpp evalCpp
#' @importFrom methods is
#' @return
#'   \item{n_peak_range}{The number of peak ranges.}
#'   \item{peak_ranges}{The location of peak ranges.}
#'   \item{score}{score matrix. (only when \emph{ret_score} is \emph{TRUE})}
#' @export
#' @examples
#' N <- 1000
#' N1 <- floor(0.1*N)
#' N2 <- floor(0.3*N)
#' a1 <- c(0.8, -0.3); c1 <- 0
#' a2 <- c(-0.5, 0.1); c2 <- 0
#' a3 <- c(0.5, -0.5); c3 <- 0
#' y <- rep(0,N)
#' L<-2
#' y[1:L] <- rnorm(L)
#' for (n in (L+1):N){
#'   if (n <= N1) {
#'     y[n] <- y[(n-1):(n-L)] %*% a1 + c1 + rnorm(1)
#'   } else if (n <= (N1+N2)) {
#'     y[n] <- y[(n-1):(n-L)] %*% a2 + c2 + rnorm(1)
#'   }
#'   else {
#'     y[n] <- y[(n-1):(n-L)] %*% a3 + c3 + rnorm(1)
#'   }
#' }
#' MultiWindow(y,window_list=c(100,50,20,10,5),point_max=5)
#' MultiWindow(y,window_list=c(100,50,20,10,5),prior_range=list(c(30,200),c(220,400)))
MultiWindow <- function(y,
                        window_list = c(100,50,20,10,5),
                        point_max   = 5,
                        prior_range = NULL,
                        get_mle     = GetMle,
                        penalty     = "bic",
                        seg_min     = 1,
                        num_init    = NULL,
                        tolerance   = 1,
                        cpp         = TRUE,
                        ret_score   = FALSE
                        ) {
  len <- length(y)
  n_window_type <- length(window_list)
  # initialize score matrix
  score <- matrix(0,nrow=len,ncol=n_window_type)
  for (r in 1:n_window_type) {
    #test
    #r=1
    #test
    window_size <- window_list[r]
    #n_window <- ceiling(len/window_size)
    # Get transformed approximated independent data
    x <- get_mle(y, window_size=window_size)
    # if the data is a list, transform it into matrix
    if (!is(x, "matrix")) {
      x <- as.matrix(x)
    }
    # set the random initialization times
    if (is.null(num_init)) {
      num_init <- floor(sqrt(dim(x)[1]))
    }
    if (is.null(prior_range)) {
      # Get the change points of transformed data
      change_point <- ChangePoints(x,point_max=point_max,penalty=penalty,seg_min=1,num_init=num_init,cpp=cpp)$change_point
    } else {
      # Transform prior_range to transformed_range according to window size
      trans_prior_range <- list()
      for (i in 1:length(prior_range)) {
        transformed_range=numeric(2)
        transformed_range[1] <- ceiling(prior_range[[i]][1]/window_size)
        transformed_range[2] <- ceiling(prior_range[[i]][2]/window_size)
        trans_prior_range[[i]] <- transformed_range
      }
      if (cpp == TRUE) {
        change_point<-PriorRangeOrderKmeansCpp(x,prior_range_x=trans_prior_range,num_init=num_init)$change_point
        cat("change_point:", change_point)
      } else {
        change_point<-PriorRangeOrderKmeans(x,prior_range_x=trans_prior_range,num_init=num_init)$change_point
      }
    }
    # Map the change points of transformed data to original data and get score the change points.
    if (r > 1){
      score[1:len,r] <- score[1:len,r-1]
    }
    for (k in 1:(length(change_point))) {
      if (k > 1) {
        if ((change_point[k] - change_point[k-1]) == 1) {
          score[(1+change_point[k]*window_size):min((change_point[k]+1) * window_size,len),r]<-score[(1+change_point[k]*window_size):min((change_point[k]+1)*window_size,len),r]+1
        } else {
          score[(1+(change_point[k]-1)*window_size):min((change_point[k]+1) * window_size,len),r]<-score[(1+(change_point[k]-1)*window_size):min((change_point[k]+1)*window_size,len),r]+1
        }
      } else {
        score[(1+(change_point[k]-1)*window_size):min((change_point[k]+1) * window_size,len),r]<-score[(1+(change_point[k]-1)*window_size):min((change_point[k]+1)*window_size,len),r]+1
      }
    }
  }
  if (!is.null(prior_range)) {
    point_max <- length(prior_range)
  }
  peakranges <- PeakRange(score=score,tolerance=tolerance,point_max=point_max)
  result <- list(n_peak_range=peakranges$n_peak_range, peak_range=peakranges$peak_range)
  if (ret_score) {
   result$score <- score
  }
  return(result)
}
