function (n_steps, start, nc, nr, mk, hk) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_simulate_ssf"]][[length(e[["cpp_simulate_ssf"]]) + 
        1]] <- list(n_steps = n_steps, start = start, nc = nc, 
        nr = nr, mk = mk, hk = hk)
    .Call("_amt_cpp_simulate_ssf", PACKAGE = "amt", n_steps, 
        start, nc, nr, mk, hk)
}
