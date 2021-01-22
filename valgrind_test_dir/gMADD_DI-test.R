function (s_fn, kmax, lb, M) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gMADD_DI"]][[length(e[["gMADD_DI"]]) + 1]] <- list(s_fn = s_fn, 
        kmax = kmax, lb = lb, M = M)
    .Call("_HDLSSkST_gMADD_DI", s_fn, kmax, lb, M)
}
