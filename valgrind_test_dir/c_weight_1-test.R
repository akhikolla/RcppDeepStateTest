function (W, T, X, inv, p, order) 
{
    e <- get("data.env", .GlobalEnv)
    e[["c_weight_1"]][[length(e[["c_weight_1"]]) + 1]] <- list(W = W, 
        T = T, X = X, inv = inv, p = p, order = order)
    .Call("_Opt5PL_c_weight_1", W, T, X, inv, p, order)
}
