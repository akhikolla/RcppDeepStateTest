function (im, type = 2L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["select"]][[length(e[["select"]]) + 1]] <- list(im = im, 
        type = type)
    .Call("_imager_select", im, type)
}
