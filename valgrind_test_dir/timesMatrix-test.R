function (ma1, h, ma2, rows, cols) 
{
    e <- get("data.env", .GlobalEnv)
    e[["timesMatrix"]][[length(e[["timesMatrix"]]) + 1]] <- list(ma1 = ma1, 
        h = h, ma2 = ma2, rows = rows, cols = cols)
    .Call("_NAM_timesMatrix", ma1, h, ma2, rows, cols)
}
