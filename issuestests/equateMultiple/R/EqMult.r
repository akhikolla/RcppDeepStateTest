



# function to minimize for MIRF or MTRF method
obj<-function(par,T,ni,ab,aj1T,bj1T,cj1T,met,itmp,wt,D=D,base){
	A<-rep(1,T)
	A[-base]<-par[1:(T-1)]
	B<-rep(0,T)
	B[-base]<-par[T:(2*T-2)]
	if (itmp==1) A[1:T]<-1
	bj1Ts<-bj1T
	for (t in 1:T) bj1Ts[,t]<-(bj1Ts[,t]*A[t]+B[t])
	aj1Ts<-aj1T
	for (t in 1:T) aj1Ts[,t]<-aj1Ts[,t]/A[t]
	bj<-rowMeans(bj1Ts,na.rm=T)
	aj<-rowMeans(aj1Ts,na.rm=T)

	f<-0
	for (t in 1:T) {
		bjts<-(bj-B[t])/A[t]
		ajts<-aj*A[t]
		ajt<-aj1T[,t]
		bjt<-bj1T[,t]
		cjt<-cj1T[,t]
		Pt<-matrix(NA,length(ab),ni)
		for (i in 1:ni)
			Pt[,i]<-equateIRT:::irtp1(ab,diff=bjt[i],discr=ajt[i],guess=cjt[i],D=D)
		Pts<-matrix(NA,length(ab),ni)
		for (i in 1:ni)
			Pts[,i]<-equateIRT:::irtp1(ab,diff=bjts[i],discr=ajts[i],guess=cjt[i],D=D)
		Pts[is.na(Pt)]<-NA
		if (met=="irf") f<-f+0.5*sum((Pt-Pts)^2*wt,na.rm=T)
		if (met=="trf") f<-f+0.5*sum(((rowSums(Pt,na.rm=T)-rowSums(Pts,na.rm=T))^2)*wt)
	}

	return(f)
}

# numerical first derivative of obj with respect to the item parameters
# used for finding the numerical second derivative of obj
# with respect to the equating coefficients and the item parameters
Sgamma<-function(x,par,T,ni,ab,tabl,nummet,itmp,wt,D=D,base){
	tabl$gamma<-x[rownames(tabl)]
	tab<-reshape(tabl,direction="wide",v.names="gamma",timevar="time", idvar = "itms")
	bj1T<-as.matrix(tab[substr(tab$itms,1,6)=="Dffclt",][,-1])
	if (itmp>1) aj1T<-as.matrix(tab[substr(tab$itms,1,6)=="Dscrmn",][,-1])
	else aj1T<-matrix(1,ni,T)
	if (itmp==3) cj1T<-as.matrix(tab[substr(tab$itms,1,6)=="Gussng",][,-1])
	else cj1T<-matrix(0,ni,T)
	grad(func=objectivefzRcpp,x=par,T=T,ab=ab,wt=wt,aj1T=aj1T,bj1T=bj1T,cj1T=cj1T,nummet=nummet,itmp=itmp,D=D,base=base) 
}



# this functions returns the matrix of second derivatives of obj
# (at the minimum) with respect to the equating coefficients and 
# the item parameters
# calls Rcpp
pABgammaR2C<-function(par,T,ab,wt,aj1T,bj1T,cj1T,nummet,itmp,D,base)
{
	nb<-sum(!is.na(aj1T))
	posnomi<-aj1T
	posnomi[!is.na(posnomi)]<-1:nb
	tabnomia<-outer(rownames(aj1T),1:T,paste,sep=".")
	tabnomia[is.na(aj1T)]<-NA
	tabnomib<-outer(rownames(bj1T),1:T,paste,sep=".")
	tabnomib[is.na(bj1T)]<-NA
	if (itmp==3) { tabnomic<-outer(rownames(cj1T),1:T,paste,sep=".")
		tabnomic[is.na(cj1T)]<-NA}
	nomia<-tabnomia[!is.na(tabnomia)]
	nomib<-tabnomib[!is.na(tabnomib)]
	if (itmp==3) nomic<-tabnomic[!is.na(tabnomic)]

	tt<-partialABgammaRcpp(par,T,ab,wt,aj1T,bj1T,cj1T,nummet,itmp,D,base,nb,posnomi)

	out_a<-tt[[1]]
	out_b<-tt[[2]]
	if(itmp==3) out_c<-tt[[3]]
	else out_c<-NULL
	colnames(out_a)<-nomia
	colnames(out_b)<-nomib
	if (itmp==3) colnames(out_c)<-nomic

	out<-cbind(out_c,out_a,out_b)
	out<-out[-c(base,base+T),]
	return(out)
}

