function (parm, Dmat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gradlikCD0"]][[length(e[["gradlikCD0"]]) + 1]] <- list(parm = parm, 
        Dmat = Dmat)
    .Call("_icRSF_gradlikCD0", PACKAGE = "icRSF", parm, Dmat)
}
