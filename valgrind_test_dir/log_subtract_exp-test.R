function (u, v) 
{
    e <- get("data.env", .GlobalEnv)
    e[["log_subtract_exp"]][[length(e[["log_subtract_exp"]]) + 
        1]] <- list(u = u, v = v)
    .Call("_TransPhylo_log_subtract_exp", PACKAGE = "TransPhylo", 
        u, v)
}
