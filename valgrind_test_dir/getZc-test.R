function (x, y, z, c) 
{
    e <- get("data.env", .GlobalEnv)
    e[["getZc"]][[length(e[["getZc"]]) + 1]] <- list(x = x, y = y, 
        z = z, c = c)
    .Call("_imager_getZc", x, y, z, c)
}