# this functions returns the matrix of second derivatives of obj
# (at the minimum) with respect to the equating coefficients and 
# the item parameters
pABgammaR<-function(A,B,T,ni,ab,tab,met,itmp,wt,D=D,base){
	nq<-length(ab)
	row.names(tab)<-tab$itms
	bj1T<-tab[substr(tab$itms,1,6)=="Dffclt",][,-1]
	if (itmp>1) aj1T<-tab[substr(tab$itms,1,6)=="Dscrmn",][,-1]
	else aj1T<-matrix(1,ni,T); aj1T[is.na(bj1T)]<-NA
	if (itmp==3) cj1T<-tab[substr(tab$itms,1,6)=="Gussng",][,-1]
	else cj1T<-matrix(0,ni,T)
	
	nb<-sum(!is.na(aj1T))
	posnomi<-aj1T
	posnomi[!is.na(posnomi)]<-1:nb
	tabnomia<-outer(rownames(aj1T),1:T,paste,sep=".")
	tabnomia[is.na(aj1T)]<-NA
	tabnomib<-outer(rownames(bj1T),1:T,paste,sep=".")
	tabnomib[is.na(bj1T)]<-NA
	if (itmp==3) { tabnomic<-outer(rownames(cj1T),1:T,paste,sep=".")
		tabnomic[is.na(cj1T)]<-NA}
	
	bj1Ts<-bj1T
	for (t in 1:T) bj1Ts[,t]<-bj1Ts[,t]*A[t]+B[t]
	aj1Ts<-aj1T
	for (t in 1:T) aj1Ts[,t]<-aj1Ts[,t]/A[t]
	bj<-rowMeans(bj1Ts,na.rm=T)
	aj<-rowMeans(aj1Ts,na.rm=T)
	nomia<-tabnomia[!is.na(tabnomia)]
	nomib<-tabnomib[!is.na(tabnomib)]
	if (itmp==3) nomic<-tabnomic[!is.na(tabnomic)]
	out_a<-matrix(0,2*T,nb)
	out_b<-matrix(0,2*T,nb)
	if (itmp==3) out_c<-matrix(0,2*T,nb) else out_c<-NULL
	colnames(out_a)<-nomia
	colnames(out_b)<-nomib
	if (itmp==3) colnames(out_c)<-nomic
	Tj<-rowSums(!is.na(bj1Ts))
	aj1T[is.na(aj1T)]<-0
	bj1T[is.na(bj1T)]<-0
	
	for (t in 1:T) {
		# print(t)
		bjts<-(bj-B[t])/A[t]
		ajts<-aj*A[t]
		ajt<-aj1T[,t]
		bjt<-bj1T[,t]
		cjt<-cj1T[,t]
		
		Pt<-matrix(NA,length(ab),ni)
		for (i in 1:ni)
			Pt[,i]<-equateIRT:::irtp1(ab,diff=bjt[i],discr=ajt[i],guess=cjt[i],D=D)
		Pts<-matrix(NA,length(ab),ni)
		for (i in 1:ni)
			Pts[,i]<-equateIRT:::irtp1(ab,diff=bjts[i],discr=ajts[i],guess=cjt[i],D=D)
		SPt<-0
		for (i in 1:ni) if (aj1T[i,t]!=0) SPt<-SPt+(Pt[,i]-Pts[,i])
		pPLP<-matrix(NA,nq,ni)
		for (i in 1:ni) pPLP[,i]<-(Pts[,i]-cjt[i])*(1-Pts[,i])/(1-cjt[i]) # Equation (46)
			

		for (s in 1:T) { # s is the index of the equating coefficient
			if (s!=base) {
				# derivatives of Pts with respect base the equating coefficients
				pPBs<-pPAs<-p1PAs<-matrix(NA,length(ab),ni)
				for (i in 1:ni) {
					if (s==t) pPBs[,i]<-pPLP[,i]*D*aj[i]*(1-1/Tj[i]*(bj1T[i,t]!=0)) # Equations (50) + (51)
					if (s!=t) pPBs[,i]<-pPLP[,i]*D*aj[i]*(-1/Tj[i]*(bj1T[i,s]!=0)) # Equations (52) + (53)
					if (s==t) p1PAs[,i]<- D/Tj[i]*(sum(aj1Ts[i,-t],na.rm=T)*ab+aj1T[i,t]/A[t]^2*(bj[i]-B[t])-aj[i]*bj1T[i,t]) # Equation (47)
					if (s!=t) p1PAs[,i]<- D/Tj[i]*(-aj1T[i,s]/A[s]^2*A[t]*ab+aj1T[i,s]/A[s]^2*(bj[i]-B[t])-aj[i]*bj1T[i,s]) # Equation (49)
					pPAs[,i]<-pPLP[,i]*p1PAs[,i] # Equation (48)
				}
				SpPBs<-SpPAs<-0
				for (i in 1:ni) if (aj1T[i,t]!=0) SpPBs<-SpPBs+pPBs[,i]
				for (i in 1:ni) if (aj1T[i,t]!=0) SpPAs<-SpPAs+pPAs[,i]
			
				for (k in 1:T) { # k is the index of item parameter
					for (i in 1:ni) { # i is the index of the item
						if (aj1T[i,t]!=0 & aj1T[i,k]!=0) {
							# derivatives of Pt with respect to the item parameters
							if (k==t) {
								pPtgamma_a<-  (Pt[,i]-cj1T[i,t])*(1-(Pt[,i]-cj1T[i,t])/(1-cj1T[i,t]))*D*(ab-bj1T[i,t]) # Equation (69)
								pPtgamma_b<- -(Pt[,i]-cj1T[i,t])*(1-(Pt[,i]-cj1T[i,t])/(1-cj1T[i,t]))*D*aj1T[i,t] # Equation (70)
								if (itmp==3) pPtgamma_c<-1-(Pt[,i]-cj1T[i,t])/(1-cj1T[i,t]) else pPtgamma_c<-0 # Equation (68)
							}
							if (k!=t) pPtgamma_a<-pPtgamma_b<-pPtgamma_c<-0
							# derivatives of Pts with respect to the item parameters
							if (k==t) {
								pPtsgamma_a<-  pPLP[,i]*D/Tj[i]*(ab-(bj[i]-B[t])/A[t])*(bj1T[i,t]!=0) # Equation (72)
								if (itmp==3) pPtsgamma_c<-1-(Pts[,i]-cj1T[i,t])/(1-cj1T[i,t]) else pPtsgamma_c<-0 # Equation (71)
							}
							if (k!=t) {
								pPtsgamma_a<-pPLP[,i]*D/Tj[i]*(ab*A[t]/A[k]-(bj[i]-B[t])/A[k])*(bj1T[i,k]!=0) # Equation (73)
								pPtsgamma_c<-0
							}
							pPtsgamma_b<- -pPLP[,i]*D/Tj[i]*aj[i]*A[k]*(bj1T[i,k]!=0) # Equation (74)
							# second derivatives of Pts with respect to the equating coefficients and the item parameters
							if (itmp==3 & k==t) ppPts_Ac<- -pPAs[,i]/(1-cj1T[i,t]) else ppPts_Ac<-0 # Equation (81)
							if (itmp==3 & k==t) ppPts_Bc<- -pPBs[,i]/(1-cj1T[i,t]) else ppPts_Bc<-0 # Equation (78)
							
							if (s==t & k==t) ppPts_Aa<-(pPtsgamma_a-2*((Pts[,i]-cj1T[i,t])/(1-cj1T[i,t]))*pPtsgamma_a)*p1PAs[,i]+pPLP[,i]*D/Tj[i]*((bj[i]-B[t])/A[t]^2-bj1T[i,t]/(Tj[i]*A[t])) # Equation (82)
							if (s==t & k!=t) ppPts_Aa<-(pPtsgamma_a-2*((Pts[,i]-cj1T[i,t])/(1-cj1T[i,t]))*pPtsgamma_a)*p1PAs[,i]+pPLP[,i]*D/Tj[i]*(ab/A[k]-bj1T[i,t]/(Tj[i]*A[k])*(bj1T[i,t]!=0)) # Equation (83)
							if (s!=t & k==s) ppPts_Aa<-(pPtsgamma_a-2*((Pts[,i]-cj1T[i,t])/(1-cj1T[i,t]))*pPtsgamma_a)*p1PAs[,i]+pPLP[,i]*D/Tj[i]*(-ab*A[t]/A[s]^2+(bj[i]-B[t])/A[s]^2-bj1T[i,s]/(Tj[i]*A[s])) # Equation (87)
							if (s!=t & k!=s) ppPts_Aa<-(pPtsgamma_a-2*((Pts[,i]-cj1T[i,t])/(1-cj1T[i,t]))*pPtsgamma_a)*p1PAs[,i]+pPLP[,i]*D/Tj[i]*(-bj1T[i,s]/(Tj[i]*A[k]))*(bj1T[i,s]!=0) # Equation (88)
							if (s==t) ppPts_Ba<-  (pPtsgamma_a-2*((Pts[,i]-cj1T[i,t])/(1-cj1T[i,t]))*pPtsgamma_a)*D*aj[i]*(1-1/Tj[i]*(bj1T[i,t]!=0))+pPLP[,i]*D/Tj[i]/A[k]*(1-1/Tj[i]*(bj1T[i,t]!=0)) # Equation (76)
							if (s!=t) ppPts_Ba<- -(pPtsgamma_a-2*((Pts[,i]-cj1T[i,t])/(1-cj1T[i,t]))*pPtsgamma_a)*D*aj[i]/Tj[i]*(bj1T[i,s]!=0)-pPLP[,i]*D/A[k]/Tj[i]^2*(bj1T[i,s]!=0) # Equation (79)
							
							if (s==t & k==t) ppPts_Ab<-(pPtsgamma_b-2*((Pts[,i]-cj1T[i,t])/(1-cj1T[i,t]))*pPtsgamma_b)*p1PAs[,i]+pPLP[,i]*D/Tj[i]*(aj1T[i,t]/(Tj[i]*A[t])-aj[i])*(aj1T[i,t]!=0) # Equation (84)
							if (s==t & k!=t) ppPts_Ab<-(pPtsgamma_b-2*((Pts[,i]-cj1T[i,t])/(1-cj1T[i,t]))*pPtsgamma_b)*p1PAs[,i]+pPLP[,i]*D/Tj[i]*(aj1T[i,t]/(Tj[i]*A[t]^2)*A[k])*(aj1T[i,t]!=0) # Equation (85)
							if (s!=t & k==s) ppPts_Ab<-(pPtsgamma_b-2*((Pts[,i]-cj1T[i,t])/(1-cj1T[i,t]))*pPtsgamma_b)*p1PAs[,i]+pPLP[,i]*D/Tj[i]*(aj1T[i,s]/(Tj[i]*A[s])-aj[i])*(aj1T[i,s]!=0) # Equation (89)
							if (s!=t & k!=s) ppPts_Ab<-(pPtsgamma_b-2*((Pts[,i]-cj1T[i,t])/(1-cj1T[i,t]))*pPtsgamma_b)*p1PAs[,i]+pPLP[,i]*D/Tj[i]*(aj1T[i,s]/(Tj[i]*A[s]^2)*A[k])*(aj1T[i,s]!=0) # Equation (90)
							if (s==t) ppPts_Bb<-  (pPtsgamma_b-2*((Pts[,i]-cj1T[i,t])/(1-cj1T[i,t]))*pPtsgamma_b)*D*aj[i]*(1-1/Tj[i]*(bj1T[i,t]!=0)) # Equation (77)
							if (s!=t) ppPts_Bb<- -(pPtsgamma_b-2*((Pts[,i]-cj1T[i,t])/(1-cj1T[i,t]))*pPtsgamma_b)*D*aj[i]/Tj[i]*(bj1T[i,s]!=0) # Equation (80)
							co<-posnomi[i,k] # which item parameter
							if (met=="irf") {
								out_a[s,co]<-out_a[s,co]+sum(((pPtgamma_a-pPtsgamma_a)*(-pPAs[,i])-(Pt[,i]-Pts[,i])*ppPts_Aa)*wt)
								out_a[s+T,co]<-out_a[s+T,co]+sum(((pPtgamma_a-pPtsgamma_a)*(-pPBs[,i])-(Pt[,i]-Pts[,i])*ppPts_Ba)*wt)
								out_b[s,co]<-out_b[s,co]+sum(((pPtgamma_b-pPtsgamma_b)*(-pPAs[,i])-(Pt[,i]-Pts[,i])*ppPts_Ab)*wt)
								out_b[s+T,co]<-out_b[s+T,co]+sum(((pPtgamma_b-pPtsgamma_b)*(-pPBs[,i])-(Pt[,i]-Pts[,i])*ppPts_Bb)*wt)
								if (itmp==3) out_c[s,co]<-out_c[s,co]+sum(((pPtgamma_c-pPtsgamma_c)*(-pPAs[,i])-(Pt[,i]-Pts[,i])*ppPts_Ac)*wt)
								if (itmp==3) out_c[s+T,co]<-out_c[s+T,co]+sum(((pPtgamma_c-pPtsgamma_c)*(-pPBs[,i])-(Pt[,i]-Pts[,i])*ppPts_Bc)*wt)
							}
							if (met=="trf") {
								out_a[s,co]<-out_a[s,co]+sum(((pPtgamma_a-pPtsgamma_a)*(-SpPAs)-SPt*ppPts_Aa)*wt)
								out_a[s+T,co]<-out_a[s+T,co]+sum(((pPtgamma_a-pPtsgamma_a)*(-SpPBs)-SPt*ppPts_Ba)*wt)
								out_b[s,co]<-out_b[s,co]+sum(((pPtgamma_b-pPtsgamma_b)*(-SpPAs)-SPt*ppPts_Ab)*wt)
								out_b[s+T,co]<-out_b[s+T,co]+sum(((pPtgamma_b-pPtsgamma_b)*(-SpPBs)-SPt*ppPts_Bb)*wt)
								if (itmp==3) out_c[s,co]<-out_c[s,co]+sum(((pPtgamma_c-pPtsgamma_c)*(-SpPAs)-SPt*ppPts_Ac)*wt)
								if (itmp==3) out_c[s+T,co]<-out_c[s+T,co]+sum(((pPtgamma_c-pPtsgamma_c)*(-SpPBs)-SPt*ppPts_Bc)*wt)
							}
						} # if
					} # for i
				} # for k
			}  # if
		} # for s
	} # for t
	outt<-cbind(out_c,out_a,out_b)
	outt<-outt[-c(base,base+T),]
	return(outt)
}


