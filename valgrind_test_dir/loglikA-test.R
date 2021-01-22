function (parm, Dm, Xmat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["loglikA"]][[length(e[["loglikA"]]) + 1]] <- list(parm = parm, 
        Dm = Dm, Xmat = Xmat)
    .Call("_icensmis_loglikA", PACKAGE = "icensmis", parm, Dm, 
        Xmat)
}
