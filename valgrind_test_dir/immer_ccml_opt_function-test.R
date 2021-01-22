function (b, ll_index1, item10, item20, cat1, cat2, n, ntot, 
    max_ll_index) 
{
    e <- get("data.env", .GlobalEnv)
    e[["immer_ccml_opt_function"]][[length(e[["immer_ccml_opt_function"]]) + 
        1]] <- list(b = b, ll_index1 = ll_index1, item10 = item10, 
        item20 = item20, cat1 = cat1, cat2 = cat2, n = n, ntot = ntot, 
        max_ll_index = max_ll_index)
    .Call("_immer_immer_ccml_opt_function", PACKAGE = "immer", 
        b, ll_index1, item10, item20, cat1, cat2, n, ntot, max_ll_index)
}
