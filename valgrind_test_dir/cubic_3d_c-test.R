function (height, width, depth, seed, freq, fractal, octaves, 
    lacunarity, gain, pertube, pertube_amp) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cubic_3d_c"]][[length(e[["cubic_3d_c"]]) + 1]] <- list(height = height, 
        width = width, depth = depth, seed = seed, freq = freq, 
        fractal = fractal, octaves = octaves, lacunarity = lacunarity, 
        gain = gain, pertube = pertube, pertube_amp = pertube_amp)
    .Call("_ambient_cubic_3d_c", PACKAGE = "ambient", height, 
        width, depth, seed, freq, fractal, octaves, lacunarity, 
        gain, pertube, pertube_amp)
}
