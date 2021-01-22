function (n) 
{
    e <- get("data.env", .GlobalEnv)
    e[["BellC"]][[length(e[["BellC"]]) + 1]] <- list(n = n)
    .Call("_multicool_BellC", PACKAGE = "multicool", n)
}
