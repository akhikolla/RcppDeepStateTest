function (im) 
{
    e <- get("data.env", .GlobalEnv)
    e[["RGBtoLab"]][[length(e[["RGBtoLab"]]) + 1]] <- list(im = im)
    .Call("_imager_RGBtoLab", im)
}
