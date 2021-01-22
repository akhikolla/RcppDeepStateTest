function (T, x, inv, order) 
{
    e <- get("data.env", .GlobalEnv)
    e[["smallds1"]][[length(e[["smallds1"]]) + 1]] <- list(T = T, 
        x = x, inv = inv, order = order)
    .Call("_Opt5PL_smallds1", T, x, inv, order)
}
