testlist <- list(N_Value = 670575960L, phi = -8.00441199882739e-253, rho = -1.58401987983262e+268)
result <- do.call(BoostMLR:::MatrixInversion_Equicorrelation_C,testlist)
str(result)