function (T, x, order) 
{
    e <- get("data.env", .GlobalEnv)
    e[["infor"]][[length(e[["infor"]]) + 1]] <- list(T = T, x = x, 
        order = order)
    .Call("_Opt5PL_infor", T, x, order)
}
