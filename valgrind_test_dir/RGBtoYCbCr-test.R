function (im) 
{
    e <- get("data.env", .GlobalEnv)
    e[["RGBtoYCbCr"]][[length(e[["RGBtoYCbCr"]]) + 1]] <- list(im = im)
    .Call("_imager_RGBtoYCbCr", im)
}
