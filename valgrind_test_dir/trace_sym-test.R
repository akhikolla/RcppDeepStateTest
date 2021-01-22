function (A, B) 
{
    e <- get("data.env", .GlobalEnv)
    e[["trace_sym"]][[length(e[["trace_sym"]]) + 1]] <- list(A = A, 
        B = B)
    .Call("_hetGP_trace_sym", PACKAGE = "hetGP", A, B)
}
