function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ggrank"]][[length(e[["ggrank"]]) + 1]] <- list(x = x)
    .Call("_dfphase1_ggrank", PACKAGE = "dfphase1", x)
}
