function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_cumsum_reset_sorted_int"]][[length(e[["do_cumsum_reset_sorted_int"]]) + 
        1]] <- list(x = x)
    .Call("_hutilscpp_do_cumsum_reset_sorted_int", x)
}
