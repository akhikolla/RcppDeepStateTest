function (x, y, lonr, latr, a, f) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_geod_xy_inverse"]][[length(e[["do_geod_xy_inverse"]]) + 
        1]] <- list(x = x, y = y, lonr = lonr, latr = latr, a = a, 
        f = f)
    .Call("_oce_do_geod_xy_inverse", x, y, lonr, latr, a, f)
}
