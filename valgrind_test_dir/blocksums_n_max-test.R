function (x, window) 
{
    e <- get("data.env", .GlobalEnv)
    e[["blocksums_n_max"]][[length(e[["blocksums_n_max"]]) + 
        1]] <- list(x = x, window = window)
    .Call("_accelerometry_blocksums_n_max", x, window)
}
