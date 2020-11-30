#include <Rmath.h>
#define ARMA_DONT_PRINT_ERRORS
#include <RcppArmadillo.h>
#include <Rcpp.h>
#include <numeric>
#include <algorithm>
#include <vector>
#include <iterator>
#include <list>

// [[Rcpp::depends(RcppArmadillo)]]


using namespace std;
using namespace Rcpp;


//[[Rcpp::export]]
double TruncNormal(double rho, double c1){

  //m runs from 0 to (p.n_rows-1)
  //Truncation boundaries
  arma::vec BOUNDARIES(2);
  BOUNDARIES(0)=-1;
  BOUNDARIES(1)=1;

  //Generate Uniform variable
  double U = as_scalar(arma::randu(1));

  //Get value to plug into qnorm
  double X = U*R::pnorm5(BOUNDARIES(1),rho,c1,1,0)+(1-U)*R::pnorm5(BOUNDARIES(0),rho,c1,1,0);

  // Rprintf("value");
  X=R::qnorm5(X,rho,c1,1,0);

  // Rprintf("Exit");

  return(X);



}


//[[Rcpp::export]]
arma::mat MATMULT(arma::mat X, arma::mat Y){

  arma::mat PROD(X.n_rows,Y.n_cols);

  int k;
  int j;
  int m=0;

  for(j = 0 ;j<X.n_rows;j++){
    for(k=0;k<PROD.n_cols;k++){
      PROD(j,k)=0;
      for(m=0;m<X.n_cols;m++){
        PROD(j,k)=PROD(j,k)+X(j,m)*Y(m,k);
      }



    }
  }


  return(PROD);


}




double  GetBeta(double a, double b){
  double s = R::rbeta(a,b);

  return(s);
}





//'Generate binary bivariate data.
//'
//'Generates binary bivariate data from a 2x2 matrix of probabilities.
//'@param PVEC Contains TRUE pi00,pi10, pi01, pi11 for each dose
//'@importFrom Rcpp evalCpp
//'@useDynLib Phase12Compare
//'@return Binary bivariate random variate (YE,YT).
//'@export
//[[Rcpp::export]]
arma::vec GETBIN( arma::vec PVEC){
  arma::vec PVECSUM=PVEC;

  int j=0;
  for(j=1;j<PVEC.n_rows;j++){
    PVECSUM(j)=PVECSUM(j)+PVECSUM(j-1);
  }
  //Draw Random unif
  double U=as_scalar(arma::randu(1));
  double YE=0;
  double YT=0;

  if(U<PVECSUM(0)){
    YE=0;
    YE=0;
  }else{
    if(U<PVECSUM(1)){

      YE=1;
      YT=0;
    }else{
      if(U<PVECSUM(2)){
        YT=1;
        YE=0;

      }else{
        YE=1;
        YT=1;
      }


    }



  }


  arma::vec Z(2);
  Z(0)=YE;
  Z(1)=YT;

  return(Z);



}






double abs1(double a){
  if(a<0){
    return(-a);
  }else{
    return(a);
  }


}


//Returns the maximum from a vector
double MaxVec(arma::vec Y){
  int J1=Y.n_rows;
  int j=0;
  double max=Y[0];
  for(j=1;j<J1;j++){
    if(Y[j]>max){
      max=Y[j];
    }
  }

  return(max);

}




//Gets max of subvec
double MaxSubVec(arma::vec Y,int k){

  int j=0;
  double max=Y[0];
  for(j=1;j<k;j++){
    if(Y[j]>max){
      max=Y[j];
    }
  }

  return(max);

}


//Gets min of subvec for ordering
double MinSubVec(arma::vec Y1,int k,arma::vec ORDER){
  arma::vec Y(ORDER.n_rows-k-1);


  int J1=Y.n_rows;
  int j=0;

  for(j=0;j<J1;j++){
    Y(j)=Y1(Y1.n_rows-j-1);
  }


  double max=Y[0];
  for(j=1;j<J1;j++){
    if(Y[j]<max){
      max=Y[j];
    }
  }

  return(max);

}



//'Obtains optimal dose level.
//'
//'Gives the optimal dose level to assign the next patient cohort to based on the vector of optimality function values for each dose level (desirability or utility based) and the doses tried throughout the trial.
//'@param Desire Vector of optimality function values for each dose level.
//'@param DoseTried Binary vector containing 1 for doses that have been tried during the trial and 0 otherwise.
//'@importFrom Rcpp evalCpp
//'@useDynLib Phase12Compare
//'@return Optimal dose level to assign the next patient cohort.
//'@export
//[[Rcpp::export]]
int ReturnOpt(arma::vec Desire,arma::vec DoseTried){
  arma::vec DoseTried1=DoseTried;

  int j=0;



  if(sum(DoseTried)<DoseTried.n_rows){
    //Not all doses have been tried
    while(DoseTried(j)==1){
      j++;
    }
    DoseTried1(j)=1;
  }

  for(j=0;j<DoseTried1.n_rows;j++){
    if(DoseTried1(j)==0){
      Desire(j)=-1000;
    }

  }


  double max1= MaxVec(Desire);

  j=0;

  while(Desire(j)<max1){
    j++;
  }

  return(j);


}





double logINT(int z){
  double z1=z;
  return(log(z1));
}

double min1(double a, double b){
  double z=0;
  if(a>=b){
    z=b;
  }else{
    z=a;
  }

  return(z);
}



double max1(double a, double b){
  double z=0;
  if(a>=b){
    z=a;
  }else{
    z=b;
  }

  return(z);
}







//'Returns the desireability value of a dose.
//'
//'Takes estimated posterior mean efficacy and toxicity values and returns the posterior mean desireability score for a given tradeoff contour.
//'@param PE True or estimated probability of efficacy.
//'@param PT True of estimated probability of toxicity.
//'@param Contour Vector containing 4 entries used to make the desireability function. Contour(1) contains a desired toxicity probability given efficacy, Countour(2) contains a desired efficacy probability given toxicity, and (Contour(3),Contour(4)) is an equally desireable pair of efficacy and toxicity probabilities that are non zero or one.
//'@importFrom Rcpp evalCpp
//'@useDynLib Phase12Compare
//'@return Computes the real-valued desireability for an estimated (PE, PT) pair and elicited co
//'@examples
//'PE=.6
//'PT=.2
//'##Contour values
//'Contour=c(.35,.7,.8,.6)
//'GetDesire(PE,PT,Contour)
//'@export
//[[Rcpp::export]]
double GetDesire(double PE,
                 double PT,
                 arma::vec Contour){


  double p=0;
  double pu=0;
  double pl=0;
  double tol=.005;


  arma::vec z9(2);

  //Now lets Solve for p to get the desirability
  while(abs1(pow((Contour(2)-1)/(Contour(0)-1),p) + pow(Contour(3)/Contour(1),p)-1) >tol){
    pu = p+.005;
    pl=p-.005;

    if( abs1(pow((Contour(2)-1)/(Contour(0)-1),pu) + pow((Contour(3)/Contour(1)),pu)-1)<
      abs1(pow((Contour(2)-1)/(Contour(0)-1),pl) + pow((Contour(3)/Contour(1)),pl)-1)){
      p=pu;
    }else{
      p=pl;
    }




  }



  double desire = 1-pow((pow(((PE-1)/(Contour(0)-1)),p)+pow((PT/Contour(1)),p)),1/p);



  return(desire);


}










double SampBern(double prob){
  double U=as_scalar(arma::randu(1));


  if(U<prob){
    return(1);
  }else{
    return(0);
  }


}


double GetMin(arma::vec DESIRE){
  double min=DESIRE[0];
  int j=0;
  for(j=1;j<DESIRE.n_rows;j++){
    if(DESIRE[j]>-200){
      if(DESIRE[j]<min){
        min=DESIRE[j];
      }
    }
  }
  return(min);



}



int GetDose(arma::vec DESIRE){
  //First off, we don't want ANY desire that's negative.
  int NumD = sum(DESIRE>0);
  arma::vec DESIRE1(NumD);
  arma::vec WHICH1(NumD);

  int j=0;
  int k=0;

  for(j=0;j<NumD;j++){
    while(DESIRE[k]<0){
      k++;
    }
    DESIRE1[j]=DESIRE[k];
    WHICH1[j]=k;
    k=k+1;


  }

  DESIRE1=DESIRE1/sum(DESIRE1);
  arma::vec cumprob=DESIRE1;


  for(j=1;j<NumD;j++){
    cumprob[j]=cumprob[j]+cumprob[j-1];
  }



  double U=as_scalar(arma::randu(1));



  int which1=0;

  if(U>cumprob[0]){
    //Not the lowest acceptable dose considered
    while(U>cumprob[which1]){
      which1++;
    }


  }




  return(WHICH1[which1]);


}




int GetDoseUT(arma::vec DESIRE){
  //First off, we don't want ANY desire that's negative.
  int NumD = sum(DESIRE>0);
  arma::vec DESIRE1(NumD);
  arma::vec WHICH1(NumD);

  int j=0;
  int k=0;

  for(j=0;j<NumD;j++){
    while(DESIRE[k]<0){
      k++;
    }
    DESIRE1[j]=DESIRE[k];
    WHICH1[j]=k;
    k=k+1;


  }


  DESIRE1=exp(DESIRE1/10)/sum(exp(DESIRE1/10));
  arma::vec cumprob=DESIRE1;


  for(j=1;j<NumD;j++){
    cumprob[j]=cumprob[j]+cumprob[j-1];
  }



  double U=as_scalar(arma::randu(1));



  int which1=0;

  if(U>cumprob[0]){
    //Not the lowest acceptable dose considered
    while(U>cumprob[which1]){
      which1++;
    }


  }




  return(WHICH1[which1]);


}


double GetSd(arma::vec X){
  double Mean = sum(X)/X.n_rows;

  return(pow(sum(pow(X-Mean,2))/(X.n_rows-1),.5));


}






double MinVec(arma::vec Y){
  int J1=Y.n_rows;
  int j=0;
  double max=Y[0];
  for(j=1;j<J1;j++){
    if(Y[j]<max){
      max=Y[j];
    }
  }

  return(max);

}




int GetOrderSum(arma::vec Y){

  int max1=0;
  int k=0;
  for(k=1;k<Y.n_rows;k++){
    if(Y(k)>Y(k-1)){
      max1++;
    }
  }
  return(max1);

}


int WhichSpot(arma::vec ORDER, int j){

  int k=j+1;

  while(ORDER(k)==0){
    k++;
  }

  return(k);

}





double CHOOSE(int n, int x){

  double Sum1=0;

  double k=0;
  for(k=1;k<x;k++){
    Sum1=Sum1+log(k);
  }

  for(k=1;k<(n-x);k++){
    Sum1 = Sum1 + log(k);
  }
  return(Sum1);

}


arma::vec GlobalPropose(arma::vec MuE,int UP){
  double minval = MinVec(MuE);
  double maxval = MaxVec(MuE);
  arma::vec MUPROP = MuE;
  int k=0;

  if(UP==1){
    //Strictly increasing
    MUPROP(0)=minval;
    MUPROP(MUPROP.n_rows-1)=maxval;
    //Generate random unif
    for(k=1;k<(MUPROP.n_rows-1);k++){
      //STRICTLY INCREASING
      MUPROP(k)=as_scalar(arma::randu(1))*(maxval-MUPROP(k-1))+MUPROP(k-1);
    }



  }
  if(UP==-1){
    //Strictly decreasing/constant
    MUPROP(0)=maxval;
    MUPROP(MUPROP.n_rows-1)=minval;

    for(k=1;k<(MUPROP.n_rows-1);k++){
      //STRICTLY decreasing/constant
      MUPROP(k)=min1(as_scalar(arma::randu(1))*(maxval-minval),MUPROP(k-1));
    }



  }

  if(UP==0){
    //Anything
    //Strictly decreasing/constant


    for(k=0;k<MUPROP.n_rows;k++){
      //STRICTLY decreasing/constant
      MUPROP(k)=as_scalar(arma::randu(1))*(maxval-minval) + minval;
    }



  }

  return(MUPROP);


}







//Things needed for Running the Adaptive EFFTOX with correlations


double Like(arma::vec YE1, //Binary indicators of efficacy
            arma::vec YT1, //Binary indicators of Toxicity
            arma::vec Doses1, //Vector of Doses given to patients
            arma::vec beta, //Parameter vector containing linear parameters, length 5
            double psi, //  association between toxicity and efficacy
            int Num
){

  double LogL =0;


  //Make YE and YT and Doses
  arma::vec YE(Num);
  arma::vec YT(Num);
  arma::vec Dose(Num);
  YE.zeros();
  YT.zeros();
  Dose.zeros();

  //Loop over the doses for the likelihood
  //Doses
  int j=0;
  //Patients
  int i=0;
  //4 EFF-TOX outcomes
  int m=0;

  for(j=0;j<Num;j++){
    YE[j]=YE1[j];
    YT[j]=YT1[j];
    Dose[j]=Doses1[j];

  }


  //Holds tox and eff prob for a given dose
  double piE=0;
  double piT=0;
  //Stores probabilities of the 4 outcomes
  // 1 Neither
  // 2 Eff - No Tox
  // 3 Tox - No Eff
  // 4 Both
  arma::vec probs(4);
  probs.zeros();
  //Association Constand
  double Con = (exp(psi)-1)/(exp(psi)+1);
  double Con1=0;

  for(i=0;i<YE.n_rows;i++){
    //Compute PiE and PiT
    piE = beta[0]+beta[1]*Dose[i]+beta[2]*pow(Dose[i],2);
    piT = beta[3]+beta[4]*Dose[i];
    piE = exp(piE);
    piT=exp(piT);
    piE = piE/(1+piE);
    piT = piT/(1+piT);
    //Now we have the probabilities of toxictity and efficacy for this dose.
    Con1 = piE*(1-piE)*piT*(1-piT)*Con;

    probs[0]=log(Con1 + (1-piE)*(1-piT));
    probs[1]=log((1-piT)*piE - Con1);
    probs[2]= log((1-piE)*piT - Con1);
    probs[3]= log(piE*piT + Con1);

    //Loop over each patient
    if( ((YE[i]==0) && (YT[i]==0))){
      LogL = LogL + probs[0];
    }
    if( ((YE[i]==1) && (YT[i]==0))){
      LogL = LogL + probs[1];
    }
    if( ((YE[i]==0) && (YT[i]==1)) ){
      LogL = LogL + probs[2];
    }
    if( ((YE[i]==1) && (YT[i]==1))){
      LogL = LogL + probs[3];
    }















  }





  return(LogL);



}











