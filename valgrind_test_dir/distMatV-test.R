function (x, y, power = 2L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["distMatV"]][[length(e[["distMatV"]]) + 1]] <- list(x = x, 
        y = y, power = power)
    .Call("_mousetrap_distMatV", x, y, power)
}
