function (L, d) 
{
    e <- get("data.env", .GlobalEnv)
    e[["solve_LO"]][[length(e[["solve_LO"]]) + 1]] <- list(L = L, 
        d = d)
    .Call("_Benchmarking_solve_LO", L, d)
}
