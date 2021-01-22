function (im) 
{
    e <- get("data.env", .GlobalEnv)
    e[["RGBtoHSI"]][[length(e[["RGBtoHSI"]]) + 1]] <- list(im = im)
    .Call("_imager_RGBtoHSI", im)
}
