function (x, nThread = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_divisible2"]][[length(e[["do_divisible2"]]) + 1]] <- list(x = x, 
        nThread = nThread)
    .Call("_hutilscpp_do_divisible2", x, nThread)
}
