function (y, blk, row, col, rN = 3, cN = 1) 
{
    e <- get("data.env", .GlobalEnv)
    e[["SPC"]][[length(e[["SPC"]]) + 1]] <- list(y = y, blk = blk, 
        row = row, col = col, rN = rN, cN = cN)
    .Call("_NAM_SPC", y, blk, row, col, rN, cN)
}