# matrix of second derivatives of obj (at the minimum)
hessR<-function(par,T,ni,ab,tab,met,itmp,wt,D=D,base){
	nq<-length(ab)
	A<-rep(1,T)
	A[-base]<-par[1:(T-1)]
	B<-rep(0,T)
	B[-base]<-par[T:(2*T-2)]
	if (itmp==1) A[1:T]<-1
	bj1T<-tab[substr(tab$itms,1,6)=="Dffclt",][,-1]
	if (itmp>1) aj1T<-tab[substr(tab$itms,1,6)=="Dscrmn",][,-1]
	else aj1T<-matrix(1,ni,T)
	if (itmp==3) cj1T<-tab[substr(tab$itms,1,6)=="Gussng",][,-1]
	else cj1T<-matrix(0,ni,T)
	bj1Ts<-bj1T
	for (t in 1:T) bj1Ts[,t]<-bj1Ts[,t]*A[t]+B[t]
	aj1Ts<-aj1T
	for (t in 1:T) aj1Ts[,t]<-aj1Ts[,t]/A[t]
	bj<-rowMeans(bj1Ts,na.rm=T)
	aj<-rowMeans(aj1Ts,na.rm=T)

	Tj<-rowSums(!is.na(bj1Ts))
	f<-matrix(0,2*T,2*T)
	aj1T[is.na(aj1T)]<-0
	bj1T[is.na(bj1T)]<-0
	for (t in 1:T) {
		bjts<-(bj-B[t])/A[t]
		ajts<-aj*A[t]
		ajt<-aj1T[,t]
		bjt<-bj1T[,t]
		cjt<-cj1T[,t]
		Pt<-matrix(NA,length(ab),ni)
		for (i in 1:ni)
			Pt[,i]<-equateIRT:::irtp1(ab,diff=bjt[i],discr=ajt[i],guess=cjt[i],D=D)
		Pts<-matrix(NA,length(ab),ni)
		for (i in 1:ni)
			Pts[,i]<-equateIRT:::irtp1(ab,diff=bjts[i],discr=ajts[i],guess=cjt[i],D=D)
		sel<-!is.na(tab[1:ni,t+1])
		pPLP<-matrix(NA,nq,ni)
		for (i in 1:ni) pPLP[,i]<-(Pts[,i]-cjt[i])*(1-Pts[,i])/(1-cjt[i]) # Equation (46)
		pPtjs<-vector("list",2*T)
		p1Ptjs<-vector("list",2*T)
		for (s in 1:T) if(s!=base) pPtjs[[s+T]]<-p1Ptjs[[s+T]]<-matrix(NA,length(ab),ni)
		for (s in 1:T) if(s!=base) if (s==t) for (i in 1:ni) pPtjs[[s+T]][,i]<-pPLP[,i]*D*aj[i]*(1-1/Tj[i]*(bj1T[i,t]!=0)) # Equations (50) + (51)
		for (s in 1:T) if(s!=base) if (s!=t) for (i in 1:ni) pPtjs[[s+T]][,i]<-pPLP[,i]*D*aj[i]*(-1/Tj[i]*(bj1T[i,s]!=0)) # Equations (52) + (53)
		for (s in 1:T) if(s!=base) pPtjs[[s]]<-p1Ptjs[[s]]<-matrix(NA,length(ab),ni)
		for (s in 1:T) if(s!=base) if (s==t) for (i in 1:ni) {
			p1Ptjs[[s]][,i]<-D/Tj[i]*(sum(aj1Ts[i,-t],na.rm=T)*ab+aj1T[i,t]/A[t]^2*(bj[i]-B[t])-aj[i]*bj1T[i,t]) # Equation (47)
			pPtjs[[s]][,i]<-pPLP[,i]*p1Ptjs[[s]][,i]} # Equation (45)
		for (s in 1:T) if(s!=base) if (s!=t) for (i in 1:ni) {
			p1Ptjs[[s]][,i]<- D/Tj[i]*(-aj1T[i,s]/A[s]^2*A[t]*ab+aj1T[i,s]/A[s]^2*(bj[i]-B[t])-aj[i]*bj1T[i,s]) # Equation (49)
			pPtjs[[s]][,i]<-pPLP[,i]*p1Ptjs[[s]][,i]} # Equation (48)

		# second derivatives
		ppPtjs<-vector("list",4*T^2)
		for (s in 1:(4*T^2)) ppPtjs[[s]]<-matrix(NA,length(ab),ni)
		#BtBt
		for (s in 1:T) if(s!=base) if (s==t) for (i in 1:ni) ppPtjs[[s+T+(s+T-1)*2*T]][,i]<- (pPtjs[[s+T]][,i]-2*((Pts[,i]-cjt[i])/(1-cjt[i]))*pPtjs[[s+T]][,i])*D*aj[i]*(1-1/Tj[i]*(bj1T[i,t]!=0)) # Equations (54) with k=t, (55) and (51) 
		#BsBs
		for (s in 1:T) if(s!=base) if (s!=t) for (i in 1:ni) ppPtjs[[s+T+(s+T-1)*2*T]][,i]<- -(pPtjs[[s+T]][,i]-2*((Pts[,i]-cjt[i])/(1-cjt[i]))*pPtjs[[s+T]][,i])*D*aj[i]/Tj[i]*(bj1T[i,s]!=0) # Equations (57), (55) and (53)
		#AtAt
		for (s in 1:T) if(s!=base) if (s==t) for (i in 1:ni) ppPtjs[[s+(s-1)*2*T]][,i]<- (pPtjs[[s]][,i]-2*((Pts[,i]-cjt[i])/(1-cjt[i]))*pPtjs[[s]][,i])*p1Ptjs[[s]][,i] + pPLP[,i]*D/Tj[i]*(-2*aj1T[i,s]/A[s]^3*(bj[i]-B[s])+2*aj1T[i,s]/A[s]^2*bj1T[i,s]/Tj[i]) # Equation (59), (47)
		#AsAs
		for (s in 1:T) if(s!=base) if (s!=t) for (i in 1:ni) ppPtjs[[s+(s-1)*2*T]][,i]<- (pPtjs[[s]][,i]-2*((Pts[,i]-cjt[i])/(1-cjt[i]))*pPtjs[[s]][,i])*p1Ptjs[[s]][,i] + pPLP[,i]*D/Tj[i]*(2*aj1T[i,s]/A[s]^3*A[t]*ab-2*aj1T[i,s]/A[s]^3*(bj[i]-B[t])+2*aj1T[i,s]/A[s]^2*bj1T[i,s]/Tj[i]) # Equation (63)
		#BtBs
		for (s in 1:T) for (k in 1:T) if(s!=base & k!=base) if (s==t) for (i in 1:ni) ppPtjs[[s+T+(k+T-1)*2*T]][,i]<-(pPtjs[[k+T]][,i]-2*((Pts[,i]-cjt[i])/(1-cjt[i]))*pPtjs[[k+T]][,i])*D*aj[i]*(1-1/Tj[i]*(bj1T[i,t]!=0)) # Equations (54), (55) and (51) 
		#BsBk
		for (s in 1:T) for (k in 1:T) if(s!=base & k!=base) if (s!=t) for (i in 1:ni) ppPtjs[[s+T+(k+T-1)*2*T]][,i]<- -(pPtjs[[k+T]][,i]-2*((Pts[,i]-cjt[i])/(1-cjt[i]))*pPtjs[[k+T]][,i])*D*aj[i]/Tj[i]*(bj1T[i,s]!=0) # Equations (57), (55) and (53)
		#AtAs
		for (s in 1:T) for (k in 1:T) if(s!=base & k!=base) if (s==t & k!=t) for (i in 1:ni) ppPtjs[[s+(k-1)*2*T]][,i]<- (pPtjs[[k]][,i]-2*((Pts[,i]-cjt[i])/(1-cjt[i]))*pPtjs[[k]][,i])*p1Ptjs[[s]][,i] + pPLP[,i]*D/Tj[i]*(-aj1T[i,k]/A[k]^2*ab+aj1T[i,t]/A[t]^2*bj1T[i,k]/Tj[i]+aj1T[i,k]/A[k]^2*bj1T[i,s]/Tj[i]) # Equations (60), (47)
		#AsAt
		for (s in 1:T) for (k in 1:T) if(s!=base & k!=base) if (s!=t & k==t) for (i in 1:ni) ppPtjs[[s+(k-1)*2*T]][,i]<- (pPtjs[[k]][,i]-2*((Pts[,i]-cjt[i])/(1-cjt[i]))*pPtjs[[k]][,i])*p1Ptjs[[s]][,i] + pPLP[,i]*D/Tj[i]*(-aj1T[i,s]/A[s]^2*ab+aj1T[i,s]/A[s]^2*bj1T[i,k]/Tj[i]+aj1T[i,k]/A[k]^2*bj1T[i,s]/Tj[i]) # Equation (64)
		#AsAk
		for (s in 1:T) for (k in 1:T) if(s!=base & k!=base) if (s!=t & k!=t & s!=k) for (i in 1:ni) ppPtjs[[s+(k-1)*2*T]][,i]<- (pPtjs[[k]][,i]-2*((Pts[,i]-cjt[i])/(1-cjt[i]))*pPtjs[[k]][,i])*p1Ptjs[[s]][,i] + pPLP[,i]*D/Tj[i]*(aj1T[i,s]/A[s]^2*bj1T[i,k]/Tj[i]+aj1T[i,k]/A[k]^2*bj1T[i,s]/Tj[i]) # Equation (67)
		#BtAk
		for (s in 1:T) for (k in 1:T) if(s!=base & k!=base) if (s==t) for (i in 1:ni) ppPtjs[[s+T+(k-1)*2*T]][,i]<-   (pPtjs[[k]][,i]-2*((Pts[,i]-cjt[i])/(1-cjt[i]))*pPtjs[[k]][,i])*D*aj[i]*(1-1/Tj[i]*(bj1T[i,t]!=0))-pPLP[,i]*D/Tj[i]*aj1T[i,k]/A[k]^2*(1-1/Tj[i]*(bj1T[i,t]!=0)) # Equations (56), (51)
		#BsAk
		for (s in 1:T) for (k in 1:T) if(s!=base & k!=base) if (s!=t) for (i in 1:ni) ppPtjs[[s+T+(k-1)*2*T]][,i]<- (-(pPtjs[[k]][,i]-2*((Pts[,i]-cjt[i])/(1-cjt[i]))*pPtjs[[k]][,i])*D*aj[i]/Tj[i]+pPLP[,i]*D/Tj[i]*aj1T[i,k]/A[k]^2/Tj[i])*(bj1T[i,s]!=0) # Equations (58), (53)
		#AtBt
		for (s in 1:T) for (k in 1:T) if(s!=base & k!=base) if (s==t & k==t) for (i in 1:ni) ppPtjs[[s+(k+T-1)*2*T]][,i]<- (pPtjs[[k+T]][,i]-2*((Pts[,i]-cjt[i])/(1-cjt[i]))*pPtjs[[k+T]][,i])*p1Ptjs[[s]][,i] + pPLP[,i]*D/Tj[i]*(aj1T[i,s]/A[s]^2*(1/Tj[i]-1)) # Equations (61), (47)
		#AtBs
		for (s in 1:T) for (k in 1:T) if(s!=base & k!=base) if (s==t & k!=t) for (i in 1:ni) ppPtjs[[s+(k+T-1)*2*T]][,i]<- (pPtjs[[k+T]][,i]-2*((Pts[,i]-cjt[i])/(1-cjt[i]))*pPtjs[[k+T]][,i])*p1Ptjs[[s]][,i] + pPLP[,i]*D/Tj[i]*(aj1T[i,s]/A[s]^2/Tj[i])*(bj1T[i,k]!=0) # Equations (62), (47)
		#AsBt
		for (s in 1:T) for (k in 1:T) if(s!=base & k!=base) if (s!=t & k==t) for (i in 1:ni) ppPtjs[[s+(k+T-1)*2*T]][,i]<- (pPtjs[[k+T]][,i]-2*((Pts[,i]-cjt[i])/(1-cjt[i]))*pPtjs[[k+T]][,i])*p1Ptjs[[s]][,i] + pPLP[,i]*D/Tj[i]*(aj1T[i,s]/A[s]^2*(1/Tj[i]*(bj1T[i,k]!=0)-1)) # Equation (66)
		#AsBk
		for (s in 1:T) for (k in 1:T) if(s!=base & k!=base) if (s!=t & k!=t) for (i in 1:ni) ppPtjs[[s+(k+T-1)*2*T]][,i]<- (pPtjs[[k+T]][,i]-2*((Pts[,i]-cjt[i])/(1-cjt[i]))*pPtjs[[k+T]][,i])*p1Ptjs[[s]][,i] + pPLP[,i]*D/Tj[i]*(aj1T[i,s]/A[s]^2/Tj[i])*(aj1T[i,k]!=0) # Equation (65)
		
		for (s in 1:(2*T)) {
			for (k in 1:(2*T)) {
				if(s!=base & k!=base & s!=(base+T) & k!=(base+T)) {
					if (met=="irf")	f[s,k]<-f[s,k]+sum(rowSums( pPtjs[[s]][,sel]*pPtjs[[k]][,sel] -(Pt[,sel]-Pts[,sel])*ppPtjs[[s+(k-1)*2*T]][,sel] ,na.rm=TRUE )*wt)
					if (met=="trf") f[s,k]<-f[s,k]+sum((rowSums( pPtjs[[s]][,sel])*rowSums(pPtjs[[k]][,sel])-rowSums(Pt[,sel]-Pts[,sel])*rowSums(ppPtjs[[s+(k-1)*2*T]][,sel]))*wt)
		}}}
	}
	f1<-f[-c(base,base+T),-c(base,base+T)]
	return(f1)
}



