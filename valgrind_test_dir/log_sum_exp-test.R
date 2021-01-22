function (u, v) 
{
    e <- get("data.env", .GlobalEnv)
    e[["log_sum_exp"]][[length(e[["log_sum_exp"]]) + 1]] <- list(u = u, 
        v = v)
    .Call("_TransPhylo_log_sum_exp", PACKAGE = "TransPhylo", 
        u, v)
}
