function (tt, D_hat, mu_hat, EstFunc, Hess_inv, Der_D1_hat, Der_D2_hat, 
    Der_D3_hat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["asyVarVUS_C"]][[length(e[["asyVarVUS_C"]]) + 1]] <- list(tt = tt, 
        D_hat = D_hat, mu_hat = mu_hat, EstFunc = EstFunc, Hess_inv = Hess_inv, 
        Der_D1_hat = Der_D1_hat, Der_D2_hat = Der_D2_hat, Der_D3_hat = Der_D3_hat)
    .Call("_bcROCsurface_asyVarVUS_C", tt, D_hat, mu_hat, EstFunc, 
        Hess_inv, Der_D1_hat, Der_D2_hat, Der_D3_hat)
}
