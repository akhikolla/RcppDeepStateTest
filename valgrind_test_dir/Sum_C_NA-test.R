function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Sum_C_NA"]][[length(e[["Sum_C_NA"]]) + 1]] <- list(x = x)
    .Call("_BoostMLR_Sum_C_NA", x)
}
