function (parm, Dm, Xmat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["loglikB"]][[length(e[["loglikB"]]) + 1]] <- list(parm = parm, 
        Dm = Dm, Xmat = Xmat)
    .Call("_icensmis_loglikB", PACKAGE = "icensmis", parm, Dm, 
        Xmat)
}
