#' Assigns next patient cohort based on the Efftox model with a Utility based objective function.
#'
#' Provides the optimal dose level as determined by the Efftox model, posterior mean toxicity probability, efficacy probability, and mean utility of each dose level. Doses that are unacceptably toxic or inefficous have a utility of 0.
#' @param YE Length n binary indicator vector of efficacy status.
#' @param YT Length n binary indicator vector of toxicity status.
#' @param Doses Length n vector of integer Doses given to patients.
#' @param Dosetried Binary vector corresponding to which doses have been tried.
#' @param HypermeansEFF Hypermeans for the Efftox model. In order, entries are hypermeans for (beta_{0,E},beta_{1,E},beta_{2,E},beta_{0,T},beta_{1,T},psi).
#' @param HypervarsEFF Hypervariances for the Efftox model. In order, entries are hypervariances for (beta_{0,E},beta_{1,E},beta_{2,E},beta_{0,T},beta_{1,T},psi).
#' @param B Number of iterations to run for the MCMC.
#' @param cohort Cohort size for the trial.
#' @param Dose Vector of standardized log-dose levels considered in the trial.
#' @param UT Utility matrix for the four bivariate (efficacy, toxicity) events.
#' @param CutE Cutoff for efficacy probability acceptability. Dose-efficacy probabilities must be larger than this for patient assignment.
#' @param CutT Cutoff for toxicity probability acceptability. Dose-toxicity probabilities must be smaller than this for patient assignment.
#' @param AcceptE Posterior probability threshold for efficacy acceptability.
#' @param AcceptT Posterior probability threshold for toxicity acceptability.
#' @return A list containing the optimal dose level to assign the next patient cohort in the first entry and a matrix in the second entry, with rows corresponding to (1) the dose #, (2) mean posterior toxicity probability at each dose, mean posterior efficacy probability at each dose, and acceptable posterior utility score of each dose level (0s indicate the dose is not acceptably efficous or toxic).
#' @examples
#' ##Get the Data
#' ##True Tox Prob
#' PT = c(.1,.2,.25,.5,.7)
#' ##True EFF Prob
#' PE = c(.3,.4,.7,.5,.5)
#' Doses=c(1,1,1,2,2,2,3,3,3,2,2,2,1,1,1,2,2,2,3,3,3)
#' YE=Doses
#' YT=Doses
#' Dosetried=rep(0,length(PE))
#' ##Generate data
#' for(k in 1:length(PE)){
#' if(sum(Doses==k)){
#'##Dose level has been tried
#'Dosetried[k]=1
#'YE[Doses==k]=rbinom(sum(Doses==k),1,PE[k])
#'YT[Doses==k]=rbinom(sum(Doses==k),1,PT[k])
#'}
#'}
#'##Hypermeans and hypervariances
#'HypermeansEFF = c(.022,3.45,0,-4.23,3.1,0)
#'HypervarsEFF = c(2.6761, 2.6852, .2, 3.1304, 3.1165, 1)
#'HypervarsEFF=HypervarsEFF^2
#'##Vector of Numerical Doses
#'Dose = c(1,2,3,3.5,5)
#'##Dose for Eff-Tox
#'Dose=log(Dose)-mean(log(Dose))
#'##Trial parameters
#'cohort=3
#'##Utility Matrix
#'UT = matrix(c(38.23529,100,0,61.76471),nrow=2,byrow=TRUE)
#'CutE=.3 ##Efficacy threshold
#'CutT=.4 ##Toxicity threshold
#'AcceptE=.3 ##Eff acceptability threshold
#'AcceptT= .3 ##Tox acceptability threshold
#'B=100##Number of iterations
#'GetEfftoxUt(YE, YT,Doses,Dose, Dosetried,
#'cohort, UT,CutE, CutT, AcceptE, AcceptT,
#'HypermeansEFF, HypervarsEFF,B )
#'@export
GetEfftoxUt=function(
  YE, ##Length n vector of patient efficacy outcomes.
  YT, ##Length n vector of patient toxicity outcomes.
  Doses, ##Length n vector of patient dose # assignments.
  Dose, ##Standardized log dose values
  Dosetried, ##Binary vector corresponding to which doses have been tried.
  cohort, ##Cohort Size
  UT, ##Contour Vector
  CutE, ##Cutoff For efficacy acceptability
  CutT, ##Cutoff for toxicity acceptability
  AcceptE, ##Probability threshold for eff acceptability
  AcceptT, ##Probability threshold for tox acceptability
  HypermeansEFF, ##Hypermeans for
  HypervarsEFF, ##Hypervariances
  B
){
  NSkip=0  ##Will  count the number of skipped simulations
  DosesTried=Dosetried

  nDose=length(Dose)



  PiLim=c(CutE,CutT)
  ProbLim=c(AcceptE,AcceptT)


  Z=  AssignEffToxUT(YE,YT, Doses, Dose, Dosetried, HypermeansEFF,  HypervarsEFF, UT, PiLim,  ProbLim, B )

  desire=Z[[2]]


  PE=Z[[3]]
  PT=Z[[4]]


  #  ACCEPTE[which(sum(Doses)<cohort)]=1
  MeanUT=pmax(desire,0)



  if(sum(MeanUT)==0 && (length(YE)>2*cohort)){
    OptDose=0

  }else{


    ##Multiply MeanUT by accept

    ##Adaptive Randomization?


    OptDose = ReturnOpt(MeanUT,Dosetried)+1

    Dosetried[OptDose]=1


  }






  X=rbind(1:length(PT),t(round(PT,2)),t(round(PE,2)),t(round(MeanUT,2)))
  rownames(X)=c("Dose #","Posterior Mean Toxicity Probability:",
                "Posterior Mean Efficacy Probability:",
                "Posterior Mean Utility:")


  if(sum(MeanUT)==0){
    message("Warning: Stop the trial, all doses are too toxic or inefficous.")
  }


  Z=list(c(0,0))
  names(OptDose)="Optimal Dose"
  Z[[1]]=OptDose
  Z[[2]]=X
  return(Z)








}
