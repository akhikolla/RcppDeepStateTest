function (parm1, Dm) 
{
    e <- get("data.env", .GlobalEnv)
    e[["loglikB0"]][[length(e[["loglikB0"]]) + 1]] <- list(parm1 = parm1, 
        Dm = Dm)
    .Call("_icensmis_loglikB0", PACKAGE = "icensmis", parm1, 
        Dm)
}
