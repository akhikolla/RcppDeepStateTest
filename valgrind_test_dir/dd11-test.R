function (T, x1, x2, xl, inv, inv1, order) 
{
    e <- get("data.env", .GlobalEnv)
    e[["dd11"]][[length(e[["dd11"]]) + 1]] <- list(T = T, x1 = x1, 
        x2 = x2, xl = xl, inv = inv, inv1 = inv1, order = order)
    .Call("_Opt5PL_dd11", T, x1, x2, xl, inv, inv1, order)
}
