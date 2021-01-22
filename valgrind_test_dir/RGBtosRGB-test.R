function (im) 
{
    e <- get("data.env", .GlobalEnv)
    e[["RGBtosRGB"]][[length(e[["RGBtosRGB"]]) + 1]] <- list(im = im)
    .Call("_imager_RGBtosRGB", im)
}
