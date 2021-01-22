function (N, x, hermite_function_mat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["hermite_integral_val"]][[length(e[["hermite_integral_val"]]) + 
        1]] <- list(N = N, x = x, hermite_function_mat = hermite_function_mat)
    .Call("_hermiter_hermite_integral_val", N, x, hermite_function_mat)
}
