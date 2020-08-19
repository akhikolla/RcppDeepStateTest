Bayes4Mixtures <- function(Data, Means, SDs, Weights, IsLogDistribution = 0*Means, PlotIt = FALSE, CorrectBorders = FALSE,Color=NULL,xlab='Data',lwd=4){
# V = Bayes4Mixtures(Data, Means, SDs, Weights, IsLogDistribution, PlotIt, CorrectBorders)
# Posteriors         = V$Posteriors(1:N,1:C)      #    Vektor der Posteriors      korrespondierend zu Data
# NormalizationFactor= V$NormalizationFactor(1:N) #    Nenner des Bayes Theorems  korrespondierend zu Data
#
# INPUT
# Data(1:N)            vector of data,  may contain NaN
# Means(1:C),SDs(1:C),Weights(1:C) parameters of the Gaussians (Mean, StdDeviation, Weight)
# 
# OPTIONAL
# IsLogDistribution(1:C) 1 oder 0, gibt an ob die jeweilige Verteilung eine Lognormaverteilung ist,(default ==0*(1:C))
# PlotIt              ==TRUE Verteilungen und Posteriors werden gezeichnet (default ==0);
# CorrectBorders      ==TRUE Daten an den Grenzen werden den Randverteilungen zugeordnet
#                    (default ==0) d.h. ganz gewoehnlicher Bayes mit allen seinen Problemen
# OUTPUT
# Posteriors         = V$Posteriors(1:N,1:C)      #    Vektor der Posteriors      korrespondierend zu Data
# NormalizationFactor= V$NormalizationFactor(1:N) #    Nenner des Bayes Theorems  korrespondierend zu Data
# 
# 
# AUTHOR: CL
# 1.Editor: MT 08/2015 : Plotten neu, Variablen vereinheitlicht
  
# Sortiere die Daten und merke die unsortiert-Reihenfolge
AnzMixtures <- length(Means)
Kernels <- unique(Data)
UNsortInd <- match(Data, Kernels)
AnzKernels <- length(Kernels)

# Berechne bedingte Wkeit p(x|ci) mit x = Daten[1:N] und ci = Klasse i, i aus 1 bis C
PDataGivenClass <- matrix(0,AnzKernels,AnzMixtures);
for(i in c(1:AnzMixtures)){
	if( IsLogDistribution[i] == 1 ){ # LogNormal
		PDataGivenClass[,i] <- Symlognpdf(Kernels,Means[i],SDs[i]); # LogNormaldichte. Achtung: Muss gespiegelt werden fuer negative Werte.
	}else{
		PDataGivenClass[,i] <- dnorm(Kernels,Means[i],SDs[i]); # Gaussian
	}#end if(IsLogDistribution[i] == 1)
}#end for(i in c(1:AnzMixtures))

NormalizationFactor <- PDataGivenClass %*% Weights;  # Gewichtete Summe der Priors; 
# Zum Normalisizerungsfaktor:
# Achtung: Es soll 1.Spalte mal 1.Eintrag von Weights + 2.Spalte mal 2.Eintrag von Weights usw. gerechnet werden. 
# Dazu brauchen wir Matrixmultiplikation!
# Bei PDataGivenClass * Weights wird die 1.Zeile von P... mal 1. Wert von Weights, 2.Zeile von P mal 2. Wert usw.
# gerechnet, was nicht Sinn der Sache ist!!!

Pmax = max(NormalizationFactor);

# to prevent division error:
ZeroInd <- which(NormalizationFactor==0);
if(length(ZeroInd) > 0){
	NormalizationFactor[ZeroInd] =10^(-7)
}#end if(length(ZeroInd) > 0) 

#Posterioris nach Bayes p(c|x) mit c = Klasse (ueber-, unter- oder nicht exprimiert) und x Datensatz.
PClassGivenData <- matrix(0, AnzKernels, AnzMixtures);
for(i in c(1:AnzMixtures)){
	PClassGivenData[,i] <- PDataGivenClass[,i]*Weights[i] / NormalizationFactor
}#end for(i in c(1:AnzMixtures))

if(CorrectBorders == TRUE & (sum(IsLogDistribution)==0)){ # Randkorrektuuren anbringen
	# Daten kleiner kleinstem Modus werden diesem zugeschlagen;
	KleinsterModus <- min(Means)
	SmallModInd <- which.min(Means)
	LowerInd <- which(Kernels<KleinsterModus);
	for(i in c(1:AnzMixtures)){
		PClassGivenData[LowerInd,i] <- 0;
	}#end for(i in c(1:AnzMixtures))
	PClassGivenData[LowerInd,SmallModInd] <- 1;
	# Daten groesser groesstem Modus werden diesem zugeschlagen;
	GroessterModus <- max(Means)
	BigModInd <- which.max(Means)
	HigherInd <- which(Kernels>GroessterModus);
	for(i in c(1:AnzMixtures)){
		PClassGivenData[HigherInd,i] <- 0;
	}#end for(i in c(1:AnzMixtures))
	PClassGivenData[HigherInd,BigModInd] <- 1;
}#end if(CorrectBorders == TRUE & (sum(IsLogDistribution)==0))

# jetzt zurueck auf Daten
Posteriors = matrix(0, length(Data), AnzMixtures)#;zeros(length(Data),AnzMixtures);
for(i in c(1:AnzMixtures)){
	Posteriors[,i] <- PClassGivenData[UNsortInd,i];  # fuer die Daten anpassen
}#end for(i in c(1:AnzMixtures))

# auch noch den Normalisierungsfaktor auf Datengroesse anpassen
Nenner <- NormalizationFactor;
NormalizationFactor <- NormalizationFactor[UNsortInd];

## MT: Neu gemacht
if(PlotIt==TRUE){
  if(is.null(Color))
	  color <- rainbow(AnzMixtures)
  else
    color=Color
  xlim=c(min(Data,na.rm=T),max(Data,na.rm=T))
  ylim=c(0,1.05)
	plot.new()
	par(xaxs='i')
	par(yaxs='i')
	par(usr=c(xlim,ylim))
	ind=order(Data)
  if(CorrectBorders){

    for(i in 1:AnzMixtures){
      points(Data[ind], Posteriors[ind,i], col = color[i],type='l',lwd=lwd)
    }#end for(i in 2:AnzMixtures)   
  }else{
	for(i in 1:AnzMixtures){
		points(Data[ind], Posteriors[ind,i], col = color[i],type='l',lwd=lwd)
	}#end for(i in 2:AnzMixtures)
  }
}#end if(PlotIt==TRUE)
axis(1,xlim=xlim,col="black",las=1) #x-Achse
axis(2,ylim=ylim,col="black",las=1) #y-Achse
#box() #Kasten um Graphen
title(ylab='Posteriori',xlab=xlab)
##
res <- list(Posteriors = Posteriors, NormalizationFactor=NormalizationFactor, PClassGivenData = PClassGivenData)
return (res) 
}