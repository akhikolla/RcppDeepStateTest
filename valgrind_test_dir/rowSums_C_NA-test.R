function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rowSums_C_NA"]][[length(e[["rowSums_C_NA"]]) + 1]] <- list(x = x)
    .Call("_BoostMLR_rowSums_C_NA", x)
}
