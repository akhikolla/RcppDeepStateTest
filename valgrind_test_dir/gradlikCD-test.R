function (parm, Dmat, x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gradlikCD"]][[length(e[["gradlikCD"]]) + 1]] <- list(parm = parm, 
        Dmat = Dmat, x = x)
    .Call("_icRSF_gradlikCD", PACKAGE = "icRSF", parm, Dmat, 
        x)
}
