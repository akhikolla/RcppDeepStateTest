function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["length_C_NA"]][[length(e[["length_C_NA"]]) + 1]] <- list(x = x)
    .Call("_BoostMLR_length_C_NA", x)
}
