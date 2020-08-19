Symlognpdf = function(Data, Mean, SD){
  #pdf = Symlognpdf(Data, Means, SDs);
  # for M>0 same as dlnorm(Data,M,S); (Dichte der log-Normalverteilung)
  # for M < 0: mirrored at y axis
  #INPUT
  #Data[1:n]  x-values
  # Means, SDs        Mean and Sdev of lognormal
  symlognSigmaMue <-  function(M,S){
    
    variance<-log(S*S/(M*M)+1)
    sig<-sqrt(variance)
    mu<-log(abs(M))-0.5*variance
    return (list(variance=variance,sig=sig,mu=mu)) 
    
  }
  temp<-symlognSigmaMue(Mean,SD)
  mu<-temp$mu
  sig<-temp$sig
  if(Mean>=0){
    pdfkt<-dlnorm(Data,meanlog=mu,sdlog=sig)  
  }else{
    pdfkt<-Data*0
    negDataInd<-which(Data<0)
    pdfkt[negDataInd] <- dlnorm(-Data[negDataInd],meanlog=mu,sdlog =sig)
    #    plot(Data,pdfkt)
  }
  return (pdfkt) 
}