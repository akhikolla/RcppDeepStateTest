function (im) 
{
    e <- get("data.env", .GlobalEnv)
    e[["XYZtoLab"]][[length(e[["XYZtoLab"]]) + 1]] <- list(im = im)
    .Call("_imager_XYZtoLab", im)
}
