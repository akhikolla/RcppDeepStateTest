function (im) 
{
    e <- get("data.env", .GlobalEnv)
    e[["RGBtoHSL"]][[length(e[["RGBtoHSL"]]) + 1]] <- list(im = im)
    .Call("_imager_RGBtoHSL", im)
}
