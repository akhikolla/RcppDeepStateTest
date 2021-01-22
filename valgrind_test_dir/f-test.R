function (T, x, order) 
{
    e <- get("data.env", .GlobalEnv)
    e[["f"]][[length(e[["f"]]) + 1]] <- list(T = T, x = x, order = order)
    .Call("_Opt5PL_f", T, x, order)
}
