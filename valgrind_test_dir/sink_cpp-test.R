function (A, maxit = 99L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sink_cpp"]][[length(e[["sink_cpp"]]) + 1]] <- list(A = A, 
        maxit = maxit)
    .Call("_expperm_sink_cpp", A, maxit)
}
