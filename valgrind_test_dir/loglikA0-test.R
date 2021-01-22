function (parm, Dm) 
{
    e <- get("data.env", .GlobalEnv)
    e[["loglikA0"]][[length(e[["loglikA0"]]) + 1]] <- list(parm = parm, 
        Dm = Dm)
    .Call("_icensmis_loglikA0", PACKAGE = "icensmis", parm, Dm)
}
