# The core of the Gibbs sampling with missing data.
# Perform GEODE with missing data.


rgeode_root_m<- function(Y, d, burn, its, tol, atau, asigma,
                       bsigma, starttime, stoptime, fast, c0, c1)
{
  #*************************************************************************
  #***        Author:      L. Rimella <lorenzo.rimella@hotmail.it>       ***
  #***                                                                   ***
  #***        Supervisors: M. Beccuti                                    ***
  #***                     A. Canale                                     ***
  #***                                                                   ***
  #*************************************************************************

  # Fit GEODE on dataset with no missing data

  ##########################################################################
  # First step:
  # Computation of the mean and the principal axes and creation
  # of the sufficient statistics A,Z
  ##########################################################################

  #Mean and Principal axes
  N= dim(Y)[1]
  D= dim(Y)[2]

  #Extract missing values
  id_m= seq(1,N)[which(apply(Y,1,function(x)return(NaN %in% x)))]
  pos_m= apply(Y[id_m,],1,function(x)return(which(is.nan(x))))

  if(!is.list(pos_m))
  {
    if(is.matrix(pos_m))
    {
      pos_m2= pos_m
      pos_m=  list()
      for(i in 1:length(id_m))
      {
        pos_m[[i]]= pos_m2[,i]
      }
    }

    else if(is.vector(pos_m))
    {
      pos_m2= pos_m
      pos_m=  list()
      for(i in 1:length(id_m))
      {
        pos_m[[i]]= pos_m2[i]
      }
    }

    else
    {
      stop("Some problems with pos_m.")
    }
  }


  Y_complete= Y[-id_m,]

  mu =  matrix(apply(Y_complete,2,mean), D, 1)
  Y_c=  t(apply(Y_complete,1,function(x)return(x-mu)))

  #Perform a fast rank-d SVD or a simple SVD
  if(fast)
  {
    #print('fast')
    W= randSVD(t(Y_c), k= d )$u
  }

  if(!fast)
  { print('not fast')
    W= svd(t(Y_c), nu= d, nv= d)$u
  }


  #Sufficient Statistics
  A = matrix(apply(Y, 1, function(x)
                   return(sum((x[which(!is.nan(x))]-
                                 mu[which(!is.nan(x))])^2))), N, 1)


  Z = t(apply(Y,1,function(x)
                return(t(W[which(!is.nan(x)),])%*%
                        (x[which(!is.nan(x))]- mu[which(!is.nan(x))]))))

  AA= lapply(pos_m, function(x) return(t(W[-x,])%*% W[-x,]) )

  ##########################################################################
  # Second step:
  # Preparation for the Gibbs sampler:
  # nc=its nb=burn tol=tol a=atau a_sigma = asigma; b_sigma= bsigma
  # step=step stoptime = ; starttime = ; T= Time
  ##########################################################################

  Time = burn + its

  InD=   rep(list(c(1:d)), stoptime)

  yms= rep(list(), Time)

  u=      matrix(0.5, d, Time)

  tau=       matrix(1, d, Time)
  tau[,1]= rexptr(d, atau, range= c(1,Inf))

  sigmaS= matrix(1, Time, 1)
  sigmaS[1]= 1/rgamma(1,shape= asigma, rate= bsigma)


  ##########################################################################
  # Third step:
  # Gibbs sampler:
  ##########################################################################

  InDtmp = seq(1,d)

  summ=0

  for(iter in 2:Time)
  {
    #Impute Missing Data
    #tic(func.tic = NULL)

    y_m = GEODE_impute(u[,iter-1],sigmaS[iter-1],
                       W,mu,AA,Z,id_m,pos_m,InDtmp)

#    Sig       = (1/u[,iter-1]-1)*sigmaS[iter-1]
#    if(length(InDtmp)< length(Sig) )
#    {
#      Sig[-InDtmp] = 0
#    }


#    helpU=u[,iter-1]
#    helpSIGMAS=sigmaS[iter-1]

#    y_m = CGEODE_impute(helpU, helpSIGMAS,
#                     W, mu, AA, Z, id_m, pos_m, Sig,
#                     d)

    #c=toc(func.toc = NULL)
    #cc= c$toc- c$tic
    #summ=summ+cc

    yms[[iter]] = y_m

    #Update Sufficient Statistics
    A_temp = A;
    Z_temp = Z;
    for(i in 1:length(id_m))
    {
      A_temp[id_m[i]] = A_temp[id_m[i]] +
                         sum((t(y_m[[i]])-mu[pos_m[[i]] ])^2)
      Z_temp[id_m[i],] = Z_temp[id_m[i],] + y_m[[i]]%*%W[pos_m[[i]],]
    }


    #Update u
    #u[,iter] = generateU_root(Z_temp, sigmaS[iter-1], N,
    #                         tau[,iter-1], InDtmp, u[,iter-1])
    u[,iter]= u[,iter-1]
    u[InDtmp,iter] = CgenerateU_root(tau[InDtmp,iter-1], N, sigmaS[iter-1],
                                     Z_temp[,InDtmp])

    #tau[,iter] = generateTau_root(u[,iter], atau, InDtmp, tau[,iter-1])
    tau[,iter]= tau[,iter-1]
    tau[InDtmp,iter]= CgenerateTau_root(u[InDtmp,iter],tau[InDtmp,iter],
                                        atau, max(InDtmp))

    sigmaS[iter] = generateSigmaS_root(A_temp, Z_temp, u[,iter], N,
                                       asigma, bsigma, D, InDtmp)

    # Adaptively prune the intrinsic dimension
    # Wang version:
    #if (iter <= stoptime & iter > starttime)
    #{
    #  u_accum = u_accum + ( u[,iter]==1 )
    #  if(any(adptpos == iter))
    #  {
    #    adapt[iter] = 1
    #    ind = InD[[iter-1]]
    #    tmp = u_accum[ind]
    #    vec = (1/u[InD[[iter-1]],iter]-1)*sigmaS[iter]
    #    d1 = ind

    #    if ( sum(tmp > (stoptime-starttime)*tol) + sum(vec/max(vec) < tol) )>0
    #    {
    #      ind = ind[ ind %in% ind[ d1 >= min(d1( (tmp > (stoptime-starttime)*tol) |
    #                                                (vec/max(vec) < tol) )) ] = [];
    #    }
    #    InD[[iter]] = ind

    #    else InD[[iter]]= InD[[iter-1]]
    #

    #  }
    #  InDtmp = InD[[iter]]

    #}

    if(iter <= stoptime & iter > starttime)
    {
      ind= InD[[iter-1]]
      #find our alphas
      vec_alpha= (1/u[InD[[iter-1]],iter]-1)*sigmaS[iter]
      max_alpha= max(vec_alpha)
      if(iter== stoptime)
      {
        if( sum(ind[vec_alpha/max_alpha < tol])>0 )
        {
          ind= ind[ ind < min( ind[vec_alpha/max_alpha < tol] ) ]
        }

      }

      else if( runif(1, 0, 1)< p(iter, c0, c1) )
      {
        if( sum(ind[vec_alpha/max_alpha < tol])>0 )
        {
          ind= ind[ ind < min( ind[vec_alpha/max_alpha < tol] ) ]
        }

        else
        {
          if(ind[length(ind)]+1<d)
          {
            ind= c(ind, ind[length(ind)]+1)
          }
        }
      }

      InD[[iter]]= ind

      InDtmp = InD[[iter]]

    }

  }


  return( list(InD, u, tau, sigmaS, W, mu, id_m, pos_m, yms) )
}
