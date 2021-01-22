function (b_fixed, A_, par, ll_index1, item10, item20, cat1, 
    cat2, max_ll_index, pp1, pp2, h1, h2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["immer_ccml_probs_from_par"]][[length(e[["immer_ccml_probs_from_par"]]) + 
        1]] <- list(b_fixed = b_fixed, A_ = A_, par = par, ll_index1 = ll_index1, 
        item10 = item10, item20 = item20, cat1 = cat1, cat2 = cat2, 
        max_ll_index = max_ll_index, pp1 = pp1, pp2 = pp2, h1 = h1, 
        h2 = h2)
    .Call("_immer_immer_ccml_probs_from_par", PACKAGE = "immer", 
        b_fixed, A_, par, ll_index1, item10, item20, cat1, cat2, 
        max_ll_index, pp1, pp2, h1, h2)
}
