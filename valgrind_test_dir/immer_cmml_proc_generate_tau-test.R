function (maxK, K) 
{
    e <- get("data.env", .GlobalEnv)
    e[["immer_cmml_proc_generate_tau"]][[length(e[["immer_cmml_proc_generate_tau"]]) + 
        1]] <- list(maxK = maxK, K = K)
    .Call("_immer_immer_cmml_proc_generate_tau", PACKAGE = "immer", 
        maxK, K)
}
