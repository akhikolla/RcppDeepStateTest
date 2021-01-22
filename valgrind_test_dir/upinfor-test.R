function (W, T, X, order) 
{
    e <- get("data.env", .GlobalEnv)
    e[["upinfor"]][[length(e[["upinfor"]]) + 1]] <- list(W = W, 
        T = T, X = X, order = order)
    .Call("_Opt5PL_upinfor", W, T, X, order)
}
