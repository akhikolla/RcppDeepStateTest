 # rsampleAdaptGauss
  ############################################################
  `rsampleAdaptGauss` <- function(k,n,uniq=TRUE,exact=TRUE){
    
    index = ceiling(runif(k)*n) # Calculate k of n values.
    if(uniq==TRUE){# if unique, avoide duplicates.
      if(k>n&exact){ # Don't run in infinite loop.
        print("The first parameter has to be <= the second.")
        print("You choose uniq = TRUE. This would cause an infinite loop.")
        print("Abort function.")
      }
      else{
        index = unique(index)
        while(exact&(length(index)<k)){
          index = c(index,ceiling(runif(k-length(index))*n))
          index = unique(index)
        }
        return(index)
      }
    }
    else{
      return(index)
    }
  }
  ############################################################