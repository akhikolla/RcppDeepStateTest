function (K21, k, p, m, s) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ARFitVARXR"]][[length(e[["ARFitVARXR"]]) + 1]] <- list(K21 = K21, 
        k = k, p = p, m = m, s = s)
    .Call("_BigVAR_ARFitVARXR", K21, k, p, m, s)
}
