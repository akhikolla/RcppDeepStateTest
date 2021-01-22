function (Sigma, bound, max_iter, theta, linear_func, gradient, 
    ever_active, nactive, kkt_tol, objective_tol, parameter_tol, 
    max_active, kkt_stop, objective_stop, param_stop) 
{
    e <- get("data.env", .GlobalEnv)
    e[["solve_QP"]][[length(e[["solve_QP"]]) + 1]] <- list(Sigma = Sigma, 
        bound = bound, max_iter = max_iter, theta = theta, linear_func = linear_func, 
        gradient = gradient, ever_active = ever_active, nactive = nactive, 
        kkt_tol = kkt_tol, objective_tol = objective_tol, parameter_tol = parameter_tol, 
        max_active = max_active, kkt_stop = kkt_stop, objective_stop = objective_stop, 
        param_stop = param_stop)
    .Call("_selectiveInference_solve_QP", PACKAGE = "selectiveInference", 
        Sigma, bound, max_iter, theta, linear_func, gradient, 
        ever_active, nactive, kkt_tol, objective_tol, parameter_tol, 
        max_active, kkt_stop, objective_stop, param_stop)
}
