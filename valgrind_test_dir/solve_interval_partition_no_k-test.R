function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["solve_interval_partition_no_k"]][[length(e[["solve_interval_partition_no_k"]]) + 
        1]] <- list(x = x)
    .Call("_RcppDynProg_solve_interval_partition_no_k", PACKAGE = "RcppDynProg", 
        x)
}
