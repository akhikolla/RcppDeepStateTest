function (height, width, depth, time, seed, freq, fractal, octaves, 
    lacunarity, gain, pertube, pertube_amp) 
{
    e <- get("data.env", .GlobalEnv)
    e[["simplex_4d_c"]][[length(e[["simplex_4d_c"]]) + 1]] <- list(height = height, 
        width = width, depth = depth, time = time, seed = seed, 
        freq = freq, fractal = fractal, octaves = octaves, lacunarity = lacunarity, 
        gain = gain, pertube = pertube, pertube_amp = pertube_amp)
    .Call("_ambient_simplex_4d_c", PACKAGE = "ambient", height, 
        width, depth, time, seed, freq, fractal, octaves, lacunarity, 
        gain, pertube, pertube_amp)
}
