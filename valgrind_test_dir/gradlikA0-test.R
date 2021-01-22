function (parm, Dm) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gradlikA0"]][[length(e[["gradlikA0"]]) + 1]] <- list(parm = parm, 
        Dm = Dm)
    .Call("_icensmis_gradlikA0", PACKAGE = "icensmis", parm, 
        Dm)
}
