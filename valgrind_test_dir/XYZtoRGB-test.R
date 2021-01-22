function (im) 
{
    e <- get("data.env", .GlobalEnv)
    e[["XYZtoRGB"]][[length(e[["XYZtoRGB"]]) + 1]] <- list(im = im)
    .Call("_imager_XYZtoRGB", im)
}
