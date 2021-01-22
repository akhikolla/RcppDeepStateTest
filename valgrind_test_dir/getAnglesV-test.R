function (xs, ys) 
{
    e <- get("data.env", .GlobalEnv)
    e[["getAnglesV"]][[length(e[["getAnglesV"]]) + 1]] <- list(xs = xs, 
        ys = ys)
    .Call("_mousetrap_getAnglesV", xs, ys)
}
