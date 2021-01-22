function (height, width, depth, time, seed, freq, pertube, pertube_amp) 
{
    e <- get("data.env", .GlobalEnv)
    e[["white_4d_c"]][[length(e[["white_4d_c"]]) + 1]] <- list(height = height, 
        width = width, depth = depth, time = time, seed = seed, 
        freq = freq, pertube = pertube, pertube_amp = pertube_amp)
    .Call("_ambient_white_4d_c", PACKAGE = "ambient", height, 
        width, depth, time, seed, freq, pertube, pertube_amp)
}
