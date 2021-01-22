function (x, y, npts) 
{
    e <- get("data.env", .GlobalEnv)
    e[["spatialize"]][[length(e[["spatialize"]]) + 1]] <- list(x = x, 
        y = y, npts = npts)
    .Call("_mousetrap_spatialize", x, y, npts)
}
