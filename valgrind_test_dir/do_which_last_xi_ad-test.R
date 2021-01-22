function (x, op, ad) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_which_last_xi_ad"]][[length(e[["do_which_last_xi_ad"]]) + 
        1]] <- list(x = x, op = op, ad = ad)
    .Call("_hutilscpp_do_which_last_xi_ad", x, op, ad)
}
