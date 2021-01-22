function (prob) 
{
    e <- get("data.env", .GlobalEnv)
    e[["spm"]][[length(e[["spm"]]) + 1]] <- list(prob = prob)
    .Call("_BalancedSampling_spm", PACKAGE = "BalancedSampling", 
        prob)
}
