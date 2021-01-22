function (height, width, seed, freq, interp, fractal, octaves, 
    lacunarity, gain, pertube, pertube_amp) 
{
    e <- get("data.env", .GlobalEnv)
    e[["perlin_2d_c"]][[length(e[["perlin_2d_c"]]) + 1]] <- list(height = height, 
        width = width, seed = seed, freq = freq, interp = interp, 
        fractal = fractal, octaves = octaves, lacunarity = lacunarity, 
        gain = gain, pertube = pertube, pertube_amp = pertube_amp)
    .Call("_ambient_perlin_2d_c", PACKAGE = "ambient", height, 
        width, seed, freq, interp, fractal, octaves, lacunarity, 
        gain, pertube, pertube_amp)
}
