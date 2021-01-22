function (x, tbl) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_which_in"]][[length(e[["do_which_in"]]) + 1]] <- list(x = x, 
        tbl = tbl)
    .Call("_hutilscpp_do_which_in", x, tbl)
}
