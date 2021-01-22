function (X, bound, ridge_term, max_iter, theta, linear_func, 
    gradient, X_theta, ever_active, nactive, kkt_tol, objective_tol, 
    parameter_tol, max_active, kkt_stop, objective_stop, param_stop) 
{
    e <- get("data.env", .GlobalEnv)
    e[["solve_QP_wide"]][[length(e[["solve_QP_wide"]]) + 1]] <- list(X = X, 
        bound = bound, ridge_term = ridge_term, max_iter = max_iter, 
        theta = theta, linear_func = linear_func, gradient = gradient, 
        X_theta = X_theta, ever_active = ever_active, nactive = nactive, 
        kkt_tol = kkt_tol, objective_tol = objective_tol, parameter_tol = parameter_tol, 
        max_active = max_active, kkt_stop = kkt_stop, objective_stop = objective_stop, 
        param_stop = param_stop)
    .Call("_selectiveInference_solve_QP_wide", PACKAGE = "selectiveInference", 
        X, bound, ridge_term, max_iter, theta, linear_func, gradient, 
        X_theta, ever_active, nactive, kkt_tol, objective_tol, 
        parameter_tol, max_active, kkt_stop, objective_stop, 
        param_stop)
}
