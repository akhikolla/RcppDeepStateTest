function (beta, x, parm, Dmat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["scorefun"]][[length(e[["scorefun"]]) + 1]] <- list(beta = beta, 
        x = x, parm = parm, Dmat = Dmat)
    .Call("_icRSF_scorefun", PACKAGE = "icRSF", beta, x, parm, 
        Dmat)
}