int GetDose1(arma::vec DESIRE){
  //First off, we don't want ANY desire that's negative.
  int j=0;
  int k=0;
  arma::vec z9(2);


  int count=0;

  for(j=0;j<DESIRE.n_rows;j++){
    if(DESIRE[j]>-200){
      count++;
    }
  }
  int NumD=count;





  if(count>1){


    arma::vec DESIRE1(NumD);
    arma::vec WHICH1(NumD);



    for(j=0;j<NumD;j++){
      while(DESIRE[k]< (-200)){
        k++;
      }
      DESIRE1[j]=DESIRE[k];
      WHICH1[j]=k;
      k=k+1;


    }




    DESIRE1=(DESIRE1-sum(DESIRE1)/DESIRE1.n_rows)/GetSd(DESIRE1);


    DESIRE1=exp(DESIRE1)/sum(exp(DESIRE1));


    arma::vec cumprob=DESIRE1;



    for(j=1;j<NumD;j++){
      cumprob[j]=cumprob[j]+cumprob[j-1];
    }



    double U=as_scalar(arma::randu(1));




    int which1=0;

    if(U>cumprob[0]){
      //Not the lowest acceptable dose considered
      while(U>cumprob[which1]){
        which1++;

        if(which1==(cumprob.n_rows-1)){
          break;
        }

      }


    }



    return(WHICH1[which1]);

  }else{



    k=0;
    while(DESIRE[k]< (-200)){
      k++;
    }






    return(k);
  }

}








int GetDose2(arma::vec DESIRE,arma::vec DoseTried){
  arma::vec Desire=DESIRE;
  arma::vec DoseTried1=DoseTried;

  int j=0;


  if(sum(DoseTried)<DoseTried.n_rows){
    //Not all doses have been tried
    while(DoseTried(j)==1){
      j++;
    }
    DoseTried1(j)=1;
  }

  for(j=0;j<DoseTried1.n_rows;j++){
    if(DoseTried1(j)==0){
      Desire(j)=-1000;
    }

  }


  //Count how many
  int count=0;

  for(j=0;j<Desire.n_rows;j++){
    if(Desire(j)>-200){
      count++;
    }

  }


  if(count>1){
    return(GetDose(Desire/10));
  }else{
    return(ReturnOpt(DESIRE,DoseTried));
  }





}





int GetDose3(arma::vec DESIRE,arma::vec DoseTried){

  arma::vec Desire=DESIRE;

  arma::vec DoseTried1=DoseTried;

  int j=0;


  if(sum(DoseTried)<DoseTried.n_rows){
    //Not all doses have been tried
    while(DoseTried(j)==1){
      j++;
    }
    DoseTried1(j)=1;
  }

  for(j=0;j<DoseTried1.n_rows;j++){
    if(DoseTried1(j)==0){
      Desire(j)=-1000;
    }

  }


  //Count how many
  int count=0;

  for(j=0;j<Desire.n_rows;j++){
    if(Desire(j)>-200){
      count++;
    }

  }


  if(count>1){
    return(GetDose1(Desire));
  }else{
    return(ReturnOpt(DESIRE,DoseTried));
  }

}






int RandomDoseUT(arma::vec DESIRE,arma::vec DoseTried){
  arma::vec Desire=DESIRE;
  arma::vec DoseTried1=DoseTried;

  int j=0;


  if(sum(DoseTried)<DoseTried.n_rows){
    //Not all doses have been tried
    while(DoseTried(j)==1){
      j++;
    }
    DoseTried1(j)=1;
  }

  for(j=0;j<DoseTried1.n_rows;j++){
    if(DoseTried1(j)==0){
      Desire(j)=-1000;
    }

  }


  //Count how many
  int count=0;

  for(j=0;j<Desire.n_rows;j++){
    if(Desire(j)>-200){
      count++;
    }

  }


  if(count>1){
    return(GetDoseUT(Desire));
  }else{
    return(ReturnOpt(DESIRE,DoseTried));
  }





}








