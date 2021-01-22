function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Mean_C"]][[length(e[["Mean_C"]]) + 1]] <- list(x = x)
    .Call("_BoostMLR_Mean_C", x)
}
