function (xs, ys) 
{
    e <- get("data.env", .GlobalEnv)
    e[["getAnglesP"]][[length(e[["getAnglesP"]]) + 1]] <- list(xs = xs, 
        ys = ys)
    .Call("_mousetrap_getAnglesP", xs, ys)
}
