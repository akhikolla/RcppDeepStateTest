function (y1, y2, lev, ind, wt) 
{
    e <- get("data.env", .GlobalEnv)
    e[["hazardl"]][[length(e[["hazardl"]]) + 1]] <- list(y1 = y1, 
        y2 = y2, lev = lev, ind = ind, wt = wt)
    .Call("_DStree_hazardl", PACKAGE = "DStree", y1, y2, lev, 
        ind, wt)
}
