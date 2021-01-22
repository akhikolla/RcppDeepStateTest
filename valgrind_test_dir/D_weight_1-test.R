function (q, W, T1, T2, T3, X, inv1, inv2, inv3) 
{
    e <- get("data.env", .GlobalEnv)
    e[["D_weight_1"]][[length(e[["D_weight_1"]]) + 1]] <- list(q = q, 
        W = W, T1 = T1, T2 = T2, T3 = T3, X = X, inv1 = inv1, 
        inv2 = inv2, inv3 = inv3)
    .Call("_Opt5PL_D_weight_1", q, W, T1, T2, T3, X, inv1, inv2, 
        inv3)
}
