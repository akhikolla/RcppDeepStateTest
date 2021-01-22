function (x, L = 1000L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ggdepthranks"]][[length(e[["ggdepthranks"]]) + 1]] <- list(x = x, 
        L = L)
    .Call("_dfphase1_ggdepthranks", PACKAGE = "dfphase1", x, 
        L)
}
