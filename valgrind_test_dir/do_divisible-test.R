function (x, d, nThread = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_divisible"]][[length(e[["do_divisible"]]) + 1]] <- list(x = x, 
        d = d, nThread = nThread)
    .Call("_hutilscpp_do_divisible", x, d, nThread)
}
