function (im) 
{
    e <- get("data.env", .GlobalEnv)
    e[["LabtoXYZ"]][[length(e[["LabtoXYZ"]]) + 1]] <- list(im = im)
    .Call("_imager_LabtoXYZ", im)
}
