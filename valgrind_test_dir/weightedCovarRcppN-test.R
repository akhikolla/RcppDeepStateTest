function (x, y, w) 
{
    e <- get("data.env", .GlobalEnv)
    e[["weightedCovarRcppN"]][[length(e[["weightedCovarRcppN"]]) + 
        1]] <- list(x = x, y = y, w = w)
    .Call("_carSurv_weightedCovarRcppN", x, y, w)
}
