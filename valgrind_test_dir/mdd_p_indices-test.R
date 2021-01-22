function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mdd_p_indices"]][[length(e[["mdd_p_indices"]]) + 1]] <- list(x = x)
    .Call("_stocks_mdd_p_indices", x)
}
