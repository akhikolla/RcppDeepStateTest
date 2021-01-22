function (x, nrow = 1L, ncol = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["repmat"]][[length(e[["repmat"]]) + 1]] <- list(x = x, 
        nrow = nrow, ncol = ncol)
    .Call("_MESS_repmat", x, nrow, ncol)
}
