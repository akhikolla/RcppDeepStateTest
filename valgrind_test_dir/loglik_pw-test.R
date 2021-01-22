function (par, Dm, eta, breaks) 
{
    e <- get("data.env", .GlobalEnv)
    e[["loglik_pw"]][[length(e[["loglik_pw"]]) + 1]] <- list(par = par, 
        Dm = Dm, eta = eta, breaks = breaks)
    .Call("_icensmis_loglik_pw", PACKAGE = "icensmis", par, Dm, 
        eta, breaks)
}
