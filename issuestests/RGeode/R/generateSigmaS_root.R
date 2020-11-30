# Posterior for sigma (generateSigmaS_root)
#
# Generate Sigma from the full conditional posterior.


  generateSigmaS_root<- function(A, Z, U, N, asigma, bsigma, D, IND)
{
  #*************************************************************************
  #***        Author:      L. Rimella <lorenzo.rimella@hotmail.it>       ***
  #***                                                                   ***
  #***        Supervisors: M. Beccuti                                    ***
  #***                     A. Canale                                     ***
  #***                                                                   ***
  #*************************************************************************

  if(nargs() <8) stop("8 inputs are required.")

  #Update sigma square
  SS     = sum(A-(Z[,IND]^2)%*%(1-U[IND]))
  sigmaS = 1/rgamma(1, shape= asigma+D*N/2, rate= (bsigma+SS/2))

  return(sigmaS)

}
