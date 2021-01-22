function (parm1, Dm) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gradlikB0"]][[length(e[["gradlikB0"]]) + 1]] <- list(parm1 = parm1, 
        Dm = Dm)
    .Call("_icensmis_gradlikB0", PACKAGE = "icensmis", parm1, 
        Dm)
}
