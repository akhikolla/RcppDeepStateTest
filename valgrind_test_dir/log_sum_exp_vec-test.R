function (w) 
{
    e <- get("data.env", .GlobalEnv)
    e[["log_sum_exp_vec"]][[length(e[["log_sum_exp_vec"]]) + 
        1]] <- list(w = w)
    .Call("_TransPhylo_log_sum_exp_vec", PACKAGE = "TransPhylo", 
        w)
}
