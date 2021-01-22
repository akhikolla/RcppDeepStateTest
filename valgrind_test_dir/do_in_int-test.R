function (x, table) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_in_int"]][[length(e[["do_in_int"]]) + 1]] <- list(x = x, 
        table = table)
    .Call("_hutilscpp_do_in_int", x, table)
}
