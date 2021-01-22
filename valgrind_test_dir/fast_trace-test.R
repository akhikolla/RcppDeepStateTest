function (A, B) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fast_trace"]][[length(e[["fast_trace"]]) + 1]] <- list(A = A, 
        B = B)
    .Call("_hetGP_fast_trace", PACKAGE = "hetGP", A, B)
}
