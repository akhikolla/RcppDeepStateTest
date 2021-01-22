function (n, k) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Stirling2C"]][[length(e[["Stirling2C"]]) + 1]] <- list(n = n, 
        k = k)
    .Call("_multicool_Stirling2C", PACKAGE = "multicool", n, 
        k)
}
