function (blk, row, col, rN = 3, cN = 1) 
{
    e <- get("data.env", .GlobalEnv)
    e[["SPM"]][[length(e[["SPM"]]) + 1]] <- list(blk = blk, row = row, 
        col = col, rN = rN, cN = cN)
    .Call("_NAM_SPM", blk, row, col, rN, cN)
}
