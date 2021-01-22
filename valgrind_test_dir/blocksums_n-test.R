function (x, window) 
{
    e <- get("data.env", .GlobalEnv)
    e[["blocksums_n"]][[length(e[["blocksums_n"]]) + 1]] <- list(x = x, 
        window = window)
    .Call("_accelerometry_blocksums_n", x, window)
}
