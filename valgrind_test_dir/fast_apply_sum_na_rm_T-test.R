function (X, dim) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fast_apply_sum_na_rm_T"]][[length(e[["fast_apply_sum_na_rm_T"]]) + 
        1]] <- list(X = X, dim = dim)
    .Call("_imp4p_fast_apply_sum_na_rm_T", PACKAGE = "imp4p", 
        X, dim)
}
