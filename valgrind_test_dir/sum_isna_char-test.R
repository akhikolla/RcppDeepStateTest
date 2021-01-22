function (x, nThread = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sum_isna_char"]][[length(e[["sum_isna_char"]]) + 1]] <- list(x = x, 
        nThread = nThread)
    .Call("_hutilscpp_sum_isna_char", x, nThread)
}
