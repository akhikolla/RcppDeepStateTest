function (im) 
{
    e <- get("data.env", .GlobalEnv)
    e[["periodic_part"]][[length(e[["periodic_part"]]) + 1]] <- list(im = im)
    .Call("_imager_periodic_part", im)
}
