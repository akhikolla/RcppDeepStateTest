function (x, y, z, c, d) 
{
    e <- get("data.env", .GlobalEnv)
    e[["checkcoords"]][[length(e[["checkcoords"]]) + 1]] <- list(x = x, 
        y = y, z = z, c = c, d = d)
    .Call("_imager_checkcoords", x, y, z, c, d)
}
