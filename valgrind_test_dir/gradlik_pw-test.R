function (par, Dm, eta, breaks) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gradlik_pw"]][[length(e[["gradlik_pw"]]) + 1]] <- list(par = par, 
        Dm = Dm, eta = eta, breaks = breaks)
    .Call("_icensmis_gradlik_pw", PACKAGE = "icensmis", par, 
        Dm, eta, breaks)
}
