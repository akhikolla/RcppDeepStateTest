function (x, op, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_which_last_xi_yi"]][[length(e[["do_which_last_xi_yi"]]) + 
        1]] <- list(x = x, op = op, y = y)
    .Call("_hutilscpp_do_which_last_xi_yi", x, op, y)
}
