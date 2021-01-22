function (T, x, inv, inv1, order) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ds11"]][[length(e[["ds11"]]) + 1]] <- list(T = T, x = x, 
        inv = inv, inv1 = inv1, order = order)
    .Call("_Opt5PL_ds11", T, x, inv, inv1, order)
}
