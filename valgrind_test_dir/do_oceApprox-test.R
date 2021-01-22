function (x, y, xout, method) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_oceApprox"]][[length(e[["do_oceApprox"]]) + 1]] <- list(x = x, 
        y = y, xout = xout, method = method)
    .Call("_oce_do_oceApprox", x, y, xout, method)
}
