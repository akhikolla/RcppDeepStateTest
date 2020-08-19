KStestMixtures=function(Data,Means,SDs,Weights,IsLogDistribution=Means*0,PlotIt=FALSE,UpperLimit=max(Data,na.rm=TRUE),Silent=T){
# res= KStestMixtures(Data,Means,SDs,Weights,IsLogDistribution,PlotIt,UpperLimit)
# Kolmogorov-Smirnov Test Data vs a given Gauss Mixture Model
#
# INPUT
# Data(1:N)                        data points
# Means(1:L,1)                     Means of Gaussians,  L ==  Number of Gaussians
# SDs(1:L,1)                     estimated Gaussian Kernels = standard deviations
# Weights(1:L,1)                   relative number of points in Gaussians (prior probabilities): 
#
# OPTIONAL
# IsLogDistribution(1:L,1) oder 0  if IsLogDistribution(i)==1, then mixture is lognormal
#                                  default == 0*(1:L)'
# PlotIt                           do a Plot of the compared cdf's and the KS-test distribution (Diff)
# UpperLimit                       test only for Data <= UpperLimit, Default = max(Data) i.e all Data.
# Silent                           Shows progress of computation by points
# OUTPUT
# PvalueKS                         Pvalue of a suiting Kolmogorov Smirnov Test, PvalueKS==0 if PvalueKS<0.001
# DataKernels,DataCDF              such that plot(DataKernels,DataCDF) gives the cdf(Data)
# CDFGaussMixture                  such that plot(DataKernels,DataCDF) gives the cdf(Data)

# MT 2015, reimplemented from ALUs matlab version
#1.Editor: MT 03/19 deutliche effizienzsteigerung eingepflegt fuer normale gausse.
par.defaults <- par(no.readonly=TRUE)

################################
#Hilfsfunktionen
################################

################################  
################################  
#[DataCDF,DataKernels] = ecdfUnique(Data) 
dummy <- ecdf(Data) # cdf(Diff)
DataCDF <- c(0,get("y", envir = environment(dummy)))
DataKernels <- c(knots(dummy)[1],knots(dummy))#CDFuniq# cdf(Data)

CDFGaussMixture = CDFMixtures(DataKernels,Means,SDs,Weights,IsLogDistribution)$CDFGaussMixture # cdf(GMM)


# UpperLimit bereucksichtigen, alles auf <=UpperLimit kuerzen
Data=Data[Data<=UpperLimit]
Ind = which(DataKernels<=UpperLimit, arr.ind=T)
DataKernels    = DataKernels[Ind]
DataCDF        = DataCDF[Ind]
CDFGaussMixture= CDFGaussMixture[Ind]


# KS messgroesse bestimmen
CDFdiff = abs(CDFGaussMixture-DataCDF)         # Unterschied = KS- testgroesse
MaxDiff= max(CDFdiff,na.rm=TRUE)              # wo steckt der groesste Unterschied
MaxInd=which(CDFdiff==MaxDiff, arr.ind=T)
KernelMaxDiff   = DataKernels[MaxInd]         # wo steckt der groesste Unterschied
DataCDFmaxDiff  = DataCDF[MaxInd]             # wo steckt der groesste Unterschied
GMMCDFmaxDiff   = CDFGaussMixture[MaxInd]      # wo steckt der groesste Unterschied

regularize.values_spec <- function(x, y,HandleTiesFUN=meanC) {
  #MT: not necessary for this special case
  # x <- xy.coords(x, y, setLab = FALSE) # -> (x,y) numeric of same length
  # y <- x$y
  # x <- x$x
  # if(any(na <- is.na(x) | is.na(y))) {
  #   ok <- !na
  #   x <- x[ok]
  #   y <- y[ok]
  # }
  nx <- length(x)

  o <- order(x)
      x <- x[o]
      y <- y[o]

    if (length(ux <- unique(x)) < nx) {
      # tapply bases its uniqueness judgement on character representations;
      # we want to use values (PR#14377)
      #y <- as.vector(tapply(y, match(x,x), meanC))# as.v: drop dim & dimn.
      #MT: not necessary for this secial case
     
      y <- tapply(y, match(x,x), HandleTiesFUN)
     
      #requireNamespace('fastmatch')
      #fmatch is also slower
      #y <- tapply(y, fastmatch::fmatch(x,x), HandleTiesFUN)
      #slower
     # y <- as.vector(fastmatch::ctapply(y, match(x,x), meanC))# 
      x <- ux
      #mt:not necessary
      #stopifnot(length(y) == length(x))# (did happen in 2.9.0-2.11.x)
    }

  list(x=x, y=y)
}

             
# Die Miller Funktion via Monte-Carlo errechnen
AnzData =length(Data)
AnzRepetitions = 1000
if(AnzData<1000) AnzRepetitions = 2000
if(AnzData<100)  AnzRepetitions = 5000
    
RandGMMDataDiff = matrix(0,AnzRepetitions,1)
Ri=sapply(1:AnzRepetitions, function(i,...) return(RandomLogGMM(...)),Means,SDs,Weights,IsLogDistribution,AnzData)

for(i in c(1:AnzRepetitions)){
   #R = RandomLogGMM(Means,SDs,Weights,IsLogDistribution,AnzData)
   R = Ri[,i]
   #[RandCDF,RandKernels] = ecdfUnique(R)
   dummy <- ecdf(R) # cdf(Diff)
   RandCDF <- c(0,get("y", envir = environment(dummy)))
   RandKernels <- c(knots(dummy)[1],knots(dummy))#CDFuniq# cdf(Data)
   #
   #RandCDF =  interp1(RandKernels,RandCDF,DataKernels, 'linear') #matlab
   #MT: resolves ties, order values 
   regval <- regularize.values_spec(RandKernels, RandCDF) # -> (x,y) numeric of same length
   y <- regval$y
   x <- regval$x
   #MT: then approx is very fast
   RandCDF = approx(x,y,DataKernels, 'linear')$y  # den MaxDiff in cdf(Diff) lokalisieren
   
   RandGMMDataDiff[i] = max(abs(CDFGaussMixture-RandCDF),na.rm=TRUE)
   if(!Silent){
     #if(Sys.info()['sysname'] == 'Windows'){
      # if(i==1)
       #   pb <- winProgressBar(title = "progress bar", min = 0,
     #                           max = AnzRepetitions, width = 300)
     #  setWinProgressBar(pb, i, title=paste( round(i/AnzRepetitions*100, 0),"% done"))
     #  if(i==AnzRepetitions) close(pb)
    # }else{
       if(i %%10==0){
         cat('.')
       }
    # }                                      
   }
}# for i
AllDiff =  RandGMMDataDiff#[is.finite(RandGMMDataDiff)]                     # die Verteilung aller Differenzen
#matlab
#[AllDiffCDF,AllDiffKenels] =  ecdfUnique(AllDiff);  # cdf(Diff)
#R
dummy <- ecdf(AllDiff) # cdf(AllDiff) ##Berechnet eine Funktion
# AllDiffCDF <- c(0,get("y", envir = environment(dummy)))
# AllDiffKernels <- c(knots(dummy)[1],knots(dummy))#CDFuniq# cdf(Data)
##Extrahiert aus der Funktion die x und y Werte
AllDiffCDF=environment(dummy)$y
AllDiffKernels=environment(dummy)$x
#matlab
#MaxDiffCDFwert = interp1([0;AllDiffKenels],[0;AllDiffCDF],MaxDiff, 'linear');  # den MaxDiff in cdf(Diff) lokalisieren
#R
regval <- regularize.values_spec(rbind(0,unname(AllDiffKernels)), rbind(0,unname(AllDiffCDF))) # -> (x,y) numeric of same length
y1 <- regval$y
x1 <- regval$x
MaxDiffCDFwert = approx(x1,y1,xout=MaxDiff, 'linear')$y  # den MaxDiff in cdf(Diff) lokalisieren

#MaxDiffCDFwert = linearapprox(rbind(0,unname(AllDiffKernels)),rbind(0,unname(AllDiffCDF)),MaxDiff,)  # den MaxDiff in cdf(Diff) lokalisieren
#print(MaxDiffCDFwert)
if(is.na(MaxDiffCDFwert)){ ##Wenn nicht approximierbar
  if(MaxDiff>max(AllDiffKernels,na.rm=T)){#Wenn Ursache daran liegt, das kein x-werte gefunden werden kann (zu weit nach rechts in der ecdf)
    MaxDiffCDFwert=1
    PvalueKS=MaxDiffCDFwert
  }else if(MaxDiff<min(AllDiffKernels,na.rm=T)){#Wenn Ursache daran liegt, das kein x-werte gefunden werden kann (zu weit nach rechts in der ecdf)
    MaxDiffCDFwert=0
    PvalueKS=MaxDiffCDFwert
  }else{
    warning('Pvalue could not be computed, something went wrong')
    PvalueKS=NaN
  }
}else{ #Standardfall
  PvalueKS = MaxDiffCDFwert                        # P- value fuer KS-test ausrechnen
  PvalueKS = round(PvalueKS,3)                     # runden auf 3 gueltige stellen
  
} 
  
  


Controls=list(MaxDiffCDFwert=MaxDiffCDFwert,AllDiffKernels=AllDiffKernels,AllDiffCDF=AllDiffCDF,AllDiff=AllDiff)

if(PlotIt ==1){
  tryCatch({
  par.defaults <- par(no.readonly=TRUE)
  par(mfrow = c(2,2))

  xlim=c(min(DataKernels,na.rm = T), max(DataKernels,na.rm = T))
  #ylim=c(min(min(DataCDF,na.rm = TRUE),min(CDFGaussMixture,na.rm = TRUE)),max(max(DataCDF,na.rm = TRUE),max(CDFGaussMixture,na.rm = TRUE)))
  ylim=c(0,1)
  plot(DataKernels,DataCDF,col='blue',xlim=xlim,ylim=ylim,xlab="",ylab="",axes=FALSE)
  points(DataKernels,CDFGaussMixture,col='red',type='l',lwd=2)
  
  points(KernelMaxDiff,DataCDFmaxDiff,col='green',pch=1)
  points(KernelMaxDiff,GMMCDFmaxDiff,col='green',pch=1)
  abline(v=KernelMaxDiff,col='green')
  axis(1,xlim=xlim,col="black",las=1) #x-Achse
  axis(2,ylim=ylim,col="black",las=1) #y-Achse
  title('KS-test: comparison CDF(GMM) vs CDF(Data)',xlab='Data',ylab='red =CDF(GMM), blue=CDF(Data)');
  
  #     subplot(2,2,2);   # hier die fraglichen PDFs zeichnen
  PlotMixtures(Data,Means,SDs,Weights,IsLogDistribution=IsLogDistribution,xlim=xlim,xlab='',ylab='',SingleGausses = T,SingleColor='magenta',MixtureColor='blue')
  title(paste0('max(Diff) at: ',KernelMaxDiff),xlab='Data',ylab='pdf(GMM), red= pdf(Data)')
  abline(v=KernelMaxDiff,col='green')
#     subplot(2,2,3);
			pdeVal2        <- DataVisualizations::ParetoDensityEstimation(AllDiff)
			xlim=c(min(MaxDiff*0.90,pdeVal2$kernels,na.rm = T),max(pdeVal2$kernels,na.rm = T))
			ylim=c(0,1.05*max(pdeVal2$paretoDensity,na.rm = T))
			plot(pdeVal2$kernels,pdeVal2$paretoDensity,type='l',xaxs='i',
			yaxs='i',xlab='MaxDiff, mag = max(Diff)',ylab='pdf(KS-MaxDiff)',main='KS-Distribution of MaxDiff',xlim=xlim,col='blue',ylim=ylim) 
      abline(v=MaxDiff,col='magenta')
      box()
#     subplot(2,2,4);
      xlim=c(min(MaxDiff*0.90,AllDiffKernels,na.rm = T),max(AllDiffKernels,na.rm = T))
      ylim=c(min(MaxDiffCDFwert*0.90,AllDiffCDF,na.rm = T),max(AllDiffCDF,na.rm = T))
      tryCatch({
        plot(AllDiffKernels,AllDiffCDF,type='p',ylab='cdf(KS-MaxDiff)',xlab='Diff, mag = max(Diff)',main=   paste0('Pvalue: ',100-PvalueKS*100,' [#]'),ylim=ylim,xlim=xlim,col='blue')
      },er=function(ex){
        plot(AllDiffKernels,AllDiffCDF,type='p',ylab='cdf(KS-MaxDiff)',xlab='Diff, mag = max(Diff)',main=   paste0('Pvalue: ',100-PvalueKS*100,' [#]'),col='blue')
      })
      abline(v=MaxDiff,col='magenta')
      #abline(a=c(MaxDiffCDFwert,MaxDiffCDFwert),b=c(0,MaxDiff))
      abline(h=MaxDiffCDFwert,col='magenta')
      box()
      par(par.defaults)
  },er=function(ex){
    return(list(PvalueKS=PvalueKS,DataKernels=DataKernels,DataCDF=DataCDF,CDFGaussMixture=CDFGaussMixture,Controls))
  })
} #if PlotIt ==1
    #kleiner Pvalue: schlecht
		#grosser pvalue: gut
		par(par.defaults)
return(invisible(list(PvalueKS=1-PvalueKS,DataKernels=DataKernels,DataCDF=DataCDF,CDFGaussMixture=CDFGaussMixture,Controls)))
}


