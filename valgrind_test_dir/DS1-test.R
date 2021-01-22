function (T, x, inv, p, order) 
{
    e <- get("data.env", .GlobalEnv)
    e[["DS1"]][[length(e[["DS1"]]) + 1]] <- list(T = T, x = x, 
        inv = inv, p = p, order = order)
    .Call("_Opt5PL_DS1", T, x, inv, p, order)
}
