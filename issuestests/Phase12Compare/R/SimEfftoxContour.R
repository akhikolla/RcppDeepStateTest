#'Simulates trial replications from the Efftox model with desirability optimality function.
#'
#'Simulates replications from a Bayesian adaptive phase 12 clinical trial design using the Efftox model and a optimality function based on the desirability tradeoff contour.
#'@param NSims Number of trial simulations to run.
#'@param Dose Logarithm of raw dose levels - the average logarithm of the raw dose levels.
#'@param PE True efficacy probability for each dose.
#'@param PT True toxicity probaiblity for each dose.
#'@param corET Correlation parameter between efficacy and toxicity probability.
#'@param Nmax Maximum trial sample size.
#'@param cohort Patient cohort size.
#'@param Contour Contour vector for desirability function. Contains in order: (pi_{1,E},pi_{2,T},pi_{3,E},pi_{4,T}).
#'@param CutE Cutoff for efficacy probability acceptability. Dose-efficacy probabilities must be larger than this for patient assignment.
#'@param CutT Cutoff for toxicity probability acceptability. Dose-toxicity probabilities must be smaller than this for patient assignment.
#'@param AcceptE Posterior probability threshold for efficacy acceptability.
#'@param AcceptT Posterior probability threshold for toxicity acceptability.
#'@param HypermeansEFF Hypermeans for the Efftox model. In order, entries are hypermeans for (beta_{0,E},beta_{1,E},beta_{2,E},beta_{0,T},beta_{1,T},psi).
#'@param HypervarsEFF Hypervariances for the Efftox model. In order, entries are hypervariances for (beta_{0,E},beta_{1,E},beta_{2,E},beta_{0,T},beta_{1,T},psi).
#'@return A list with the first entry corresponding to a matrix with: (1) True toxicity probabilities at each dose, (2) True efficacy probabilities at each dose, (3) True Desirability of each dose, (4) Optimal dose selection probability, (5) Average sample size of patients treated at each dose. The second entry of the list contains a vector with rows corresponding to (1) the true binary bivariate correlation between efficacy and toxicity, (2) Stopping probability of the trial, (3) Average number of efficacy events, (4) Average number of toxicity events, and (5) Delta.
#'@importFrom mvtnorm rmvnorm dmvnorm pmvnorm
#'@importFrom stats rnorm runif var pnorm qnorm
#'@examples
#'library(mvtnorm)
#'##True toxicity probability
#'PT=c(.05,.10,.15,.20,.30)
#'##True Efficacy Probability
#'PE=c(.2,.4,.6,.65,.7)
#'#True Correlation
#'corET=.5
#'##Number of simulations
#'NSims=1 ##Increase this when using
#'##Hypermeans and hypervariances
#'HypermeansEFF = c(.022,3.45,0,-4.23,3.1,0)
#'HypervarsEFF = c(2.6761, 2.6852, .2, 3.1304, 3.1165, 1)
#'HypervarsEFF=HypervarsEFF^2
#'##Trial Parameters
#'##Cohort Size, N^F and N_ET
#'cohort=3
#'##Starting Dose
#'DoseStart=1
#'##Vector of Numerical Doses
#'Dose = c(1,2,3,3.5,5)
#'##Dose for Eff-Tox
#'Dose=log(Dose)-mean(log(Dose))
#'Nmax=30 ##Max Sample Size
#'#Acceptability Criterion
#'CutE=.3
#'CutT=.4
#'##Limits on acceptability
#'AcceptE=.1
#'AcceptT=.1
#'##Contour vector
#' Contour = c(.35, .75,.7,.4)
#' RESULTS=SimEfftoxContour(NSims, Dose,PE,  PT, corET,
#' Nmax, cohort, Contour, CutE, CutT, AcceptE,AcceptT,  HypermeansEFF, HypervarsEFF)
#' RESULTS
#'@export
SimEfftoxContour=function(
  NSims, ##Number of simulations
  Dose, ##logdoses
  PE, ##True Efficacy Probability for each dose
  PT, ##True toxicity probaiblity for each dose
  corET, ##Correlation parameter between Eff and Tox
  Nmax, ##MAximum Sample size
  cohort, ##Cohort Size
  Contour, ##Contour vector
  CutE, ##Cutoff For efficacy acceptability
  CutT, ##Cutoff for toxicity acceptability
  AcceptE, ##Probability threshold for eff acceptability
  AcceptT, ##Probability threshold for tox acceptability
  HypermeansEFF, ##Hypermeans for
  HypervarsEFF ##Hypervariances
){


  NF=Nmax
  Hypermeans = HypermeansEFF
  Hypervars=HypervarsEFF




  nDose=length(Dose)



  TRUEUT=rep(NA,nDose)

  ##Calculate the True Utility Scores at each dose level
  TRUEUT=rep(NA,nDose)



  Sigma=matrix(c(1,corET,
                 corET, 1), nrow=2, byrow=TRUE)
  PMAT=Sigma

  MeanUT=rep(0,nDose)
  PROBS=matrix(rep(NA,4*nDose),ncol=4)
  for(D in 1:nDose){
    MU=c(qnorm(PE[D]),qnorm(PT[D]))
    ##YE,YT=0,0
    lower <- rep(-Inf, 2)
    upper <- rep(0, 2)
    PMAT[1,1] <- pmvnorm(lower, upper, MU, sigma=Sigma)
    PROBS[D,1]=PMAT[1,1]
    ##YE,YT=0,1
    lower <- c(-Inf,0)
    upper <- c(0,Inf)
    PMAT[2,1] <- pmvnorm(lower, upper, MU, sigma=Sigma)
    PROBS[D,3]=PMAT[2,1]
    ##YE,YT = 1,0
    lower <- c(0,-Inf)
    upper <- c(Inf,0)
    PMAT[1,2] <- pmvnorm(lower, upper, MU, sigma=Sigma)
    PROBS[D,2]=PMAT[1,2]
    ##YE, YT = 1,1
    lower <- c(0,0)
    upper <- c(Inf,Inf)
    PMAT[2,2] <- pmvnorm(lower, upper, MU, sigma=Sigma)
    PROBS[D,4]=PMAT[2,2]





  }


  TRUEUT=MeanUT



  PiLim=c(CutE,CutT)
  ProbLim=c(AcceptE,AcceptT)
  B=2000




  NumTrt=matrix(rep(0,nDose*NSims),nrow=NSims)

  ##Setup Simulation parameters
  SIMSTORE = as.list(rep(0,NSims))

  DoseOpt=rep(0,NSims)
  NTox = rep(0,NSims)
  NEff=rep(0,NSims)

  DoseStore=rep(0,Nmax)
  YEStore = rep(0,Nmax)
  YTStore =rep(0,Nmax)

  NF=Nmax

  ##No correlation
  for(m1 in 1:NSims){


    List=  RunAdaptiveEffToxTrialCORRCONTOUR(1,Dose, Hypermeans,  Hypervars,
                                             Contour, PiLim, ProbLim,  cohort, Nmax,  NF, B, 1,
                                             PROBS )


    Doses=List[[3]][,1]+1
    YE=List[[3]][,2]
    YT=List[[3]][,3]
    OptDose=List[[1]]


    ##This simulation doesn't count now.


    NTox[m1]=sum(YT)
    NEff[m1]=sum(YE)
    DoseOpt[m1]=OptDose

    for(j in 1:nDose){
      NumTrt[m1,j]=sum(Doses==j)
    }



  }

  ##Calculate True Accept
  TRUECEPT = (PE>=CutE)*(PT<=CutT)
  ##These are the doses that are truly acceptable

  ##Calculate the true desireability



  ##Shift Desire to 0-100 range
  desire=TRUEUT

  for(j in 1:length(desire)){
    desire[j]=GetDesire(PE[j],PT[j],Contour)
  }

  ##desire = 50*desire+50

  desire = 100*(desire - GetDesire(0,1,Contour))/(1-GetDesire(0,1,Contour))


  TRUECEPT = (PE>=CutE)*(PT<=CutT)
  ##These are the doses that are truly acceptable



  prob1=rep(0,nDose)

  for(j in 1:nDose){
    prob1[j]=mean(DoseOpt==j)
  }

  X=rbind(1:nDose,round(PT,2),round(PE,2),TRUECEPT,round(desire,2),prob1,round(colMeans(NumTrt),2))
  rownames(X)=c("Dose #","True Toxicity Probability:","True Efficacy Probability:",
                "Is the dose acceptable?", "True Desirability:",
                "Dose Selection Probability:", "Average # Treated:")
  colnames(X)=1:nDose


  Z=as.list(c(0,0))

Z[[1]]=X

##Next we need the Single values

X1=c(mean(DoseOpt==0),mean(NEff),mean(NTox))


  TRUECEPT = (PE>=CutE)*(PT<=CutT)

  ##Utilities of ACCEPTABLE doses
  U1=desire*TRUECEPT



X1=c(corET,X1,round(sum(prob1*(U1-min(U1))/(max(U1)-min(U1))),2))
X1=as.matrix(X1)
rownames(X1)=c("CorET","P[Stop]","NEff","NTox","Delta")

Z[[2]]=X1
return(Z)




}
