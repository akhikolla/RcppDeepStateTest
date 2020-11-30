#' Assigns next patient cohort based on the SPSOP model with a Utility based objective function.
#'
#' Provides the optimal dose level as determined by the SPSO model, posterior mean toxicity probability, efficacy probability, and desirability of each dose level. Doses that are unacceptably toxic or inefficous have a desirability of 0.
#' @param YE Length n binary indicator vector of efficacy status.
#' @param YT Length n binary indicator vector of toxicity status.
#' @param Doses Length n vector of integer Doses given to patients.
#' @param Dosetried Binary vector corresponding to which doses have been tried.
#' @param HypermeansE Hypermeans for dose-specific efficacy parameters.
#' @param HypermeansT Hypermeans for dose-specific toxcity parameters.
#' @param Hypervars Hypervariances needed for the SPSO model. Contains, in order (sigma_0^2, sigma_mu^2,tau).
#' @param B Number of iterations to run for the MCMC.
#' @param cohort Cohort size for the trial.
#' @param Contour Contour vector for desirability function. Contains in order: (pi_{1,E},pi_{2,T},pi_{3,E},pi_{4,T}).
#' @param CutE Cutoff for efficacy probability acceptability. Dose-efficacy probabilities must be larger than this for patient assignment.
#' @param CutT Cutoff for toxicity probability acceptability. Dose-toxicity probabilities must be smaller than this for patient assignment.
#' @param AcceptE Posterior probability threshold for efficacy acceptability.
#' @param AcceptT Posterior probability threshold for toxicity acceptability.
#' @return A list containing the optimal dose level to assign the next patient cohort in the first entry and a matrix in the second entry, with rows corresponding to (1) the dose #, (2) mean posterior toxicity probability at each dose, mean posterior efficacy probability at each dose, and acceptable posterior desirability score of each dose level (0s indicate the dose is not acceptably efficous or toxic).
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
#'##Hyperparameters
#'HypermeansE=c(-1,-.5,0,.5,1,2)
#'HypermeansT=HypermeansE
#'Hypervars=c(1,16,1)
#'##Trial parameters
#'cohort=3
#'##Contour vector
#'Contour = c(.35, .75,.7,.4)
#'CutE=.3 ##Efficacy threshold
#'CutT=.4 ##Toxicity threshold
#'AcceptE=.3 ##Eff acceptability threshold
#'AcceptT= .3 ##Tox acceptability threshold
#'B=100##Number of iterations
#'GetSpsoContour(YE,YT,Doses,Dosetried,cohort,Contour,CutE, CutT, AcceptE, AcceptT,
#'HypermeansE,  HypermeansT,Hypervars,B )
#'@export
GetSpsoContour=function(
YE, ##Length n vector of patient efficacy outcomes.
YT, ##Length n vector of patient toxicity outcomes.
Doses, ##Length n vector of patient dose # assignments.
Dosetried, ##Binary vector corresponding to which doses have been tried.
cohort, ##Cohort Size
Contour, ##Contour Vector
CutE, ##Cutoff For efficacy acceptability
CutT, ##Cutoff for toxicity acceptability
AcceptE, ##Probability threshold for eff acceptability
AcceptT, ##Probability threshold for tox acceptability
HypermeansE, ##Hypermeans for efficacy
HypermeansT, ##Hypermeans for Toxcity
Hypervars, ##Hypervariances
B ##Number of iterations for the MCMC
){
  NSkip=0  ##Will  count the number of skipped simulations



  nDose=length(HypermeansE)

  B=2000

  Z=UTEFFTOX(YE,YT, Doses, HypermeansE, HypermeansT,  Hypervars, B )

  MeanUT=rep(0,nDose)




  Sigma=matrix(c(Hypervars[1]+Hypervars[3],Hypervars[3]*mean(Z[[4]]),
                 Hypervars[3]*mean(Z[[4]]), Hypervars[1]+Hypervars[3]), nrow=2, byrow=TRUE)
  PMAT=Sigma





  PE = rep(NA,nDose)
  PT = rep(NA,nDose)




  ACCEPTE=rep(1,nDose)
  ACCEPTT=rep(1,nDose)
  ##What Doses are acceptable?
  for(D in 1:nDose){
    ##Calculate the probability of eff over all the samples
    PEFF = 1-pnorm(0,Z[[1]][,D],sqrt(Hypervars[1]+Hypervars[3]))
    ##IS THIS DOSE ACCEPTABLE IN TERMS OF EFFICACY?
    if(sum(Doses==D)>=cohort){
      ACCEPTE[D]=mean(PEFF>=CutE)>AcceptE
    }
    ##Calculate the probability of tox over all the samples
    PTOX = 1-pnorm(0,Z[[2]][,D],sqrt(Hypervars[1]+Hypervars[3]))

    ##IS THIS DOSE ACCEPTABLE IN TERM OF TOXICITY?
    ACCEPTT[D]=mean(PTOX<=CutT)>AcceptT

    PE[D]=mean(PEFF)
    PT[D]=mean(PTOX)

  }



  for(D in 1:nDose){
    MU=c(mean(Z[[1]][,D]),mean(Z[[2]][,D]))

    PEFF = 1-pnorm(0,MU[1],sqrt(Hypervars[1]+Hypervars[3]))
    PTOX = 1-pnorm(0,MU[2],sqrt(Hypervars[1]+Hypervars[3]))

    MeanUT[D]=GetDesire(PEFF,PTOX,Contour)

  }

desire=MeanUT

  MeanUT = 100*(desire - GetDesire(0,1,Contour))/(1-GetDesire(0,1,Contour))






  #  ACCEPTE[which(sum(Doses)<cohort)]=1

  if(sum(ACCEPTE*ACCEPTT)==0 && (length(YE)>2*cohort)){
    OptDose=0

  }else{


    ##Multiply MeanUT by accept

    ##Adaptive Randomization?



    for(j in 1:nDose){
      if(ACCEPTT[j]*ACCEPTE[j]==0){
        MeanUT[j]=-1000

      }




    }

    OptDose = ReturnOpt(MeanUT,Dosetried)+1

    Dosetried[OptDose]=1


  }


  MeanUT=pmax(MeanUT,0)

  X=rbind(1:length(PT),t(round(PT,2)),t(round(PE,2)),t(round(MeanUT,2)))
  rownames(X)=c("Dose #","Posterior Mean Toxicity Probability:",
                "Posterior Mean Efficacy Probability:",
                "Posterior Mean Desirability:")

  if(sum(MeanUT)==0){
    message("Warning: Stop the trial, all doses are too toxic or inefficous.")
  }
  names(OptDose)="Optimal Dose"
  Z=list(c(0,0))
  Z[[1]]=OptDose
  Z[[2]]=X
  return(Z)




}
