function (prob, Xbal) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cube"]][[length(e[["cube"]]) + 1]] <- list(prob = prob, 
        Xbal = Xbal)
    .Call("_BalancedSampling_cube", PACKAGE = "BalancedSampling", 
        prob, Xbal)
}
