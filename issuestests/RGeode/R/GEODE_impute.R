# Missing Data Imputation (GEODE_impute)
#
# Generate pseudo-observation from a Multivariate Normal
# Distribution to substitute Missing Data.


GEODE_impute<- function(U,SIGMAS,LAMBDA,MU,AA,Z,id_m,pos_m,IND)
{
  #*************************************************************************
  #***        Author:      L. Rimella <lorenzo.rimella@hotmail.it>       ***
  #***                                                                   ***
  #***        Supervisors: M. Beccuti                                    ***
  #***                     A. Canale                                     ***
  #***                                                                   ***
  #*************************************************************************

  # Missing Data Imputation
  d= dim(LAMBDA)[2]
  SIG       = (1/U-1)*SIGMAS;
  SIG[-IND] = matrix(0,d-length(IND),1)

  y_m= list()

  #summ1=0
  #summ2=0

  for(i in 1:length(id_m))
  {

    if(is.matrix(LAMBDA[pos_m[[i]],])==FALSE)
    {
      #tic(func.tic = NULL)
      inv= solve(diag(SIG)%*%AA[[i]]/SIGMAS+diag(d))
      #c=toc(func.toc = NULL)
      #cc= c$toc- c$tic
      #summ1=summ1+cc

      #tic(func.tic = NULL)
      C_eta = inv%*% diag(SIG)
      #c=toc(func.toc = NULL)
      #cc= c$toc- c$tic
      #summ2=summ2+cc

      C_M   = LAMBDA[pos_m[[i]],] %*% tcrossprod(C_eta, t(LAMBDA[pos_m[[i]],]))+
              SIGMAS*diag(length(pos_m[[i]]))


      mu_hat  = MU[pos_m[[i]] ] +
                LAMBDA[pos_m[[i]],]%*% (C_eta %*% Z[id_m[i],])/SIGMAS

    }

    else
    {
      #tic(func.tic = NULL)
      inv= solve(diag(SIG)%*%AA[[i]]/SIGMAS+diag(d))
      #c=toc(func.toc = NULL)
      #cc= c$toc- c$tic
      #summ1=summ1+cc

      #tic(func.tic = NULL)
      C_eta = inv%*% diag(SIG)
      #c=toc(func.toc = NULL)
      #cc= c$toc- c$tic
      #summ2=summ2+cc


      C_M   = LAMBDA[pos_m[[i]],] %*% tcrossprod(C_eta, LAMBDA[pos_m[[i]],])+
        SIGMAS*diag(length(pos_m[[i]]))


      mu_hat  = MU[pos_m[[i]] ] +
        LAMBDA[pos_m[[i]],]%*% (C_eta %*% Z[id_m[i],])/SIGMAS
    }




      #Remember that the Z i already the Z observed by construction

      y_m[[i]]= mvrnorm(1, mu_hat, C_M)

  }

  return(y_m)

}
