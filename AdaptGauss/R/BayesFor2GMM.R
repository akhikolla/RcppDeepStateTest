
BayesFor2GMM <- function(Data, Means, SDs, Weights, IsLogDistribution = Means*0, Ind1 = c(1:floor(length(Means)/2)),
 Ind2 = c((floor(length(Means)/2)+1):length(Means)), PlotIt = 0, CorrectBorders = 0){
# die Berechnung der Posteriors wobei das gegeben GMM als zwei Gruppen Ind1 und Ind2 aufgefasst werden.

# INPUT
# Data(1:N)            vector of data,  may contain NaN, where lay the kernels?
# Means(1:C),SDs(1:C),Weights(1:C) parameters of the Gaussians 
#                      assume for now Means is sorted;
# OPTIONAL
# IsLogDistribution(1:C) oder 0, gibt an ob die jeweilige Verteilung eine Lognormalverteilung ist,(default ==0*(1:C))
# Ind1, Ind2            indices from (1:C) such that [Means(Ind1),SDs(Ind1) ,Weights(Ind1) ]is one mixture, [Means(Ind2),SDs(Ind2) ,Weights(Ind2) ] the second mixture
#                       default Ind1= 1:C/2, Ind2= C/2+1:C;

# PlotIt              ==1 Verteilungen und Posteriors werden gezeichnet (default ==0);
# CorrectBorders      ==1 Daten an den Grenzen werden den Randverteilungen zugeordnet
#                    (default ==0) d.h. ganz gewoehnlicher Bayes mit allen seinen Problemen
# OUTPUT
# Posteriors(1:N,1:C)          Vektor der Posteriors      korrespondierend zu Data
# NormalizationFactor(1:N)     Nenner des Bayes Theorems  korrespondierend zu Data


# sort Means and equal SDs,Weights,...
# Author: reimplemented from Matlab, ALU 
# 1. Editor: MT 2014
  
  

AnzMixtures <- length(Means)

Ind1=as.vector(Ind1)  
Ind2=as.vector(Ind2)    
Kernels <- unique(Data) 
AnzKernels <- length(Kernels)

##Unique liefer keine Sortierten Indizies:
#MT: Wird in matlab zwar berechnet, aber nie benutzt
# z <- order(Means) # returns a permutation which rearranges its first argument into descending order, 
# Means <- Means[z]
# SDs <- SDs[z]
# Weights <- Weights[z]
# IsLogDistribution <- IsLogDistribution[z]
# ind <- c()
# for(i in Ind1){
#   ind <- c(ind,grep(i, z))
# }
# Ind1 <- sort(ind)
# 
# ind <- c()
# for(i in Ind2){
# 	ind <- c(ind,grep(i, z))
# }
# Ind2 <- sort(ind)




PDataGivenClass <- matrix(0,AnzKernels,AnzMixtures)

for( i in 1:AnzMixtures){
	if(IsLogDistribution[i] ==1){ # Log Normal
		PDataGivenClass[,i] <- dlnorm(Kernels,Means[i],SDs[i])
	}else{
		PDataGivenClass[,i] <- dnorm(Kernels,Means[i],SDs[i])
	}
}

NormalizationFactor <- PDataGivenClass %*% Weights # Gewichtete Summe der Priors
Pmax <- max(NormalizationFactor)

ZeroIndv <- which(NormalizationFactor==0, arr.ind = TRUE)
ZeroInd <- ZeroIndv[,2]
if(length(ZeroInd > 0)){
	NormalizationFactor[ZeroInd]  <- 10^(-7)
}

Xones <- Kernels * 0 + 1
PClassGivenData <- matrix(0,AnzKernels,2)
#MT: If-Abfrage Erg?nzung:
if(length(Weights[Ind1])>1){
PClassGivenData[,1] <- PDataGivenClass[,Ind1] %*% Weights[Ind1]
}else{
  PClassGivenData[,1] <- PDataGivenClass[,Ind1] * Weights[Ind1]  
}
if(length(Weights[Ind2])>1){
PClassGivenData[,2] <- PDataGivenClass[,Ind2] %*% Weights[Ind2]
}else{
  PClassGivenData[,2] <- PDataGivenClass[,Ind2] * Weights[Ind2]
}
  
PClassGivenData <- PClassGivenData / (NormalizationFactor %*% matrix(1,1,2))
Posteriors <- PClassGivenData

if(CorrectBorders == 1 & (sum(IsLogDistribution) == 0)){ # randkorrekturen anbringen
	# Daten kleiner kleinstem Modus werden diesem zugeschlagen
	KleinsterModus <- min(Means)
	SmallModInd <- which.min(Means)
	LowerInd <- which(Kernels < KleinsterModus)
	PClassGivenData[LowerInd,1] <- 1
	PClassGivenData[LowerInd,2] <- 0
	# Daten groesser groesstem Modus werden diesem zugeschlagen
	GroessterModus <- max(Means)
	BigModInd <- which.max(Means)
	HigherInd <- which(Kernels > GroessterModus)
	PClassGivenData[HigherInd,1] <- 0
	PClassGivenData[HigherInd,2] <- 1
}

#browser()

if ( PlotIt == 1){
	print( 'BayesFor2GMM(): Plot is in development')
  gPlot <- ggplot2::ggplot()
  
  
  
  for (i in 1:AnzMixtures){
    df = data.frame(x = Kernels, y=PDataGivenClass[,i]*Weights[i]/Pmax)
    gPlot = gPlot + ggplot2::geom_line(data = df, ggplot2::aes_string(x="x",y="y"), color="blue")
  }
  
  df = data.frame(x = Kernels, y=Posteriors[,1])
  gPlot = gPlot + ggplot2::geom_line(data = df, ggplot2::aes_string(x="x",y="y"), color="green")
  df = data.frame(x = Kernels, y=Posteriors[,2])
  gPlot = gPlot + ggplot2::geom_line(data = df, ggplot2::aes_string(x="x",y="y"), color="red")
   # hold on; plot(Kernels,PDataGivenClass(:,i)*Weights(i)/Pmax,'b-');hold off;
  # end;% i = 1:AnzMixtures
  # hold on; plot(Kernels,Posteriors(:,1),'g-');hold off;
  # hold on; plot(Kernels,Posteriors(:,2),'r-');hold off;
    # xlabel('Data');ylabel('ro/gn=Bayes Entscheidung, bl= GMM');
 # title(['Bayes fuer zwei GMM , Ind1 = ' num2str(Ind1')]);
# end; % if PlotIt ==1;
  print(gPlot)
}


# jetzt zurueck auf Daten
UNsortInd <- match(Data, Kernels) # Data == Kernels[UNsortInd]
Posteriors <- PClassGivenData[UNsortInd,]
NormalizationFactor <- NormalizationFactor[UNsortInd]

res <- list(Posteriors = Posteriors, NormalizationFactor = NormalizationFactor)
return(res)

}