# this function is used to compute the numerical derivatives of a_j^* and b_j^* 
# with respect to the item parameter estimates
# as input requires the item parameter estimates (gamma)
# as output returns a_j^* and b_j^* 
gamma2ab<-function(x,par,T,ni,ab,tabl,nummet,itmp,wt,D=D,base,ini){
	#print(x)
	#Ts<-paste("T",1:T,sep="")
	tabl$gamma<-x[rownames(tabl)]
	tab<-reshape(tabl,direction="wide",v.names="gamma",timevar="time", idvar = "itms")
	bj1T<-as.matrix(tab[substr(tab$itms,1,6)=="Dffclt",][,-1])
	if (itmp>1) aj1T<-as.matrix(tab[substr(tab$itms,1,6)=="Dscrmn",][,-1])
	else aj1T<-matrix(1,ni,T)
	if (itmp==3) cj1T<-as.matrix(tab[substr(tab$itms,1,6)=="Gussng",][,-1])
	else cj1T<-matrix(0,ni,T)
	out<-nlminb(start=ini,objective=objectivefzRcpp,T=T,ab=ab,wt=wt,aj1T=aj1T,bj1T=bj1T,cj1T=cj1T,nummet=nummet,itmp=itmp,D=1,base=base,control=list(iter.max=100000,eval.max=10000,trace=FALSE))
	par<-out$par
	As<-rep(1,T)
	#names(As)<-Ts
	As[-base]<-par[1:(T-1)]
	Bs<-rep(0,T)
	#names(Bs)<-Ts
	Bs[-base]<-par[T:(2*T-2)]
	bj1Ts<-bj1T
	for (t in 1:T) bj1Ts[,t]<-bj1Ts[,t]*As[t]+Bs[t]
	aj1Ts<-aj1T
	for (t in 1:T) aj1Ts[,t]<-aj1Ts[,t]/As[t]
	bj<-rowMeans(bj1Ts,na.rm=T)
	aj<-rowMeans(aj1Ts,na.rm=T)
	#names(bj)<-tab$itms[substr(tab$itms,1,6)=="Dffclt"]
	#names(aj)<-tab$itms[substr(tab$itms,1,6)=="Dscrmn"]
	return(c(aj,bj))
}



