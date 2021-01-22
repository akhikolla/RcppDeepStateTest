function (height, width, seed, freq, pertube, pertube_amp) 
{
    e <- get("data.env", .GlobalEnv)
    e[["white_2d_c"]][[length(e[["white_2d_c"]]) + 1]] <- list(height = height, 
        width = width, seed = seed, freq = freq, pertube = pertube, 
        pertube_amp = pertube_amp)
    .Call("_ambient_white_2d_c", PACKAGE = "ambient", height, 
        width, seed, freq, pertube, pertube_amp)
}
