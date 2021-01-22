function (x, y, z, npts) 
{
    e <- get("data.env", .GlobalEnv)
    e[["spatialize3d"]][[length(e[["spatialize3d"]]) + 1]] <- list(x = x, 
        y = y, z = z, npts = npts)
    .Call("_mousetrap_spatialize3d", x, y, z, npts)
}
