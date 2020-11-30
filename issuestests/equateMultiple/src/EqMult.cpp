// [[Rcpp::depends(RcppArmadillo)]]

#include <RcppArmadillo.h>
using namespace Rcpp;


Rcpp::IntegerVector whichNotNA(Rcpp::NumericVector x) {
  Rcpp::IntegerVector v = Rcpp::seq(0, x.size()-1);
  return v[!Rcpp::is_na(x)];
}


//number of not NA for each row
NumericVector rowSumsNotNA(NumericMatrix x) {
  int nrow = x.nrow();
  NumericVector out(nrow);
  for (int i = 0; i < nrow; i++) {
		NumericMatrix::Row x_row = x(i,_);
		LogicalVector NotNAinRow = (!Rcpp::is_na(x_row));
		out[i] = sum(NotNAinRow);
  }
  return out;
}


// IRT probabilities for a vector of abilities
NumericVector irtp1(NumericVector ab, double diff, double discr, double guess, double D)
{
	NumericVector elp = exp(D*discr*(ab-diff));
	NumericVector prob = guess+(1-guess)*elp/(1+elp);
	return prob;
}


// [[Rcpp::export]]
double objectivefzRcpp(
	NumericVector par, //equating coefficients: solution
	int T, //number of administrations
	NumericVector ab, //quadrature points
	NumericVector wt, //quadrature weights
	NumericMatrix aj1T, //matrix of discrimination parameters
	NumericMatrix bj1T, //matrix of difficulty parameters
	NumericMatrix cj1T, //matrix of guessing parameters
	int nummet, //method 1=irf, 2=trf
	int itmp, //number of item parameters (1,2,3)
	double D, //D constant
	int base //reference form (remember to subtract 1)
)
{
	base-=1;
	int it;
	int t;
	int nq = ab.length();
	NumericVector A(T);
	A	= rep(1,T);
	NumericVector B(T);
	//B = rep(0,T);
	IntegerVector v1 = seq(0,T-1);
	IntegerVector v2 = seq(0,T-2);
	A[v1!=base] = par[v2];
	B[v1!=base] = par[v2+T-1];
	if (itmp==1) A = rep(1,T);
	NumericMatrix aj1Ts = clone(aj1T);
	NumericMatrix bj1Ts = clone(bj1T);
	for (t=0;t<T;t++) {
		NumericMatrix::Column aj1Ts_colt = aj1Ts( _, t);
		aj1Ts_colt = aj1Ts_colt / A[t];	
		NumericMatrix::Column bj1Ts_colt = bj1Ts( _, t);
		bj1Ts_colt = bj1Ts_colt * A[t] + B[t];	
	}
	NumericVector aj = rowMeans(aj1Ts,true);
	NumericVector bj = rowMeans(bj1Ts,true);
	double f=0;
	for (t=0;t<T;t++) {
		NumericVector bjt = bj1T(_,t);
		IntegerVector items_t = whichNotNA(bjt); //positions of items not NA, that is items administered at time t
		int num_items_t = items_t.length();
		
		NumericVector Pt(nq);
		NumericVector Pts(nq);

		NumericVector bj_t = bj[items_t];
		NumericVector aj_t = aj[items_t];
		NumericVector bjts = (bj_t-B[t])/A[t];
		NumericVector ajts = aj_t*A[t];

		NumericVector sumPt(nq);
		NumericVector sumPts(nq);
		
		int k;
		for (k=0;k<num_items_t;k++) {
			it=items_t[k];
			Pt = irtp1(ab,bj1T(it,t),aj1T(it,t),cj1T(it,t),D);
			Pts = irtp1(ab,bjts[k],ajts[k],cj1T(it,t),D);
			if (nummet==1) //irf method 
				f+=0.5*sum(pow(Pt-Pts,2)*wt);
			if (nummet==2) { //irf method
				sumPt = sumPt+Pt;
				sumPts = sumPts+Pts;
			}			
		}
		if (nummet==2) { //irf method 
			NumericVector diff2 = pow(sumPt-sumPts,2);
			f+=sum(0.5*diff2*wt);
		}
	}
	return f;
}




