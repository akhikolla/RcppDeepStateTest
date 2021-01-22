function (im) 
{
    e <- get("data.env", .GlobalEnv)
    e[["RGBtoXYZ"]][[length(e[["RGBtoXYZ"]]) + 1]] <- list(im = im)
    .Call("_imager_RGBtoXYZ", im)
}
