function (n) 
{
    e <- get("data.env", .GlobalEnv)
    e[["setBitNumber"]][[length(e[["setBitNumber"]]) + 1]] <- list(n = n)
    .Call("_mosum_setBitNumber", n)
}