//'Simulates utility based Efftox trials
//'
//'Simulates utility based Efftox trials
//'@param DoseStart Dose level to START the EFF-Tox Trial
//'@param Dose Vector of Doses considered in the trial
//'@param Hypermeans 6 vector of prior means
//'@param Hypervars 6 vector of prior standard deviations
//'@param UT 2x2 matrix of utilities corresponding to the four binary bivariate (toxicity, efficacy) events.
//'@param PiLim 2 vector of acceptable limits
//'@param ProbLim 2 vector of cutoff for acceptabilities
//'@param cohort Cohort size
//'@param NET Maximum Sample size to run the EFFtox Trial, must be divisible by cohort
//'@param NF Minimum sample size to begin adaptive randomization, must be divisible by count
//'@param B Number of reps to perform in MCMC
//'@param nSims Number of Simulated trials to run.
//'@param PMAT Contains TRUE pi00,pi10, pi01, pi11 for each dose
//'@importFrom Rcpp evalCpp
//'@useDynLib Phase12Compare
//'@return Trial simulation results to be processed for operating characteristics summaries.
//'@export
//[[Rcpp::export]]
List RunAdaptiveEffToxTrialCORR( int DoseStart, //Dose level to START the EFF-Tox Trial
                                 arma::vec Dose, //Vector of Doses considered in the trial
                                 arma::vec Hypermeans, //6 vector of prior means
                                 arma::vec Hypervars, //6 vector of prior standard deviations
                                 arma::mat UT, //4 vector of Utilities
                                 arma::vec PiLim, //2 vector of acceptable limits
                                 arma::vec ProbLim, //2 vector of cutoff for acceptabilities
                                 int cohort, //Cohort size
                                 int NET, //Maximum Sample size to run the EFFtox Trial, must be divisible by cohort
                                 int NF, //Minimum sample size to begin adaptive randomization, must be divisible by count
                                 double B, // Number of reps to perform in MCMC
                                 int nSims, //Number of Simulated trials to run.
                                 arma::mat PMAT //Contains TRUE pi00,pi10, pi01, pi11 for each dose
){




  int Nmax=NET;
  int Nmin=NF;
  arma::vec Accept=PiLim;
  arma::vec Lower=ProbLim;
  arma::vec MeanUt(Dose.n_rows);
  arma::vec PiEff(Dose.n_rows);
  arma::vec PiTox(Dose.n_rows);
  arma::vec ACCEPTTOX(Dose.n_rows);
  arma::vec ACCEPTEFF(Dose.n_rows);
  arma::vec DESIRE(Dose.n_rows);
  arma::vec ACCEPT(Dose.n_rows);
  ACCEPTTOX.zeros();
  ACCEPTEFF.zeros();

  double p=0;
  double pu=0;
  double pl=0;
  double tol=.005;




  double NCohort = Nmax/cohort;
  double MinCohort=Nmin/cohort;

  //What Doses are Acceptable

  arma::vec ACCTOX(Dose.n_rows);
  arma::vec ACCEFF=ACCTOX;


  //Storage for each trial outputs
  arma::vec Doses(Nmax);
  arma::vec YE(Nmax);
  arma::vec YT(Nmax);


  //Storage matrices for trial output
  arma::vec CHOSENDOSE(nSims);
  arma::mat UTStore(nSims,Dose.n_rows);
  arma::mat TrialStore(nSims*Nmax,3);
  arma::mat HOLD(1,2);

  int Count=0;




  double B1 = B/2;

  //Used for for loop
  int b=0;
  //Used in Sim look
  int nREP=0;

  //Storage Matrices
  arma::mat piEStore(B1,Dose.n_rows);
  arma::mat piTStore(B1,Dose.n_rows);
  arma::mat AcceptTox(B1,Dose.n_rows);
  arma::mat AcceptEff(B1,Dose.n_rows);
  AcceptTox.zeros();
  AcceptEff.zeros();
  arma::vec DESIRE2(Dose.n_rows);
  DESIRE2.zeros();


  arma::mat ParamStore(B1,6);
  //Setup innitial
  arma::vec beta(5);
  beta.zeros();
  arma::vec betaprop=beta;
  double psi=0;
  double psiprop=0;
  //Quantities for MCMC
  double U=0;
  double alpha=0;
  int m=0;
  int j=0;
  int StoreInx=0;
  double PE=0;
  double PT=0;

  arma::vec bvar(6);
  bvar.zeros();
  bvar=bvar+1;
  arma::vec Intb = bvar;
  arma::vec Numb = bvar + 1;

  arma::vec Doses2=Doses;

  NumericVector z9(2);
  int CoNum=0;

  int STOPPED=0;
  int i=0;
  int OptDose=0;
  double min1=0;
  int DoseStart1=DoseStart;

  //
  double piE=0;
  double piT=0;
  double Con1=0;
  double Con=0;

  int nRep=0;

  arma::vec DESIRE1=DESIRE;

  arma::vec z5(2);
  arma::vec DoseTried(Dose.n_rows);


  while(nRep<nSims){

    STOPPED=0;
    if(nRep>0){
      if(nRep%100==0){



        Rprintf("Iteration:");
        z9[0]=nRep;
        z9[1]=nRep;
        Rf_PrintValue(wrap(z9));


      }
    }
    Doses2.zeros();
    //Wrap Trial right here
    Doses2=Doses2-1;
    Doses.zeros();
    Doses=Doses-1;
    DoseTried.zeros();

    YE.zeros();
    YT.zeros();


    for(m=0;m<DoseStart;m++){
      DoseTried[m]=1;
    }

    DoseStart1=DoseStart-1;
    OptDose=DoseStart1;


    //Wrap around each cohort
    for(i=0;i<NCohort;i++){



      //Fill in next cohort with the data size
      for(b=0;b<cohort;b++){
        Doses[i*cohort+b] = Dose[OptDose];
        Doses2[i*cohort+b] = OptDose;

        HOLD=GETBIN(PMAT.row(OptDose).t());
        //     Rf_PrintValue(wrap(HOLD));
        YE[i*cohort+b]=HOLD(0);
        YT[i*cohort+b]=HOLD(1);

        DoseTried(OptDose)=1;

      }



      CoNum=(i+1)*cohort;

      Intb=Intb.zeros()+1;
      Numb=Numb.zeros()+2;
      bvar=bvar.zeros()+1;

      for(j=0;j<5;j++){
        beta[j]=Hypermeans[j];
      }
      psi=Hypermeans[5];

      //Perform MCMC
      for(b=0;b<B;b++){


        if(b<(B/2 + 2)){
          if(b%250==0){

            for(j=0;j<6;j++){
              if((Intb[j]/Numb[j])>.5){
                bvar[j]=bvar[j]*2;
              }

              if((Intb[j]/Numb[j])<.2){
                bvar[j]=bvar[j]/2;
              }


              Intb[j]=1;
              Numb[j]=2;

            }





          }
        }




        //All but beta_T can be less than 0, sample those
        for(j=0;j<4;j++){

          betaprop=beta;
          betaprop[j]=as_scalar(arma::randn(1))*bvar[j] + betaprop[j];

          alpha =   Like(YE,YT,Doses,betaprop,psi,CoNum) - Like(YE,YT,Doses, beta, psi,CoNum);
          alpha = alpha - .5*pow(betaprop[j]-Hypermeans[j],2)/Hypervars[j] + .5*pow(beta[j]-Hypermeans[j],2)/Hypervars[j];

          U=log(as_scalar(arma::randu(1)));

          if(U<alpha){
            beta[j]=betaprop[j];
            Intb[j]=Intb[j]+1;
          }

          Numb[j] = Numb[j]+1;





        }


        //toxicity slope
        j=4;
        betaprop=beta;
        betaprop[j]=exp(as_scalar(arma::randn(1))*bvar[j] + log(betaprop[j]));

        alpha =   Like(YE,YT,Doses,betaprop,psi,CoNum) - Like(YE,YT,Doses, beta, psi,CoNum);
        alpha = alpha - .5*pow(betaprop[j]-Hypermeans[j],2)/Hypervars[j] + .5*pow(beta[j]-Hypermeans[j],2)/Hypervars[j];

        alpha = alpha + log(betaprop[j]) - log(beta[j]);


        U=log(as_scalar(arma::randu(1)));

        if(U<alpha){
          beta[j]=betaprop[j];
          Intb[j]=Intb[j]+1;
        }

        Numb[j] = Numb[j]+1;




        //Get new Psi

        //toxicity slope
        j=5;

        psiprop=as_scalar(arma::randn(1))*bvar[j] + psi;

        alpha =   Like(YE,YT,Doses,beta,psiprop,CoNum) - Like(YE,YT,Doses, beta, psi,CoNum);
        alpha = alpha - .5*pow(psiprop-Hypermeans[j],2)/Hypervars[j] + .5*pow(psi-Hypermeans[j],2)/Hypervars[j];

        U=log(as_scalar(arma::randu(1)));

        if(U<alpha){
          psi=psiprop;
          Intb[j]=Intb[j]+1;
        }

        Numb[j]=Numb[j]+1;









        if(b>(B-B1-1)){

          StoreInx = b-B1;

          for(j=0;j<5;j++){
            ParamStore(StoreInx,j)=beta[j];
          }
          ParamStore(StoreInx,5)=psi;

          //Fill in Toxcity and Efficacy probabilities


          for(j=0;j<Dose.n_rows;j++){
            PE = beta[0]+beta[1]*Dose[j]+beta[2]*pow(Dose[j],2);
            PT = beta[3]+beta[4]*Dose[j];

            PE = exp(PE);
            PT=exp(PT);
            PE=PE/(1+PE);
            PT = PT/(1+PT);
            piEStore(StoreInx,j)=PE;
            piTStore(StoreInx,j)=PT;


            if(PE>Accept[0]){
              AcceptEff(StoreInx,j)=1;
            }else{
              AcceptEff(StoreInx,j)=0;

            }

            if(PT<Accept[1]){
              AcceptTox(StoreInx,j)=1;
            }else{
              AcceptTox(StoreInx,j)=0;

            }






          }



        }



      }

      //Compute posterior mean



      for(j=0;j<Dose.n_rows;j++){
        if(sum(Doses2==j)>=cohort){
          ACCEPTEFF[j]=sum(AcceptEff.col(j))>(Lower(0)*B1)  ;
        }else{
          ACCEPTEFF[j]=1;
        }
        ACCEPTTOX[j]=sum(AcceptTox.col(j))>(Lower(1)*B1) ;
      }




      //If ==1, for both EFF and TOX then dose j is acceptable

      //Determine Optimal Dose

      //Get Posterior mean of parameters
      for(j=0;j<5;j++){
        beta[j]=sum( ParamStore.col(j))/ParamStore.n_rows;
      }

      psi=sum(ParamStore.col(5))/ParamStore.n_rows;


      for(j=0;j<Dose.n_rows;j++){
        PE = beta[0]+beta[1]*Dose[j]+beta[2]*pow(Dose[j],2);
        PT = beta[3]+beta[4]*Dose[j];

        PE = exp(PE);
        PT=exp(PT);
        PE=PE/(1+PE);
        PT = PT/(1+PT);
        PiEff(j)=PE;
        PiTox(j)=PT;

      }




      Con = (exp(psi)-1)/(exp(psi)+1);


      //Now get the mean desireability for each dose if they are acceptable
      for(j=0;j<Dose.n_rows;j++){
        if((ACCEPTEFF[j]+ACCEPTTOX[j])==2){
          //Dose is ACCEPTABLe
          piE=PiEff(j);
          piT=PiTox(j);

          //Now we have the probabilities of toxictity and efficacy for this dose.
          Con1 = piE*(1-piE)*piT*(1-piT)*Con;
          DESIRE[j]=UT(0,0)*(Con1 + (1-piE)*(1-piT))+UT(0,1)*((1-piT)*piE - Con1) + UT(1,1)*(piE*piT + Con1);


          ACCEPT[j]=1;

        }else{
          ACCEPT[j]=0;
          DESIRE[j]=-1000;
        }



      }






      if(sum(ACCEPT)>0){


        //Now pick the dose





        if((i<MinCohort)){

          OptDose=ReturnOpt( DESIRE, DoseTried);









        }else{
          //Ok let's adaptively randomize patients



          OptDose=  GetDose3(DESIRE,DoseTried);









        }









      }else{

        if(i>1){
          //Trial Stopped
          OptDose=-1;
          STOPPED=1;


          CHOSENDOSE[nRep]=OptDose+1;
          for(j=0;j<Dose.n_rows;j++){
            UTStore(nRep,j)= DESIRE[j];
          }


          for(j=0;j<Nmax;j++){
            TrialStore(nRep*Nmax+j,0)=Doses2(j);
            TrialStore(nRep*Nmax+j,1)=YE(j);
            TrialStore(nRep*Nmax+j,2)=YT(j);



          }



          break;


        }else{
          OptDose=0;
        }

      }






    }


    if(STOPPED==0){


      Intb=Intb.zeros()+1;
      Numb=Numb.zeros()+2;
      bvar=bvar.zeros()+1;



      for(j=0;j<5;j++){
        beta[j]=Hypermeans[j];
      }
      psi=Hypermeans[5];

      //Perform MCMC
      for(b=0;b<B;b++){


        if(b<(B/2 + 2)){
          if(b%250==0){

            for(j=0;j<6;j++){
              if((Intb[j]/Numb[j])>.5){
                bvar[j]=bvar[j]*2;
              }

              if((Intb[j]/Numb[j])<.2){
                bvar[j]=bvar[j]/2;
              }


              Intb[j]=1;
              Numb[j]=2;

            }





          }
        }




        //All but beta_T can be less than 0, sample those
        for(j=0;j<4;j++){

          betaprop=beta;
          betaprop[j]=as_scalar(arma::randn(1))*bvar[j] + betaprop[j];

          alpha =   Like(YE,YT,Doses,betaprop,psi,CoNum) - Like(YE,YT,Doses, beta, psi,CoNum);
          alpha = alpha - .5*pow(betaprop[j]-Hypermeans[j],2)/Hypervars[j] + .5*pow(beta[j]-Hypermeans[j],2)/Hypervars[j];

          U=log(as_scalar(arma::randu(1)));

          if(U<alpha){
            beta[j]=betaprop[j];
            Intb[j]=Intb[j]+1;
          }

          Numb[j] = Numb[j]+1;





        }


        //toxicity slope
        j=4;
        betaprop=beta;
        betaprop[j]=exp(as_scalar(arma::randn(1))*bvar[j] + log(betaprop[j]));

        alpha =   Like(YE,YT,Doses,betaprop,psi,CoNum) - Like(YE,YT,Doses, beta, psi,CoNum);
        alpha = alpha - .5*pow(betaprop[j]-Hypermeans[j],2)/Hypervars[j] + .5*pow(beta[j]-Hypermeans[j],2)/Hypervars[j];

        alpha = alpha + log(betaprop[j]) - log(beta[j]);


        U=log(as_scalar(arma::randu(1)));

        if(U<alpha){
          beta[j]=betaprop[j];
          Intb[j]=Intb[j]+1;
        }

        Numb[j] = Numb[j]+1;




        //Get new Psi

        //toxicity slope
        j=5;

        psiprop=as_scalar(arma::randn(1))*bvar[j] + psi;

        alpha =   Like(YE,YT,Doses,beta,psiprop,CoNum) - Like(YE,YT,Doses, beta, psi,CoNum);
        alpha = alpha - .5*pow(psiprop-Hypermeans[j],2)/Hypervars[j] + .5*pow(psi-Hypermeans[j],2)/Hypervars[j];

        U=log(as_scalar(arma::randu(1)));

        if(U<alpha){
          psi=psiprop;
          Intb[j]=Intb[j]+1;
        }

        Numb[j]=Numb[j]+1;









        if(b>(B-B1-1)){

          StoreInx = b-B1;

          for(j=0;j<5;j++){
            ParamStore(StoreInx,j)=beta[j];
          }
          ParamStore(StoreInx,5)=psi;

          //Fill in Toxcity and Efficacy probabilities


          for(j=0;j<Dose.n_rows;j++){
            PE = beta[0]+beta[1]*Dose[j]+beta[2]*pow(Dose[j],2);
            PT = beta[3]+beta[4]*Dose[j];

            PE = exp(PE);
            PT=exp(PT);
            PE=PE/(1+PE);
            PT = PT/(1+PT);
            piEStore(StoreInx,j)=PE;
            piTStore(StoreInx,j)=PT;


            if(PE>Accept[0]){
              AcceptEff(StoreInx,j)=1;
            }else{
              AcceptEff(StoreInx,j)=0;

            }

            if(PT<Accept[1]){
              AcceptTox(StoreInx,j)=1;
            }else{
              AcceptTox(StoreInx,j)=0;

            }






          }



        }



      }

      //Compute posterior mean





      for(j=0;j<Dose.n_rows;j++){
        if(sum(Doses2==j)>=cohort){
          ACCEPTEFF[j]=sum(AcceptEff.col(j))>(Lower(0)*B1)  ;
        }else{
          ACCEPTEFF[j]=1;
        }
        ACCEPTTOX[j]=sum(AcceptTox.col(j))>(Lower(1)*B1) ;
      }




      //If ==1, for both EFF and TOX then dose j is acceptable

      //Determine Optimal Dose

      //Get Posterior mean of parameters
      for(j=0;j<5;j++){
        beta[j]=sum( ParamStore.col(j))/ParamStore.n_rows;
      }

      psi=sum(ParamStore.col(5))/ParamStore.n_rows;


      for(j=0;j<Dose.n_rows;j++){
        PE = beta[0]+beta[1]*Dose[j]+beta[2]*pow(Dose[j],2);
        PT = beta[3]+beta[4]*Dose[j];

        PE = exp(PE);
        PT=exp(PT);
        PE=PE/(1+PE);
        PT = PT/(1+PT);
        PiEff(j)=PE;
        PiTox(j)=PT;

      }




      Con = (exp(psi)-1)/(exp(psi)+1);


      //Now get the mean desireability for each dose if they are acceptable
      for(j=0;j<Dose.n_rows;j++){
        if((ACCEPTEFF[j]+ACCEPTTOX[j])==2){
          //Dose is ACCEPTABLe
          piE=PiEff(j);
          piT=PiTox(j);

          //Now we have the probabilities of toxictity and efficacy for this dose.
          Con1 = piE*(1-piE)*piT*(1-piT)*Con;
          DESIRE[j]=UT(0,0)*(Con1 + (1-piE)*(1-piT))+UT(0,1)*((1-piT)*piE - Con1) + UT(1,1)*(piE*piT + Con1);


          ACCEPT[j]=1;

        }else{
          ACCEPT[j]=0;
          DESIRE[j]=-1000;
        }



      }





      if(sum(ACCEPT)>0){


        //Cant pick any dose not tried as optimal
        for(j=0;j<Dose.n_rows;j++){
          if(DoseTried(j)==0){
            DESIRE(j)=-1000;

          }
        }

        OptDose=ReturnOpt( DESIRE, DoseTried);





      }else{
        OptDose=-1;
      }












    }else{
      OptDose=-1;
    }



    CHOSENDOSE[nRep]=OptDose+1;
    for(j=0;j<Dose.n_rows;j++){
      UTStore(nRep,j)= DESIRE[j];
    }


    for(j=0;j<Nmax;j++){
      TrialStore(nRep*Nmax+j,0)=Doses2(j);
      TrialStore(nRep*Nmax+j,1)=YE(j);
      TrialStore(nRep*Nmax+j,2)=YT(j);



    }

    nRep=nRep+1;


  }


  List z1 = List::create(CHOSENDOSE,UTStore,TrialStore,ParamStore);

  return(z1);
}




