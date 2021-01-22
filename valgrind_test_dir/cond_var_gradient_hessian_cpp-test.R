function (var, eps, omega, alpha, beta, init_vals) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cond_var_gradient_hessian_cpp"]][[length(e[["cond_var_gradient_hessian_cpp"]]) + 
        1]] <- list(var = var, eps = eps, omega = omega, alpha = alpha, 
        beta = beta, init_vals = init_vals)
    .Call("_CPAT_cond_var_gradient_hessian_cpp", PACKAGE = "CPAT", 
        var, eps, omega, alpha, beta, init_vals)
}
