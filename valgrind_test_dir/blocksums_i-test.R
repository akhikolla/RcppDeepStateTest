function (x, window) 
{
    e <- get("data.env", .GlobalEnv)
    e[["blocksums_i"]][[length(e[["blocksums_i"]]) + 1]] <- list(x = x, 
        window = window)
    .Call("_accelerometry_blocksums_i", x, window)
}
