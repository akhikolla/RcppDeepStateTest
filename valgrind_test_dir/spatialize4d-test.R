function (x, y, z1, z2, npts) 
{
    e <- get("data.env", .GlobalEnv)
    e[["spatialize4d"]][[length(e[["spatialize4d"]]) + 1]] <- list(x = x, 
        y = y, z1 = z1, z2 = z2, npts = npts)
    .Call("_mousetrap_spatialize4d", x, y, z1, z2, npts)
}
