RandomLogGMM=function(Means,SDs,Weights,IsLogDistribution,TotalNoPoints=1000){
  # GMM = RandomLogGMM(Means,SDs,Weights,IsLogDistribution,TotalNoPoints)
  # genereierung von ZufalsDaten, die einer Mischung von Vereilungen aus
  # Gauss & Log-Normalen folgt
  # INPUT
  # Means(1:L), SDs(1:L), Weights(1:L) die Paramter von der Verteilungen
  # IsLogDistribution(1:L) gibt an ob die einzelverteilung einer (generalisierten)Lognormaverteilung ist
  #             wenn IsLogDistribution(i)==0 dann Mix(i) = Weights(i) * N(Means(i),SDs(i)
  #             wenn IsLogDistribution(i)==1 dann Mix(i) = Weights(i) * LogNormal(Means(i),SDs(i)
  # Die Gesamtverteilung ergibst sich als Summe der GMM(1:L)
  # 
  # OPTIONAL
  # TotalNoPoints              Mix enthalet so viele Punkte am Schluss.
  #                              Default: TotalNrOfPoints ca 1000
  #
  # NOTA: die Log-Normalverteilung ist generaisiert d.h.: L(Means,SDs) = sign(Means)*lognrnd(abs(Means),SDs);
  #author: ?, RG
  #1.Eitor: MT 06/2015
  #2.Editor: MT 03/19 deutliche effizienzsteigerung eingepflegt fuer normale gausse.
  L= length(Means)
  AnzPoints = round(Weights*TotalNoPoints*1.1)
  # Verteilung der Mischungen  erzeugen
  Mix = c() # init
  if(missing(Means)){
    stop('Means are missing.')
  }
  if(is.null(Means)){
    stop('Means are NULL.')
  }
  if(missing(IsLogDistribution))
    IsLogDistribution=Means*0
  #requireNamespace('dqrng')
  for(d in 1:L){
    if(IsLogDistribution[d]==1){
      # Mixi = symlogrnd(Means[d],SDs[d],AnzPoints[d],1)
      # Mix(i) als LogNormal erzeugen
      #temp <- symlognSigmaMue(Means[d],SDs[d])
      variance<-log(SDs[d]*SDs[d]/(Means[d]*Means[d])+1)
      sig<-sqrt(variance)
      mu<-log(abs(Means[d]))-0.5*variance
      temp=list(variance=variance,sig=sig,mu=mu)
      mu <- temp$mu
      sig <- temp$sig
      n <- AnzPoints[d]*1
      Mixi <- matrix(sign(Means[d]) * rlnorm(n, abs(mu), sig), AnzPoints[d], 1)
    }else{ # Mormalverteilung
      #Mixi = normrnd(Means[d],SDs[d],AnzPoints[d],1) # Mix(i) als Gauss erzeugen
      x <- 1*AnzPoints[d]
      #Mixi <- matrix(rnorm(n=x, mean=Means[d], sd=SDs[d]), nrow=AnzPoints[d], ncol=1)   
      
	  #MT 2019/03: das ist die schnelle version fuer den bottleneck
      #Mixi <- matrix(dqrng::dqrnorm(n=x, mean=Means[d], sd=SDs[d]), nrow=AnzPoints[d], ncol=1)   
      # 2019/12: Using Ralf's Stubner suggestions
	  if(requireNamespace("dqrng", quietly = TRUE)){
		Mixi <- matrix(dqrng::dqrnorm(n=x, mean=Means[d], sd=SDs[d]), nrow=AnzPoints[d], ncol=1)
	  }else{
		Mixi <- matrix(rnorm(n=x, mean=Means[d], sd=SDs[d]), nrow=AnzPoints[d], ncol=1)   
	  }
    }
    Mix = c(Mix,Mixi)
  }  # for d
  # hier enthaelt Mix die der Vereilung entsprechende Punkte  
  # Dureinanderwuerfeln und auf gewuenschte Anzahl bringen
  
  #MT 2019/03: das ist die schnelle version, noch anzupassen
  #internal disabled for cran
  # if(sum(AnzPoints)>TotalNoPoints)
  #   Ind = .Internal(sample(sum(AnzPoints),TotalNoPoints, FALSE, NULL))
  # else
  #   Ind = .Internal(sample(sum(AnzPoints),TotalNoPoints, TRUE, NULL))
  # 
  if(sum(AnzPoints)>TotalNoPoints)
    Ind = sample(sum(AnzPoints),TotalNoPoints, FALSE, NULL)
  else
    Ind = sample(sum(AnzPoints),TotalNoPoints, TRUE, NULL)
  
  #Ind = sample(c(1:sum(AnzPoints)),TotalNoPoints)
  GMM=Mix[Ind]
  return(GMM)  
}
