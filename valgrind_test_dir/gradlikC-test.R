function (parm, Dm, Xmat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gradlikC"]][[length(e[["gradlikC"]]) + 1]] <- list(parm = parm, 
        Dm = Dm, Xmat = Xmat)
    .Call("_icensmis_gradlikC", PACKAGE = "icensmis", parm, Dm, 
        Xmat)
}
