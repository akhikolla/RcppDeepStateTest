function (prob, x, rand) 
{
    e <- get("data.env", .GlobalEnv)
    e[["scps_coord"]][[length(e[["scps_coord"]]) + 1]] <- list(prob = prob, 
        x = x, rand = rand)
    .Call("_BalancedSampling_scps_coord", PACKAGE = "BalancedSampling", 
        prob, x, rand)
}
