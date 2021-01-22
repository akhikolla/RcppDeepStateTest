function (x, y, z, c) 
{
    e <- get("data.env", .GlobalEnv)
    e[["getCc"]][[length(e[["getCc"]]) + 1]] <- list(x = x, y = y, 
        z = z, c = c)
    .Call("_imager_getCc", x, y, z, c)
}
