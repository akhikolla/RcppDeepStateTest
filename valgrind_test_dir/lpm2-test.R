function (prob, x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["lpm2"]][[length(e[["lpm2"]]) + 1]] <- list(prob = prob, 
        x = x)
    .Call("_BalancedSampling_lpm2", PACKAGE = "BalancedSampling", 
        prob, x)
}
