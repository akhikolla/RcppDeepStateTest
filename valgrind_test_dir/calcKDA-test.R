function (A) 
{
    e <- get("data.env", .GlobalEnv)
    e[["calcKDA"]][[length(e[["calcKDA"]]) + 1]] <- list(A = A)
    .Call("_GUILDS_calcKDA", PACKAGE = "GUILDS", A)
}
