function (src) 
{
    e <- get("data.env", .GlobalEnv)
    e[["intToRaw"]][[length(e[["intToRaw"]]) + 1]] <- list(src = src)
    .Call("_FeatureHashing_intToRaw", PACKAGE = "FeatureHashing", 
        src)
}
