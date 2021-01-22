function (x, y, z, freq, seed, interp) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gen_value3d_c"]][[length(e[["gen_value3d_c"]]) + 1]] <- list(x = x, 
        y = y, z = z, freq = freq, seed = seed, interp = interp)
    .Call("_ambient_gen_value3d_c", PACKAGE = "ambient", x, y, 
        z, freq, seed, interp)
}
