function (pi, theta, shape, beta, gamma, lower1, lower2, lower3, 
    lower4, lower5, upper3, upper4, upper5, trunclower, tsplice, 
    truncupper, eps, beta_tol, maxiter) 
{
    e <- get("data.env", .GlobalEnv)
    e[["spliceEM_splicefit_raw_Rexport"]][[length(e[["spliceEM_splicefit_raw_Rexport"]]) + 
        1]] <- list(pi = pi, theta = theta, shape = shape, beta = beta, 
        gamma = gamma, lower1 = lower1, lower2 = lower2, lower3 = lower3, 
        lower4 = lower4, lower5 = lower5, upper3 = upper3, upper4 = upper4, 
        upper5 = upper5, trunclower = trunclower, tsplice = tsplice, 
        truncupper = truncupper, eps = eps, beta_tol = beta_tol, 
        maxiter = maxiter)
    .Call("_ReIns_spliceEM_splicefit_raw_Rexport", pi, theta, 
        shape, beta, gamma, lower1, lower2, lower3, lower4, lower5, 
        upper3, upper4, upper5, trunclower, tsplice, truncupper, 
        eps, beta_tol, maxiter)
}
