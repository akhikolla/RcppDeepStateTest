function (row, col, N) 
{
    e <- get("data.env", .GlobalEnv)
    e[["coordToIndex"]][[length(e[["coordToIndex"]]) + 1]] <- list(row = row, 
        col = col, N = N)
    .Call("_propr_coordToIndex", row, col, N)
}
