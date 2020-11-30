#'Returns prior dose-specific means and prior ESS for the SPSO model.
#'
#'Uses elicited efficacy and toxicity dose-specific parameters along withlatent prior variance, dose-specific mean hypervariance, frailty variance, and global probability of monotonicity to determine dose-specific prior means for efficacy and toxicityand prints the prior effective sample size associated with the specified prior parameters.
#'@param PROBST Elicited prior toxicity probability at each dose.
#'@param PROBSE Elicted prior efficacy probability at each dose.
#'@param Var Latent parameter variance for normal probability of efficacy and toxicity.
#'@param HypVar Hypervariance on dose specific mean efficacy and toxicity parameters.
#'@param tau Frailty variance parameter.
#'@param PGLOBAL Global monotonicity probability of dose-efficacy curve.
#'@return A list contianing (1) the prior effective sample size, (2) the vector of dose-specific efficacy probability prior mean parameters and, (3) the vector of dose-specific toxicity probability prior mean parameters.
#'@importFrom mvtnorm rmvnorm
#'@importFrom stats rnorm runif var pnorm
#'@examples
#'library(mvtnorm)
#'##Elicited probabilities of toxicity
#'PROBST=c(.05,.10,.15,.20,.30)
#'##Elicited probabilities of efficacy
#'PROBSE=c(.2,.4,.6,.65,.7)
#'##Sigma_0
#'Var=1
#'##Sigma_mu
#'HypVar=16
#'##Frailty Variance
#'tau=1
#'##Global Monotonicity Probability
#'PGLOBAL=.1
#'Z=GetPriorsSPSO(PROBST,PROBSE,tau,Var,HypVar,PGLOBAL)
#'Z
#'@export
GetPriorsSPSO=function(PROBST,PROBSE,tau,Var,HypVar, PGLOBAL){



  MeansT= rep(NA,length(PROBST))

  for(m in 1:length(MeansT)){
    ##Start at small value
    x=-5
    prob = 0
    while(prob<PROBST[m]){
      prob=1-pnorm(0,x,sqrt(Var))
      x=x+.001
    }


    MeansT[m]=x



  }

  MeansE=MeansT


  for(m in 1:length(MeansE)){
    ##Start at small value
    x=-5
    prob = 0
    while(prob<PROBSE[m]){
      prob=1-pnorm(0,x,sqrt(Var))
      x=x+.001
    }


    MeansE[m]=x



  }


  ##Ok Now lets generate a bunch of probabilities for each dose
  B=1000
  PIT=matrix(rep(NA,B*length(MeansE)),nrow=B)
  PIE=matrix(rep(NA,B*length(MeansE)),nrow=B)

  MU1=c(0,0)
  MUTOX = MeansE
  MUEFF=MUTOX

  for(b in 1:nrow(PIT)){
    rho=runif(1,-1,1)

    for(m in 1:length(MeansE)){
      ##Get the tox
      MUTOX[m]=rnorm(1,MeansT[m],HypVar)

    }


    ##Sort the MUTOX

    for(m in 2:length(MeansE)){
      ##Get the tox
      MUTOX[m]=max(MUTOX[m],MUTOX[m-1])

    }

    U=runif(1,0,1)

    for(m in 1:length(MeansE)){
      ##Get the tox
      MUEFF[m]=rnorm(1,MeansE[m],HypVar)

    }
    if(U<2*PGLOBAL){
      if(U<PGLOBAL){
        ##INCREASING
        for(m in 2:length(MeansE)){
          ##Get the tox
          MUEFF[m]=max(MUEFF[m],MUEFF[m-1]+.00001)

        }
      }else{

        for(m in 2:length(MeansE)){
          ##Get the tox
          MUEFF[m]=min(MUEFF[m],MUEFF[m-1])

        }

      }
    }



    for(m in 1:length(MeansE)){

      MU1[1]=MUEFF[m]
      MU1[2]=MUTOX[m]


      MU = rmvnorm(1,MU1,
                   matrix(c(Var+tau,Var*rho*tau,Var*rho*tau,Var+tau),byrow=TRUE,nrow=2))


      PIT[b,m]=1-pnorm(0,MU[2],sqrt(Var+tau))
      PIE[b,m]=1-pnorm(0,MU[1],sqrt(Var+tau))


    }
  }

  PriorESS = .5*mean(colMeans(PIT)*(1-colMeans(PIT))/apply(PIT,2,var)) +
    .5*mean(colMeans(PIE)*(1-colMeans(PIE))/apply(PIE,2,var))






  Z=as.list(c(0,0))

  Z[[1]]=PriorESS
    Z[[2]]=MeansE
  Z[[3]]=MeansT

  return(Z)


}








