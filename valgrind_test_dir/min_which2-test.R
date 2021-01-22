function (array, n, minout, whichout) 
{
    e <- get("data.env", .GlobalEnv)
    e[["min_which2"]][[length(e[["min_which2"]]) + 1]] <- list(array = array, 
        n = n, minout = minout, whichout = whichout)
    .Call("_bartBMA_min_which2", array, n, minout, whichout)
}
