function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Mean_C_NA"]][[length(e[["Mean_C_NA"]]) + 1]] <- list(x = x)
    .Call("_BoostMLR_Mean_C_NA", x)
}
