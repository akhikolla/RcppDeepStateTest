function (X, y, type) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fastLm_Impl"]][[length(e[["fastLm_Impl"]]) + 1]] <- list(X = X, 
        y = y, type = type)
    .Call("_RcppEigen_fastLm_Impl", X, y, type)
}
