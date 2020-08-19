Pdf4Mixtures=function(Data,Means,SDs,Weights,IsLogDistribution,PlotIt=F){
# pdfV=Pdf4Mixtures(Data,Means,SDs,Weights,IsLogDistribution,PlotIt=T)
# generate the pdf for the Mixture
# INPUT
# Data(1:AnzCases)            this data column for which the distribution #															was modelled
# Means(1:L,1)                Means of Gaussians,  L ==  Number of Gaussians
# SDs(1:L,1)                 estimated Gaussian Kernels = standard #															deviations
# Weights(1:L,1)              relative number of points in Gaussians #														(prior probabilities): sum(Weights) ==1, #														default 1/L
# Optional
# IsLogDistribution(1:L)      default ==0*(1:L), gibt an ob die jeweilige #															Verteilung eine Lognormaverteilung ist  
# PlotIt                      PDF wird gezeichnet  
# OUTPUT
# PDF(1:N)             		Vektor der PDF      korrespondierend zu Data
# PDF4modes(1:N,1:C)   		Vektor der PDF der teilmodi  
# PDFmixture        			vector der Superposition, wird in 
#													PlotMixtures() genutzt
#
# author: MT 01/2016 ausgelagert von  PlotMixtures
# Note: Funktionsnamen vereinheitlicht mit LikelihoodRatio4Mixtures, LogLikelihood4Mixtures, Chi2testMixtures, CDFMixtures, KStestMixtures, in matlab unter PdfForMixes

#########################################################
  if(missing(IsLogDistribution)) 
		IsLogDistribution = rep(FALSE,length(Means))
		
	
  AnzGaussians = length(Means)
  PDF4modes=matrix(0,nrow=length(Data),ncol=AnzGaussians)
  GaussMixture=Data*0
  for(g in c(1:AnzGaussians)){
    if(IsLogDistribution[g] == TRUE){ # LogNormal 
      PDF4modes[,g] <- Symlognpdf(Data,Means[g],SDs[g]) # LogNormal 
    }else{ # Gaussian
      PDF4modes[,g] = dnorm(Data,Means[g],SDs[g])
    }# if IsLogDistribution(i) ==T  
    GaussMixture =  GaussMixture + PDF4modes[,g]*Weights[g] 
  } # for AnzGaussians

	#PDF4modes gewichtet:
  PDF=PDF4modes
  for(g in c(1:AnzGaussians))
    PDF[,g] =  PDF4modes[,g] * Weights[g] 

  if(PlotIt){
    X=sort(na.last=T,Data) 
    Sind=order(Data)
    plot(X,GaussMixture[Sind],type='l',xlim=c(X[1],X[length(X)]),ylab='pdf (Superposition of Gaussians)',xlab='Data')
  }
  return(list(PDF4modes=PDF4modes,PDF=PDF,PDFmixture=GaussMixture ))
}