 # getOptGauss
  #########################################################################
  `getOptGauss` <- function(Data, Kernels, ParetoDensity,fast){ 
    # Teste RMS fuer einen Gauss
    Mean1 <- mean(Data)
    Deviation1 <- sd(Data)
    Weight1 <- 1
    Var=EMGauss(Data,fast=fast)
    Mean1 <- Var$Means
    Deviation1 <- Var$SDs
    Weight1 <- Var$Weights
    Fi <- dnorm(Kernels,Mean1,Deviation1)*Weight1
    RMS1 <- sqrt(sum((Fi-ParetoDensity)^2))
    
    # Teste RMS fuer 3 Gauss
    Means2 <- c(0,0,0)
    Deviations2 <- c(0,0,0)
    Weights2 <- c(0,0,0)
    Valskmeans <- kmeans(Data,3,iter.max=100)
    KValues <- Valskmeans$cluster
    #print(KValues2)
    for (i in 1:3){
      Means2[i] <- mean(Data[KValues==i])
      Deviations2[i] <- sd(Data[KValues==i])
      Weights2[i] <- sum(KValues==i)
      if (is.na(Deviations2[i])) {Deviations2[i] <- 0}
    }
    Weights2 <- Weights2/length(KValues)
    Var=EMGauss(Data,K=length(Means2), Means2,Deviations2,Weights2,10,fast=fast)
    Means2 <- Var$Means
    Deviations2 <- Var$SDs
    Weights2 <- Var$Weights
    Fi <- 0
    for (i in 1:3){
      Fi <- Fi+dnorm(Kernels,Means2[i],Deviations2[i])*Weights2[i]
    }
    RMS2 <- sqrt(sum((Fi-ParetoDensity)^2))
    
    # ueberpruefe ob RMS1( 1 Gauss) oder RMS2 (3 Gauss ) kleiner ist. Speichere zugehoerige means, deviations und weights
    SSE1=RMS1^2*log(3)
    SSE2=RMS2^2*log(3*3)
    if (SSE1<SSE2){
      means <- Mean1
      deviations <- Deviation1
      weights <- Weight1
    } else {
      means <- Means2
      deviations <- Deviations2
      weights <- Weights2
    }
    # Ordne gaussians nach mean
    order <- order(means)
    means <- means[order]
    deviations <- deviations[order]
    weights <- weights[order]
    out=list(means=means,deviations=deviations,weights=weights)
    
    
    return(out)
  }
  #########################################################################
  