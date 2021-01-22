function (tesselation) 
{
    e <- get("data.env", .GlobalEnv)
    e[["SizeEstimate_"]][[length(e[["SizeEstimate_"]]) + 1]] <- list(tesselation = tesselation)
    .Call("_icosa_SizeEstimate_", tesselation)
}
