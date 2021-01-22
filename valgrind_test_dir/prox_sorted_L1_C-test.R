function (y, lambda) 
{
    e <- get("data.env", .GlobalEnv)
    e[["prox_sorted_L1_C"]][[length(e[["prox_sorted_L1_C"]]) + 
        1]] <- list(y = y, lambda = lambda)
    .Call("_grpSLOPE_prox_sorted_L1_C", y, lambda)
}
