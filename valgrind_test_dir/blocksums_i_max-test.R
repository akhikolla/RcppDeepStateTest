function (x, window) 
{
    e <- get("data.env", .GlobalEnv)
    e[["blocksums_i_max"]][[length(e[["blocksums_i_max"]]) + 
        1]] <- list(x = x, window = window)
    .Call("_accelerometry_blocksums_i_max", x, window)
}
