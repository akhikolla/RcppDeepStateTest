function (A) 
{
    e <- get("data.env", .GlobalEnv)
    e[["brute_cpp"]][[length(e[["brute_cpp"]]) + 1]] <- list(A = A)
    .Call("_expperm_brute_cpp", A)
}
