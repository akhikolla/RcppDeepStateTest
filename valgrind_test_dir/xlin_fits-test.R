function (x, y, w, i, j) 
{
    e <- get("data.env", .GlobalEnv)
    e[["xlin_fits"]][[length(e[["xlin_fits"]]) + 1]] <- list(x = x, 
        y = y, w = w, i = i, j = j)
    .Call("_RcppDynProg_xlin_fits", PACKAGE = "RcppDynProg", 
        x, y, w, i, j)
}
