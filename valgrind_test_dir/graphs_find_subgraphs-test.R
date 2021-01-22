function (id_1, id_2, verbose = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["graphs_find_subgraphs"]][[length(e[["graphs_find_subgraphs"]]) + 
        1]] <- list(id_1 = id_1, id_2 = id_2, verbose = verbose)
    .Call("_dsmisc_graphs_find_subgraphs", PACKAGE = "dsmisc", 
        id_1, id_2, verbose)
}
