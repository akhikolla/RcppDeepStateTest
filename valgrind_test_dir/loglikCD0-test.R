function (parm, Dmat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["loglikCD0"]][[length(e[["loglikCD0"]]) + 1]] <- list(parm = parm, 
        Dmat = Dmat)
    .Call("_icRSF_loglikCD0", PACKAGE = "icRSF", parm, Dmat)
}
