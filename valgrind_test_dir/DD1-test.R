function (T, x1, x2, xl, inv, p, order) 
{
    e <- get("data.env", .GlobalEnv)
    e[["DD1"]][[length(e[["DD1"]]) + 1]] <- list(T = T, x1 = x1, 
        x2 = x2, xl = xl, inv = inv, p = p, order = order)
    .Call("_Opt5PL_DD1", T, x1, x2, xl, inv, p, order)
}
