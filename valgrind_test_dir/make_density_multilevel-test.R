function (ordered, interval) 
{
    e <- get("data.env", .GlobalEnv)
    e[["make_density_multilevel"]][[length(e[["make_density_multilevel"]]) + 
        1]] <- list(ordered = ordered, interval = interval)
    .Call("_imagerExtra_make_density_multilevel", ordered, interval)
}
