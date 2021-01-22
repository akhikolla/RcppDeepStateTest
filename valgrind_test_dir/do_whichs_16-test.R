function (op, x, y, nThread = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_whichs_16"]][[length(e[["do_whichs_16"]]) + 1]] <- list(op = op, 
        x = x, y = y, nThread = nThread)
    .Call("_hutilscpp_do_whichs_16", op, x, y, nThread)
}
