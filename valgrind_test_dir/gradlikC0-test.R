function (parm, Dm) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gradlikC0"]][[length(e[["gradlikC0"]]) + 1]] <- list(parm = parm, 
        Dm = Dm)
    .Call("_icensmis_gradlikC0", PACKAGE = "icensmis", parm, 
        Dm)
}
