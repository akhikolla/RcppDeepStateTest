function (parm, Dmat, x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["loglikCD"]][[length(e[["loglikCD"]]) + 1]] <- list(parm = parm, 
        Dmat = Dmat, x = x)
    .Call("_icRSF_loglikCD", PACKAGE = "icRSF", parm, Dmat, x)
}