multiec_irf<-function(mods,base,nq=30,method,se,start,eval.max=10000,trace=FALSE,check=FALSE){
	cat("Computation of equating coefficients  .  .  .  . \n")
	if (class(start)=="mlteqc") start<-c(start$A[-1],start$B[-1])
	itms<-c()
	for (k in 1:length(mods)) itms<-c(itms,names(mods[[k]]$coef))
	itms<-sort(unique(itms))
	T<-length(mods)
	#Ts<-paste("T",1:T,sep="")
	modsnames<-names(mods)
	tab<-data.frame(itms=itms)
	for (k in 1:length(mods)) 
		tab<-merge(tab,mods[[k]]$coef,by.x="itms",by.y=0,all=T,suffixes=c(k-1,k))
	colnames(tab)[-1]<-modsnames
	tab<-tab[rowSums(!is.na(tab[,-1]))>=2,]
	
	tab$itms<-as.character(tab$itms)
	itmp<-2
	if (sum(substr(tab$itms,1,6)=="Dscrmn")==0) itmp=1
	if (sum(substr(tab$itms,1,6)=="Gussng")>0) itmp=3

	if (is.null(start)) ini<-c(rep(1,T-1),rep(0,T-1))
	if (!is.null(start)) ini<-start
	names(ini)<-c(modsnames[-base],modsnames[-base])
	
	gq<-gauss.quad.prob(nq,dist="normal")
	ab<-gq$nodes
	wt<-gq$weights

	ni<-nrow(tab)/itmp
	bj1T<-as.matrix(tab[substr(tab$itms,1,6)=="Dffclt",][,-1])
	if (itmp>1) aj1T<-as.matrix(tab[substr(tab$itms,1,6)=="Dscrmn",][,-1])
	if (itmp==1) aj1T<-matrix(1,ni,T); aj1T[is.na(bj1T)]<-NA
	if (itmp==3) cj1T<-as.matrix(tab[substr(tab$itms,1,6)=="Gussng",][,-1])
	if (itmp<3) cj1T<-matrix(0,ni,T)
	if (method=="irf") nummet<-1
	if (method=="trf") nummet<-2
	# the following uses Rcpp function
	out<-nlminb(start=ini,objective=objectivefzRcpp,gradient=gradRcpp,hessian=hessRcpp,T=T,ab=ab,wt=wt,aj1T=aj1T,bj1T=bj1T,cj1T=cj1T,nummet=nummet,itmp=itmp,D=1,base=base,control=list(iter.max=100000,eval.max=eval.max,trace=trace))
	#out<-nlminb(start=ini,objective=objectivefzRcpp,T=T,ab=ab,wt=wt,aj1T=aj1T,bj1T=bj1T,cj1T=cj1T,nummet=nummet,itmp=itmp,D=1,base=base,control=list(iter.max=100000,eval.max=eval.max,trace=trace))
	if (check) {
		# the following uses R function
		outR<-nlminb(start=ini,objective=obj,T=T,ni=ni,ab=ab,aj1T=aj1T,bj1T=bj1T,cj1T=cj1T,met=method,itmp=itmp,wt=wt,D=1,base=base,control=list(iter.max=100000,eval.max=eval.max,trace=FALSE))
		# test if Rcpp function returns the same value of the R function:
		cat("check parameter estimation \n")
		print(max(abs(out$par-outR$par)))
		# the same with optim
		outo<-optim(par=out$par,fn=objectivefzRcpp,T=T,ab=ab,wt=wt,aj1T=aj1T,bj1T=bj1T,cj1T=cj1T,nummet=nummet,itmp=itmp,D=1,base=base,control=list(reltol=1e-14,abstol=1e-14,maxit=100000,trace=FALSE),hessian=TRUE)
		cat("check gradient \n")
		numericgr<-grad(func=objectivefzRcpp,x=ini,T=T,ab=ab,wt=wt,aj1T=aj1T,bj1T=bj1T,cj1T=cj1T,nummet=nummet,itmp=itmp,D=1,base=base)
		analiticgr<-gradRcpp(ini,T=T,ab=ab,wt=wt,aj1T=aj1T,bj1T=bj1T,cj1T=cj1T,nummet=nummet,itmp=itmp,D=1,base=base)
		print(max(abs(analiticgr-numericgr)))
	}
	par<-out$par
	As<-rep(1,T)
	names(As)<-modsnames
	As[-base]<-par[1:(T-1)]
	Bs<-rep(0,T)
	names(Bs)<-modsnames
	Bs[-base]<-par[T:(2*T-2)]
	
	bj1Ts<-bj1T
	for (t in 1:T) bj1Ts[,t]<-bj1Ts[,t]*As[t]+Bs[t]
	aj1Ts<-aj1T
	for (t in 1:T) aj1Ts[,t]<-aj1Ts[,t]/As[t]
	bj<-rowMeans(bj1Ts,na.rm=T)
	aj<-rowMeans(aj1Ts,na.rm=T)
	names(bj)<-tab$itms[substr(tab$itms,1,6)=="Dffclt"]
	names(aj)<-tab$itms[substr(tab$itms,1,6)=="Dscrmn"]
	rownames(aj1T)<-tab$itms[substr(tab$itms,1,6)=="Dscrmn"]
	rownames(bj1T)<-tab$itms[substr(tab$itms,1,6)=="Dffclt"]
	rownames(cj1T)<-tab$itms[substr(tab$itms,1,6)=="Gussng"]
	
	if (se) {
		cat("Computation of standard errors ")
		# h1 is the matrix of second derivatives at the minimum (hessian)
		# the following uses Rcpp function
		h1<-hessRcpp(par=out$par,T=T,ab=ab,wt=wt,aj1T=aj1T,bj1T=bj1T,cj1T=cj1T,nummet=nummet,itmp=itmp,D=1,base=base)
		colnames(h1)<-c(rep("A",T-1),rep("B",T-1))
		cat(" . ")
		if (check) {
			# the following uses R function
			h1R<-hessR(par=out$par,T=T,ni=ni,ab=ab,tab=tab,met=method,itmp=itmp,wt=wt,D=1,base=base)
			if (itmp==1) h1R[1:(T-1),]<-h1R[,1:(T-1)]<-0
			# test if Rcpp function returns the same value of the R function:
			cat("\n check hessian matrix \n")
			print(max(abs(h1-h1R)))
			# test if Rcpp function returns the same value return by optim (which uses numerical derivatives)
			print(max(abs(outo$hess-h1)))
		}
		
		# pfABg is the matrix of second derivatives with respect to the equating coefficients and the item parameters
		# the following uses Rcpp function
		pfABg<-pABgammaR2C(par=out$par,T=T,ab=ab,wt=wt,aj1T=aj1T,bj1T=bj1T,cj1T=cj1T,nummet=nummet,itmp=itmp,D=1,base=base)
		if (itmp==1) {pfABg[1:(T-1),]<-0; pfABg<-pfABg[,grep("Dffclt",colnames(pfABg))]}
		cat(" . ")
		if (check) {
			# the following uses R function
			pfABgR<-pABgammaR(A=As,B=Bs,T=T,ni=ni,ab=ab,tab=tab,met=method,itmp=itmp,wt=wt,D=1,base=base)
			# test if Rcpp function returns the same value of the R function:
			if (itmp==1) {pfABgR[1:(T-1),]<-0; pfABgR<-subset(pfABgR,select=grepl("^Dffclt",colnames(pfABgR)))}
			cat("\n check second derivatives \n")
			print(max(abs(pfABg-pfABgR)))
			# the following computes numerical derivatives
			tabl<-reshape(tab,direction="long",varying=modsnames,idvar="itms",times=1:T,v.names="gamma")
			gamma<-tabl$gamma
			names(gamma)<-rownames(tabl)
			gamma<-gamma[!is.na(gamma)]
			pSgamma<-jacobian(func=Sgamma,x=gamma,par=out$par,T=T,ni=ni,ab=ab,tabl=tabl,nummet=nummet,itmp=itmp,wt=wt,D=1,base=base,method="simple")
			colnames(pSgamma)<-names(gamma)
			# test if the analytical second derivative is equal to the numerical second derivative
			print(max(abs(pfABg[,colnames(pSgamma)]-pSgamma)))
		}
		
		if (itmp==1) {h1<-h1[-(1:(T-1)),-(1:(T-1))]; pfABg<-pfABg[-(1:(T-1)),]}
		dAB_gamma<--solve(h1)%*%pfABg
		dAB_gamma<-dAB_gamma[,colSums(dAB_gamma)!=0]
		cat(" . ")

		sel<-colnames(dAB_gamma)
		vars<-lapply(mods,FUN=function(x) x$var)
		for (i in 1:length(vars)) rownames(vars[[i]])<-colnames(vars[[i]])<-paste(rownames(vars[[i]]),i,sep=".")
		VarAll<-VarExtRcpp(vars)
		VarAllNames<-c()
		for (i in 1:length(vars)) VarAllNames<-c(VarAllNames,rownames(vars[[i]]))
		rownames(VarAll)<-colnames(VarAll)<-VarAllNames
		#VarAll<-VarExt(mods)
		varAB<-dAB_gamma%*%VarAll[sel,sel]%*%t(dAB_gamma)
		seAB<-diag(varAB)^0.5
		seA<-rep(0,T)
		names(seA)<-modsnames
		if (itmp>1) seA[-base]<-seAB[1:(T-1)]
		seB<-rep(0,T)
		names(seB)<-modsnames
		if (itmp>1) seB[-base]<-seAB[T:(2*T-2)]
		if (itmp==1) seB[-base]<-seAB[1:(T-1)]
		
		# standard errors of synthetic item parameters
		
		invT<-as.matrix(rowSums(!is.na(bj1T))) # -> u_j
		invT<-invT[,c(rep(1,T))]
		colnames(invT)<-modsnames

		if (itmp>1) {
			pajA<-as.matrix(aj1T)
			for (t in 1:T) pajA[,t]<-aj1T[,t]/As[t]^2
			pajA[is.na(pajA)]<-0
			pajA<- -pajA/invT
			pajA<-as.matrix(pajA[,-base])
		
			grAa<-subset(dAB_gamma,subset=(rownames(dAB_gamma)=="A"),select=grepl("^Dscrmn",colnames(dAB_gamma))) # derivatives of equating coefficients A with respect to the discrimination item parameters
			pajgamma_a<-pajA%*%grAa # this is the result of the sum in Equations (91) and (92) multiplied by -1/u_j
			
			colnames_spl<-strsplit(colnames(grAa),split=".",fixed=T)
			colnames_no_t<-sapply(colnames_spl,FUN=function(x) paste(x[1],x[2],sep="."))
			sel_sameitem<-outer(rownames(aj1T),colnames_no_t,FUN="==")
			
			whicht<-as.numeric(as.character(sapply(colnames_spl,FUN=function(x) x[3])))
			
			pajgamma_a[sel_sameitem]<-pajgamma_a[sel_sameitem]+(matrix(1/invT[,1])%*%(1/As[whicht]))[sel_sameitem] # these are the derivatives in Equations (91) and (92)

			grAb<-subset(dAB_gamma,subset=(rownames(dAB_gamma)=="A"),select=grepl("^Dffclt",colnames(dAB_gamma))) # derivatives of equating coefficients A with respect to the difficulty item parameters
			pajgamma_b<-pajA%*%grAb # this is the result of the sum in Equation (93) multiplied by -1/u_j

			grAc<-subset(dAB_gamma,subset=(rownames(dAB_gamma)=="A"),select=grepl("^Gussng",colnames(dAB_gamma))) # derivatives of equating coefficients A with respect to the difficulty item parameters
			if (itmp==3) pajgamma_c<-pajA%*%grAc # similar to Equation (92), derivative of a_j^* with respect to c_it
			else pajgamma_c<-c()

			pajgamma<-cbind(pajgamma_a,pajgamma_b,pajgamma_c)
			
			sel<-colnames(pajgamma)
			seaj<-diag(pajgamma%*%VarAll[sel,sel]%*%t(pajgamma))^0.5
			seaj<-seaj[names(aj)]
		}
		if (itmp==1) aj<-seaj<-NULL
		
		cat(" . \n")
		
		pbjA<-as.matrix(bj1T)
		pbjA[is.na(pbjA)]<-0
		pbjA<- pbjA/invT
		pbjA<-as.matrix(pbjA[,-base])
		
		pbjB<-pbjA
		pbjB[pbjB!=0]<-1/invT[,-base][pbjB!=0]
		
		grAa<-subset(dAB_gamma,subset=(rownames(dAB_gamma)=="A"),select=grepl("^Dscrmn",colnames(dAB_gamma))) # derivatives of equating coefficients A with respect to the discrimination item parameters
		grBa<-subset(dAB_gamma,subset=(rownames(dAB_gamma)=="B"),select=grepl("^Dscrmn",colnames(dAB_gamma))) # derivatives of equating coefficients B with respect to the discrimination item parameters
		if (itmp>1) pbjgamma_a<-pbjA%*%grAa+pbjB%*%grBa # Equation (94)
		if (itmp==1) pbjgamma_a<-pbjB%*%grBa # Equation (94)
		
		grAb<-subset(dAB_gamma,subset=(rownames(dAB_gamma)=="A"),select=grepl("^Dffclt",colnames(dAB_gamma))) # derivatives of equating coefficients A with respect to the difficulty item parameters
		grBb<-subset(dAB_gamma,subset=(rownames(dAB_gamma)=="B"),select=grepl("^Dffclt",colnames(dAB_gamma))) # derivatives of equating coefficients B with respect to the difficulty item parameters
		if (itmp>1) pbjgamma_b<-pbjA%*%grAb+pbjB%*%grBb # this is the result of the sum in Equations (95) and (96) multiplied by -1/u_j
		if (itmp==1) pbjgamma_b<-pbjB%*%grBb # this is the result of the sum in Equations (95) and (96) multiplied by -1/u_j

		grAc<-subset(dAB_gamma,subset=(rownames(dAB_gamma)=="A"),select=grepl("^Gussng",colnames(dAB_gamma))) # derivatives of equating coefficients A with respect to the guessing item parameters
		grBc<-subset(dAB_gamma,subset=(rownames(dAB_gamma)=="B"),select=grepl("^Gussng",colnames(dAB_gamma))) # derivatives of equating coefficients B with respect to the guessing item parameters
		if (itmp==3) pbjgamma_c<-pbjA%*%grAc+pbjB%*%grBc # similar to Equation (94), derivative of b_j^* with respect to c_it
		else pbjgamma_c<-c()

		colnames_spl<-strsplit(colnames(grBb),split=".",fixed=T)
		colnames_no_t<-sapply(colnames_spl,FUN=function(x) paste(x[1],x[2],sep="."))
		sel_sameitem<-outer(rownames(bj1T),colnames_no_t,FUN="==")
		
		whicht<-as.numeric(as.character(sapply(colnames_spl,FUN=function(x) x[3])))
		
		pbjgamma_b[sel_sameitem]<-pbjgamma_b[sel_sameitem]+(matrix(1/invT[,1])%*%As[whicht])[sel_sameitem]
		
		pbjgamma<-cbind(pbjgamma_a,pbjgamma_b,pbjgamma_c)
		
		sel<-colnames(pbjgamma)
		sebj<-diag(pbjgamma%*%VarAll[sel,sel]%*%t(pbjgamma))^0.5
		sebj<-sebj[names(bj)]
		
		if (check) {
			# the following computes numerical derivatives of the synthetic item parameters with respect to the item parameter estimates
			cat("check derivatives of synthetic parameters \n")
			tabl<-reshape(tab,direction="long",varying=modsnames,idvar="itms",times=1:T,v.names="gamma")
			gamma<-tabl$gamma
			names(gamma)<-rownames(tabl)
			gamma<-gamma[!is.na(gamma)]
			p_ab_gamma<-jacobian(func=gamma2ab,x=gamma,par=par,T=T,ni=ni,ab=ab,tabl=tabl,nummet=nummet,itmp=itmp,wt=wt,D=1,base=base,ini=c(As,Bs),method="simple")
			colnames(p_ab_gamma)<-names(gamma)
			# test if the analytical second derivative is equal to the numerical second derivative
			if (itmp==1) pajgamma<-matrix(0,nrow(pbjgamma),ncol(pbjgamma))
			analitder<-rbind(pajgamma,pbjgamma)
			print(max(abs(analitder[,names(gamma)]-p_ab_gamma)))
			plot(analitder[,names(gamma)],p_ab_gamma)
		}
		partial<-t(dAB_gamma) # derivatives of A and B equating coefficients with respect to the item parameters
		namesAB<-c(paste("A",(1:T)[-base],sep="."),paste("B",(1:T)[-base],sep="."))
		colnames(partial)<-namesAB
		rownames(varAB)<-colnames(varAB)<-namesAB
	}
	else {
		seA<-rep(NA,T)
		seB<-rep(NA,T)
		varAB<-matrix(NA,T,T)
		seaj<-NULL
		sebj<-NULL
		vars<-NULL
		partial<-NULL
	}
	if (itmp==1) tabs<-bj1Ts
	if (itmp==2) tabs<-rbind(bj1Ts,aj1Ts)
	if (itmp==3) tabs<-rbind(bj1Ts,aj1Ts,cj1T)
	colnames(tabs)<-paste(colnames(tabs),modsnames[base],sep=".as.")
	tabs<-tabs[,-base]
	tab<-cbind(tab,tabs)
	colnames(tab)[1]<-"Item"
	out<-list(A=As,B=Bs,se.A=seA,se.B=seB,varAB=varAB,as=aj,bs=bj,se.as=seaj,se.bs=sebj,tab=tab,varFull=vars,partial=partial,itmp=itmp,method=method,basename=modsnames[base],convergence=out$convergence)
	class(out)<-"mlteqc"
	return(out)
}




