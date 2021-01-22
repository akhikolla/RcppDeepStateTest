function (x, parm, Dmat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["scorefun0"]][[length(e[["scorefun0"]]) + 1]] <- list(x = x, 
        parm = parm, Dmat = Dmat)
    .Call("_icRSF_scorefun0", PACKAGE = "icRSF", x, parm, Dmat)
}
