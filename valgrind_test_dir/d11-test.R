function (T, x, xl, inv, inv1, order) 
{
    e <- get("data.env", .GlobalEnv)
    e[["d11"]][[length(e[["d11"]]) + 1]] <- list(T = T, x = x, 
        xl = xl, inv = inv, inv1 = inv1, order = order)
    .Call("_Opt5PL_d11", T, x, xl, inv, inv1, order)
}
