function (im, sx, sy, sz = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["dilate_rect"]][[length(e[["dilate_rect"]]) + 1]] <- list(im = im, 
        sx = sx, sy = sy, sz = sz)
    .Call("_imager_dilate_rect", im, sx, sy, sz)
}
