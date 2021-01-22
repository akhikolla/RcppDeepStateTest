function (T, x, xl, inv, p, order) 
{
    e <- get("data.env", .GlobalEnv)
    e[["D1"]][[length(e[["D1"]]) + 1]] <- list(T = T, x = x, 
        xl = xl, inv = inv, p = p, order = order)
    .Call("_Opt5PL_D1", T, x, xl, inv, p, order)
}
