function (x, y, z, freq, seed, interp) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gen_perlin3d_c"]][[length(e[["gen_perlin3d_c"]]) + 1]] <- list(x = x, 
        y = y, z = z, freq = freq, seed = seed, interp = interp)
    .Call("_ambient_gen_perlin3d_c", PACKAGE = "ambient", x, 
        y, z, freq, seed, interp)
}
