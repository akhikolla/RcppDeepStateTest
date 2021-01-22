function (classi) 
{
    e <- get("data.env", .GlobalEnv)
    e[["getRank"]][[length(e[["getRank"]]) + 1]] <- list(classi = classi)
    .Call("_aricode_getRank", PACKAGE = "aricode", classi)
}
