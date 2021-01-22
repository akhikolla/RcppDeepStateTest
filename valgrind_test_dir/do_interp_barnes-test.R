function (x, y, z, w, xg, yg, xr, yr, gamma, iterations) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_interp_barnes"]][[length(e[["do_interp_barnes"]]) + 
        1]] <- list(x = x, y = y, z = z, w = w, xg = xg, yg = yg, 
        xr = xr, yr = yr, gamma = gamma, iterations = iterations)
    .Call("_oce_do_interp_barnes", x, y, z, w, xg, yg, xr, yr, 
        gamma, iterations)
}
