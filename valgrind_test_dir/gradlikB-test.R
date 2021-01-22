function (parm, Dm, Xmat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gradlikB"]][[length(e[["gradlikB"]]) + 1]] <- list(parm = parm, 
        Dm = Dm, Xmat = Xmat)
    .Call("_icensmis_gradlikB", PACKAGE = "icensmis", parm, Dm, 
        Xmat)
}
