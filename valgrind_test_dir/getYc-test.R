function (x, y, z, c) 
{
    e <- get("data.env", .GlobalEnv)
    e[["getYc"]][[length(e[["getYc"]]) + 1]] <- list(x = x, y = y, 
        z = z, c = c)
    .Call("_imager_getYc", x, y, z, c)
}
