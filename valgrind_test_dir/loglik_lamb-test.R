function (par, Dm, eta) 
{
    e <- get("data.env", .GlobalEnv)
    e[["loglik_lamb"]][[length(e[["loglik_lamb"]]) + 1]] <- list(par = par, 
        Dm = Dm, eta = eta)
    .Call("_icensmis_loglik_lamb", PACKAGE = "icensmis", par, 
        Dm, eta)
}
