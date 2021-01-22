function (parm, Dm, TXmat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["loglikTB"]][[length(e[["loglikTB"]]) + 1]] <- list(parm = parm, 
        Dm = Dm, TXmat = TXmat)
    .Call("_icensmis_loglikTB", PACKAGE = "icensmis", parm, Dm, 
        TXmat)
}
