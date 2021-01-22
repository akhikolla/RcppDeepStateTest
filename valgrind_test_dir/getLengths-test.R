function (xs, ys) 
{
    e <- get("data.env", .GlobalEnv)
    e[["getLengths"]][[length(e[["getLengths"]]) + 1]] <- list(xs = xs, 
        ys = ys)
    .Call("_mousetrap_getLengths", xs, ys)
}