# iterative proportional fitting
# mean-mean method
ipfR<-function(aj1T) {
	namesaj<-aj1T$itempar
	aj1T<-aj1T[,-1]
	ni<-nrow(aj1T)
	TT<-ncol(aj1T)
	uno<-matrix(1,1,TT)
	due<-matrix(1,ni,1)
	hpi<-rowSums(aj1T,na.rm=TRUE) #sum over t
	hpj<-colSums(aj1T,na.rm=TRUE) #sum over items
	delta<-aj1T
	delta[!is.na(aj1T)]<-1
	cd<-colSums(delta,na.rm=TRUE) #number of items for each administration
	bj1<-hpj/cd #mean value for each administration (starting values)
	cond<-TRUE
	while (cond) {
		ai<-hpi/rowSums((due%*%matrix(bj1,nrow=1))*delta,na.rm=TRUE) #update discrimination parameters
		#print(ai)
		bj2<-hpj/colSums((matrix(ai)%*%uno)*delta,na.rm=TRUE) #update A equating coefficients
		#print(bj2)
		#print(max(abs(bj2-bj1),na.rm=T))
		cond<-max(abs(bj2-bj1),na.rm=T)>0.00001
		bj1<-bj2
	}
	As<-bj2/bj2[1]
	aj<-ai*bj2[1]
	names(aj)<-namesaj
	return(list(As=As,aj=aj))
}


# this function is used to calculate numerical derivatives
# of the A equating coefficient with respect to the discrimination parameters
# der_A_discrmn_bis<-function(X,gamma,itms,t,to,aj1T) {
	# #requireNamespace(numDeriv)
	# #library(equateMultiple)
	# # this function is used to calculate numerical derivatives
	# # one at a time for parallelization
	# ipf4der_4parallel<-function(gammaX,itms,t,to,X,aj1T) {
		# row<-itms[X]
		# col<-paste("gamma",t[X],sep=".")
		# aj1T[row,col]<-gammaX
		# mmout<-ipfRcpp(as.matrix(aj1T[,-1]),to,0.00001)
		# As<-mmout[[1]]
		# return(As)
	# }
	# drv<-jacobian(func=ipf4der_4parallel,x=gamma[X],itms=itms,t=t,base=base,X=X,aj1T=aj1T) # numeric derivatives of each A equating coefficients with respect to the discrimination parameters
	# return(drv)
# }

ipf4der<-function(gamma,itms,t,base,aj1T) {
	names(gamma)<-itms
	for (tt in 1:max(t)) aj1T[,paste("gamma",tt,sep=".")]<-gamma[t==tt][rownames(aj1T)]
	mmout<-ipfRcpp(as.matrix(aj1T[,-1]),base,0.00001)
	As<-mmout[[1]]
	return(As)
}



# this function is used to calculate numerical derivatives
# of a*, A, b*, B with respect to the discrimination and difficulty parameters
der_asAbsB_ab<-function(gamma,tab,base,method1,T,ni)
{
	tab$gamma<-gamma
	itms<-tab$itempar
	#Ts<-paste("T",1:T,sep="") # label of administrations: T1, T2, ...

	tabDscrmn<-tab[substr(tab$itempar,1,6)=="Dscrmn",] # table with discrimination parameters
	tabDffclt<-tab[substr(tab$itempar,1,6)=="Dffclt",] # table with difficulty parameters
	
	# MULTIPLE MEAN-GEOMETRIC MEAN (performed anyway)
	# step 1: estimation of A equating coefficients
	if (nrow(tabDscrmn)>0) {
		if (any(tabDscrmn$gamma<0)) warning("Negative discrimination parameter. Converted to positive value.")
		tabDscrmn$gamma<-abs(tabDscrmn$gamma) # negative discriminations converted to positive values
		tabDscrmn$t<-as.factor(tabDscrmn$t)
		tabDscrmn$t <- relevel(tabDscrmn$t, ref = base) #set the A equating coefficient of the reference administration to 1
		reg1<-lm(log(gamma)~factor(itempar)+t-1,data=tabDscrmn,x=TRUE) # estimation of the A equating coefficients with the multiple mean-geometric mean method (Haberman, 2009)
		As<-rep(1,T)
		#names(As)<-Ts
		As[-base]<-exp(reg1$coef)[(ni+1):(ni+T-1)] # store A equating coefficients
		aj<-exp(reg1$coef[1:ni]) # store synthetic discrimination parameters
		names(aj)<-substr(names(aj),16,1000)
	}
	# MULTIPLE MEAN-MEAN
	# step 1: estimation of A equating coefficients
	if (nrow(tabDscrmn)>0 & method1=="mean-mean") {
		aj1T<-reshape(tabDscrmn[,c("itempar","gamma","t")],direction="wide",v.names="gamma",timevar="t", idvar = "itempar") # discrimination parameters in wide format
		rownames(aj1T)<-aj1T$itempar
		mmout<-ipfRcpp(as.matrix(aj1T[,-1]),base,0.0000001)
		As<-mmout[[1]]
		aj_tmp<-mmout[[2]]
		#names(As)<-Ts
		names(aj_tmp)<-aj1T$itempar
		aj<-aj_tmp[names(aj)]
	}

	# if there are no discrimination parameters set all A equating coefficients to 1
	if (nrow(tabDscrmn)==0) {
		As<-rep(1,T)
		#names(As)<-Ts
		aj<-rep(1,ni)
		names(aj)<-names(seaj)<-paste("Dscrmn",substr(itms,8,100),sep=".")
	}
	
	# step 2: estimation of B equating coefficients (for both multiple mean-mean and multiple mean geometric mean methods)
	vettA<-As[tabDffclt$t]
	tabDffclt$gammaA<-tabDffclt$gamma*vettA # response variable for the second regression model
	tabDffclt$t<-as.factor(tabDffclt$t)
	tabDffclt$t <- relevel(tabDffclt$t, ref = base) #set the B equating coefficient of the reference administration to 0
	reg2<-lm(gammaA~factor(itempar)+t-1,data=tabDffclt,x=T) # estimation of the B equating coefficients
	Bs<-rep(0,T)
	#names(Bs)<-Ts
	Bs[-base]<- -reg2$coef[(ni+1):(ni+T-1)] # store B equating coefficients
	bj<-reg2$coef[1:ni] # store synthetic difficulty parameters
	names(bj)<-substr(names(bj),16,1000)

	return(c(aj,As[-base],bj,Bs[-base]))
}


