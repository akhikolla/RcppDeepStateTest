function (v, k) 
{
    e <- get("data.env", .GlobalEnv)
    e[["remove_k_smallest"]][[length(e[["remove_k_smallest"]]) + 
        1]] <- list(v = v, k = k)
    .Call("_rlme_remove_k_smallest", PACKAGE = "rlme", v, k)
}
