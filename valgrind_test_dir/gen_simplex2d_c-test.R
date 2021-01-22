function (x, y, freq, seed) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gen_simplex2d_c"]][[length(e[["gen_simplex2d_c"]]) + 
        1]] <- list(x = x, y = y, freq = freq, seed = seed)
    .Call("_ambient_gen_simplex2d_c", PACKAGE = "ambient", x, 
        y, freq, seed)
}
