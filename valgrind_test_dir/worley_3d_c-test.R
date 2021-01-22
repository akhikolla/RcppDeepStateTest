function (height, width, depth, seed, freq, fractal, octaves, 
    lacunarity, gain, dist, value, dist2ind, jitter, pertube, 
    pertube_amp) 
{
    e <- get("data.env", .GlobalEnv)
    e[["worley_3d_c"]][[length(e[["worley_3d_c"]]) + 1]] <- list(height = height, 
        width = width, depth = depth, seed = seed, freq = freq, 
        fractal = fractal, octaves = octaves, lacunarity = lacunarity, 
        gain = gain, dist = dist, value = value, dist2ind = dist2ind, 
        jitter = jitter, pertube = pertube, pertube_amp = pertube_amp)
    .Call("_ambient_worley_3d_c", PACKAGE = "ambient", height, 
        width, depth, seed, freq, fractal, octaves, lacunarity, 
        gain, dist, value, dist2ind, jitter, pertube, pertube_amp)
}
