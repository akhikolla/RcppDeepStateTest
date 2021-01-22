function (par, Dm, eta) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gradlik_lamb"]][[length(e[["gradlik_lamb"]]) + 1]] <- list(par = par, 
        Dm = Dm, eta = eta)
    .Call("_icensmis_gradlik_lamb", PACKAGE = "icensmis", par, 
        Dm, eta)
}
