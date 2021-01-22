function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["corr"]][[length(e[["corr"]]) + 1]] <- list(x = x, y = y)
    .Call("_ldsr_corr", x, y)
}
