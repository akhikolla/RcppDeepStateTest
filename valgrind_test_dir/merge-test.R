function (i, x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["merge"]][[length(e[["merge"]]) + 1]] <- list(i = i, x = x)
    .Call("_FeatureHashing_merge", PACKAGE = "FeatureHashing", 
        i, x)
}
