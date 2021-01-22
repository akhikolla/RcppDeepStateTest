function (b_fixed, A_, par, ll_index1, item10, item20, cat1, 
    cat2, n, ntot, max_ll_index, h) 
{
    e <- get("data.env", .GlobalEnv)
    e[["immer_ccml_se"]][[length(e[["immer_ccml_se"]]) + 1]] <- list(b_fixed = b_fixed, 
        A_ = A_, par = par, ll_index1 = ll_index1, item10 = item10, 
        item20 = item20, cat1 = cat1, cat2 = cat2, n = n, ntot = ntot, 
        max_ll_index = max_ll_index, h = h)
    .Call("_immer_immer_ccml_se", PACKAGE = "immer", b_fixed, 
        A_, par, ll_index1, item10, item20, cat1, cat2, n, ntot, 
        max_ll_index, h)
}
