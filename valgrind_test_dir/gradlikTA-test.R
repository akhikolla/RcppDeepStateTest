function (parm, Dm, TXmat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gradlikTA"]][[length(e[["gradlikTA"]]) + 1]] <- list(parm = parm, 
        Dm = Dm, TXmat = TXmat)
    .Call("_icensmis_gradlikTA", PACKAGE = "icensmis", parm, 
        Dm, TXmat)
}
