function (x, nThread = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_divisible16"]][[length(e[["do_divisible16"]]) + 1]] <- list(x = x, 
        nThread = nThread)
    .Call("_hutilscpp_do_divisible16", x, nThread)
}
