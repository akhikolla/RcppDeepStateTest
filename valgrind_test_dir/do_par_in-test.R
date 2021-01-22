function (x, table, nThread = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_par_in"]][[length(e[["do_par_in"]]) + 1]] <- list(x = x, 
        table = table, nThread = nThread)
    .Call("_hutilscpp_do_par_in", x, table, nThread)
}
