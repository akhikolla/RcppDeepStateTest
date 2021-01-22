function (index_i, index_j) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_n_cells"]][[length(e[["get_n_cells"]]) + 1]] <- list(index_i = index_i, 
        index_j = index_j)
    .Call("_fixest_get_n_cells", index_i, index_j)
}
