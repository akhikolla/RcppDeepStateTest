function (A, n) 
{
    e <- get("data.env", .GlobalEnv)
    e[["triadCensusSign"]][[length(e[["triadCensusSign"]]) + 
        1]] <- list(A = A, n = n)
    .Call("_signnet_triadCensusSign", A, n)
}
