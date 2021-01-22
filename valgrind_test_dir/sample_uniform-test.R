function (range, n) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sample_uniform"]][[length(e[["sample_uniform"]]) + 1]] <- list(range = range, 
        n = n)
    .Call("_xyz_sample_uniform", range, n)
}
