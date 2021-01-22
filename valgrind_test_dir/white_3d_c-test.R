function (height, width, depth, seed, freq, pertube, pertube_amp) 
{
    e <- get("data.env", .GlobalEnv)
    e[["white_3d_c"]][[length(e[["white_3d_c"]]) + 1]] <- list(height = height, 
        width = width, depth = depth, seed = seed, freq = freq, 
        pertube = pertube, pertube_amp = pertube_amp)
    .Call("_ambient_white_3d_c", PACKAGE = "ambient", height, 
        width, depth, seed, freq, pertube, pertube_amp)
}
