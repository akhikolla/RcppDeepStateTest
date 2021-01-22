function (im) 
{
    e <- get("data.env", .GlobalEnv)
    e[["RGBtoHSV"]][[length(e[["RGBtoHSV"]]) + 1]] <- list(im = im)
    .Call("_imager_RGBtoHSV", im)
}
