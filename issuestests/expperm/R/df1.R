#' A small data frame of simulated records
#'
#' A small data frame of simulated records as might be found in a population census. This data is used to demonstrate the package's algorithms in a more realistic setting. It also allows for reproduction of the example towards the end of the paper that accompanies this package. The data is a subset of a larger set simulated by of P. McLeod, R. Heasman and I. Forbes of the UK's Office for National Statistics. At the time of publication this data is available at https://ec.europa.eu/eurostat/cros/content/job-training_en. The example below shows how we could compute a distance matrix for the records in dataframes \code{df1} and \code{df2}.
#' @examples
#' \dontrun{
#' library(stringdist)
#' D<-matrix(,n,n)
#' for(i in 1:n){for(j in 1:n){
#'  D[i,j]<-stringdist(df1$PERNAME1[i],df2$PERNAME1[j]) + 
#'   stringdist(df1$PERNAME2[i],df2$PERNAME2[j],method="dl") + 
#'   stringdist(df1$DOB_YEAR[i],df2$DOB_Y#' EAR[j],method="dl")
#' }}
#' }
"df1"
