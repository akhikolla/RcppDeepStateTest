function (n_steps, start, nc, nr, mk, hk) 
{
    e <- get("data.env", .GlobalEnv)
    e[["simulate_udf"]][[length(e[["simulate_udf"]]) + 1]] <- list(n_steps = n_steps, 
        start = start, nc = nc, nr = nr, mk = mk, hk = hk)
    .Call("_amt_simulate_udf", PACKAGE = "amt", n_steps, start, 
        nc, nr, mk, hk)
}
