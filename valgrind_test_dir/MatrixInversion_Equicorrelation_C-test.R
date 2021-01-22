function (N_Value, phi, rho) 
{
    e <- get("data.env", .GlobalEnv)
    e[["MatrixInversion_Equicorrelation_C"]][[length(e[["MatrixInversion_Equicorrelation_C"]]) + 
        1]] <- list(N_Value = N_Value, phi = phi, rho = rho)
    .Call("_BoostMLR_MatrixInversion_Equicorrelation_C", N_Value, 
        phi, rho)
}
