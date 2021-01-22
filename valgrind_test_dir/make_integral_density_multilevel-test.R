function (density) 
{
    e <- get("data.env", .GlobalEnv)
    e[["make_integral_density_multilevel"]][[length(e[["make_integral_density_multilevel"]]) + 
        1]] <- list(density = density)
    .Call("_imagerExtra_make_integral_density_multilevel", density)
}
