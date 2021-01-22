function (x, nThread = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_pmin0_bitwise"]][[length(e[["do_pmin0_bitwise"]]) + 
        1]] <- list(x = x, nThread = nThread)
    .Call("_hutilscpp_do_pmin0_bitwise", x, nThread)
}
