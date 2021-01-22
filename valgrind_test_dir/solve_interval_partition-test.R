function (x, kmax) 
{
    e <- get("data.env", .GlobalEnv)
    e[["solve_interval_partition"]][[length(e[["solve_interval_partition"]]) + 
        1]] <- list(x = x, kmax = kmax)
    .Call("_RcppDynProg_solve_interval_partition", PACKAGE = "RcppDynProg", 
        x, kmax)
}
