function (x, nThread = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_pmax0_bitwise"]][[length(e[["do_pmax0_bitwise"]]) + 
        1]] <- list(x = x, nThread = nThread)
    .Call("_hutilscpp_do_pmax0_bitwise", x, nThread)
}
