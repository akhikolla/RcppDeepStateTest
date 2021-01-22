function (x, y, r) 
{
    e <- get("data.env", .GlobalEnv)
    e[["arcDist"]][[length(e[["arcDist"]]) + 1]] <- list(x = x, 
        y = y, r = r)
    .Call("_signnet_arcDist", x, y, r)
}
