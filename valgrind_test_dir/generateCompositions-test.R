function (n) 
{
    e <- get("data.env", .GlobalEnv)
    e[["generateCompositions"]][[length(e[["generateCompositions"]]) + 
        1]] <- list(n = n)
    .Call("_multicool_generateCompositions", PACKAGE = "multicool", 
        n)
}
