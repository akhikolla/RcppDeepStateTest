function (x, theta, b, a, K, x_ind, phi, psi, eps, pid, rater, 
    N) 
{
    e <- get("data.env", .GlobalEnv)
    e[["immer_sampling_xi"]][[length(e[["immer_sampling_xi"]]) + 
        1]] <- list(x = x, theta = theta, b = b, a = a, K = K, 
        x_ind = x_ind, phi = phi, psi = psi, eps = eps, pid = pid, 
        rater = rater, N = N)
    .Call("_immer_immer_sampling_xi", PACKAGE = "immer", x, theta, 
        b, a, K, x_ind, phi, psi, eps, pid, rater, N)
}
