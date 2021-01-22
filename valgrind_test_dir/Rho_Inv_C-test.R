function (Rho_Value, N_Value) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Rho_Inv_C"]][[length(e[["Rho_Inv_C"]]) + 1]] <- list(Rho_Value = Rho_Value, 
        N_Value = N_Value)
    .Call("_BoostMLR_Rho_Inv_C", Rho_Value, N_Value)
}
