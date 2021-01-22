function (x, kmax) 
{
    e <- get("data.env", .GlobalEnv)
    e[["solve_interval_partition_k"]][[length(e[["solve_interval_partition_k"]]) + 
        1]] <- list(x = x, kmax = kmax)
    .Call("_RcppDynProg_solve_interval_partition_k", PACKAGE = "RcppDynProg", 
        x, kmax)
}
