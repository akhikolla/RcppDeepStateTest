function (parm, Dm, Xmat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gradlikA"]][[length(e[["gradlikA"]]) + 1]] <- list(parm = parm, 
        Dm = Dm, Xmat = Xmat)
    .Call("_icensmis_gradlikA", PACKAGE = "icensmis", parm, Dm, 
        Xmat)
}
