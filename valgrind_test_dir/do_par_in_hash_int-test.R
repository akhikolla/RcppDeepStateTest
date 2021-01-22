function (x, table, nThread = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_par_in_hash_int"]][[length(e[["do_par_in_hash_int"]]) + 
        1]] <- list(x = x, table = table, nThread = nThread)
    .Call("_hutilscpp_do_par_in_hash_int", x, table, nThread)
}
