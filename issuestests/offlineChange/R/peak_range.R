#' Peak Ranges Selection
#'
#' Select the narrow peak ranges.
#'
#' For each column(window type), find the union of all the peak
#' ranges whose associated scores are no less than S - tolerance, where S is highest score,
#' then choose the largest window type with that the number of peak ranges meet the restriction.
#'
#' @references
#' J. Ding, Y. Xiang, L. Shen, and V. Tarokh, \emph{Multiple Change Point Analysis:
#' Fast Implementation and Strong Consistency}. IEEE Transactions on Signal
#' Processing, vol. 65, no. 17, pp. 4495-4510, 2017.
#'
#' @param score The score data to peak ranges.
#' @param tolerance The tolerance level , the selected narrow ranges are with score at least S-tolerance
#' @param point_max The largest candidate number of change points.
#'
#' @return
#'         \item{n_peak_range}{The number of peak ranges.}
#'         \item{peak_range}{The location of peak ranges.}
#' @export
PeakRange<-function(score,tolerance=1,point_max=5) {
  N<-dim(score)[1]
  R<-dim(score)[2]
  # compute the hightest score
  S<-max(score)
  # in case the tolerance is negative number
  if (tolerance < 0) {
    stop("Tolerance can't be negative!")
  }
  # Warning if tolerance is larger than S
  if (tolerance > S) {
    warning("Tolerance is too large!")
  }
  
  for (r in R:1) {
    S<-max(score[,r])
    score[,r]<-ifelse(score[,r] > (S-tolerance), S-tolerance, score[,r])
    J<-list()
    # store number of unions
    num<-0
    #test
    #r=4
    #test
    if (score[1,r]>=S-tolerance) {
      num<-num+1
      J[[num]]<-1
    }
    for (i in 2:N) {
      if (score[i,r]>=S-tolerance) {
        # update the number of unions when meet new union
        if (score[i,r]!=score[i-1,r]) {
          num<-num+1
          J[[num]]<-i
        } else {
          J[[num]]<-c(J[[num]],i)
        }
      }
    }
    # when the number of unions meet the requirement of largest number of change points, end the loop
    if (num<=point_max) {
      break
    }
  }
  optimal<-list(n_peak_range=num,peak_range=J)
  return(optimal)
}