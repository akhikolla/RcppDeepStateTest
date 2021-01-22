function (x, y, z, c) 
{
    e <- get("data.env", .GlobalEnv)
    e[["getXc"]][[length(e[["getXc"]]) + 1]] <- list(x = x, y = y, 
        z = z, c = c)
    .Call("_imager_getXc", x, y, z, c)
}
