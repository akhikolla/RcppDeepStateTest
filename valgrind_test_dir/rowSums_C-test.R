function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rowSums_C"]][[length(e[["rowSums_C"]]) + 1]] <- list(x = x)
    .Call("_BoostMLR_rowSums_C", x)
}
