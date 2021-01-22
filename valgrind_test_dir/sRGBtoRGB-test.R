function (im) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sRGBtoRGB"]][[length(e[["sRGBtoRGB"]]) + 1]] <- list(im = im)
    .Call("_imager_sRGBtoRGB", im)
}
