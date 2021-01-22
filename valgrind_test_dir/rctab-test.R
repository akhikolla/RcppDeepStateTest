function (M) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rctab"]][[length(e[["rctab"]]) + 1]] <- list(M = M)
    .Call("_HDLSSkST_rctab", M)
}