//'Simulates desirability based Efftox trials
//'
//'Simulates Efftox trials based on the desirability tradeoff contour.
//'@param DoseStart Dose level to START the EFF-Tox Trial
//'@param Dose Vector of Doses considered in the trial
//'@param Hypermeans 6 vector of prior means
//'@param Hypervars 6 vector of prior standard deviations
//'@param Contour 4 vector used to specify the tradeoff contour.
//'@param PiLim 2 vector of acceptable limits
//'@param ProbLim 2 vector of cutoff for acceptabilities
//'@param cohort Cohort size
//'@param NET Maximum Sample size to run the EFFtox Trial, must be divisible by cohort
//'@param NF Minimum sample size to begin adaptive randomization, must be divisible by count
//'@param B Number of reps to perform in MCMC
//'@param nSims Number of Simulated trials to run.
//'@param PMAT Contains TRUE pi00,pi10, pi01, pi11 for each dose
//'@importFrom Rcpp evalCpp
//'@useDynLib Phase12Compare
//'@return Trial simulation results to be processed for operating characteristics summaries.
//'@export
//[[Rcpp::export]]
List RunAdaptiveEffToxTrialCORRCONTOUR( int DoseStart, //Dose level to START the EFF-Tox Trial
                                        arma::vec Dose, //Vector of Doses considered in the trial
                                        arma::vec Hypermeans, //6 vector of prior means
                                        arma::vec Hypervars, //6 vector of prior standard deviations
                                        arma::vec Contour, //4 vector of Contour parameter
                                        arma::vec PiLim, //2 vector of acceptable limits
                                        arma::vec ProbLim, //2 vector of cutoff for acceptabilities
                                        int cohort, //Cohort size
                                        int NET, //Maximum Sample size to run the EFFtox Trial, must be divisible by cohort
                                        int NF, //Minimum sample size to begin adaptive randomization, must be divisible by count
                                        double B, // Number of reps to perform in MCMC
                                        int nSims, //Number of Simulated trials to run.
                                        arma::mat PMAT //Matrix of Probs
){






  int Nmax=NET;
  int Nmin=NF;
  arma::vec Accept=PiLim;
  arma::vec Lower=ProbLim;
  arma::vec MeanUt(Dose.n_rows);
  arma::vec PiEff(Dose.n_rows);
  arma::vec PiTox(Dose.n_rows);
  arma::vec ACCEPTTOX(Dose.n_rows);
  arma::vec ACCEPTEFF(Dose.n_rows);
  arma::vec DESIRE(Dose.n_rows);
  arma::vec ACCEPT(Dose.n_rows);
  ACCEPTTOX.zeros();
  ACCEPTEFF.zeros();

  double p=0;
  double pu=0;
  double pl=0;
  double tol=.005;



  //Now lets Solve for p to get the desirability
  while(abs1(pow((Contour[2]-1)/(Contour[0]-1),p) + pow(Contour[3]/Contour[1],p)-1) >tol){
    pu = p+.005;
    pl=p-.005;

    if( abs1(pow((Contour[2]-1)/(Contour[0]-1),pu) + pow((Contour[3])/(Contour[1]),pu)-1)<
      abs1(pow((Contour[2]-1)/(Contour[0]-1),pl) + pow((Contour[3])/(Contour[1]),pl)-1)){
      p=pu;
    }else{
      p=pl;
    }




  }





  double NCohort = Nmax/cohort;
  double MinCohort=Nmin/cohort;

  //What Doses are Acceptable

  arma::vec ACCTOX(Dose.n_rows);
  arma::vec ACCEFF=ACCTOX;


  //Storage for each trial outputs
  arma::vec Doses(Nmax);
  arma::vec YE(Nmax);
  arma::vec YT(Nmax);


  //Storage matrices for trial output
  arma::vec CHOSENDOSE(nSims);
  arma::mat UTStore(nSims,Dose.n_rows);
  arma::mat TrialStore(nSims*Nmax,3);
  arma::mat HOLD(1,2);

  int Count=0;




  double B1 = B/2;

  //Used for for loop
  int b=0;
  //Used in Sim look
  int nREP=0;

  //Storage Matrices
  arma::mat piEStore(B1,Dose.n_rows);
  arma::mat piTStore(B1,Dose.n_rows);
  arma::mat AcceptTox(B1,Dose.n_rows);
  arma::mat AcceptEff(B1,Dose.n_rows);
  AcceptTox.zeros();
  AcceptEff.zeros();
  arma::vec DESIRE2(Dose.n_rows);
  DESIRE2.zeros();


  arma::mat ParamStore(B1,6);
  //Setup innitial
  arma::vec beta(5);
  beta.zeros();
  arma::vec betaprop=beta;
  double psi=0;
  double psiprop=0;
  //Quantities for MCMC
  double U=0;
  double alpha=0;
  int m=0;
  int j=0;
  int StoreInx=0;
  double PE=0;
  double PT=0;

  arma::vec bvar(6);
  bvar.zeros();
  bvar=bvar+1;
  arma::vec Intb = bvar;
  arma::vec Numb = bvar + 1;

  arma::vec Doses2=Doses;

  NumericVector z9(2);
  int CoNum=0;

  int STOPPED=0;
  int i=0;
  int OptDose=0;
  double min1=0;
  int DoseStart1=DoseStart;



  int nRep=0;

  arma::vec DESIRE1=DESIRE;

  arma::vec z5(2);
  arma::vec DoseTried(Dose.n_rows);



  while(nRep<nSims){

    STOPPED=0;
    if(nRep>0){
      if(nRep%100==0){



        Rprintf("Iteration:");
        z9[0]=nRep;
        z9[1]=nRep;
        Rf_PrintValue(wrap(z9));


      }
    }
    Doses2.zeros();
    //Wrap Trial right here
    Doses2=Doses2-1;
    Doses.zeros();
    Doses=Doses-1;

    DoseTried.zeros();

    YE.zeros();
    YT.zeros();


    for(m=0;m<DoseStart;m++){
      DoseTried[m]=1;
    }

    DoseStart1=DoseStart-1;
    OptDose=DoseStart1;


    //Wrap around each cohort
    for(i=0;i<NCohort;i++){



      //Fill in next cohort with the data size
      for(b=0;b<cohort;b++){
        Doses[i*cohort+b] = Dose[OptDose];
        Doses2[i*cohort+b] = OptDose;

        HOLD=GETBIN(PMAT.row(OptDose).t());
        //     Rf_PrintValue(wrap(HOLD));
        YE[i*cohort+b]=HOLD(0);
        YT[i*cohort+b]=HOLD(1);

        DoseTried(OptDose)=1;

      }



      CoNum=(i+1)*cohort;

      Intb=Intb.zeros()+1;
      Numb=Numb.zeros()+2;
      bvar=bvar.zeros()+1;

      for(j=0;j<5;j++){
        beta[j]=Hypermeans[j];
      }
      psi=Hypermeans[5];

      //Perform MCMC
      for(b=0;b<B;b++){


        if(b<(B/2 + 2)){
          if(b%250==0){

            for(j=0;j<6;j++){
              if((Intb[j]/Numb[j])>.5){
                bvar[j]=bvar[j]*2;
              }

              if((Intb[j]/Numb[j])<.2){
                bvar[j]=bvar[j]/2;
              }


              Intb[j]=1;
              Numb[j]=2;

            }





          }
        }




        //All but beta_T can be less than 0, sample those
        for(j=0;j<4;j++){

          betaprop=beta;
          betaprop[j]=as_scalar(arma::randn(1))*bvar[j] + betaprop[j];

          alpha =   Like(YE,YT,Doses,betaprop,psi,CoNum) - Like(YE,YT,Doses, beta, psi,CoNum);
          alpha = alpha - .5*pow(betaprop[j]-Hypermeans[j],2)/Hypervars[j] + .5*pow(beta[j]-Hypermeans[j],2)/Hypervars[j];

          U=log(as_scalar(arma::randu(1)));

          if(U<alpha){
            beta[j]=betaprop[j];
            Intb[j]=Intb[j]+1;
          }

          Numb[j] = Numb[j]+1;





        }


        //toxicity slope
        j=4;
        betaprop=beta;
        betaprop[j]=exp(as_scalar(arma::randn(1))*bvar[j] + log(betaprop[j]));

        alpha =   Like(YE,YT,Doses,betaprop,psi,CoNum) - Like(YE,YT,Doses, beta, psi,CoNum);
        alpha = alpha - .5*pow(betaprop[j]-Hypermeans[j],2)/Hypervars[j] + .5*pow(beta[j]-Hypermeans[j],2)/Hypervars[j];

        alpha = alpha + log(betaprop[j]) - log(beta[j]);


        U=log(as_scalar(arma::randu(1)));

        if(U<alpha){
          beta[j]=betaprop[j];
          Intb[j]=Intb[j]+1;
        }

        Numb[j] = Numb[j]+1;




        //Get new Psi

        //toxicity slope
        j=5;

        psiprop=as_scalar(arma::randn(1))*bvar[j] + psi;

        alpha =   Like(YE,YT,Doses,beta,psiprop,CoNum) - Like(YE,YT,Doses, beta, psi,CoNum);
        alpha = alpha - .5*pow(psiprop-Hypermeans[j],2)/Hypervars[j] + .5*pow(psi-Hypermeans[j],2)/Hypervars[j];

        U=log(as_scalar(arma::randu(1)));

        if(U<alpha){
          psi=psiprop;
          Intb[j]=Intb[j]+1;
        }

        Numb[j]=Numb[j]+1;









        if(b>(B-B1-1)){

          StoreInx = b-B1;

          for(j=0;j<5;j++){
            ParamStore(StoreInx,j)=beta[j];
          }
          ParamStore(StoreInx,5)=psi;

          //Fill in Toxcity and Efficacy probabilities


          for(j=0;j<Dose.n_rows;j++){
            PE = beta[0]+beta[1]*Dose[j]+beta[2]*pow(Dose[j],2);
            PT = beta[3]+beta[4]*Dose[j];

            PE = exp(PE);
            PT=exp(PT);
            PE=PE/(1+PE);
            PT = PT/(1+PT);
            piEStore(StoreInx,j)=PE;
            piTStore(StoreInx,j)=PT;


            if(PE>Accept[0]){
              AcceptEff(StoreInx,j)=1;
            }else{
              AcceptEff(StoreInx,j)=0;

            }

            if(PT<Accept[1]){
              AcceptTox(StoreInx,j)=1;
            }else{
              AcceptTox(StoreInx,j)=0;

            }






          }



        }



      }

      //Compute posterior mean



      for(j=0;j<Dose.n_rows;j++){
        if(sum(Doses2==j)>=cohort){
          ACCEPTEFF[j]=sum(AcceptEff.col(j))>(Lower(0)*B1)  ;
        }else{
          ACCEPTEFF[j]=1;
        }
        ACCEPTTOX[j]=sum(AcceptTox.col(j))>(Lower(1)*B1) ;
      }


      //If ==1, for both EFF and TOX then dose j is acceptable

      //Determine Optimal Dose

      //Get Posterior mean of parameters
      for(j=0;j<5;j++){
        beta[j]=sum( ParamStore.col(j))/ParamStore.n_rows;
      }


      for(j=0;j<Dose.n_rows;j++){
        PE = beta[0]+beta[1]*Dose[j]+beta[2]*pow(Dose[j],2);
        PT = beta[3]+beta[4]*Dose[j];

        PE = exp(PE);
        PT=exp(PT);
        PE=PE/(1+PE);
        PT = PT/(1+PT);
        PiEff(j)=PE;
        PiTox(j)=PT;

      }






      //Now get the mean desireability for each dose if they are acceptable
      for(j=0;j<Dose.n_rows;j++){
        if((ACCEPTEFF[j]+ACCEPTTOX[j])==2){
          //Dose is ACCEPTABLE
          DESIRE[j]=1-pow(pow(((PiEff(j)-1)/(Contour[0]-1)),p)+pow((PiTox(j)/Contour[1]),p),1/p);
          ACCEPT[j]=1;

        }else{
          ACCEPT[j]=0;
          DESIRE[j]=-1000;
        }



      }



      if(sum(ACCEPT)>0){


        //Now pick the dose





        if((i<MinCohort)){

          OptDose=ReturnOpt( DESIRE, DoseTried);









        }else{
          //Ok let's adaptively randomize patients



          OptDose=  GetDose3(DESIRE,DoseTried);









        }









      }else{

        if(i>1){
          //Trial Stopped
          OptDose=-1;
          STOPPED=1;


          CHOSENDOSE[nRep]=OptDose+1;
          for(j=0;j<Dose.n_rows;j++){
            UTStore(nRep,j)= DESIRE[j];
          }


          for(j=0;j<Nmax;j++){
            TrialStore(nRep*Nmax+j,0)=Doses2(j);
            TrialStore(nRep*Nmax+j,1)=YE(j);
            TrialStore(nRep*Nmax+j,2)=YT(j);



          }



          break;


        }else{
          OptDose=0;
        }

      }






    }


    if(STOPPED==0){


      Intb=Intb.zeros()+1;
      Numb=Numb.zeros()+2;
      bvar=bvar.zeros()+1;



      for(j=0;j<5;j++){
        beta[j]=Hypermeans[j];
      }
      psi=Hypermeans[5];

      //Perform MCMC
      for(b=0;b<B;b++){


        if(b<(B/2 + 2)){
          if(b%250==0){

            for(j=0;j<6;j++){
              if((Intb[j]/Numb[j])>.5){
                bvar[j]=bvar[j]*2;
              }

              if((Intb[j]/Numb[j])<.2){
                bvar[j]=bvar[j]/2;
              }


              Intb[j]=1;
              Numb[j]=2;

            }





          }
        }




        //All but beta_T can be less than 0, sample those
        for(j=0;j<4;j++){

          betaprop=beta;
          betaprop[j]=as_scalar(arma::randn(1))*bvar[j] + betaprop[j];

          alpha =   Like(YE,YT,Doses,betaprop,psi,CoNum) - Like(YE,YT,Doses, beta, psi,CoNum);
          alpha = alpha - .5*pow(betaprop[j]-Hypermeans[j],2)/Hypervars[j] + .5*pow(beta[j]-Hypermeans[j],2)/Hypervars[j];

          U=log(as_scalar(arma::randu(1)));

          if(U<alpha){
            beta[j]=betaprop[j];
            Intb[j]=Intb[j]+1;
          }

          Numb[j] = Numb[j]+1;





        }


        //toxicity slope
        j=4;
        betaprop=beta;
        betaprop[j]=exp(as_scalar(arma::randn(1))*bvar[j] + log(betaprop[j]));

        alpha =   Like(YE,YT,Doses,betaprop,psi,CoNum) - Like(YE,YT,Doses, beta, psi,CoNum);
        alpha = alpha - .5*pow(betaprop[j]-Hypermeans[j],2)/Hypervars[j] + .5*pow(beta[j]-Hypermeans[j],2)/Hypervars[j];

        alpha = alpha + log(betaprop[j]) - log(beta[j]);


        U=log(as_scalar(arma::randu(1)));

        if(U<alpha){
          beta[j]=betaprop[j];
          Intb[j]=Intb[j]+1;
        }

        Numb[j] = Numb[j]+1;




        //Get new Psi

        //toxicity slope
        j=5;

        psiprop=as_scalar(arma::randn(1))*bvar[j] + psi;

        alpha =   Like(YE,YT,Doses,beta,psiprop,CoNum) - Like(YE,YT,Doses, beta, psi,CoNum);
        alpha = alpha - .5*pow(psiprop-Hypermeans[j],2)/Hypervars[j] + .5*pow(psi-Hypermeans[j],2)/Hypervars[j];

        U=log(as_scalar(arma::randu(1)));

        if(U<alpha){
          psi=psiprop;
          Intb[j]=Intb[j]+1;
        }

        Numb[j]=Numb[j]+1;









        if(b>(B-B1-1)){

          StoreInx = b-B1;

          for(j=0;j<5;j++){
            ParamStore(StoreInx,j)=beta[j];
          }
          ParamStore(StoreInx,5)=psi;

          //Fill in Toxcity and Efficacy probabilities


          for(j=0;j<Dose.n_rows;j++){
            PE = beta[0]+beta[1]*Dose[j]+beta[2]*pow(Dose[j],2);
            PT = beta[3]+beta[4]*Dose[j];

            PE = exp(PE);
            PT=exp(PT);
            PE=PE/(1+PE);
            PT = PT/(1+PT);
            piEStore(StoreInx,j)=PE;
            piTStore(StoreInx,j)=PT;


            if(PE>Accept[0]){
              AcceptEff(StoreInx,j)=1;
            }else{
              AcceptEff(StoreInx,j)=0;

            }

            if(PT<Accept[1]){
              AcceptTox(StoreInx,j)=1;
            }else{
              AcceptTox(StoreInx,j)=0;

            }






          }



        }



      }

      //Compute posterior mean


      for(j=0;j<Dose.n_rows;j++){
        if(sum(Doses2==j)>=cohort){
          ACCEPTEFF[j]=sum(AcceptEff.col(j))>(Lower(0)*B1)  ;
        }else{
          ACCEPTEFF[j]=1;
        }
        ACCEPTTOX[j]=sum(AcceptTox.col(j))>(Lower(1)*B1) ;
      }



      //If ==1, for both EFF and TOX then dose j is acceptable

      //Determine Optimal Dose

      //Get Posterior mean of parameters
      for(j=0;j<5;j++){
        beta[j]=sum( ParamStore.col(j))/ParamStore.n_rows;
      }


      for(j=0;j<Dose.n_rows;j++){
        PE = beta[0]+beta[1]*Dose[j]+beta[2]*pow(Dose[j],2);
        PT = beta[3]+beta[4]*Dose[j];

        PE = exp(PE);
        PT=exp(PT);
        PE=PE/(1+PE);
        PT = PT/(1+PT);
        PiEff(j)=PE;
        PiTox(j)=PT;

      }






      //Now get the mean desireability for each dose if they are acceptable
      for(j=0;j<Dose.n_rows;j++){
        if((ACCEPTEFF[j]+ACCEPTTOX[j])==2){
          //Dose is ACCEPTABLE
          DESIRE[j]=1-pow(pow(((PiEff(j)-1)/(Contour[0]-1)),p)+pow((PiTox(j)/Contour[1]),p),1/p);
          ACCEPT[j]=1;

        }else{
          ACCEPT[j]=0;
          DESIRE[j]=-1000;
        }



      }





      if(sum(ACCEPT)>0){


        for(j=0;j<Dose.n_rows;j++){
          if(DoseTried(j)==0){
            DESIRE(j)=-1000;

          }
        }


        OptDose=ReturnOpt( DESIRE, DoseTried);





      }else{
        OptDose=-1;
      }












    }else{
      OptDose=-1;
    }



    CHOSENDOSE[nRep]=OptDose+1;
    for(j=0;j<Dose.n_rows;j++){
      UTStore(nRep,j)= DESIRE[j];
    }


    for(j=0;j<Nmax;j++){
      TrialStore(nRep*Nmax+j,0)=Doses2(j);
      TrialStore(nRep*Nmax+j,1)=YE(j);
      TrialStore(nRep*Nmax+j,2)=YT(j);



    }

    nRep=nRep+1;


  }




  List z1 = List::create(CHOSENDOSE,UTStore,TrialStore,ParamStore);

  return(z1);
}



