# multiple equating coefficients
multiec<-function(mods, base=1, method="mean-mean", se=TRUE, nq=30, start=NULL, eval.max=100000)
{
	if (method=="mean-mean" | method=="mean-gmean") out<-multiec_moments(mods=mods,base=base,method=method,se=se)
	if (method=="irf" | method=="trf") out<-multiec_irf(mods=mods,base=base,method=method,se=se,nq=nq,start=start,eval.max=eval.max)
	return(out)
}


# multiple equating coefficients with methods based on moments
multiec_moments<-function(mods,base,method,se,check=FALSE){
	cat("Computation of equating coefficients  .  .  .  . \n")
	itms<-c() # item labels
	for (k in 1:length(mods)) itms<-c(itms,names(mods[[k]]$coef))
	itms<-sort(unique(itms))
	itms<-itms[substr(itms,1,6)!="Gussng"]
	T<-length(mods) # number of administrations
	#Ts<-paste("T",1:T,sep="") # label of administrations: T1, T2, ...
	modsnames<-names(mods)
	tab<-c() # table with all item parameters. Columns: itempar (label of item parameters), gamma (item parameter value), t (administration)
	for (k in 1:length(mods)) {
		tab1<-data.frame(itempar=names(mods[[k]]$coef),gamma=mods[[k]]$coef,stringsAsFactors=FALSE)
		tab1$t<-k
		tab<-rbind(tab,tab1)
	}
	tabDscrmn<-tab[substr(tab$itempar,1,6)=="Dscrmn",] # table with discrimination parameters
	tabDffclt<-tab[substr(tab$itempar,1,6)=="Dffclt",] # table with difficulty parameters
	ni<-length(grep("Dffclt",itms)) # numer of items
	
	# MULTIPLE MEAN-GEOMETRIC MEAN (performed anyway)
	# step 1: estimation of A equating coefficients
	if (nrow(tabDscrmn)>0) {
		if (any(tabDscrmn$gamma<0)) warning("Negative discrimination parameter. Converted to positive value.")
		tabDscrmn$gamma<-abs(tabDscrmn$gamma) # negative discriminations converted to positive values
		tabDscrmn$t<-as.factor(tabDscrmn$t)
		tabDscrmn$t <- relevel(tabDscrmn$t, ref = base) #set the A equating coefficient of the reference administration to 1
		reg1<-lm(log(gamma)~factor(itempar)+t-1,data=tabDscrmn,x=TRUE) # estimation of the A equating coefficients with the multiple mean-geometric mean method (Haberman, 2009)
		As<-rep(1,T)
		names(As)<-modsnames
		As[-base]<-exp(reg1$coef)[(ni+1):(ni+T-1)] # store A equating coefficients
		aj<-exp(reg1$coef[1:ni]) # store synthetic discrimination parameters
		names(aj)<-substr(names(aj),16,1000)
	}

	# MULTIPLE MEAN-MEAN
	# step 1: estimation of A equating coefficients
	if (nrow(tabDscrmn)>0 & method=="mean-mean") {
		aj1T<-reshape(tabDscrmn[,c("itempar","gamma","t")],direction="wide",v.names="gamma",timevar="t", idvar = "itempar") # discrimination parameters in wide format
		rownames(aj1T)<-aj1T$itempar
		#mmout<-ipfR(aj1T=aj1T) # estimation of the A equating coefficients with the multiple mean-mean method and iterative proportional fitting algorithm
		#As<-mmout$As # store of A equating coefficients
		#aj<-mmout$aj[names(aj)] # store synthetic discrimination parameters
		#names(As)<-modsnames
		mmout<-ipfRcpp(as.matrix(aj1T[,-1]),base,0.0000001)
		As<-mmout[[1]]
		aj_tmp<-mmout[[2]]
		names(As)<-modsnames
		names(aj_tmp)<-aj1T$itempar
		aj<-aj_tmp[names(aj)]
	}

	# if there are no discrimination parameters set all A equating coefficients to 1 and standard errors to 0
	if (nrow(tabDscrmn)==0) {
		As<-rep(1,T)
		names(As)<-modsnames
		seA<-rep(0,T)
		names(seA)<-modsnames
		aj<-rep(1,ni)
		seaj<-rep(0,ni)
		names(aj)<-names(seaj)<-paste("Dscrmn",substr(itms,8,100),sep=".")
	}
	
	# step 2: estimation of B equating coefficients (for both multiple mean-mean and multiple mean geometric mean methods)
	vettA<-As[tabDffclt$t]
	tabDffclt$gammaA<-tabDffclt$gamma*vettA # response variable for the second regression model
	tabDffclt$t<-as.factor(tabDffclt$t)
	tabDffclt$t <- relevel(tabDffclt$t, ref = base) #set the B equating coefficient of the reference administration to 0
	reg2<-lm(gammaA~factor(itempar)+t-1,data=tabDffclt,x=T) # estimation of the B equating coefficients
	Bs<-rep(0,T)
	names(Bs)<-modsnames
	Bs[-base]<- -reg2$coef[(ni+1):(ni+T-1)] # store B equating coefficients
	bj<-reg2$coef[1:ni] # store synthetic difficulty parameters
	names(bj)<-substr(names(bj),16,1000)

	if (se) {
		# ================================
		# computation of standard errors
		# ================================

		cat("Computation of standard errors ")
		
		tabDscrmn$t<-as.numeric(as.character(tabDscrmn$t))
		
		if (nrow(tabDscrmn)>0) {
			#VarAll<-VarExt(mods) 
			vars<-lapply(mods,FUN=function(x) x$var)
			for (i in 1:length(vars)) rownames(vars[[i]])<-colnames(vars[[i]])<-paste(rownames(vars[[i]]),i,sep=".")
			VarAll<-VarExtRcpp(vars)
			VarAllNames<-c()
			for (i in 1:length(vars)) VarAllNames<-c(VarAllNames,rownames(vars[[i]]))
			rownames(VarAll)<-colnames(VarAll)<-VarAllNames
			
			X1<-reg1$x # design matrix
			X2<-reg2$x # design matrix
			X2[,(ni+1):(ni+T-1)]<- -X2[,(ni+1):(ni+T-1)]
			colnames(X1)[1:ni]<-substr(colnames(X1)[1:ni],16,1000)
			colnames(X2)[1:ni]<-substr(colnames(X2)[1:ni],16,1000)
			sel1<-paste(tabDscrmn$itempar,tabDscrmn$t,sep=".")
			sel2<-paste(tabDffclt$itempar,tabDffclt$t,sep=".")
			sel<-c(sel1,sel2)
			
			cat(" . ")
			
			if (method=="mean-gmean") {
				invXX1<-summary(reg1)$cov.unscaled
				#pAa<-diag(exp(reg1$coef))%*%invXX1%*%t(X1)%*%diag(1/tabDscrmn$gamma)#) # see Battauz (2016) Equation (37)
				tmp2<-matD(t(X1),1/tabDscrmn$gamma)
				tmp1<-Dmat(exp(reg1$coef),invXX1)
				pAa<-tmp1%*%tmp2
				rownames(pAa)<-rownames(t(X1))
				colnames(pAa)<-sel1
				
				cat(" . ")
				
			}
			if (method=="mean-mean") {
				#no_cores <- detectCores() - 1
				#cl <- makeCluster(no_cores)
				#clusterEvalQ(cl, library("equateMultiple"))
				#clusterEvalQ(cl, library("numDeriv"))
				#st3<-system.time(
				#pAa0<-parSapply(cl=cl, X=1:nrow(tabDscrmn), FUN=der_A_discrmn_bis,gamma=tabDscrmn$gamma,itms=tabDscrmn$itempar,t=tabDscrmn$t,base=base,aj1T=aj1T)
				#)
				#stopCluster(cl)
				pAa0<-jacobian(func=ipf4der,x=tabDscrmn$gamma,itms=tabDscrmn$itempar,t=tabDscrmn$t,base=base,aj1T=aj1T)

				cat(" . ")

				rownames(pAa0)<-modsnames
				colnames(pAa0)<-paste(tabDscrmn$itempar,tabDscrmn$t,sep=".")
				sumajs<-tapply(tabDscrmn$gamma,tabDscrmn$itempar,sum)
				sumAs<-tapply(As[tabDscrmn$t],tabDscrmn$itempar,sum)
				sumpAa0<-aggregate(pAa0[tabDscrmn$t,],by=list(Group.1=tabDscrmn$itempar),FUN=sum)
				rn<-sumpAa0$Group.1
				sumpAa0<-sumpAa0[,-1]
				tmp1<-matrix(NA,nrow(sumpAa0),ncol(sumpAa0))
				for (i in 1:ncol(sumpAa0)) tmp1[,i]<-sumajs/sumAs^2*sumpAa0[,i]
				rownames(tmp1)<-rn
				colnames(tmp1)<-paste(tabDscrmn$itempar,tabDscrmn$t,sep=".")
				tmp2<-as.matrix(1/sumAs)
				tmp2<-tmp2[,rep(1,ncol(tmp1))]
				tmp2<-tmp2*t(X1[,1:ni])
				colnames(tmp2)<-colnames(tmp1)
				pAa1<-tmp2-tmp1
				pAa<-rbind(pAa1,pAa0[-base,]) # see Battauz (2016) Equations (41) and (42)
			
			}

			cat(" . ")

			pAb<-matrix(0,ncol(X1),nrow(X1))
			colnames(pAb)<-sel2
			#system.time(pBa2<-t(X2)%*%diag(tabDffclt$gamma)%*%(-X2[,(ni+1):(ni+T-1)]))
			#system.time(
			#	{
					tmp<-Dmat(tabDffclt$gamma,-X2[,(ni+1):(ni+T-1)])
					pBa2<-t(X2)%*%tmp
			#	}
			#)
			invXX2<-summary(reg2)$cov.unscaled
			colnames(invXX2)[1:ni]<-rownames(invXX2)[1:ni]<-colnames(X2)[1:ni]
			invXX2[1:ni,-(1:ni)]<- -invXX2[1:ni,-(1:ni)]
			invXX2[-(1:ni),1:ni]<- -invXX2[-(1:ni),1:ni]
			pBa<-(invXX2%*%(pBa2))%*%pAa[(ni+1):(ni+T-1),] # see Battauz (2016) Equation (39)
			#pBb<-invXX2%*%t(X2)%*%diag(vettA)
			pBb<-matD(invXX2%*%t(X2),vettA) # see Battauz (2016) Equation (40)
			tmp1<-cbind(pAa,pAb)
			tmp2<-cbind(pBa,pBb)
			colnames(tmp2)<-colnames(tmp1)
			part<-rbind(tmp1,tmp2)
			cat(" . \n")
			if (check) {
				numericder<-jacobian(func=der_asAbsB_ab,x=tab$gamma,tab=tab,base=base,method1=method,T=T,ni=ni,method="simple")
				colnames(numericder)<-paste(tab$itempar,tab$t,sep=".")
				print(max(abs(numericder[,colnames(part)]-part)))
			}
			varABgamma<-part%*%VarAll[sel,sel]%*%t(part) # covariance matrix of equating coefficients and synthetic item parameters
			seABgamma<-diag(varABgamma)^0.5
			seA<-rep(0,T)
			names(seA)<-modsnames
			seA[-base]<-seABgamma[(ni+1):(ni+T-1)] # standard errors of A equating coefficients
			seB<-rep(0,T)
			names(seB)<-modsnames
			seB[-base]<-seABgamma[(ni+ncol(X1)+1):(ni+ncol(X1)+T-1)] # standard errors of B equating coefficients
			varAB<-varABgamma[c((ni+1):(ni+T-1),(ni+ncol(X1)+1):(ni+ncol(X1)+T-1)),c((ni+1):(ni+T-1),(ni+ncol(X1)+1):(ni+ncol(X1)+T-1))] # covariance matrix of equating coefficients
			seaj<-seABgamma[1:ni] # standard errors of synthetic discrimination parameters aj
			sebj<-seABgamma[(ni+T):(2*ni+T-1)] # standard errors of synthetic difficulty parameters bj
		}
		
		if (nrow(tabDscrmn)==0) {
			X2<-reg2$x
			mat<-summary(reg2)$cov.unscaled%*%t(X2)
			cat(" . ")
			colnames(mat)<-sel<-paste(tabDffclt$itempar,tabDffclt$t,sep=".")
			vars<-lapply(mods,FUN=function(x) x$var)
			for (i in 1:length(vars)) rownames(vars[[i]])<-colnames(vars[[i]])<-paste(rownames(vars[[i]]),i,sep=".")
			VarAll<-VarExtRcpp(vars)
			cat(" . ")
			VarAllNames<-c()
			for (i in 1:length(vars)) VarAllNames<-c(VarAllNames,rownames(vars[[i]]))
			rownames(VarAll)<-colnames(VarAll)<-VarAllNames
			sel<-paste(tabDffclt$itempar,tabDffclt$t,sep=".")
			varB<-mat%*%VarAll[sel,sel]%*%t(mat)
			cat(" . ")
			seBt<-sqrt(diag(varB))
			seB<-rep(0,T)
			names(seB)<-modsnames
			seB[-base]<-seBt[1:(T-1)]
			sebj<-seBt[T:ncol(X2)]
			cat(" . \n")
		}
	  partial<-t(part[c((ni+1):(ni+T-1),(ni+ncol(X1)+1):(ni+ncol(X1)+T-1)),]) # derivatives of A and B equating coefficients with respect to the item parameters
	  namesAB<-c(paste("A",(1:T)[-base],sep="."),paste("B",(1:T)[-base],sep="."))
	  colnames(partial)<-namesAB
	  rownames(varAB)<-colnames(varAB)<-namesAB
	}
	else {
		seA<-rep(NA,T)
		seB<-rep(NA,T)
		varAB<-matrix(NA,T,T)
		seaj<-NULL
		sebj<-NULL
		vars<-NULL
		partial<-NULL
	}
	
	tabwide<-reshape(tab[,c("itempar","gamma","t")],direction="wide",v.names="gamma",timevar="t", idvar = "itempar") # parameters in wide format
	colnames(tabwide)<-c("Item",modsnames)
	tabwide<-tabwide[order(tabwide$Item),]
	tabwides<-tabwide[,-1]
	for (t in 1:T) {
		selDffclt<-grep("Dffclt",tabwide$Item)
		selDscrmn<-grep("Dscrmn",tabwide$Item)
		tabwides[selDffclt,t]<-tabwides[selDffclt,t]*As[t]+Bs[t] # conversion of difficulty parameters to the scale of the base form
		tabwides[selDscrmn,t]<-tabwides[selDscrmn,t]/As[t] # conversion of discrimination parameters to the scale of the base form
	}
	colnames(tabwides)<-paste(colnames(tabwides),modsnames[base],sep=".as.")
	tabwides<-tabwides[,-base]
	tabwide<-cbind(tabwide,tabwides)
	itmp<-2
	if (sum(substr(tabwide$Item,1,6)=="Dscrmn")==0) itmp=1
	if (sum(substr(tabwide$Item,1,6)=="Gussng")>0) itmp=3

	out<-list(A=As,B=Bs,se.A=seA,se.B=seB,varAB=varAB,as=aj,bs=bj,se.as=seaj,se.bs=sebj,tab=tabwide,varFull=vars,partial=partial,itmp=itmp,method=method,basename=modsnames[base])
	class(out)<-"mlteqc"
	return(out)
}


