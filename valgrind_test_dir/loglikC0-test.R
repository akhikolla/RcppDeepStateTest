function (parm, Dm) 
{
    e <- get("data.env", .GlobalEnv)
    e[["loglikC0"]][[length(e[["loglikC0"]]) + 1]] <- list(parm = parm, 
        Dm = Dm)
    .Call("_icensmis_loglikC0", PACKAGE = "icensmis", parm, Dm)
}
