function (prob, x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["lpm1"]][[length(e[["lpm1"]]) + 1]] <- list(prob = prob, 
        x = x)
    .Call("_BalancedSampling_lpm1", PACKAGE = "BalancedSampling", 
        prob, x)
}
