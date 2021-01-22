function (M) 
{
    e <- get("data.env", .GlobalEnv)
    e[["SDM"]][[length(e[["SDM"]]) + 1]] <- list(M = M)
    .Call("_Opt5PL_SDM", M)
}
