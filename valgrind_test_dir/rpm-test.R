function (prob) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rpm"]][[length(e[["rpm"]]) + 1]] <- list(prob = prob)
    .Call("_BalancedSampling_rpm", PACKAGE = "BalancedSampling", 
        prob)
}
