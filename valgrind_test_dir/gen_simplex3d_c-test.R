function (x, y, z, freq, seed) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gen_simplex3d_c"]][[length(e[["gen_simplex3d_c"]]) + 
        1]] <- list(x = x, y = y, z = z, freq = freq, seed = seed)
    .Call("_ambient_gen_simplex3d_c", PACKAGE = "ambient", x, 
        y, z, freq, seed)
}
