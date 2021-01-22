function (x, y, w, i, j) 
{
    e <- get("data.env", .GlobalEnv)
    e[["xlogistic_fits"]][[length(e[["xlogistic_fits"]]) + 1]] <- list(x = x, 
        y = y, w = w, i = i, j = j)
    .Call("_RcppDynProg_xlogistic_fits", PACKAGE = "RcppDynProg", 
        x, y, w, i, j)
}
