function (x, y, w, i, j) 
{
    e <- get("data.env", .GlobalEnv)
    e[["xlin_pfits"]][[length(e[["xlin_pfits"]]) + 1]] <- list(x = x, 
        y = y, w = w, i = i, j = j)
    .Call("_RcppDynProg_xlin_pfits", PACKAGE = "RcppDynProg", 
        x, y, w, i, j)
}
