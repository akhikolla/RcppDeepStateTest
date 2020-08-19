Intersect2Mixtures <- function(Mean1,SD1,Weight1,Mean2,SD2,Weight2,IsLogDistribution = c(FALSE,FALSE),MinData,MaxData){
  #  [CutX,CutY] = Intersect2Mixtures(Mean1,SD1,Weight1,Mean2,SD2,Weight2,IsLogDistribution);
  # INPUT
  # Mean1,SD1,Weight1,Mean2,SD2,Weight2        parameters of the gaussians
  # OPTIONAL 
  # IsLogDistribution(1:2)   ==1 if distribution(i) is a LogNormal, default c(0,0)
  # OUTPUT
  # CutX, CutY               [CutX, CutY] is where N1 == N2
  
  #  Author: RG
  # 1.Editor: MT 08/2015
  #  in /dbt/BayesDecision/
  
  M = c(Mean1,Mean2) 
  S = c(SD1,SD2)
  X0 = min(M)
  MinInd = which(M==X0,arr.ind=TRUE)
  X1 = max(M)
  MaxInd = which(M==X1,arr.ind=TRUE)

  if(missing(MinData)){
    X0 = X0-2*S[MinInd]
  }else{
    X0 = MinData
  }
  
  if(missing(MaxData)){
    X1 = X1+2*S[MaxInd]
  } else{
    X1 = MaxData
  }
  
  if(abs(Mean1-Mean2) < 0.00001){ # no differences in mean
    CutX = Mean1   
    CutY = 1
  }
  
  
  else if((Weight1 == 0) |  (Weight2 == 0)){
    CutX=NA 
    CutY=NA 
  }
  
  else{
    # simple solution: look at NrOfIteration points between Modi
    NrOfIteration = 20000
    dx = (X1- X0)/NrOfIteration
    X = seq(from = X0, to = X1, by = dx)
    # X sind Werte an denen die Gaussians ausgewertet werden
    
    if(IsLogDistribution[1] == TRUE)
      N1 = Symlognpdf(X,Mean1,SD1)*Weight1 # LogNormal 
    else # N1 ist normalverteilt
      N1 = dnorm(X,Mean1,SD1)*Weight1  # Gauss
    
    
    if(IsLogDistribution[2] == TRUE)
      N2 = Symlognpdf(X,Mean2,SD2)*Weight2 # LogNormal 
    else # N2 ist normalverteilt
      N2 = dnorm(X,Mean2,SD2)*Weight2  # Gauss
    
    # N1 ist die pdf von Mean1
    # N2 ist die pdf des Mean2
    Difference = N1 - N2
    Vorzeichen = unique(sign(Difference))
    AnzVorzeichen = length(Vorzeichen)
    # jetzt noch Bereucksichtigen dass die sich garnicht schneiden
    if(AnzVorzeichen < 2){ # schneiden sich nicht
      CutY = 0;
      if(Mean1 < Mean2)
        CutX = X0
      else
        CutX = X1
    }
    else{ # sie schneiden sich        
      MinDiff = min(abs(Difference))
      CutInd = which(abs(Difference)==MinDiff,arr.ind=TRUE)
      CutX = X[CutInd]
      CutY = N1[CutInd]
    }
  }
  # test  
  #  figure;plot(X,N1,'b-',X,N2,'r-'); 
  #  vline(CutX); hline(CutY)
  
  return(list(CutX=CutX,CutY=CutY))
}