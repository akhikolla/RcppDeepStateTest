function (im, sx, sy, sz = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["erode_rect"]][[length(e[["erode_rect"]]) + 1]] <- list(im = im, 
        sx = sx, sy = sy, sz = sz)
    .Call("_imager_erode_rect", im, sx, sy, sz)
}
