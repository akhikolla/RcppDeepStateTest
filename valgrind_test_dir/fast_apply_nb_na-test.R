function (X, dim) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fast_apply_nb_na"]][[length(e[["fast_apply_nb_na"]]) + 
        1]] <- list(X = X, dim = dim)
    .Call("_imp4p_fast_apply_nb_na", PACKAGE = "imp4p", X, dim)
}
