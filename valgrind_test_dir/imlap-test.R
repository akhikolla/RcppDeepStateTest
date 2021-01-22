function (im) 
{
    e <- get("data.env", .GlobalEnv)
    e[["imlap"]][[length(e[["imlap"]]) + 1]] <- list(im = im)
    .Call("_imager_imlap", im)
}
