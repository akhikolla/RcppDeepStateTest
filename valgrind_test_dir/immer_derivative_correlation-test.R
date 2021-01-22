function (cov12, var1, var2, cov12_der, var1_der, var2_der) 
{
    e <- get("data.env", .GlobalEnv)
    e[["immer_derivative_correlation"]][[length(e[["immer_derivative_correlation"]]) + 
        1]] <- list(cov12 = cov12, var1 = var1, var2 = var2, 
        cov12_der = cov12_der, var1_der = var1_der, var2_der = var2_der)
    .Call("_immer_immer_derivative_correlation", PACKAGE = "immer", 
        cov12, var1, var2, cov12_der, var1_der, var2_der)
}
