function (im) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sRGBtoLab"]][[length(e[["sRGBtoLab"]]) + 1]] <- list(im = im)
    .Call("_imager_sRGBtoLab", im)
}
