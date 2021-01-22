function (x, nThread = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sum_isna_int"]][[length(e[["sum_isna_int"]]) + 1]] <- list(x = x, 
        nThread = nThread)
    .Call("_hutilscpp_sum_isna_int", x, nThread)
}
