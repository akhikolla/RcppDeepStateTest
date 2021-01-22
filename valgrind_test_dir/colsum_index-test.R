function (X, indexes) 
{
    e <- get("data.env", .GlobalEnv)
    e[["colsum_index"]][[length(e[["colsum_index"]]) + 1]] <- list(X = X, 
        indexes = indexes)
    .Call("_xyz_colsum_index", X, indexes)
}
