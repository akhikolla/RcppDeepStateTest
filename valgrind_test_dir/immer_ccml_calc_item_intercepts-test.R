function (b_fixed, A_, par) 
{
    e <- get("data.env", .GlobalEnv)
    e[["immer_ccml_calc_item_intercepts"]][[length(e[["immer_ccml_calc_item_intercepts"]]) + 
        1]] <- list(b_fixed = b_fixed, A_ = A_, par = par)
    .Call("_immer_immer_ccml_calc_item_intercepts", PACKAGE = "immer", 
        b_fixed, A_, par)
}
