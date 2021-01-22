function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Approx_Match_C"]][[length(e[["Approx_Match_C"]]) + 1]] <- list(x = x, 
        y = y)
    .Call("_BoostMLR_Approx_Match_C", x, y)
}
