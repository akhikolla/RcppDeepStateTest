function (y1, y2, lev, ind, wt) 
{
    e <- get("data.env", .GlobalEnv)
    e[["hazardr"]][[length(e[["hazardr"]]) + 1]] <- list(y1 = y1, 
        y2 = y2, lev = lev, ind = ind, wt = wt)
    .Call("_DStree_hazardr", PACKAGE = "DStree", y1, y2, lev, 
        ind, wt)
}
