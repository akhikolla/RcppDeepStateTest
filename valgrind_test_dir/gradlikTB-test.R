function (parm, Dm, TXmat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gradlikTB"]][[length(e[["gradlikTB"]]) + 1]] <- list(parm = parm, 
        Dm = Dm, TXmat = TXmat)
    .Call("_icensmis_gradlikTB", PACKAGE = "icensmis", parm, 
        Dm, TXmat)
}
