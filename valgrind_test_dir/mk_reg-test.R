function (t1, time_dist, time_tol, start) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mk_reg"]][[length(e[["mk_reg"]]) + 1]] <- list(t1 = t1, 
        time_dist = time_dist, time_tol = time_tol, start = start)
    .Call("_amt_mk_reg", PACKAGE = "amt", t1, time_dist, time_tol, 
        start)
}
