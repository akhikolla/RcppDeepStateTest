function (parm, Dm, TXmat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["loglikTA"]][[length(e[["loglikTA"]]) + 1]] <- list(parm = parm, 
        Dm = Dm, TXmat = TXmat)
    .Call("_icensmis_loglikTA", PACKAGE = "icensmis", parm, Dm, 
        TXmat)
}
