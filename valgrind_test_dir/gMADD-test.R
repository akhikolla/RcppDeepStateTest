function (s_fn, n_clust, lb, M) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gMADD"]][[length(e[["gMADD"]]) + 1]] <- list(s_fn = s_fn, 
        n_clust = n_clust, lb = lb, M = M)
    .Call("_HDLSSkST_gMADD", s_fn, n_clust, lb, M)
}
