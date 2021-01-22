function (prob, x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["scps"]][[length(e[["scps"]]) + 1]] <- list(prob = prob, 
        x = x)
    .Call("_BalancedSampling_scps", PACKAGE = "BalancedSampling", 
        prob, x)
}
