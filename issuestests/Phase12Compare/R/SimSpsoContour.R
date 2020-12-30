#'Simulates trial replications from the SPSO model with desirability optimality function.
#'
#'Simulates replications from a Bayesian adaptive phase 12 clinical trial design using the SPSO model and a optimality function based on the desirability tradeoff contour.
#'@param NSims Number of trial simulations to run.
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
#'@param HypermeansE Hypermeans for dose-specific efficacy parameters.
#'@param HypermeansT Hypermeans for dose-specific toxcity parameters.
#'@param Hypervars Hypervariances needed for the SPSO model. Contains, in order (sigma_0^2, sigma_mu^2,tau).
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
#'HypermeansE=c(-1.189, -0.357,  0.360,  0.546,  0.743)
#'HypermeansT=c(-2.325, -1.811, -1.464, -1.189, -0.740)
#'Hypervars=c(1,16,1)
#'##Trial Parameters
#'##Cohort Size, N^F and N_ET
#'cohort=3
#'##Starting Dose
#'DoseStart=1
#'Nmax=30 ##Max Sample Size
#'#Acceptability Criterion
#'CutE=.3
#'CutT=.4
#'##Limits on acceptability
#'AcceptE=.1
#'AcceptT=.1
#'##Contour vector
#'Contour = c(.35, .75,.7,.4)
#'RESULTS=SimSpsoContour(NSims, PE, PT, corET, Nmax, cohort, Contour,
#'CutE, CutT, AcceptE, AcceptT,HypermeansE, HypermeansT, Hypervars)
#'RESULTS
#'@export
SimSpsoContour=function(
  NSims, ##Number of simulations
  PE, ##True Efficacy Probability for each dose
  PT, ##True toxicity probaiblity for each dose
  corET, ##Correlation parameter between Eff and Tox
  Nmax, ##MAximum Sample size
  cohort, ##Cohort Size
  Contour, ##Contour
  CutE, ##Cutoff For efficacy acceptability
  CutT, ##Cutoff for toxicity acceptability
  AcceptE, ##Probability threshold for eff acceptability
  AcceptT, ##Probability threshold for tox acceptability
  HypermeansE, ##Hypermeans for efficacy
  HypermeansT, ##Hypermeans for Toxcity
  Hypervars ##Hypervariances
){
  NSkip=0  ##Will  count the number of skipped simulations
  NF=Nmax
  nDose=length(HypermeansE)


  NumTrt=matrix(rep(NA,nDose*NSims),nrow=NSims)

  CORMAT <- matrix(c(1,corET,corET,1), ncol=2)
  CORRMAT=CORMAT

  Z1=CORMAT

  ##Calculate the True Utility Scores at each dose level
  TRUEUT=rep(NA,nDose)



  Sigma=matrix(c(1,corET,
                 corET, 1), nrow=2, byrow=TRUE)
  PMAT=Sigma

  MeanUT=rep(0,nDose)


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



  ##Setup Simulation parameters
  SIMSTORE = as.list(rep(0,NSims))

  DoseOpt=rep(NA,NSims)
  NTox = rep(NA,NSims)
  NEff=rep(NA,NSims)

  DoseStore=rep(NA,Nmax)
  YEStore = rep(NA,Nmax)
  YTStore =rep(NA,Nmax)

  B=2000


  for(m1 in 1:NSims){

    if(m1%%1000==0){

      cat(paste(m1,"Simulations
                ",sep="  "))

    }


    Dosetried=c(1,rep(0,nDose-1))

    ##Start at lowest dose
    Doses=rep(1,cohort)

    OUT <- GETBIN(PROBS[1,])

    YE=OUT[1]
    YT=OUT[2]
    if(cohort>1){
      for(i in 2:cohort){
        OUT <- GETBIN(t(PROBS[1,]))

        YE=c(YE,OUT[1])
        YT=c(YT,OUT[2])
      }
    }
    ##Ok now we have the starting values





    for(i in 2:(Nmax/cohort)){


      Z=UTEFFTOX(YE,YT, Doses, HypermeansE, HypermeansT,  Hypervars, B )
      MeanUT=rep(0,nDose)



      Sigma=matrix(c(Hypervars[1]+Hypervars[3],Hypervars[3]*mean(Z[[3]]),
                     Hypervars[3]*mean(Z[[3]]), Hypervars[1]+Hypervars[3]), nrow=2, byrow=TRUE)
      PMAT=Sigma
      MeanUT=rep(0,nDose)


      for(D in 1:nDose){
        MU=c(mean(Z[[1]][,D]),mean(Z[[2]][,D]))

        PEFF = 1-pnorm(0,MU[1],sqrt(Hypervars[1]+Hypervars[3]))
        PTOX = 1-pnorm(0,MU[2],sqrt(Hypervars[1]+Hypervars[3]))

        MeanUT[D]=GetDesire(PEFF,PTOX,Contour)

      }








      ACCEPTE=rep(1,nDose)
      ACCEPTT=rep(1,nDose)
      ##What Doses are acceptable?
      for(D in 1:nDose){
        ##Calculate the probability of eff over all the samples
        PEFF = 1-pnorm(0,Z[[1]][,D],sqrt(Hypervars[1]+Hypervars[3]))
        if(sum(Doses==D)>=cohort){
          ##IS THIS DOSE ACCEPTABLE IN TERMS OF EFFICACY?
          ACCEPTE[D]=mean(PEFF>=CutE)>AcceptE
        }
        ##Calculate the probability of tox over all the samples
        PTOX = 1-pnorm(0,Z[[2]][,D],sqrt(Hypervars[1]+Hypervars[3]))

        ##IS THIS DOSE ACCEPTABLE IN TERM OF TOXICITY?
        ACCEPTT[D]=mean(PTOX<=CutT)>AcceptT

      }
      ## ACCEPTE[which(sum(Doses)<cohort)]=1


      if(sum(ACCEPTE*ACCEPTT)==0 && i>2){
        OptDose=0

        break


      }else{


        ##Multiply MeanUT by accept


        for(j in 1:nDose){
          if(ACCEPTE[j]*ACCEPTT[j]==0){
            MeanUT[j]=-1000
          }}
        ##Assign Next Dose Deterministically
        OptDose = ReturnOpt(MeanUT,Dosetried) +1
        Dosetried[OptDose]=1



        ##Now enroll the next three patients
        Doses=c(Doses,rep(OptDose,cohort))
        #What are their binary outcomes

        for(m in 1:cohort){
          OUT <- GETBIN(PROBS[OptDose,])

          YE=c(YE,OUT[1])
          YT=c(YT,OUT[2])
        }




      }



    }




    if(OptDose==0){
      NSkip=NSkip+1
      ##This simulation doesn't count now.

      X1=as.list(c(0,0,0))
      X1[[1]]=OptDose
      X1[[2]]=MeanUT
      X1[[3]]=cbind(Doses,YE,YT)

      SIMSTORE[[m1]]=X1
      NTox[m1]=sum(YT)
      NEff[m1]=sum(YE)
      DoseOpt[m1]=OptDose
      for(j in 1:nDose){
        NumTrt[m1,j]=sum(Doses==j)
      }


    }else{

      ##Ok now weve done the whole trial, whats the optimal dose

      Z=UTEFFTOX(YE,YT, Doses, HypermeansE, HypermeansT,  Hypervars, B )


      MeanUT=rep(0,nDose)

      Sigma=matrix(c(Hypervars[1]+Hypervars[3],Hypervars[3]*mean(Z[[3]]),
                     Hypervars[3]*mean(Z[[3]]), Hypervars[1]+Hypervars[3]), nrow=2, byrow=TRUE)
      PMAT=Sigma



      for(D in 1:nDose){
        MU=c(mean(Z[[1]][,D]),mean(Z[[2]][,D]))

        PEFF = 1-pnorm(0,MU[1],sqrt(Hypervars[1]+Hypervars[3]))
        PTOX = 1-pnorm(0,MU[2],sqrt(Hypervars[1]+Hypervars[3]))


        MeanUT[D]=GetDesire(PEFF,PTOX,Contour)


      }




      ACCEPTE=rep(1,nDose)
      ACCEPTT=rep(1,nDose)

      ##What Doses are acceptable?
      for(D in 1:nDose){
        ##Calculate the probability of eff over all the samples
        PEFF = 1-pnorm(0,Z[[1]][,D],sqrt(Hypervars[1]+Hypervars[3]))
        if(sum(Doses==D)>=cohort){
          ##IS THIS DOSE ACCEPTABLE IN TERMS OF EFFICACY?
          ACCEPTE[D]=mean(PEFF>=CutE)>AcceptE
        }
        ##Calculate the probability of tox over all the samples
        PTOX = 1-pnorm(0,Z[[2]][,D],sqrt(Hypervars[1]+Hypervars[3]))

        ##IS THIS DOSE ACCEPTABLE IN TERM OF TOXICITY?
        ACCEPTT[D]=mean(PTOX<=CutT)>AcceptT

      }








      ##Multiply MeanUT by accept

      if(sum(ACCEPTE*ACCEPTT)==0){
        OptDose=0


      }else{
        for(j in 1:nDose){
          if(ACCEPTE[j]*ACCEPTT[j]*Dosetried[j]==0){
            MeanUT[j]=-1000
          }}
        ##Assign Next Dose Deterministically
        OptDose = which(MeanUT==max(MeanUT))
      }

      ##Fill this list with our values
      X1=as.list(c(0,0,0))
      X1[[1]]=min(OptDose)
      X1[[2]]=MeanUT
      X1[[3]]=cbind(Doses,YE,YT)

      SIMSTORE[[m1]]=X1

      NTox[m1]=sum(YT)
      NEff[m1]=sum(YE)

      for(j in 1:nDose){
        NumTrt[m1,j]=sum(Doses==j)
      }

      DoseOpt[m1]=min(OptDose)


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
