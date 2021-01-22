function (mu, sig, n) 
{
    e <- get("data.env", .GlobalEnv)
    e[["simData_rls"]][[length(e[["simData_rls"]]) + 1]] <- list(mu = mu, 
        sig = sig, n = n)
    .Call("_robustBLME_simData_rls", mu, sig, n)
}
