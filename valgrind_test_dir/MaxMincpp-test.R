function (locations) 
{
    e <- get("data.env", .GlobalEnv)
    e[["MaxMincpp"]][[length(e[["MaxMincpp"]]) + 1]] <- list(locations = locations)
    .Call("_GPvecchia_MaxMincpp", PACKAGE = "GPvecchia", locations)
}
