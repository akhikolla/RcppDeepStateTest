function (x, y, w) 
{
    e <- get("data.env", .GlobalEnv)
    e[["weightedCovarRcpp"]][[length(e[["weightedCovarRcpp"]]) + 
        1]] <- list(x = x, y = y, w = w)
    .Call("_carSurv_weightedCovarRcpp", x, y, w)
}
