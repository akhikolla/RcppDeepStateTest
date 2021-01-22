function (A, B) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tracemp"]][[length(e[["tracemp"]]) + 1]] <- list(A = A, 
        B = B)
    .Call("_MESS_tracemp", A, B)
}
