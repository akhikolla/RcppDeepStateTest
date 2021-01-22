function (parm, Dm, Xmat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["loglikC"]][[length(e[["loglikC"]]) + 1]] <- list(parm = parm, 
        Dm = Dm, Xmat = Xmat)
    .Call("_icensmis_loglikC", PACKAGE = "icensmis", parm, Dm, 
        Xmat)
}
