function (T, x1, x2, xl, inv, order) 
{
    e <- get("data.env", .GlobalEnv)
    e[["smalldd1"]][[length(e[["smalldd1"]]) + 1]] <- list(T = T, 
        x1 = x1, x2 = x2, xl = xl, inv = inv, order = order)
    .Call("_Opt5PL_smalldd1", T, x1, x2, xl, inv, order)
}
