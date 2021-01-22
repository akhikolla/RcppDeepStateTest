function (x, op, a) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_which_last_xi_ai"]][[length(e[["do_which_last_xi_ai"]]) + 
        1]] <- list(x = x, op = op, a = a)
    .Call("_hutilscpp_do_which_last_xi_ai", x, op, a)
}
