function (y1, y2, lev, wt) 
{
    e <- get("data.env", .GlobalEnv)
    e[["hazard"]][[length(e[["hazard"]]) + 1]] <- list(y1 = y1, 
        y2 = y2, lev = lev, wt = wt)
    .Call("_DStree_hazard", PACKAGE = "DStree", y1, y2, lev, 
        wt)
}
