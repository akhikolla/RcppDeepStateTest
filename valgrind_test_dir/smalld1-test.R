function (T, x, xl, inv, order) 
{
    e <- get("data.env", .GlobalEnv)
    e[["smalld1"]][[length(e[["smalld1"]]) + 1]] <- list(T = T, 
        x = x, xl = xl, inv = inv, order = order)
    .Call("_Opt5PL_smalld1", T, x, xl, inv, order)
}
