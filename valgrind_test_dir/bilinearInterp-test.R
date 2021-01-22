function (x, y, gx, gy, g) 
{
    e <- get("data.env", .GlobalEnv)
    e[["bilinearInterp"]][[length(e[["bilinearInterp"]]) + 1]] <- list(x = x, 
        y = y, gx = gx, gy = gy, g = g)
    .Call("_oce_bilinearInterp", x, y, gx, gy, g)
}
