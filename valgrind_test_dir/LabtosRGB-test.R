function (im) 
{
    e <- get("data.env", .GlobalEnv)
    e[["LabtosRGB"]][[length(e[["LabtosRGB"]]) + 1]] <- list(im = im)
    .Call("_imager_LabtosRGB", im)
}
