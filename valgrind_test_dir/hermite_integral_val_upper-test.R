function (N, x, hermite_function_mat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["hermite_integral_val_upper"]][[length(e[["hermite_integral_val_upper"]]) + 
        1]] <- list(N = N, x = x, hermite_function_mat = hermite_function_mat)
    .Call("_hermiter_hermite_integral_val_upper", N, x, hermite_function_mat)
}
