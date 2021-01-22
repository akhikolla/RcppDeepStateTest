function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Approx_Match_C_NA"]][[length(e[["Approx_Match_C_NA"]]) + 
        1]] <- list(x = x, y = y)
    .Call("_BoostMLR_Approx_Match_C_NA", x, y)
}
