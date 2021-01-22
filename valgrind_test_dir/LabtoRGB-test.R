function (im) 
{
    e <- get("data.env", .GlobalEnv)
    e[["LabtoRGB"]][[length(e[["LabtoRGB"]]) + 1]] <- list(im = im)
    .Call("_imager_LabtoRGB", im)
}