arma::mat inv1(arma::mat Y){

  arma::mat Y1=Y;

  double det = Y(0,0)*Y(1,1)-Y(0,1)*Y(1,0);


  Y1(0,0)=Y(1,1);
  Y1(1,1)=Y(0,0);
  Y1(0,1)=-Y(0,1);
  Y1(1,0)=-Y(1,0);

  Y1=Y1/det;
  return(Y1);


}

//' Samples from the posterior of the utility based phase12 model.
//'
//' Takes arguments of data, hypermens and hypervariance vectors and returns a list of posterior samples from the Utility based phase12 model decribed by Chapple and Thall (2019).
//'
//'@param YE Binary indicator vector of efficacy status.
//'@param YT Binary indicator vector of toxicity status.
//'@param Doses Vector of integer Doses given to patients.
//'@param HypermeansEFF Vector of length nDose for dose prior means for efficacy.
//'@param HypermeansTOX Vector of length nDose for dose prior means for toxicity
//'@param Hypervars Length 3 vector of hypervariances.Hypervars(1) contains sigma_0^2, Hypervars(2) contains sigma_mu, Hypervars(3) contains tau - the frailty variance.
//'@param B Number of iterations to run for the MCMC.
//'@return A list of posterior samples after burnin in order: Posterior efficacy dose-vector, Posterior toxicity dose-vector, Posterior correlation.
//'@examples
//'n=100  #Generate Data
//'YE=rbinom(n,1,.6)
//'YT=rbinom(n,1,.2)
//'nDose=5
//'Doses=sample(1:nDose,n,replace=TRUE)
//'##Hyperparameters
//'HypermeansEFF=c(-1,-.5,0,.5,1,2)
//'HypermeansTOX=HypermeansEFF
//'Hypervars=c(1,16,1)
//'B=100
//'UTEFFTOX(YE, YT,Doses,HypermeansEFF,HypermeansTOX, Hypervars, B)
//'@export
//[[Rcpp::export]]
List UTEFFTOX(arma::vec YE, //Binary indicators of efficacy
              arma::vec YT, //Binary indicators of Toxicity
              arma::vec Doses, //Vector of Numerical Doses given to patients
              arma::vec HypermeansEFF, //Vector of length nDose + 1 for dose prior means for efficacy
              arma::vec HypermeansTOX, //Vector of length nDose + 1 for dose prior means for toxicity
              arma::vec Hypervars, // (\sigma^2_E, \sigma^2_T, \sigma^2_{E,0},\sigma^2_{T,0}, \tau^2, \corr between EFF-TOX )
              double B // Number of reps to perform in MCMC
){


  //This should be a bit different in the actual trial conduct
  Doses=Doses-1;  //Formats dose vector for c++



  //Extract hyperparameters
  int nDose = HypermeansEFF.n_rows;

  //Get The hypervars
  double SigmaE = Hypervars[0];  //Dose effect EFF vars
  double SigmaT = Hypervars[0];  //Dose effect TOX vars
  double SigmaE0 = Hypervars[1]; //MEAN Dose effect EFF vars
  double SigmaT0 = Hypervars[1]; //MEAN Dose effect TOX vars
  double tau = Hypervars[2]; //Variance parameter for frailty
  double phivar=Hypervars[2];  //Variance parameter for frailty correlations
  double phi=0;
  double phinew=0;
  //  double rho = 2*exp(phi)/(1+exp(phi))-1;  //Correlation between EFF-TOX within frailties.

  double rho=0; //Correlation between Eff-Tox within frailties




  //Important Integers
  double B1 = B/2;
  //Used for for loop
  int b=0;
  int i=0; //Patient level index
  int j =0; //For indexing doses


  int StoreInx = 0;


  //Ok First we need to set up our storage
  int n = Doses.n_rows; //Sample Size

  arma::vec epsilonE(n); //Vector containing latent effiacy
  arma::vec epsilonT(n); //Vector containing latent toxicity
  //Ok let's fill these with starting values depending on patient (Y_E, Y_T)
  epsilonE=YE - .5;
  epsilonT=YT - .5;
  //Starting values are all -.5 or .5

  //Get sums of counts within each dose
  arma::vec NumDose(nDose);
  int count=0; //count for number of treated at each dose
  //Loop over each dose
  for(j=0;j<nDose;j++){
    //Loop over each individual and count
    count=0;
    for(i=0;i<n;i++){
      if(Doses[i]==j){
        count++;
      }


    }

    NumDose[j]=count;

  }

  //Now NumDose contains the number treated at each dose




  //Dose mean vectors
  arma::vec MuE(nDose);
  arma::vec MuT(nDose);
  MuE.zeros();
  MuT.zeros();

  //Storage matrix for these:
  arma::mat MuEStore(B1,nDose);
  arma::mat MuTStore(B1,nDose);
  //Storage for epsilons
  arma::mat epsilonEStore(B1,n);
  arma::mat epsilonTStore(B1,n);


  //MCMC Quantities
  double U = 0; //For metropolis hastings
  double alpha = 0; //For metropolis hastings
  double epprop = 0; //proposal values for epsilon
  double  muprop = 0; //proposal for mu_epsilon



  //Get solved covariance matrix that we need for evaluation of individual
  //Latent EFF-TOX variables
  arma::mat SIGMA(2,2);
  //Fill the matrix
  SIGMA(0,0)=SigmaE + tau;
  SIGMA(0,1)=rho*tau;
  SIGMA(1,0)=rho*tau;
  SIGMA(1,1)=SigmaT+tau;
  //Ok now let's invert this matrix
  arma::mat SIGMAINV=inv1(SIGMA);


  //Fill in prior variance matrix for dose specific parameters
  arma::mat Sigma0(2,2);
  Sigma0.zeros();
  Sigma0(0,0)=1/SigmaE0;
  Sigma0(1,1)=1/SigmaT0;
  //Fill in prior mean vector for dose specific parameters
  arma::vec MEANS0(2);
  MEANS0[0]=0;
  MEANS0[1]=0;

  //Let's get all our sigma matrices so we don't need to  do them later.

  arma::mat SigmaNEW(2,2); //Used in sampling
  arma::mat SigmaNEWINV=SigmaNEW;


  //Make meanvec for MCMC sampling each latent vector
  arma::vec MEANVEC(2);
  MEANVEC.zeros();

  //For counting sum of epsilons
  arma::vec epVEC(2);


  arma::vec ORDER(nDose);
  ORDER.zeros();
  ORDER=ORDER+1;

  arma::vec ORDERPROP=ORDER;


  //These are the efficacy and toxicity tuning params
  double epEC = 1;
  double epTC = 1;


  //Used for sampling condiitonal norm, med
  double munorm=0;
  double signorm=0;

  double rhonew=0;


  arma::mat SIGMANEW(2,2);
  arma::mat SIGMANEWINV(2,2);

  arma::mat SIGMALATE(2,2);
  SIGMALATE(0,0)=tau;
  SIGMALATE(0,1)=rho*tau;
  SIGMALATE(1,0)=rho*tau;
  SIGMALATE(1,1)=tau;
  arma::mat SIGMALATEINV = inv1(SIGMALATE);

  arma::vec rhoStore(B1);

  arma::vec z9(2);
  double corr=0;

  //counters
  double nrho = 1;
  double arho=1;

  double crho = .125;
  rho=0;

  int k=0;


  double pmono=.75;


  double holdmax=0;
  double holdmin=1;


  arma::mat ORDERSTORE(B1,nDose);
  double ESS = 10;

  arma::vec HOLDMEANS = ORDER;
  arma::vec HOLDSDS = ORDER;

  arma::vec MUEPROP = MuE;

  int Global = 0;

  double PGLOBAL = .1;
  //Perform MCMC


  for(b=0;b<B;b++){



    if( ((b%100==0) & (b<(B-B1)))){
      if((arho/nrho)<.2){
        crho=crho/2;

      }

      if((arho/nrho)>.5){
        crho=min1(crho*2,.25);
      }



      arho=1;
      nrho=1;

    }




    //Now let's sample the mean parameters
    for(j=0;j<nDose;j++){
      epVEC.zeros();
      //Get sum of epsilon vectors
      for(i=0;i<n;i++){
        if(Doses[i]==j){
          epVEC[0]=epVEC[0]+epsilonE[i];
          epVEC[1]=epVEC[1]+epsilonT[i];
        }
      }

      //This is dose specific hyperparameters
      MEANS0[0]=HypermeansEFF[j];
      MEANS0[1]=HypermeansTOX[j];

      //First make the mean and covariance matrices
      SigmaNEW = Sigma0 + NumDose[j]*SIGMAINV;



      SigmaNEWINV = inv1(SigmaNEW);


     MEANVEC = MATMULT(SigmaNEWINV,(MATMULT(Sigma0,MEANS0) + MATMULT(SIGMAINV,epVEC)));



      //Sampling for toxicity
      //Get the conditional distribution
      signorm = pow((1-corr)*SigmaNEWINV(1,1),.5);
      //Conditional mean
      munorm = MEANVEC[1] + corr*(MuE[j]-MEANVEC[0])*pow(SigmaNEWINV(1,1)/SigmaNEWINV(0,0),.5);



      //Generate new variable, where it's truncated
      if(j>0){

        if(j==(nDose-1)){
          MuT[j] = max1(MuT[j-1],as_scalar(arma::randn(1))*signorm+munorm);
          //Last dose level
        }else{
          //Now were in the middle doses
          MuT[j] = max1(MuT[j-1],min1(MuT[j+1],as_scalar(arma::randn(1))*signorm+munorm));
        }



      }else{
        //First dose mean efficacy parameter
        MuT[j] = min1(MuT[j+1],as_scalar(arma::randn(1))*signorm+munorm);

      }






      //Posterior distribution is truncated normal with above mean vector and covariance matrix
      //This comes straight from a conjugate normal setup.



      corr=SigmaNEWINV(0,1)/pow(SigmaNEWINV(0,0)*SigmaNEWINV(1,1),.5);


      //Get the conditional distribution
      signorm = pow((1-corr)*SigmaNEWINV(0,0),.5);
      //Conditional mean
      munorm = MEANVEC[0] + corr*(MuT[j]-MEANVEC[1])*pow(SigmaNEWINV(0,0)/SigmaNEWINV(1,1),.5);





      //Generate new variable, where it's truncated

      HOLDMEANS[j]=munorm;
      HOLDSDS[j]=signorm;




      //Generate new variable, where it's truncated


      if(j==(nDose-1)){
        if(ORDER(j)>0){

          //It's gotta be bigger than the last one
          MuE(j) = max1(MuE(j-1)+.0001,as_scalar(arma::randn(1))*signorm+munorm);
        }else{

          //Must be LESS than or equal to the the last one
          MuE(j) = min1(MuE(j-1),as_scalar(arma::randn(1))*signorm+munorm);


        }
        //Last dose level
      }else{

        if(j>0){
          //Now were in the middle doses


          if(ORDER(j)==1){
            //if Order(j)=1, this has got to be bigger entry j-1

            if(ORDER(j+1)>0){
              //MuE(j) < MuE(j+1)
              //MuE(j) > MuE(j-1)
              //Which is the first ordering?
              MuE(j) = max1(MuE(j-1)+.0001,min1(MuE(j+1)-.0001,as_scalar(arma::randn(1))*signorm+munorm));

            }else{
              //Must be bigger than MuE(j-1)
              //Bigger or equal to MuE(j+1)
              MuE(j) = max1(MuE(j+1),max1(MuE(j-1)+.0001,as_scalar(arma::randn(1))*signorm+munorm));




            }





          }else{
            //must be smaller than or equal to j-1


            if(ORDER(j+1)>0){
              //MuE(j) < MuE(j+1)
              //MuE(j) <= MuE(j-1)
              //Which is the first ordering?
              MuE(j) = min1(MuE(j-1),min1(MuE(j+1)-.0001,as_scalar(arma::randn(1))*signorm+munorm));

            }else{
              //must be <= MuE(j-1)
              //Must be >= MuE(j+1)
              MuE(j) = max1(MuE(j+1),min1(MuE(j-1),as_scalar(arma::randn(1))*signorm+munorm));




            }




          }


        }else{
          //First dose mean efficacy parameter
          if(ORDER(j+1)>0){
            //Can't be bigger than the param above with ORDER==1
            //Must be less than j-1 too
            //Ok this parameter cant be bigger than the parameter for j+1
            MuE(j) = min1(MuE(j+1)-.0001,as_scalar(arma::randn(1))*signorm+munorm);
          }else{
            //Must be bigger or equal to j+1
            MuE(j) = max1(MuE(j+1),as_scalar(arma::randn(1))*signorm+munorm);



          }
        }


      }



      //Ok lets propose changing the order for each
      if(Global==0){
        if(j>0){
          //No ordering for the first value
          if(j<(nDose-1)){
            if(ORDER(j)==1){
              ///Can we change the order W.R.T. the maximum?
              muprop = MuE(j) - as_scalar(arma::randu(1))*crho;

              if(ORDER(j+1)==1){
                //We need to propose MuE(j)<=MuE(j-1)
                //And MuE(j)<MuE(j+1)
                muprop = min1(min1(MuE(j+1)-.0001,MuE(j-1)),muprop);

              }else{
                //We need to propose MuE(j)<=MuE(j-1)
                //And MuE(j)>=MuE(j+1)
                muprop = min1(max1(MuE(j+1),muprop),MuE(j-1));


              }

              //Ok let's do alpha
              alpha = -.5*pow(((muprop-munorm)/signorm),2)+.5*pow(((MuE(j)-munorm)/signorm),2)+log(1-pmono)-log(pmono);

              U = log(as_scalar(arma::randu(1)));

              if(U<alpha){
                MuE(j)=muprop;
                ORDER(j)=0;
              }



            }else{

              muprop = holdmax + as_scalar(arma::randu(1))*crho;


              if(ORDER(j+1)==1){
                //We need to propose MuE(j)>MuE(j-1)
                //And MuE(j)<MuE(j+1)
                muprop = max1(min1(MuE(j+1)-.0001,muprop) , MuE(j-1)+.0001);

              }else{
                //We need to propose MuE(j)>MuE(j-1)
                //And MuE(j)>=MuE(j+1)
                muprop = max1(max1(MuE(j-1)+.0001,muprop), MuE(j+1));


              }

              //Ok let's do alpha
              alpha = -.5*pow(((muprop-munorm)/signorm),2)+.5*pow(((MuE(j)-munorm)/signorm),2)+log(pmono)-log(1-pmono);

              U = log(as_scalar(arma::randu(1)));

              if(U<alpha){
                MuE(j)=muprop;
                ORDER(j)=1;
              }


            }
          }else{

            if(ORDER(j)==1){
              ///Can we change the order W.R.T. the maximum?
              muprop = MuE(j) - as_scalar(arma::randu(1))*crho;


              //We need to propose MuE(j)<=MuE(j-1)
              muprop = min1(muprop,MuE(j-1));




              //Ok let's do alpha
              alpha = -.5*pow(((muprop-munorm)/signorm),2)+.5*pow(((MuE(j)-munorm)/signorm),2)+log(1-pmono)-log(pmono);

              U = log(as_scalar(arma::randu(1)));

              if(U<alpha){
                MuE(j)=muprop;
                ORDER(j)=0;
              }



            }else{

              muprop = holdmax + as_scalar(arma::randu(1))*crho;



              muprop = max1(muprop , MuE(j-1)+.0001);



              //Ok let's do alpha
              alpha = -.5*pow(((muprop-munorm)/signorm),2)+.5*pow(((MuE(j)-munorm)/signorm),2)+log(pmono)-log(1-pmono);

              U = log(as_scalar(arma::randu(1)));

              if(U<alpha){
                MuE(j)=muprop;
                ORDER(j)=1;
              }


            }

          }
        }
      }







    }






    //Propose changing Global ordering
    if(Global == 0){
      //Propose setting all positive or all negative
      U=as_scalar(arma::randu(1));
      holdmax=sum(ORDER)-1; //How many monotone

      if(U<.5){
        //Global set to -
        //Old density
        alpha = log(PGLOBAL) -CHOOSE(ORDER.n_rows-1,holdmax) - holdmax*log(pmono) - (ORDER.n_rows-1-holdmax)*log(1-pmono) - log(1-2*PGLOBAL);
        //Let's Globally re-arrange the mus in decreasing/constant order.
        MUEPROP = GlobalPropose(MuE,-1);
        //Let's loop over each dose and adjust the proposal ratio
        alpha = alpha - ESS*.9*log(pmono) - ESS*.1*log(1-pmono);

        for(j=0;j<nDose;j++){

          alpha = alpha + .5*pow((MuE(j)-HOLDMEANS(j))/HOLDSDS(j),2) - .5*pow((MUEPROP(j)-HOLDMEANS(j))/HOLDSDS(j),2);

        }

        U=as_scalar(arma::randu(1));

        if(U<alpha){
          //NO ORDERING
          ORDER.zeros();
          Global = -1;
          MuE = MUEPROP;

        }



      }else{
        //Global set to +

        alpha = log(PGLOBAL) -CHOOSE(ORDER.n_rows-1,holdmax) - holdmax*log(pmono) - (ORDER.n_rows-1-holdmax)*log(1-pmono) - log(1-2*PGLOBAL);
        //Let's Globally re-arrange the mus in increasing order.
        MUEPROP = GlobalPropose(MuE,1);
        //Let's loop over each dose and adjust the proposal ratio

        alpha = alpha - ESS*.9*log(pmono) - ESS*.1*log(1-pmono);

        for(j=0;j<nDose;j++){

          alpha = alpha + .5*pow((MuE(j)-HOLDMEANS(j))/HOLDSDS(j),2) - .5*pow((MUEPROP(j)-HOLDMEANS(j))/HOLDSDS(j),2);

        }

        U=as_scalar(arma::randu(1));

        if(U<alpha){
          //NO ORDERING
          ORDER.zeros();
          ORDER=ORDER+1;
          Global = 1;
          MuE = MUEPROP;

        }



      }



    }



    //Propose changing Global ordering
    if(Global == -1){
      //Propose setting all positive or all negative
      U=as_scalar(arma::randu(1));
      holdmax=sum(ORDER)-1; //How many monotone

      if(U<.5){
        //Global set to Freely varying
        MUEPROP = GlobalPropose(MuE,0);
        ORDERPROP = ORDER;
        for(k=1;k<ORDER.n_rows;k++){
          if(MUEPROP(k)>MUEPROP(k-1)){
            ORDERPROP(k)=1;
          }
        }

        holdmax=sum(ORDERPROP)-1;
        //Old density

        pmono = GetBeta(ESS*.9 + holdmax,.1*ESS+nDose - holdmax-1);
        pmono = as_scalar(arma::randu(1));

        alpha = -log(PGLOBAL) + CHOOSE(ORDER.n_rows-1,holdmax) + holdmax*log(pmono) + (ORDER.n_rows-1-holdmax)*log(1-pmono) + log(1-2*PGLOBAL);
        //Let's Globally re-arrange the mus in decreasing/constant order.
        //Adjust proposal for this beta
        alpha = alpha + ESS*.9*log(pmono) + ESS*.1*log(1-pmono);


        //Let's Globally re-arrange the mus in decreasing/constant order.

        //Let's loop over each dose and adjust the proposal ratio

        for(j=0;j<nDose;j++){

          alpha = alpha + .5*pow((MuE(j)-HOLDMEANS(j))/HOLDSDS(j),2) - .5*pow((MUEPROP(j)-HOLDMEANS(j))/HOLDSDS(j),2);

        }

        U=as_scalar(arma::randu(1));

        if(U<alpha){
          //NO ORDERING
          ORDER=ORDERPROP;
          Global = 0;
          MuE = MUEPROP;

        }



      }else{
        //Global set to +

        alpha = 0;
        //Let's Globally re-arrange the mus in increasing order.
        MUEPROP = GlobalPropose(MuE,1);
        //Let's loop over each dose and adjust the proposal ratio

        for(j=0;j<nDose;j++){

          alpha = alpha + .5*pow((MuE(j)-HOLDMEANS(j))/HOLDSDS(j),2) - .5*pow((MUEPROP(j)-HOLDMEANS(j))/HOLDSDS(j),2);

        }

        U=as_scalar(arma::randu(1));

        if(U<alpha){
          //NO ORDERING
          ORDER.zeros();
          ORDER=ORDER+1;
          Global = 1;
          MuE = MUEPROP;

        }



      }



    }



    //Propose changing Global ordering
    if(Global == 1){
      //Propose setting all positive or all negative
      U=as_scalar(arma::randu(1));
      holdmax=sum(ORDER)-1; //How many monotone

      if(U<.5){
        //Global set to -
        //Old density
        alpha = 0;
        //Let's Globally re-arrange the mus in decreasing/constant order.
        MUEPROP = GlobalPropose(MuE,-1);
        //Let's loop over each dose and adjust the proposal ratio

        for(j=0;j<nDose;j++){

          alpha = alpha + .5*pow((MuE(j)-HOLDMEANS(j))/HOLDSDS(j),2) - .5*pow((MUEPROP(j)-HOLDMEANS(j))/HOLDSDS(j),2);

        }

        U=as_scalar(arma::randu(1));

        if(U<alpha){
          //NO ORDERING
          ORDER.zeros();
          Global = -1;
          MuE = MUEPROP;

        }



      }else{
        //Global set to free
        //Global set to Freely varying

        MUEPROP = GlobalPropose(MuE,0);
        ORDERPROP = ORDER;
        for(k=1;k<ORDER.n_rows;k++){
          if(MUEPROP(k)>MUEPROP(k-1)){
            ORDERPROP(k)=1;
          }
        }

        holdmax=sum(ORDERPROP)-1;
        //Old density
        pmono = GetBeta(ESS*.9 + holdmax,.1*ESS+nDose - holdmax-1);
        pmono=as_scalar(arma::randu(1));

        alpha = -log(PGLOBAL) + CHOOSE(ORDER.n_rows-1,holdmax) + holdmax*log(pmono) + (ORDER.n_rows-1-holdmax)*log(1-pmono) + log(1-2*PGLOBAL);
        //Let's Globally re-arrange the mus in decreasing/constant order.
        //Adjust proposal for this beta
        alpha = alpha + ESS*.9*log(pmono) + ESS*.1*log(1-pmono);


        //Let's loop over each dose and adjust the proposal ratio

        for(j=0;j<nDose;j++){

          alpha = alpha + .5*pow((MuE(j)-HOLDMEANS(j))/HOLDSDS(j),2) - .5*pow((MUEPROP(j)-HOLDMEANS(j))/HOLDSDS(j),2);

        }

        U=as_scalar(arma::randu(1));

        if(U<alpha){
          //NO ORDERING
          ORDER=ORDERPROP;
          Global = 0;
          MuE = MUEPROP;

        }


      }



    }



    if(Global==0){
      //Not global increasing or decreasing
      holdmax=sum(ORDER)-1;
      //Ok Draw the new probability of monotonicity
      pmono = GetBeta(ESS*.9 + holdmax,.1*ESS+nDose - holdmax-1);
      pmono= GetBeta(1 + holdmax,1 +nDose - holdmax-1);
      //              pmono=.5;
    }








    //   rhonew=2*exp(phinew)/(1+exp(phinew))-1;

    // Rf_PrintValue(wrap(z9));

    rhonew = TruncNormal(rho,crho);




    SIGMANEW(0,0)=tau + SigmaE ;
    SIGMANEW(0,1)=rhonew*tau;
    SIGMANEW(1,0)=rhonew*tau;
    SIGMANEW(1,1)=tau  + SigmaT ;
    SIGMANEWINV=inv1(SIGMANEW);



    alpha = 0;


    for(i=0;i<n;i++){


      epVEC[0]=epsilonE[i]-MuE[Doses[i]];
      epVEC[1]=epsilonT[i]-MuT[Doses[i]];



      //   alpha = alpha - as_scalar(.5*epVEC.t()*SIGMANEWINV*epVEC) + as_scalar(.5*epVEC.t()*SIGMA*epVEC);
      //Determinant
      alpha = alpha- epVEC[0]*(epVEC[0]*SIGMANEWINV(0,0)+epVEC[1]*SIGMANEWINV(1,0))-epVEC(1)*(epVEC[0]*SIGMANEWINV(0,1)+epVEC[1]*SIGMANEWINV(1,1));

      alpha = alpha+ epVEC[0]*(epVEC[0]*SIGMAINV(0,0)+epVEC[1]*SIGMAINV(1,0))+epVEC(1)*(epVEC[0]*SIGMAINV(0,1)+epVEC[1]*SIGMAINV(1,1));


      alpha = alpha - .5*log(abs1(SIGMANEW(1,1)*SIGMANEW(0,0)-SIGMANEW(0,1)*SIGMANEW(1,0))) + .5*log(abs1(SIGMA(1,1)*SIGMA(0,0)-SIGMA(0,1)*SIGMA(1,0))) ;



    }





    U=log(as_scalar(arma::randu(1)));



    if(U<alpha){

      SIGMA=SIGMANEW;
      SIGMAINV=SIGMANEWINV;
      rho=rhonew;
      phi=phinew;


      arho=arho+1;
    }
    nrho=nrho+1;






    if(b>(B-B1-1)){

      StoreInx = b-B1;

      for(j=0;j<nDose;j++){
        MuEStore(StoreInx,j)=MuE[j];
        MuTStore(StoreInx,j)=MuT[j];
        ORDERSTORE(StoreInx,j)=ORDER(j);
      }


      for(i=0; i<n; i++){
        epsilonTStore(StoreInx,i) = epsilonT[i];
        epsilonEStore(StoreInx,i) = epsilonE[i];

      }

      rhoStore(StoreInx)=rho;



    }



  }





  //Return the two storage matrices and discard the rest
  List z1 = List::create(MuEStore,MuTStore,ORDERSTORE,rhoStore);
  return(z1);
}







