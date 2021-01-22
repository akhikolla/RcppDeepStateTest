function (im) 
{
    e <- get("data.env", .GlobalEnv)
    e[["RGBtoYUV"]][[length(e[["RGBtoYUV"]]) + 1]] <- list(im = im)
    .Call("_imager_RGBtoYUV", im)
}
