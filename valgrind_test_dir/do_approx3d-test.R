function (x, y, z, f, xout, yout, zout) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_approx3d"]][[length(e[["do_approx3d"]]) + 1]] <- list(x = x, 
        y = y, z = z, f = f, xout = xout, yout = yout, zout = zout)
    .Call("_oce_do_approx3d", x, y, z, f, xout, yout, zout)
}
