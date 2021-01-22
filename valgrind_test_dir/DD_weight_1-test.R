function (W, T, X, inv, inv1, order) 
{
    e <- get("data.env", .GlobalEnv)
    e[["DD_weight_1"]][[length(e[["DD_weight_1"]]) + 1]] <- list(W = W, 
        T = T, X = X, inv = inv, inv1 = inv1, order = order)
    .Call("_Opt5PL_DD_weight_1", W, T, X, inv, inv1, order)
}