//' Determines the optimal dose to assign the next patient cohort.
//'
//' This function returns the optimal acceptable dose number to assign the next patient cohort or stops the trial if no dose is deemed acceptable.
//' @param YE   Vector containing observed efficacy indicators.
//' @param YT   Vector containing observed toxicity indicators.
//' @param Doses Vector containing numbered Doses of patients in trial.
//' @param Dose Vector containing the standardized doses considered.
//' @param DosesTried Binary vector corresponding to which doses have been tried.
//' @param Hypermeans Vector containing prior hypermeans of length 6 for Eff-Tox parameters.
//' @param Hypervars Vector containing prior hypervariances of length 6 for Eff-Tox parameters.
//' @param Contour Vector containing 4 entries used to make the desireability function. Contour[1] contains a desired toxicity probability given efficacy, Countour[2] contains a desired efficacy probability given toxicity, and (Contour[3],Contour[4]) is an equally desireable pair of efficacy and toxicity probabilities that are non-zero or one.
//' @param PiLim Vector of length two with PiLim[1] containing the acceptable lower limit on efficacy probability and PiLim[2] containing the acceptable upper limit on toxicity probability.
//' @param ProbLim Vector of length two with ProbLim[1] containing the probability cutoff for acceptable efficacy probability and ProbLim[2] containing the probability cutoff for acceptable toxicity probability.
//' @param B Number of iterations to perform in the MCMC.
//' @return The optimal dose level to administer the next patient cohort.
//'@examples
//'##Doses, YE,YT
//'Doses= c(1,1,1,2,2,2,1,1,1,3,3,3,1,1,1,2,2,2)
//'YE = c(0,0,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0)
//'YT=c(0,0,0,1,1,0,1,0,0,1,1,1,0,0,0,1,0,0)
//'##Vector of Numerical Doses
//'Dose = c(1,2,3,3.5,5)
//'Dose=(Dose-mean(Dose))/sd(Dose)
//'##Five doses, but only 3 tried so we have
//'DosesTried=c(1,1,1,0,0)
//'## Contour Vector
//'Contour = c(.35, .75,.7,.4)
//'##Hypermeans
//'Hypermeans = c(.022,3.45,0,-4.23,3.1,0)
//'Hypervars = c(2.6761, 2.6852, .2, 3.1304, 3.1165, 1)
//'Hypervars=Hypervars^2
//'##Acceptability Criteria
//'PiLim = c(.3,.4)
//'ProbLim=c(.1,.1)
//'##Number of iterations
//'B=2000
//'AssignEffTox(YE,YT, Doses, Dose, DosesTried, Hypermeans,  Hypervars, Contour, PiLim,  ProbLim, B )
//'@export
//[[Rcpp::export]]
List AssignEffTox( arma::vec YE, //Observed Efficacy Indicator Vector
                   arma::vec YT, //Observed toxicity indicator vector.
                   arma::vec Doses, //Vector of numeric doses assigned to patients
                   arma::vec Dose, //Vector of Doses considered in the trial
                   arma::vec DosesTried, //Vector of whether or not each dose has been tried
                   arma::vec Hypermeans, //6 vector of prior means
                   arma::vec Hypervars, //6 vector of prior standard deviations
                   arma::vec Contour, //4 vector of Contour parameter
                   arma::vec PiLim, //2 vector of acceptable limits
                   arma::vec ProbLim, //2 vector of cutoff for acceptabilities
                   double B // Number of reps to perform in MCMC
){

  arma::vec Accept=PiLim;
  arma::vec Lower=ProbLim;

  int Stopped=0;


  arma::vec MeanUt(Dose.n_rows);
  arma::vec PiEff(Dose.n_rows);
  arma::vec PiTox(Dose.n_rows);
  arma::vec ACCEPTTOX(Dose.n_rows);
  arma::vec ACCEPTEFF(Dose.n_rows);
  arma::vec DESIRE(Dose.n_rows);
  arma::vec ACCEPT(Dose.n_rows);
  ACCEPTTOX.zeros();
  ACCEPTEFF.zeros();

  double p=0;
  double pu=0;
  double pl=0;
  double tol=.005;



  //Now lets Solve for p to get the desirability
  while(abs1(pow((Contour[2]-1)/(Contour[0]-1),p) + pow(Contour[3]/Contour[1],p)-1) >tol){
    pu = p+.005;
    pl=p-.005;

    if( abs1(pow((Contour[2]-1)/(Contour[0]-1),pu) + pow((Contour[3])/(Contour[1]),pu)-1)<
      abs1(pow((Contour[2]-1)/(Contour[0]-1),pl) + pow((Contour[3])/(Contour[1]),pl)-1)){
      p=pu;
    }else{
      p=pl;
    }




  }



  //What Doses are Acceptable

  arma::vec ACCTOX(Dose.n_rows);
  ACCTOX.zeros();
  arma::vec ACCEFF=ACCTOX;



  int Count=0;




  double B1 = B/2;

  //Used for for loop
  int b=0;
  //Used in Sim look
  int nREP=0;

  //Storage Matrices
  arma::mat piEStore(B1,Dose.n_rows);
  arma::mat piTStore(B1,Dose.n_rows);
  arma::mat AcceptTox(B1,Dose.n_rows);
  arma::mat AcceptEff(B1,Dose.n_rows);
  AcceptTox.zeros();
  AcceptEff.zeros();
  arma::vec DESIRE2(Dose.n_rows);
  DESIRE2.zeros();


  arma::mat ParamStore(B1,6);
  //Setup innitial
  arma::vec beta(5);
  beta.zeros();
  arma::vec betaprop=beta;
  double psi=0;
  double psiprop=0;
  //Quantities for MCMC
  double U=0;
  double alpha=0;
  int m=0;
  int j=0;
  int StoreInx=0;
  double PE=0;
  double PT=0;

  arma::vec bvar(6);
  bvar.zeros();
  bvar=bvar+1;
  arma::vec Intb = bvar;
  arma::vec Numb = bvar + 1;

  arma::vec Doses2=Doses;

  NumericVector z9(2);
  int CoNum=YE.n_rows;

  int STOPPED=0;
  int i=0;
  int OptDose=0;
  double min1=0;



  int nRep=0;

  arma::vec DESIRE1=DESIRE;

  arma::vec z5(2);
  arma::vec DoseTried(Dose.n_rows);





  STOPPED=0;



  Doses2.zeros();
  //Wrap Trial right here
  OptDose=0;
  Doses.zeros();
  DoseTried.zeros();
  DoseTried[0]=1;
  //Wrap around each cohort

  //Fill in next cohort with the data size


  Intb=Intb.zeros()+1;
  Numb=Numb.zeros()+2;
  bvar=bvar.zeros()+1;

  for(j=0;j<5;j++){
    beta[j]=Hypermeans[j];
  }
  psi=Hypermeans[5];

  //Perform MCMC
  for(b=0;b<B;b++){


    if(b<(B/2 + 2)){
      if(b%250==0){

        for(j=0;j<6;j++){
          if((Intb[j]/Numb[j])>.5){
            bvar[j]=bvar[j]*2;
          }

          if((Intb[j]/Numb[j])<.2){
            bvar[j]=bvar[j]/2;
          }


          Intb[j]=1;
          Numb[j]=2;

        }





      }
    }




    //All but beta_T can be less than 0, sample those
    for(j=0;j<4;j++){

      betaprop=beta;
      betaprop[j]=as_scalar(arma::randn(1))*bvar[j] + betaprop[j];

      alpha =   Like(YE,YT,Doses,betaprop,psi,CoNum) - Like(YE,YT,Doses, beta, psi,CoNum);
      alpha = alpha - .5*pow(betaprop[j]-Hypermeans[j],2)/Hypervars[j] + .5*pow(beta[j]-Hypermeans[j],2)/Hypervars[j];

      U=log(as_scalar(arma::randu(1)));

      if(U<alpha){
        beta[j]=betaprop[j];
        Intb[j]=Intb[j]+1;
      }

      Numb[j] = Numb[j]+1;





    }


    //toxicity slope
    j=4;
    betaprop=beta;
    betaprop[j]=exp(as_scalar(arma::randn(1))*bvar[j] + log(betaprop[j]));

    alpha =   Like(YE,YT,Doses,betaprop,psi,CoNum) - Like(YE,YT,Doses, beta, psi,CoNum);
    alpha = alpha - .5*pow(betaprop[j]-Hypermeans[j],2)/Hypervars[j] + .5*pow(beta[j]-Hypermeans[j],2)/Hypervars[j];

    alpha = alpha + log(betaprop[j]) - log(beta[j]);


    U=log(as_scalar(arma::randu(1)));

    if(U<alpha){
      beta[j]=betaprop[j];
      Intb[j]=Intb[j]+1;
    }

    Numb[j] = Numb[j]+1;




    //Get new Psi

    //toxicity slope
    j=5;

    psiprop=as_scalar(arma::randn(1))*bvar[j] + psi;

    alpha =   Like(YE,YT,Doses,beta,psiprop,CoNum) - Like(YE,YT,Doses, beta, psi,CoNum);
    alpha = alpha - .5*pow(psiprop-Hypermeans[j],2)/Hypervars[j] + .5*pow(psi-Hypermeans[j],2)/Hypervars[j];

    U=log(as_scalar(arma::randu(1)));

    if(U<alpha){
      psi=psiprop;
      Intb[j]=Intb[j]+1;
    }

    Numb[j]=Numb[j]+1;









    if(b>(B-B1-1)){

      StoreInx = b-B1;

      for(j=0;j<5;j++){
        ParamStore(StoreInx,j)=beta[j];
      }
      ParamStore(StoreInx,5)=psi;

      //Fill in Toxcity and Efficacy probabilities


      for(j=0;j<Dose.n_rows;j++){
        PE = beta[0]+beta[1]*Dose[j]+beta[2]*pow(Dose[j],2);
        PT = beta[3]+beta[4]*Dose[j];

        PE = exp(PE);
        PT=exp(PT);
        PE=PE/(1+PE);
        PT = PT/(1+PT);
        piEStore(StoreInx,j)=PE;
        piTStore(StoreInx,j)=PT;


        if(PE>Accept[0]){
          AcceptEff(StoreInx,j)=1;
        }else{
          AcceptEff(StoreInx,j)=0;

        }

        if(PT<Accept[1]){
          AcceptTox(StoreInx,j)=1;
        }else{
          AcceptTox(StoreInx,j)=0;

        }






      }



    }



  }

  //Compute posterior mean



  for(j=0;j<Dose.n_rows;j++){
    ACCEPTEFF[j]=sum(AcceptEff.col(j))>(Lower(0)*B1)  ;
    ACCEPTTOX[j]=sum(AcceptTox.col(j))>(Lower(1)*B1) ;
  }




  //If ==1, for both EFF and TOX then dose j is acceptable

  //Determine Optimal Dose

  //Get Posterior mean of parameters
  for(j=0;j<5;j++){
    beta[j]=sum( ParamStore.col(j))/ParamStore.n_rows;
  }


  for(j=0;j<Dose.n_rows;j++){
    PE = beta[0]+beta[1]*Dose[j]+beta[2]*pow(Dose[j],2);
    PT = beta[3]+beta[4]*Dose[j];

    PE = exp(PE);
    PT=exp(PT);
    PE=PE/(1+PE);
    PT = PT/(1+PT);
    PiEff(j)=PE;
    PiTox(j)=PT;

  }






  //Now get the mean desireability for each dose if they are acceptable
  for(j=0;j<Dose.n_rows;j++){
    if((ACCEPTEFF[j]+ACCEPTTOX[j])==2){
      //Dose is ACCEPTABLE
      DESIRE[j]=1-pow(pow(((PiEff(j)-1)/(Contour[0]-1)),p)+pow((PiTox(j)/Contour[1]),p),1/p);
      ACCEPT[j]=1;

    }else{
      ACCEPT[j]=0;
      DESIRE[j]=-1000;
    }



  }



  //Check if we should stop the trial

  if(sum(ACCEPT)>0){


    //Now pick the dose





    OptDose=0;

    for(j=1;j<Dose.n_rows;j++){
      if(DESIRE[j]>DESIRE[j-1]){
        OptDose=j;
      }
    }

    //Is this dose bigger than the dose higher than what's been tried?
    if(DoseTried(OptDose)==0){
      j=0;

      while(DoseTried(j)==1){
        j++;
      }

      OptDose=j;

    }

















  }else{
    //Trial Stopped
    OptDose=-1;
    STOPPED=1;

  }



  List z1 = List::create(OptDose,DESIRE,PiEff,PiTox);


  return(z1);


}