// matrix of second derivatives of objectivefz in the point of minimum
// [[Rcpp::export]]
NumericMatrix hessRcpp(
	NumericVector par, //equating coefficients: solution
	int T, //number of administrations
	NumericVector ab, //quadrature points
	NumericVector wt, //quadrature weights
	NumericMatrix aj1T, //matrix of discrimination parameters
	NumericMatrix bj1T, //matrix of difficulty parameters
	NumericMatrix cj1T, //matrix of guessing parameters
	int nummet, //method 1=irf, 2=trf
	int itmp, //number of item parameters (1,2,3)
	double D, //D constant
	int base //reference form (remember to subtract 1)
)
{
	base-=1;
	int i, t, k, s, r, j=0;
	int nq = ab.length();
	int ni=aj1T.nrow();
	NumericVector A(T);
	A	= rep(1,T);
	NumericVector B(T);
	//B = rep(0,T);
	IntegerVector v1 = seq(0,T-1);
	IntegerVector v2 = seq(0,T-2);
	A[v1!=base] = par[v2];
	B[v1!=base] = par[v2+T-1];
	if (itmp==1) A = rep(1,T);
	NumericMatrix aj1Ts = clone(aj1T);
	NumericMatrix bj1Ts = clone(bj1T);
	for (t=0;t<T;t++) {
		NumericMatrix::Column aj1Ts_colt = aj1Ts( _, t);
		aj1Ts_colt = aj1Ts_colt / A[t];	
		NumericMatrix::Column bj1Ts_colt = bj1Ts( _, t);
		bj1Ts_colt = bj1Ts_colt * A[t] + B[t];	
	}
	NumericVector aj = rowMeans(aj1Ts,true);
	NumericVector bj = rowMeans(bj1Ts,true);
	NumericVector Tj= rowSumsNotNA(bj1T);
	NumericMatrix f(2*T-2,2*T-2);

	double saj1Ts, p1PAs, p1PAk, pPAs, pPBs, pPAk, pPBk, ppPAsAk=0, ppPBsBk=0, ppPAsBk=0, ppPBsAk=0;
	double SPt,SpPAs,SpPAk,SpPBs,SpPBk,SppPAsAk,SppPBsAk,SppPAsBk,SppPBsBk;
	NumericMatrix Pt(nq,ni);
	NumericMatrix Pts(nq,ni);
	NumericMatrix pPLP(nq,ni);

	NumericMatrix aj1Tcopy = clone(aj1T); //necessary, otherwise object aj1T changed in R environment
	NumericMatrix bj1Tcopy = clone(bj1T); //necessary, otherwise object aj1T changed in R environment
	// substitute NAs with 0
	for (t=0;t<T;t++) {
		for (i=0;i<ni;i++) {
			if (NumericMatrix::is_na(bj1T(i,t))) {
				bj1Tcopy(i,t)=0;
				aj1Tcopy(i,t)=0;
			}
		}
	}
	aj1T=clone(aj1Tcopy);
	bj1T=clone(bj1Tcopy);

	for (t=0;t<T;t++) {
		for (i=0;i<ni;i++) {
			if (bj1T(i,t)!=0) {
				NumericMatrix::Column Pt_col = Pt( _, i);
				NumericMatrix::Column Pts_col = Pts( _, i);
				NumericMatrix::Column pPLP_col = pPLP( _, i);		
				Pt_col = irtp1(ab,bj1T(i,t),aj1T(i,t),cj1T(i,t),D);
				Pts_col = irtp1(ab,(bj[i]-B[t])/A[t],aj[i]*A[t],cj1T(i,t),D);
				pPLP_col = (Pts_col-cj1T(i,t))*(1-Pts_col)/(1-cj1T(i,t));
			}
		}
		
		int minustos = 0; // this is used to skip the row equal to the base form (base)
		int minustok = 0; // this is used to skip the column equal to the base form (base)
		for (s=0;s<T;s++) {
			if (s==base) minustos=1;
			minustok = 0;
			for (k=s;k<T;k++) {
				if (k>=base) minustok=1;
				if ((s!=base) & (k!=base)) {
					for (j=0;j<nq;j++) {
						SPt=0;
						SpPAs=0;
						SpPAk=0;
						SpPBs=0;
						SpPBk=0;
						SppPAsAk=0;
						SppPBsAk=0;
						SppPAsBk=0;
						SppPBsBk=0;
						for (i=0;i<ni;i++) {
							if (aj1T(i,t)!=0) { //& !NumericMatrix::is_na(aj1T(i,s)) & !NumericMatrix::is_na(aj1T(i,k))) {
								// first derivatives
								if (s==t) {
									saj1Ts=0;
									for (r=0;r<T;r++) if(r!=t) saj1Ts+=aj1T(i,r)/A[r];
									p1PAs=D/Tj[i]*(saj1Ts*ab[j]+aj1T(i,t)/pow(A[t],2)*(bj[i]-B[t])-aj[i]*bj1T(i,t)); // Equation (47)
								}
								if (s!=t) p1PAs=D/Tj[i]*(-aj1T(i,s)/pow(A[s],2)*A[t]*ab[j]+aj1T(i,s)/pow(A[s],2)*(bj[i]-B[t])-aj[i]*bj1T(i,s)); // Equation (49)
								pPAs=pPLP(j,i)*p1PAs; //first derivative of Pmjts with respect to As (Equations 45 and 48)
								
								if (s==t) pPBs=pPLP(j,i)*D*aj[i]*(1-1/Tj[i]*(bj1T(i,t)!=0)); //first derivative of Pmjts with respect to  Bs (Equations 50, 51)
								if (s!=t) pPBs=-pPLP(j,i)*D*aj[i]/Tj[i]*(bj1T(i,s)!=0); //first derivative of Pmjts with respect to Bs (Equations 52, 53)

								if (k==s) {
									p1PAk=p1PAs;
									pPAk=pPAs;
									pPBk=pPBs;
								}
								else {
									if (k==t) {
										saj1Ts=0;
										for (r=0;r<T;r++) if(r!=t) saj1Ts+=aj1T(i,r)/A[r];
										p1PAk=D/Tj[i]*(saj1Ts*ab[j]+aj1T(i,t)/pow(A[t],2)*(bj[i]-B[t])-aj[i]*bj1T(i,t)); // Equation (47)
									}
									if (k!=t) p1PAk=D/Tj[i]*(-aj1T(i,k)/pow(A[k],2)*A[t]*ab[j]+aj1T(i,k)/pow(A[k],2)*(bj[i]-B[t])-aj[i]*bj1T(i,k)); // Equation (49)
									pPAk=pPLP(j,i)*p1PAk; //first derivative of Pmjts with respect to Ak (Equations 45 and 48)
									
									if (k==t) pPBk=pPLP(j,i)*D*aj[i]*(1-1/Tj[i]*(bj1T(i,t)!=0)); //first derivative of Pmjts with respect to Bk (Equations 50, 51)
									if (k!=t) pPBk=-pPLP(j,i)*D*aj[i]/Tj[i]*(bj1T(i,k)!=0); //first derivative of Pmjts with respect to Bk (Equations 52, 53)
								}

								// second derivatives
								if ((s==k) & (s==t))          ppPAsAk=(pPAs-2*((Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*pPAs)*p1PAs + pPLP(j,i)*D/Tj[i]*(-2*aj1T(i,s)/pow(A[s],3)*(bj[i]-B[s])+aj1T(i,s)/pow(A[s],2)*bj1T(i,s)/Tj[i]+aj1T(i,s)/pow(A[s],2)*bj1T(i,s)/Tj[i]); // second derivative of Pmjts with respect to AtAt (Equation 59)
								if ((s==k) & (s!=t))          ppPAsAk=(pPAs-2*((Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*pPAs)*p1PAs + pPLP(j,i)*D/Tj[i]* (2*aj1T(i,s)/pow(A[s],3)*A[t]*ab[j]-2*aj1T(i,s)/pow(A[s],3)*(bj[i]-B[t])+aj1T(i,s)/pow(A[s],2)*bj1T(i,s)/Tj[i]+aj1T(i,s)/pow(A[s],2)*bj1T(i,s)/Tj[i]); // second derivative of Pmjts with respect to AsAs (Equation 63)
								if ((s==t) & (k!=t))          ppPAsAk=(pPAk-2*((Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*pPAk)*p1PAs + pPLP(j,i)*D/Tj[i]*  (-aj1T(i,k)/pow(A[k],2)*ab[j]+aj1T(i,t)/pow(A[t],2)*bj1T(i,k)/Tj[i]+aj1T(i,k)/pow(A[k],2)*bj1T(i,s)/Tj[i]); //second derivative of Pmjts with respect to AtAk (Equation 60)
								if ((s!=t) & (k==t))          ppPAsAk=(pPAk-2*((Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*pPAk)*p1PAs + pPLP(j,i)*D/Tj[i]*  (-aj1T(i,s)/pow(A[s],2)*ab[j]+aj1T(i,s)/pow(A[s],2)*bj1T(i,k)/Tj[i]+aj1T(i,k)/pow(A[k],2)*bj1T(i,s)/Tj[i]); //second derivative of Pmjts with respect to AsAt (Equation 64)
								if ((s!=t) & (k!=t) & (s!=k)) ppPAsAk=(pPAk-2*((Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*pPAk)*p1PAs + pPLP(j,i)*D/Tj[i]*   (aj1T(i,s)/pow(A[s],2)*bj1T(i,k)/Tj[i]+aj1T(i,k)/pow(A[k],2)*bj1T(i,s)/Tj[i]); //second derivative of Pmjts with respect to AsAk  (Equation 67)
								
								if (s==t) ppPBsBk= (pPBk-2*((Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*pPBk)*D*aj[i]*(1-1/Tj[i]*(bj1T(i,t)!=0)); //second derivative of Pmjts with respect to BtBk (Equation 54)
								if (s!=t) ppPBsBk=-(pPBk-2*((Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*pPBk)*D*aj[i]/Tj[i]*(bj1T(i,s)!=0); //second derivative of Pmjts with respect to BsBk (Equation 57)
								
								if (s==t) ppPBsAk=  (pPAk-2*((Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*pPAk)*D*aj[i]*(1-1/Tj[i]*(bj1T(i,t)!=0))-pPLP(j,i)*D/Tj[i]*aj1T(i,k)/pow(A[k],2)*(1-1/Tj[i]*(bj1T(i,t)!=0)); //second derivative of Pmjts with respect to BtAk  (Equation 56)
								if (s!=t) ppPBsAk=(-(pPAk-2*((Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*pPAk)*D*aj[i]/Tj[i]+pPLP(j,i)*D/Tj[i]*aj1T(i,k)/pow(A[k],2)/Tj[i])*(bj1T(i,s)!=0); //second derivative of Pmjts with respect to BsAk (Equation 58)
								
								if ((s==t) & (k==t)) ppPAsBk=(pPBk-2*((Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*pPBk)*p1PAs + pPLP(j,i)*D/Tj[i]*(aj1T(i,s)/pow(A[s],2)*(1/Tj[i]-1)); //second derivative of Pmjts with respect to AtBt (Equation 61)
								if ((s==t) & (k!=t)) ppPAsBk=(pPBk-2*((Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*pPBk)*p1PAs + pPLP(j,i)*D/Tj[i]*(aj1T(i,s)/pow(A[s],2)/Tj[i])*(bj1T(i,k)!=0); //second derivative of Pmjts with respect to AtBk (Equation 62)
								if ((s!=t) & (k==t)) ppPAsBk=(pPBk-2*((Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*pPBk)*p1PAs + pPLP(j,i)*D/Tj[i]*(aj1T(i,s)/pow(A[s],2)*(1/Tj[i]*(bj1T(i,k)!=0)-1)); //second derivative of Pmjts with respect to AsBk (Equation 66)
								if ((s!=t) & (k!=t)) ppPAsBk=(pPBk-2*((Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*pPBk)*p1PAs + pPLP(j,i)*D/Tj[i]*(aj1T(i,s)/pow(A[s],2)/Tj[i])*(aj1T(i,k)!=0); //second derivative of Pmjts with respect to AsBk (Equation 65)

								if ((nummet==1) & (bj1T(i,t)!=0)) {
									f(s-minustos,k-minustok)+= (pPAs*pPAk -(Pt(j,i)-Pts(j,i))*ppPAsAk)*wt[j];
									f(s+T-1-minustos,k-minustok)+= (pPBs*pPAk -(Pt(j,i)-Pts(j,i))*ppPBsAk)*wt[j];
									f(s-minustos,k+T-1-minustok)+= (pPAs*pPBk -(Pt(j,i)-Pts(j,i))*ppPAsBk)*wt[j];
									f(s+T-1-minustos,k+T-1-minustok)+=(pPBs*pPBk -(Pt(j,i)-Pts(j,i))*ppPBsBk)*wt[j];
								}
								if ((nummet==2) & (bj1T(i,t)!=0)) {
									SPt+=(Pt(j,i)-Pts(j,i));
									SpPAs+=pPAs;
									SpPAk+=pPAk;
									SpPBs+=pPBs;
									SpPBk+=pPBk;
									SppPAsAk+=ppPAsAk;
									SppPBsAk+=ppPBsAk;
									SppPAsBk+=ppPAsBk;
									SppPBsBk+=ppPBsBk;
								}
							}
						} //i
						f(s-minustos,k-minustok)+= (SpPAs*SpPAk - SPt*SppPAsAk)*wt[j];
						f(s+T-1-minustos,k-minustok)+= (SpPBs*SpPAk - SPt*SppPBsAk)*wt[j];
						f(s-minustos,k+T-1-minustok)+= (SpPAs*SpPBk - SPt*SppPAsBk)*wt[j];
						f(s+T-1-minustos,k+T-1-minustok)+= (SpPBs*SpPBk - SPt*SppPBsBk)*wt[j];
					} //j
				} //if
			} //k
		} //s
		// Rprintf("t %i \n", t);	
	} //t
	for (k=0;k<(T-1);k++) {
		for (s=0;s<k;s++) {
			f(k,s) = f(s,k);
			f(k,s+T-1) = f(s+T-1,k);
			f(k+T-1,s) = f(s,k+T-1);
			f(k+T-1,s+T-1) = f(s+T-1,k+T-1);
		}
	}
	return(f);
	
}



// vector of first derivatives of objectivefz in the point of minimum
// [[Rcpp::export]]
NumericVector gradRcpp(
	NumericVector par, //equating coefficients: solution
	int T, //number of administrations
	NumericVector ab, //quadrature points
	NumericVector wt, //quadrature weights
	NumericMatrix aj1T, //matrix of discrimination parameters
	NumericMatrix bj1T, //matrix of difficulty parameters
	NumericMatrix cj1T, //matrix of guessing parameters
	int nummet, //method 1=irf, 2=trf
	int itmp, //number of item parameters (1,2,3)
	double D, //D constant
	int base //reference form (remember to subtract 1)
)
{
	base-=1;
	int i, t, s, r, j=0;
	int nq = ab.length();
	int ni=aj1T.nrow();
	NumericVector A(T);
	A	= rep(1,T);
	NumericVector B(T);
	//B = rep(0,T);
	IntegerVector v1 = seq(0,T-1);
	IntegerVector v2 = seq(0,T-2);
	A[v1!=base] = par[v2];
	B[v1!=base] = par[v2+T-1];
	if (itmp==1) A = rep(1,T);
	NumericMatrix aj1Ts = clone(aj1T);
	NumericMatrix bj1Ts = clone(bj1T);
	for (t=0;t<T;t++) {
		NumericMatrix::Column aj1Ts_colt = aj1Ts( _, t);
		aj1Ts_colt = aj1Ts_colt / A[t];	
		NumericMatrix::Column bj1Ts_colt = bj1Ts( _, t);
		bj1Ts_colt = bj1Ts_colt * A[t] + B[t];	
	}
	NumericVector aj = rowMeans(aj1Ts,true);
	NumericVector bj = rowMeans(bj1Ts,true);
	NumericVector Tj= rowSumsNotNA(bj1T);
	NumericVector f(2*T-2);

	double saj1Ts, p1PAs, pPAs, pPBs;
	double SPt,SpPAs,SpPBs;
	NumericMatrix Pt(nq,ni);
	NumericMatrix Pts(nq,ni);
	NumericMatrix pPLP(nq,ni);

	NumericMatrix aj1Tcopy = clone(aj1T); //necessary, otherwise object aj1T changed in R environment
	NumericMatrix bj1Tcopy = clone(bj1T); //necessary, otherwise object aj1T changed in R environment
	// substitute NAs with 0
	for (t=0;t<T;t++) {
		for (i=0;i<ni;i++) {
			if (NumericMatrix::is_na(bj1T(i,t))) {
				bj1Tcopy(i,t)=0;
				aj1Tcopy(i,t)=0;
			}
		}
	}
	aj1T=clone(aj1Tcopy);
	bj1T=clone(bj1Tcopy);

	for (t=0;t<T;t++) {
		for (i=0;i<ni;i++) {
			if (bj1T(i,t)!=0) {
				NumericMatrix::Column Pt_col = Pt( _, i);
				NumericMatrix::Column Pts_col = Pts( _, i);
				NumericMatrix::Column pPLP_col = pPLP( _, i);		
				Pt_col = irtp1(ab,bj1T(i,t),aj1T(i,t),cj1T(i,t),D);
				Pts_col = irtp1(ab,(bj[i]-B[t])/A[t],aj[i]*A[t],cj1T(i,t),D);
				pPLP_col = (Pts_col-cj1T(i,t))*(1-Pts_col)/(1-cj1T(i,t));
			}
		}
		int minusto = 0;
		for (s=0;s<T;s++) {
			if (s==base) minusto=1;
			if (s!=base) {
				for (j=0;j<nq;j++) {
					SPt=0;
					SpPAs=0;
					SpPBs=0;
					for (i=0;i<ni;i++) {
						if (aj1T(i,t)!=0) { //& !NumericMatrix::is_na(aj1T(i,s)) & !NumericMatrix::is_na(aj1T(i,k))) {
							// first derivatives
							if (s==t) {
								saj1Ts=0;
								for (r=0;r<T;r++) if(r!=t) saj1Ts+=aj1T(i,r)/A[r];
								p1PAs=D/Tj[i]*(saj1Ts*ab[j]+aj1T(i,t)/pow(A[t],2)*(bj[i]-B[t])-aj[i]*bj1T(i,t)); // Equation (47)
							}
							if (s!=t) p1PAs=D/Tj[i]*(-aj1T(i,s)/pow(A[s],2)*A[t]*ab[j]+aj1T(i,s)/pow(A[s],2)*(bj[i]-B[t])-aj[i]*bj1T(i,s)); // Equation (49)
							pPAs=pPLP(j,i)*p1PAs; //first derivative of Pmjts with respect to As (Equations 45 and 48)
							
							if (s==t) pPBs=pPLP(j,i)*D*aj[i]*(1-1/Tj[i]*(bj1T(i,t)!=0)); //first derivative of Pmjts with respect to  Bs (Equations 50, 51)
							if (s!=t) pPBs=-pPLP(j,i)*D*aj[i]/Tj[i]*(bj1T(i,s)!=0); //first derivative of Pmjts with respect to Bs (Equations 52, 53)

							if ((nummet==1) & (bj1T(i,t)!=0)) {
								f[s-minusto]+=   -(Pt(j,i)-Pts(j,i))*pPAs*wt[j];
								f[s+T-1-minusto]+= -(Pt(j,i)-Pts(j,i))*pPBs*wt[j];
							}
							if ((nummet==2) & (bj1T(i,t)!=0)) {
								SPt+=(Pt(j,i)-Pts(j,i));
								SpPAs+=pPAs;
								SpPBs+=pPBs;
							}
						}
					} //i
					f[s-minusto]+=   - SPt*SpPAs*wt[j];
					f[s+T-1-minusto]+= - SPt*SpPBs*wt[j];
				} //j
			} //if
		} //s
		// Rprintf("t %i \n", t);	
	} //t
	
	return(f);
	
}





// [[Rcpp::export]]
List partialABgammaRcpp(
	NumericVector par, //equating coefficients: solution
	int T, //number of administrations
	NumericVector ab, //quadrature points
	NumericVector wt, //quadrature weights
	NumericMatrix aj1T, //matrix of discrimination parameters
	NumericMatrix bj1T, //matrix of difficulty parameters
	NumericMatrix cj1T, //matrix of guessing parameters
	int nummet, //method 1=irf, 2=trf
	int itmp, //number of item parameters (1,2,3)
	double D, //D constant
	int base, //reference form (remember to subtract 1)
	int nb, 
	IntegerVector posnomi
)
{
	base-=1;
	posnomi = posnomi-1;
	int i, t, k, s, r, co, j=0;
	int nq = ab.length();
	int ni=aj1T.nrow();
	NumericVector A(T);
	A	= rep(1,T);
	NumericVector B(T);
	//B = rep(0,T);
	IntegerVector v1 = seq(0,T-1);
	IntegerVector v2 = seq(0,T-2);
	A[v1!=base] = par[v2];
	B[v1!=base] = par[v2+T-1];
	if (itmp==1) A = rep(1,T);
	NumericMatrix aj1Ts = clone(aj1T);
	NumericMatrix bj1Ts = clone(bj1T);
	for (t=0;t<T;t++) {
		NumericMatrix::Column aj1Ts_colt = aj1Ts( _, t);
		aj1Ts_colt = aj1Ts_colt / A[t];	
		NumericMatrix::Column bj1Ts_colt = bj1Ts( _, t);
		bj1Ts_colt = bj1Ts_colt * A[t] + B[t];	
	}
	NumericVector aj = rowMeans(aj1Ts,true);
	NumericVector bj = rowMeans(bj1Ts,true);
	NumericVector Tj= rowSumsNotNA(bj1T);
	NumericMatrix out_a(2*T,nb);
	NumericMatrix out_b(2*T,nb);
	NumericMatrix out_c(2*T,nb);

	double saj1Ts,pPtgamma_a,pPtgamma_b,pPtgamma_c,pPtsgamma_a,pPtsgamma_b,pPtsgamma_c;
	double ppPts_Aa=0,ppPts_Ab=0,ppPts_Ac=0,ppPts_Ba=0,ppPts_Bb=0,ppPts_Bc=0;
	NumericMatrix Pt(nq,ni);
	NumericMatrix Pts(nq,ni);
	NumericMatrix pPLP(nq,ni);
	NumericMatrix pPAs(nq,ni);
	NumericMatrix p1PAs(nq,ni);
	NumericMatrix pPBs(nq,ni);
	NumericVector SPt(nq);
	NumericVector SpPLPs(nq);
	NumericVector SpPBs(nq);
	NumericVector SpPAs(nq);
	
	NumericMatrix aj1Tcopy = clone(aj1T); //necessary, otherwise object aj1T changed in R environment
	NumericMatrix bj1Tcopy = clone(bj1T); //necessary, otherwise object aj1T changed in R environment
	// substitute NAs with 0
	for (t=0;t<T;t++) {
		for (i=0;i<ni;i++) {
			if (NumericMatrix::is_na(bj1T(i,t))) {
				bj1Tcopy(i,t)=0;
				aj1Tcopy(i,t)=0;
			}
		}
	}
	aj1T=clone(aj1Tcopy);
	bj1T=clone(bj1Tcopy);

	for (t=0;t<T;t++) {
		SPt = rep(0,nq);
		for (i=0;i<ni;i++) {
			if (bj1T(i,t)!=0) {
				NumericMatrix::Column Pt_col = Pt( _, i);
				NumericMatrix::Column Pts_col = Pts( _, i);
				NumericMatrix::Column pPLP_col = pPLP( _, i);		
				Pt_col = irtp1(ab,bj1T(i,t),aj1T(i,t),cj1T(i,t),D);
				Pts_col = irtp1(ab,(bj[i]-B[t])/A[t],aj[i]*A[t],cj1T(i,t),D);
				pPLP_col = (Pts_col-cj1T(i,t))*(1-Pts_col)/(1-cj1T(i,t));  // Equation (46)
				SPt = SPt+(Pt_col-Pts_col);
			}
		}

		for (s=0;s<T;s++) { // s is the index of the equating coefficient
			if (s!=base) {
				for (i=0;i<ni;i++) {
					// if (!NumericMatrix::is_na(aj1T(i,t)) & !NumericMatrix::is_na(aj1T(i,s))) {
					if (aj1T(i,t)!=0) {
						// first derivatives of Pts with respect to the equating coefficients
						NumericMatrix::Column pPAs_col = pPAs( _, i);		
						NumericMatrix::Column pPBs_col = pPBs( _, i);		
						NumericMatrix::Column p1PAs_col = p1PAs( _, i);		
						NumericMatrix::Column pPLP_col = pPLP( _, i);		
						if (s==t) {
							saj1Ts=0;
							for (r=0;r<T;r++) if((r!=t)) saj1Ts+=aj1T(i,r)/A[r];
							p1PAs_col = D/Tj[i]*(saj1Ts*ab+aj1T(i,t)/pow(A[t],2)*(bj[i]-B[t])-aj[i]*bj1T(i,t)); // Equation (47)
						}
						if (s!=t) p1PAs_col = D/Tj[i]*(-aj1T(i,s)/pow(A[s],2)*A[t]*ab+aj1T(i,s)/pow(A[s],2)*(bj[i]-B[t])-aj[i]*bj1T(i,s)); // Equation (49)
						pPAs_col = pPLP_col * p1PAs_col; //first derivative of Pmjts with respect to As, Equation (48)
						if (s==t) pPBs_col = pPLP_col * D * aj[i] * (1-1/Tj[i]); //first derivative of Pmjts with respect to Bs, Equations (50) + (51)
						if (s!=t) pPBs_col = -pPLP_col * D * aj[i] /Tj[i]*(bj1T(i,s)!=0); //first derivative of Pmjts with respect to Bs, Equations (52) + (53)
					}
				}
				
				SpPBs = rep(0,nq);
				SpPAs = rep(0,nq);
				for (i=0;i<ni;i++) {
					if(aj1T(i,t)!=0) {
						NumericMatrix::Column pPBs_col = pPBs( _, i);
						NumericMatrix::Column pPAs_col = pPAs( _, i);
						SpPBs = SpPBs + pPBs_col;
						SpPAs = SpPAs + pPAs_col;
					}
				}
				for (k=0;k<T;k++) { // k is the index of the item parameter
					for (j=0;j<nq;j++) {
						for (i=0;i<ni;i++) {
							if ((aj1T(i,t)!=0) & (aj1T(i,k)!=0)) {
								// derivatives of Pt with respect to the item parameters
								if (k==t) {
									pPtgamma_a=  (Pt(j,i)-cj1T(i,t))*(1-(Pt(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*D*(ab[j]-bj1T(i,t)); // Equation (69)
									pPtgamma_b= -(Pt(j,i)-cj1T(i,t))*(1-(Pt(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*D*aj1T(i,t); // Equation (70)
									if (itmp==3) pPtgamma_c=1-(Pt(j,i)-cj1T(i,t))/(1-cj1T(i,t)); else pPtgamma_c=0; // Equation (68)
								}
								if (k!=t) { 
									pPtgamma_a=0;
									pPtgamma_b=0;
									pPtgamma_c=0;
								}
								// derivatives of Pts with respect to the item parameters
								if (k==t) {
									pPtsgamma_a =  pPLP(j,i)*D/Tj[i]*(ab[j]-(bj[i]-B[t])/A[t]); // Equation (72)
									if (itmp==3) pPtsgamma_c = 1-(Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)); else pPtsgamma_c=0;
								}
								if (k!=t) {
									pPtsgamma_a= pPLP(j,i)*D/Tj[i]*(ab[j]*A[t]/A[k]-(bj[i]-B[t])/A[k])*(bj1T(i,k)!=0); // Equation (73)
									pPtsgamma_c=0;
								}
								pPtsgamma_b= -pPLP(j,i)*D/Tj[i]*aj[i]*A[k]*(bj1T(i,k)!=0); // Equation (74)
								// second derivatives of Pts with respect to the equating coefficients and the item parameters
								if ((itmp==3) & (k==t)) ppPts_Ac = -pPAs(j,i)/(1-cj1T(i,t)); else ppPts_Ac=0; // Equation (81)
								if ((itmp==3) & (k==t)) ppPts_Bc = -pPBs(j,i)/(1-cj1T(i,t)); else ppPts_Bc=0; // Equation (78)
								
								if ((s==t) & (k==t)) ppPts_Aa= (pPtsgamma_a-2*((Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*pPtsgamma_a)*p1PAs(j,i)+pPLP(j,i)*D/Tj[i]*((bj[i]-B[t])/pow(A[t],2)-bj1T(i,t)/(Tj[i]*A[t])); // Equation (82)
								if ((s==t) & (k!=t)) ppPts_Aa= (pPtsgamma_a-2*((Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*pPtsgamma_a)*p1PAs(j,i)+pPLP(j,i)*D/Tj[i]*(ab[j]/A[k]-bj1T(i,t)/(Tj[i]*A[k])); // Equation (83)
								if ((s!=t) & (k==s)) ppPts_Aa= (pPtsgamma_a-2*((Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*pPtsgamma_a)*p1PAs(j,i)+pPLP(j,i)*D/Tj[i]*(-ab[j]*A[t]/pow(A[s],2)+(bj[i]-B[t])/pow(A[s],2)-bj1T(i,s)/(Tj[i]*A[s])); // Equation (87)
								if ((s!=t) & (k!=s)) ppPts_Aa= (pPtsgamma_a-2*((Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*pPtsgamma_a)*p1PAs(j,i)+pPLP(j,i)*D/Tj[i]*(-bj1T(i,s)/(Tj[i]*A[k]))*(bj1T(i,s)!=0); // Equation (88)
								if (s==t) ppPts_Ba=  (pPtsgamma_a-2*((Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*pPtsgamma_a)*D*aj[i]*(1-1/Tj[i])+pPLP(j,i)*D/Tj[i]/A[k]*(1-1/Tj[i]); // Equation (76)
								if (s!=t) ppPts_Ba= -(pPtsgamma_a-2*((Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*pPtsgamma_a)*D*aj[i]/Tj[i]*(bj1T(i,s)!=0)-pPLP(j,i)*D/Tj[i]/A[k]/Tj[i]*(bj1T(i,s)!=0); // Equation (79)
								
								if ((s==t) & (k==t)) ppPts_Ab=(pPtsgamma_b-2*((Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*pPtsgamma_b)*p1PAs(j,i)+pPLP(j,i)*D/Tj[i]*(aj1T(i,t)/(Tj[i]*A[t])-aj[i]);
								if ((s==t) & (k!=t)) ppPts_Ab=(pPtsgamma_b-2*((Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*pPtsgamma_b)*p1PAs(j,i)+pPLP(j,i)*D/Tj[i]*(aj1T(i,t)/(Tj[i]*pow(A[t],2))*A[k]);
								if ((s!=t) & (k==s)) ppPts_Ab=(pPtsgamma_b-2*((Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*pPtsgamma_b)*p1PAs(j,i)+pPLP(j,i)*D/Tj[i]*(aj1T(i,s)/(Tj[i]*A[s])-aj[i])*(aj1T(i,s)!=0);
								if ((s!=t) & (k!=s)) ppPts_Ab=(pPtsgamma_b-2*((Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*pPtsgamma_b)*p1PAs(j,i)+pPLP(j,i)*D/Tj[i]*(aj1T(i,s)/(Tj[i]*pow(A[s],2))*A[k])*(aj1T(i,s)!=0);
								if (s==t) ppPts_Bb=  (pPtsgamma_b-2*((Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*pPtsgamma_b)*D*aj[i]*(1-1/Tj[i]);
								if (s!=t) ppPts_Bb= -(pPtsgamma_b-2*((Pts(j,i)-cj1T(i,t))/(1-cj1T(i,t)))*pPtsgamma_b)*D*aj[i]/Tj[i]*(bj1T(i,s)!=0);
								co=posnomi(i,k);
								if (nummet==1) {
									out_a(s,co) += ((pPtgamma_a-pPtsgamma_a)*(-pPAs(j,i))-(Pt(j,i)-Pts(j,i))*ppPts_Aa)*wt[j];
									out_a(s+T,co) += ((pPtgamma_a-pPtsgamma_a)*(-pPBs(j,i))-(Pt(j,i)-Pts(j,i))*ppPts_Ba)*wt[j];
									out_b(s,co) += ((pPtgamma_b-pPtsgamma_b)*(-pPAs(j,i))-(Pt(j,i)-Pts(j,i))*ppPts_Ab)*wt[j];
									out_b(s+T,co) += ((pPtgamma_b-pPtsgamma_b)*(-pPBs(j,i))-(Pt(j,i)-Pts(j,i))*ppPts_Bb)*wt[j];
									if (itmp==3) out_c(s,co) += ((pPtgamma_c-pPtsgamma_c)*(-pPAs(j,i))-(Pt(j,i)-Pts(j,i))*ppPts_Ac)*wt[j];
									if (itmp==3) out_c(s+T,co) += ((pPtgamma_c-pPtsgamma_c)*(-pPBs(j,i))-(Pt(j,i)-Pts(j,i))*ppPts_Bc)*wt[j];
								}
								if (nummet==2) {
									out_a(s,co) += ((pPtgamma_a-pPtsgamma_a)*(-SpPAs[j])-SPt[j]*ppPts_Aa)*wt[j];
									out_a(s+T,co) += ((pPtgamma_a-pPtsgamma_a)*(-SpPBs[j])-SPt[j]*ppPts_Ba)*wt[j];
									out_b(s,co) += ((pPtgamma_b-pPtsgamma_b)*(-SpPAs[j])-SPt[j]*ppPts_Ab)*wt[j];
									out_b(s+T,co) += ((pPtgamma_b-pPtsgamma_b)*(-SpPBs[j])-SPt[j]*ppPts_Bb)*wt[j];
									if (itmp==3) out_c(s,co) += ((pPtgamma_c-pPtsgamma_c)*(-SpPAs[j])-SPt[j]*ppPts_Ac)*wt[j];
									if (itmp==3) out_c(s+T,co) += ((pPtgamma_c-pPtsgamma_c)*(-SpPBs[j])-SPt[j]*ppPts_Bc)*wt[j];
								}
							}
						} //i
					} //j
				} //k
			} //if s
		} //s
		// Rprintf("t %i \n", t);	
	} //t
	return Rcpp::List::create(out_a, out_b, out_c);
}



// [[Rcpp::export]]
arma::mat VarExtRcpp ( List x ) {

	//x: list of matrices 

	int n = x.size() ;
	int dimen = 0 ;
	arma::ivec dimvec(n) ;

	for(int i=0; i<n; i++) {
		arma::mat xi = as<arma::mat>(x[i]);
		dimvec[i] = xi.n_rows ; 
		dimen += dimvec[i] ;
	}

	arma::mat X(dimen,dimen);
	X.zeros();
	int idx=0;

	for(int i=0; i<n; i++) {
		arma::mat xi = as<arma::mat>(x[i]);
		X.submat( idx, idx, idx + dimvec[i] - 1, idx + dimvec[i] - 1 ) = xi ;
		idx = idx + dimvec[i] ;
	}

	return(X);
}



// itertive proportional fitting
// [[Rcpp::export]]
List ipfRcpp(NumericMatrix aj1T, int base, double eps) {
	int ref=base-1;
	int ni=aj1T.nrow();
	int TT=aj1T.ncol();
	NumericVector hpi(ni);
	NumericVector hpj(TT);
	NumericVector cd(TT);
	hpi=rowSums(aj1T,true);
	hpj=colSums(aj1T,true);
	NumericMatrix delta(ni,TT);
	for (int i = 0; i < ni; i++) {
		for (int j = 0; j < TT; j++) {
			if (!NumericMatrix::is_na(aj1T(i,j))) delta(i,j)=1;
			else delta(i,j)=0;
		}
	}
	cd=colSums(delta,true);
	NumericVector bj1(TT);
	NumericVector bj2(TT);
	NumericVector ai(ni);
	bj1=hpj/cd;
	double value=10;
	while (value>eps) {
		NumericVector den1(ni);
		for (int i=0;i<ni;i++)
			for (int j=0;j<TT;j++)
				den1[i]+= bj1[j]*delta(i,j);
		ai=hpi/den1;
		NumericVector den(TT);
		for (int i=0;i<ni;i++)
			for (int j=0;j<TT;j++)
				den[j]+= ai[i]*delta(i,j);
		bj2=hpj/den;
		value=max(abs(bj2-bj1));
		bj1=clone(bj2);
	}
	NumericVector As(TT);
	As=bj2/bj2[ref];
	NumericVector aj(ni);
	aj=ai*bj2[ref];
	List out(2);
	out[0]=As;
	out[1]=aj;
	return(out);
}

