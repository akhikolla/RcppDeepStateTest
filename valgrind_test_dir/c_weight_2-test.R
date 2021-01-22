function (W, T, X, inv, p, order) 
{
    e <- get("data.env", .GlobalEnv)
    e[["c_weight_2"]][[length(e[["c_weight_2"]]) + 1]] <- list(W = W, 
        T = T, X = X, inv = inv, p = p, order = order)
    .Call("_Opt5PL_c_weight_2", W, T, X, inv, p, order)
}
