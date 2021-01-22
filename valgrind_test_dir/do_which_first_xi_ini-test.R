function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_which_first_xi_ini"]][[length(e[["do_which_first_xi_ini"]]) + 
        1]] <- list(x = x, y = y)
    .Call("_hutilscpp_do_which_first_xi_ini", x, y)
}