print.mlteqc<-function(x, ...)
{
	cat("Multiple equating coefficients \n")
	cat("Method: ")
	cat(x$method,"\n")
	#cat("Forms: ")
	#cat(names(As),"\n")
}


summary.mlteqc <- function(object, ...)
{
	ct<-data.frame(EQ=rep(c("A","B"),each=length(object$A)),Form=c(names(object$A),names(object$B)),Estimate=c(object$A,object$B),StdErr=c(object$se.A,object$se.B))
	cat("Equating coefficients:\n")
	print(ct,digits=5,row.names=F)
}




# product of a matrix mat and a diagonal matrix with diagonal D: mat%*%diag(D)
matD<-function(mat,D){
	nr<-nrow(mat)
	for (i in 1:nr) mat[i,]<-mat[i,]*D
	return(mat)
	rownames(mat)<-colnames(mat)<-NULL
}	
		
# product of a diagonal matrix with diagonal D and a matrix mat: diag(D)%*%mat
Dmat<-function(D,mat){
	nc<-ncol(mat)
	for (i in 1:nc) mat[,i]<-D*mat[,i]
	rownames(mat)<-colnames(mat)<-NULL
	return(mat)
}			





itm.mlteqc<-function(x, ...) x$tab


eqc.mlteqc<-function(x, ...)
{
	A1<-x$A
	B1<-x$B
	out<-data.frame(A=A1,B=B1)
	rownames(out)<-NULL
	return(out)
}



score.mlteqc<-function(obj, method="TSE", D=1, scores=NULL, se=TRUE, nq=30, w=0.5, theta=NULL, weights=NULL, ...)
{
  if (!is.null(scores)) if (any(round(scores)!=scores)) stop("Scores should be integer values.")
  
  itmpar<-itm(obj)
  basename<-obj$basename
  modsnames<-names(obj$A)
  T<-length(obj$A)
  base<-(1:T)[modsnames==basename]
  out<-NULL
  for (t in 1:T) {
    if (base!=t) {
      sel<-c("Item",modsnames[t],basename,paste(modsnames[t],basename,sep=".as."))
      sel1<-c(paste("A",t,sep="."),paste("B",t,sep="."))
      itm_prepare<-equateIRT:::score_prepare(itmpar[,sel],suff1=paste(".",t,sep=""),suff2=paste(".",base,sep=""))
      out_t<-equateIRT:::score_compute(method=method,itm_prepare=itm_prepare,D=D,varFull=obj$varFull,partial=obj$partial[,sel1],varAB=obj$varAB[sel1,sel1],itmp=obj$itmp,A=obj$A[t],B=obj$B[t],scores=scores,se=se,nq=nq,w=w,theta=theta,weights=weights,names=sel[3:4])
      if (is.null(out)) {
				k<-ncol(out_t)
				if (se) colnames(out_t)[k]<-paste(colnames(out_t)[k],colnames(out_t)[k-1],sep="_")
				out<-out_t
			}
      else {
        if (method=="TSE") out_t<-subset(out_t,select=3:ncol(out_t))
        if (method=="OSE") out_t<-subset(out_t,select=2:ncol(out_t))
        if (se) colnames(out_t)[2]<-paste(colnames(out_t)[2],colnames(out_t)[1],sep="_")
        out<-cbind(out,out_t)
      }
    }
  }
  return(out)
}