//' Determines the optimal dose to assign the next patient cohort.
//'
//' This function returns the optimal acceptable dose number to assign the next patient cohort or stops the trial if no dose is deemed acceptable.
//' @param YE   Vector containing observed efficacy indicators.
//' @param YT   Vector containing observed toxicity indicators.
//' @param Doses Vector containing numbered Doses of patients in trial.
//' @param Dose Vector containing the standardized doses considered.
//' @param DosesTried Binary vector corresponding to which doses have been tried.
//' @param Hypermeans Vector containing prior hypermeans of length 6 for Eff-Tox parameters.
//' @param Hypervars Vector containing prior hypervariances of length 6 for Eff-Tox parameters.
//' @param UT 2x2 utility matrix.
//' @param PiLim Vector of length two with PiLim[1] containing the acceptable lower limit on efficacy probability and PiLim[2] containing the acceptable upper limit on toxicity probability.
//' @param ProbLim Vector of length two with ProbLim[1] containing the probability cutoff for acceptable efficacy probability and ProbLim[2] containing the probability cutoff for acceptable toxicity probability.
//' @param B Number of iterations to perform in the MCMC.
//' @return The optimal dose level to administer the next patient cohort.
//'@examples
//'##Doses, YE,YT
//'Doses= c(1,1,1,2,2,2,1,1,1,3,3,3,1,1,1,2,2,2)
//'YE = c(0,0,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0)
//'YT=c(0,0,0,1,1,0,1,0,0,1,1,1,0,0,0,1,0,0)
//'##Vector of Numerical Doses
//'Dose = c(1,2,3,3.5,5)
//'Dose=(Dose-mean(Dose))/sd(Dose)
//'##Five doses, but only 3 tried so we have
//'DosesTried=c(1,1,1,0,0)
//''UT = matrix(c(38.23529,100,0,61.76471),nrow=2,byrow=TRUE)
//'##Hypermeans
//'Hypermeans = c(.022,3.45,0,-4.23,3.1,0)
//'Hypervars = c(2.6761, 2.6852, .2, 3.1304, 3.1165, 1)
//'Hypervars=Hypervars^2
//'##Acceptability Criteria
//'PiLim = c(.3,.4)
//'ProbLim=c(.1,.1)
//'##Number of iterations
//'B=2000
//'AssignEffTox(YE,YT, Doses, Dose, DosesTried, Hypermeans,  Hypervars, UT, PiLim,  ProbLim, B )
//'@export
//[[Rcpp::export]]
List AssignEffToxUT( arma::vec YE, //Observed Efficacy Indicator Vector
                     arma::vec YT, //Observed toxicity indicator vector.
                     arma::vec Doses, //Vector of numeric doses assigned to patients
                     arma::vec Dose, //Vector of Doses considered in the trial
                     arma::vec DosesTried, //Vector of whether or not each dose has been tried
                     arma::vec Hypermeans, //6 vector of prior means
                     arma::vec Hypervars, //6 vector of prior standard deviations
                     arma::mat UT, //4 vector of Contour parameter
                     arma::vec PiLim, //2 vector of acceptable limits
                     arma::vec ProbLim, //2 vector of cutoff for acceptabilities
                     double B // Number of reps to perform in MCMC
){

  arma::vec Accept=PiLim;
  arma::vec Lower=ProbLim;

  int Stopped=0;


  arma::vec MeanUt(Dose.n_rows);
  arma::vec PiEff(Dose.n_rows);
  arma::vec PiTox(Dose.n_rows);
  arma::vec ACCEPTTOX(Dose.n_rows);
  arma::vec ACCEPTEFF(Dose.n_rows);
  arma::vec DESIRE(Dose.n_rows);
  arma::vec ACCEPT(Dose.n_rows);
  ACCEPTTOX.zeros();
  ACCEPTEFF.zeros();
  ACCEPT.zeros();
  DESIRE.zeros();
  MeanUt.zeros();
  PiEff.zeros();
  PiTox.zeros();

  double p=0;
  double pu=0;
  double pl=0;
  double tol=.005;






  //What Doses are Acceptable

  arma::vec ACCTOX(Dose.n_rows);
  ACCTOX.zeros();
  arma::vec ACCEFF=ACCTOX;



  int Count=0;




  double B1 = B/2;

  //Used for for loop
  int b=0;
  //Used in Sim look
  int nREP=0;

  //Storage Matrices
  arma::mat piEStore(B1,Dose.n_rows);
  arma::mat piTStore(B1,Dose.n_rows);
  arma::mat AcceptTox(B1,Dose.n_rows);
  arma::mat AcceptEff(B1,Dose.n_rows);
  AcceptTox.zeros();
  AcceptEff.zeros();
  piEStore.zeros();
  piTStore.zeros();
  arma::vec DESIRE2(Dose.n_rows);
  DESIRE2.zeros();


  arma::mat ParamStore(B1,6);
  ParamStore.zeros();
  //Setup innitial
  arma::vec beta(5);
  beta.zeros();
  arma::vec betaprop=beta;
  double psi=0;
  double psiprop=0;
  //Quantities for MCMC
  double U=0;
  double alpha=0;
  int m=0;
  int j=0;
  int StoreInx=0;
  double PE=0;
  double PT=0;

  arma::vec bvar(6);
  bvar.zeros();
  bvar=bvar+1;
  arma::vec Intb = bvar;
  arma::vec Numb = bvar + 1;

  arma::vec Doses2=Doses;

  NumericVector z9(2);
  int CoNum=YE.n_rows;

  int STOPPED=0;
  int i=0;
  int OptDose=0;
  double min1=0;



  int nRep=0;

  arma::vec DESIRE1=DESIRE;

  arma::vec z5(2);
  arma::vec DoseTried(Dose.n_rows);





  STOPPED=0;



  Doses2.zeros();
  //Wrap Trial right here
  OptDose=0;
  Doses.zeros();
  DoseTried.zeros();
  DoseTried[0]=1;
  //Wrap around each cohort

  //Fill in next cohort with the data size


  Intb=Intb.zeros()+1;
  Numb=Numb.zeros()+2;
  bvar=bvar.zeros()+1;

  for(j=0;j<5;j++){
    beta[j]=Hypermeans[j];
  }
  psi=Hypermeans[5];

  //Perform MCMC
  for(b=0;b<B;b++){


    if(b<(B/2 + 2)){
      if(b%250==0){

        for(j=0;j<6;j++){
          if((Intb[j]/Numb[j])>.5){
            bvar[j]=bvar[j]*2;
          }

          if((Intb[j]/Numb[j])<.2){
            bvar[j]=bvar[j]/2;
          }


          Intb[j]=1;
          Numb[j]=2;

        }





      }
    }




    //All but beta_T can be less than 0, sample those
    for(j=0;j<4;j++){

      betaprop=beta;
      betaprop[j]=as_scalar(arma::randn(1))*bvar[j] + betaprop[j];

      alpha =   Like(YE,YT,Doses,betaprop,psi,CoNum) - Like(YE,YT,Doses, beta, psi,CoNum);
      alpha = alpha - .5*pow(betaprop[j]-Hypermeans[j],2)/Hypervars[j] + .5*pow(beta[j]-Hypermeans[j],2)/Hypervars[j];

      U=log(as_scalar(arma::randu(1)));

      if(U<alpha){
        beta[j]=betaprop[j];
        Intb[j]=Intb[j]+1;
      }

      Numb[j] = Numb[j]+1;





    }


    //toxicity slope
    j=4;
    betaprop=beta;
    betaprop[j]=exp(as_scalar(arma::randn(1))*bvar[j] + log(betaprop[j]));

    alpha =   Like(YE,YT,Doses,betaprop,psi,CoNum) - Like(YE,YT,Doses, beta, psi,CoNum);
    alpha = alpha - .5*pow(betaprop[j]-Hypermeans[j],2)/Hypervars[j] + .5*pow(beta[j]-Hypermeans[j],2)/Hypervars[j];

    alpha = alpha + log(betaprop[j]) - log(beta[j]);


    U=log(as_scalar(arma::randu(1)));

    if(U<alpha){
      beta[j]=betaprop[j];
      Intb[j]=Intb[j]+1;
    }

    Numb[j] = Numb[j]+1;




    //Get new Psi

    j=5;

    psiprop=as_scalar(arma::randn(1))*bvar[j] + psi;

    alpha =   Like(YE,YT,Doses,beta,psiprop,CoNum) - Like(YE,YT,Doses, beta, psi,CoNum);
    alpha = alpha - .5*pow(psiprop-Hypermeans[j],2)/Hypervars[j] + .5*pow(psi-Hypermeans[j],2)/Hypervars[j];

    U=log(as_scalar(arma::randu(1)));

    if(U<alpha){
      psi=psiprop;
      Intb[j]=Intb[j]+1;
    }

    Numb[j]=Numb[j]+1;









    if(b>(B-B1-1)){

      StoreInx = b-B1;

      for(j=0;j<5;j++){
        ParamStore(StoreInx,j)=beta[j];
      }
      ParamStore(StoreInx,5)=psi;

      //Fill in Toxcity and Efficacy probabilities


      for(j=0;j<Dose.n_rows;j++){
        PE = beta[0]+beta[1]*Dose[j]+beta[2]*pow(Dose[j],2);
        PT = beta[3]+beta[4]*Dose[j];

        PE = exp(PE);
        PT=exp(PT);
        PE=PE/(1+PE);
        PT = PT/(1+PT);
        piEStore(StoreInx,j)=PE;
        piTStore(StoreInx,j)=PT;


        if(PE>Accept[0]){
          AcceptEff(StoreInx,j)=1;
        }else{
          AcceptEff(StoreInx,j)=0;

        }

        if(PT<Accept[1]){
          AcceptTox(StoreInx,j)=1;
        }else{
          AcceptTox(StoreInx,j)=0;

        }






      }



    }



  }

  //Compute posterior mean

  //Rprintf("OUT MCMC");

  for(j=0;j<Dose.n_rows;j++){
    ACCEPTEFF[j]=sum(AcceptEff.col(j))>(Lower(0)*B1)  ;
    ACCEPTTOX[j]=sum(AcceptTox.col(j))>(Lower(1)*B1) ;
  }




  //If ==1, for both EFF and TOX then dose j is acceptable

  //Determine Optimal Dose

  //Get Posterior mean of parameters
  for(j=0;j<5;j++){
    beta[j]=sum( ParamStore.col(j))/ParamStore.n_rows;
  }


  psi=sum( ParamStore.col(5))/ParamStore.n_rows;

  for(j=0;j<Dose.n_rows;j++){
    PE = beta[0]+beta[1]*Dose[j]+beta[2]*pow(Dose[j],2);
    PT = beta[3]+beta[4]*Dose[j];

    PE = exp(PE);
    PT=exp(PT);
    PE=PE/(1+PE);
    PT = PT/(1+PT);
    PiEff(j)=PE;
    PiTox(j)=PT;

  }


  //Rprintf("GOT STUFF");
  double Con = (exp(psi)-1)/(exp(psi)+1);
  double Con1=0;
  double piE=0;
  double piT=0;

  //  Rf_PrintValue(wrap(UT));

  //Now get the mean desireability for each dose if they are acceptable
  for(j=0;j<Dose.n_rows;j++){
    if((ACCEPTEFF[j]+ACCEPTTOX[j])==2){
      //Dose is ACCEPTABLE



      //Dose is ACCEPTABLe
      piE=PiEff(j);
      piT=PiTox(j);

      //Now we have the probabilities of toxictity and efficacy for this dose.
      Con1 = piE*(1-piE)*piT*(1-piT)*Con;
      DESIRE[j]=UT(0,0)*(Con1 + (1-piE)*(1-piT))+UT(0,1)*((1-piT)*piE - Con1) + UT(1,1)*(piE*piT + Con1);
      ACCEPT[j]=1;

    }else{
      ACCEPT[j]=0;
      DESIRE[j]=-1000;
    }



  }

  // Rprintf("Out Desirea");

  //Check if we should stop the trial

  if(sum(ACCEPT)>0){


    //Now pick the dose





    OptDose=0;

    for(j=1;j<Dose.n_rows;j++){
      if(DESIRE[j]>DESIRE[j-1]){
        OptDose=j;
      }
    }

    //Is this dose bigger than the dose higher than what's been tried?
    if(DoseTried(OptDose)==0){
      j=0;

      while(DoseTried(j)==1){
        j++;
      }

      OptDose=j;

    }

















  }else{
    //Trial Stopped
    OptDose=-1;
    STOPPED=1;

  }



  List z1 = List::create(OptDose,DESIRE,PiEff,PiTox);


  return(z1);


}


