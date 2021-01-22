function (prob, x, h) 
{
    e <- get("data.env", .GlobalEnv)
    e[["lpm"]][[length(e[["lpm"]]) + 1]] <- list(prob = prob, 
        x = x, h = h)
    .Call("_BalancedSampling_lpm", PACKAGE = "BalancedSampling", 
        prob, x, h)
}
