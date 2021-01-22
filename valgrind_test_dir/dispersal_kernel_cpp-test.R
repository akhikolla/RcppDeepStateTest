function (cur_x, cur_y, nc, nr, dk, coefs, standardize, first_order_terms, 
    second_order_terms, hab, other_covars, other_covars_indicator, 
    stop) 
{
    e <- get("data.env", .GlobalEnv)
    e[["dispersal_kernel_cpp"]][[length(e[["dispersal_kernel_cpp"]]) + 
        1]] <- list(cur_x = cur_x, cur_y = cur_y, nc = nc, nr = nr, 
        dk = dk, coefs = coefs, standardize = standardize, first_order_terms = first_order_terms, 
        second_order_terms = second_order_terms, hab = hab, other_covars = other_covars, 
        other_covars_indicator = other_covars_indicator, stop = stop)
    .Call("_amt_dispersal_kernel_cpp", PACKAGE = "amt", cur_x, 
        cur_y, nc, nr, dk, coefs, standardize, first_order_terms, 
        second_order_terms, hab, other_covars, other_covars_indicator, 
        stop)
}
